#include <XnCppWrapper.h>

//#include "../Gui/gui.h"
//#include "../Gui/tab.h"
// #include "../Gui/input_singleton.h"
// #include "../Gui/video.h"
// #include "../Gui/button.h"
#include "../Plugin_API/pluginapi.h"
#include "../SharedMemory/SharedMemory.h"
#include "../Human/Human.h"
#include "../Human/joint.h"

#include "Ni_Device.h"
//#include <Fl/fl_file_chooser.h>
#define PLUGIN_NAME "Kinect_Plugin"
#define SAMPLE_XML_PATH "../data/Kinect/SamplesConfig2.xml"

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
//#include "../MDP/MDP.h"

SharedMemory *sharedMemory;

#define ORIGIN_X 56
#define ORIGIN_Y 107

#define DEG_TO_RAD 0.0174532925;
clock_t t_ini, t_fin;
bool firstTime= true;
//Calcula un punto en el mapa con recout << "Robot Position: "<< robotx << "," << roboty << "," << robotth<<endl;specto a un punto del kinect (regresado por un gesto)
Location getPointInMap(Location location){
    float robotx=location.get_X();
    float roboty=location.get_Y();
    float robotth=location.get_Angle() * DEG_TO_RAD;

    float humanx=Human::getInstance().gesture[2];//le reste 100 probando cque no vaya tan cerca de la persona
    float humany=Human::getInstance().gesture[1]*-1;

    float X=robotx+(((humanx*cos(robotth))-(humany*sin(robotth)))*.7);
    float Y=roboty+(((humanx*sin(robotth))+(humany*cos(robotth)))*.7); 
    
    cout << "Robot Position: "<< robotx << "," << roboty << "," << robotth<<endl;
    cout << "Gesture Position: "<< humanx << "," << humany << "," << robotth<<endl;
    
    Location temp;
    temp.set_X(X);
    temp.set_Y(Y);
    temp.set_Angle(location.get_Angle()); 
    cout << "Punto obtenido de kinect a mapa: "<< X << "," << Y << "," << location.get_Angle()<<endl;
    cout << "Punto obtenido de kinect a mapa: "<< temp.get_X() << "," << temp.get_Y() << "," << temp.get_Angle()<<endl;
    return temp;
}

class Kinect_Plugin : public IPlugin
{
public:
    void Main();
    void run();
    void stop();
    void human();
};

PLUGIN_FUNC IPlugin *CreatePlugin()
{
    return new Kinect_Plugin;
}

PLUGIN_FUNC void DestroyPlugin(IPlugin *r)
{
    delete r;
}

PLUGIN_DISPLAY_NAME(PLUGIN_NAME);

PLUGIN_INIT()
{
    // register our new plugin
    std::cout << "PLUGIN_INIT" << std::endl;
    RegisterPlugin(PLUGIN_NAME, CreatePlugin, DestroyPlugin);
    return 0;
}

//---------------------------------------------------------------------------
// Globals
//---------------------------------------------------------------------------
Ni_Device *KNI_DEV;


/* When true, frames will not be read from the device. */
bool g_bPause = false;
/* When true, only a single frame will be read, and then reading will be paused. */
bool g_bStep = false;

XnBool g_bNeedPose = FALSE;
XnChar g_strPose[20] = "";

#define MAX_NUM_USERS 1
//---------------------------------------------------------------------------
// Code
//---------------------------------------------------------------------------

XnBool fileExists(const char *fn)
{
    XnBool exists;
    xnOSDoesFileExist(fn, &exists);
    return exists;
}

// Callback: New user was detected
void XN_CALLBACK_TYPE User_NewUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie)
{
    XnUInt32 epochTime = 0;
    xnOSGetEpochTime(&epochTime);
    printf("%d New User %d\n", epochTime, nId);
    // New user found
    if (g_bNeedPose)
    {
        KNI_DEV->getInstance().g_User.GetPoseDetectionCap().StartPoseDetection(g_strPose, nId);
    }
    else
    {
        KNI_DEV->getInstance().g_User.GetSkeletonCap().RequestCalibration(nId, TRUE);
    }
}
// Callback: An existing user was lost
void XN_CALLBACK_TYPE User_LostUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie)
{
    XnUInt32 epochTime = 0;
    xnOSGetEpochTime(&epochTime);
    printf("%d Lost user %d\n", epochTime, nId);
}
// Callback: Detected a pose
void XN_CALLBACK_TYPE UserPose_PoseDetected(xn::PoseDetectionCapability& capability, const XnChar* strPose, XnUserID nId, void* pCookie)
{
    XnUInt32 epochTime = 0;
    xnOSGetEpochTime(&epochTime);
    printf("%d Pose %s detected for user %d\n", epochTime, strPose, nId);
    KNI_DEV->getInstance().g_User.GetPoseDetectionCap().StopPoseDetection(nId);
    KNI_DEV->getInstance().g_User.GetSkeletonCap().RequestCalibration(nId, TRUE);
}
// Callback: Started calibration
void XN_CALLBACK_TYPE UserCalibration_CalibrationStart(xn::SkeletonCapability& capability, XnUserID nId, void* pCookie)
{
    XnUInt32 epochTime = 0;
    xnOSGetEpochTime(&epochTime);
    printf("%d Calibration started for user %d\n", epochTime, nId);
}

// Callback for wave detection
void XN_CALLBACK_TYPE OnWaveCB(void* cxt)
{
	cout<<"**** InitialWAVE! *****"<<endl;
	Human::getInstance().gesture_detected=true;
}
// callback for a new position of any hand
void XN_CALLBACK_TYPE OnPointUpdate(const XnVHandPointContext* pContext, void* cxt)
{
  if(!Human::getInstance().gesture_detected)
  {
	Human::getInstance().gesture_detected=true;
	Human::getInstance().gesture[0]= pContext->ptPosition.X;
	Human::getInstance().gesture[1]= pContext->ptPosition.Y;
	Human::getInstance().gesture[2]= pContext->ptPosition.Z;
	std::cout <<"mano en " << Human::getInstance().gesture[0] << " " << Human::getInstance().gesture[1] << " " << Human::getInstance().gesture[2] << std::endl;
  }
}

void XN_CALLBACK_TYPE UserCalibration_CalibrationComplete(xn::SkeletonCapability& capability, XnUserID nId, XnCalibrationStatus eStatus, void* pCookie)
{
    XnUInt32 epochTime = 0;
    xnOSGetEpochTime(&epochTime);
    if (eStatus == XN_CALIBRATION_STATUS_OK)
    {
        // Calibration succeeded
        printf("%d Calibration complete, start tracking user %d\n", epochTime, nId);
        KNI_DEV->getInstance().g_User.GetSkeletonCap().StartTracking(nId);
    }
    else
    {
        // Calibration failed
        printf("%d Calibration failed for user %d\n", epochTime, nId);
        if(eStatus==XN_CALIBRATION_STATUS_MANUAL_ABORT)
        {
            printf("Manual abort occured, stop attempting to calibrate!");
            return;
        }
        if (g_bNeedPose)
        {
            KNI_DEV->getInstance().g_User.GetPoseDetectionCap().StartPoseDetection(g_strPose, nId);
        }
        else
        {
            KNI_DEV->getInstance().g_User.GetSkeletonCap().RequestCalibration(nId, TRUE);
        }
    }
}

// Callback for when the focus is in progress
void XN_CALLBACK_TYPE SessionProgress(const XnChar* strFocus, const XnPoint3D& ptFocusPoint, XnFloat fProgress, void* UserCxt)
{
// 	printf("Session progress (%6.2f,%6.2f,%6.2f) - %6.2f [%s]\n", ptFocusPoint.X, ptFocusPoint.Y, ptFocusPoint.Z, fProgress,  strFocus);
}
// callback for session start
void XN_CALLBACK_TYPE SessionStart(const XnPoint3D& ptFocusPoint, void* UserCxt)
{
// 	printf("Session started. Please wave (%6.2f,%6.2f,%6.2f)...\n", ptFocusPoint.X, ptFocusPoint.Y, ptFocusPoint.Z);
}
// Callback for session end
void XN_CALLBACK_TYPE SessionEnd(void* UserCxt)
{
// 	printf("Session ended. Please perform focus gesture to start session\n");
}


#define CHECK_RC(nRetVal, what)                                     \
if (nRetVal != XN_STATUS_OK)                                \
{                                                                   \
printf("%s failed: %s\n", what, xnGetStatusString(nRetVal));    \
return nRetVal;                                             \
}

float heading, attitude, bank;

#include <math.h>

void rotate(XnFloat  m[9]) {
    // Assuming the angles are in radians.
    if (m[4] > 0.998) { // singularity at north pole
        heading = atan2(m[3],m[9]);
        attitude = 3.141592/2;
        bank = 0;
        return;
    }
    if (m[4] < -0.998) { // singularity at south pole
        heading = atan2(m[3],m[9]);
        attitude = -3.141592/2;
        bank = 0;
        return;
    }
    heading = atan2(-m[7],m[0]);
    bank = atan2(-m[6],m[5]);
    attitude = asin(m[4]);
}


XnUInt64 F_;
XnDouble pixel_size_;

// void getdephtmm(int u, int v, double &X, double &Y, double &Z)
// {
//     KNI_DEV->getInstance().g_Depth.GetIntProperty("ZPD", F_);
// 
//     const XnDepthPixel* pDepthMap = KNI_DEV->getInstance().g_Depth.GetDepthMap();
//     KNI_DEV->getInstance().g_Depth.GetRealProperty ("ZPPS", pixel_size_);
//     int depthIdx=v * XN_VGA_X_RES + u;
//     X = (u - 320) * pDepthMap[depthIdx] * (pixel_size_ * 2)   / F_;
//     Y = (v - 240) * pDepthMap[depthIdx] * (pixel_size_* 2)  / F_;
//     Z = pDepthMap[depthIdx] ;
// 
//     std::cout << "kinect says point " << u << " " << v << " is at " << X << "  " << Y << "   " << Z << std::endl;
// 
// 
// }

void getdephtmm(int u, int v, double &X, double &Y, double &Z)
{
    KNI_DEV->getInstance().g_Depth.GetIntProperty("ZPD", F_);

    const XnDepthPixel* pDepthMap = KNI_DEV->getInstance().g_Depth.GetDepthMap();
    KNI_DEV->getInstance().g_Depth.GetRealProperty ("ZPPS", pixel_size_);
    int depthIdx=v * XN_VGA_X_RES + u;
     X = (u - 320) * pDepthMap[depthIdx] * (pixel_size_*2)  / F_;
      Y = (v - 240) * pDepthMap[depthIdx] * (pixel_size_*2)  / F_;
      Z = pDepthMap[depthIdx] ;
    for (int j=-2; j<=2; j++)
    {
      for (int k=-2; k<=2; k++)
      {
	int depthIdx=(v+k) * XN_VGA_X_RES + (u+j);
       X =(X+ ((u+j) - 320) * pDepthMap[depthIdx] * (pixel_size_*2)  / F_)/2;
       Y = (Y+ ((v+k) - 240) * pDepthMap[depthIdx] * (pixel_size_*2)  / F_)/2;
       Z = (Z+pDepthMap[depthIdx])/2 ;
      }
    }

    std::cout << "kinect says point " << u << " " << v << " is at " << X << "  " << Y << "   " << Z << std::endl;
//     sleep(10);

}



void Kinect_Plugin::Main()
{
    std::cout << "Starting KINECTplugin" << std::endl;
    XnStatus nRetVal = XN_STATUS_OK;
    xn::EnumerationErrors errors;
    KNI_DEV->getInstance().Initialize();

    Human::getInstance().Initialize("../data/Kinect/Skeleton");


    //Gui::getInstance();
    //Tab *pluginTab;

    //Video *polo;

    //pluginTab = new Tab("Kinect_Plugin");
    //polo=new Video(10,10,640,480,"polo", pluginTab);


    nRetVal = KNI_DEV->getInstance().openDeviceFromXml(SAMPLE_XML_PATH,  errors);



    if (nRetVal == XN_STATUS_NO_NODE_PRESENT)
    {
        XnChar strError[1024];
        errors.ToString(strError, 1024);
        printf("%s\n", strError);
    }
    else if (nRetVal != XN_STATUS_OK)
    {
        printf("Open failed: %s\n", xnGetStatusString(nRetVal));
    }else 
       std::cout << "KINECTplugin started" << std::endl;

    nRetVal = KNI_DEV->getInstance().g_Context.FindExistingNode(XN_NODE_TYPE_IMAGE, *KNI_DEV->getInstance().getImageGenerator());
    nRetVal = KNI_DEV->getInstance().g_Context.FindExistingNode(XN_NODE_TYPE_DEPTH, *KNI_DEV->getInstance().getDepthGenerator());
     KNI_DEV->getInstance().getDepthGenerator()->GetAlternativeViewPointCap().SetViewPoint(*KNI_DEV->getInstance().getImageGenerator());
     nRetVal = KNI_DEV->getInstance().g_Context.FindExistingNode(XN_NODE_TYPE_USER, *KNI_DEV->getInstance().getUserGenerator());
//     
    nRetVal = KNI_DEV->getInstance().g_Context.FindExistingNode(XN_NODE_TYPE_GESTURE, *KNI_DEV->getInstance().getGestureGenerator());
    nRetVal = KNI_DEV->getInstance().g_Context.FindExistingNode(XN_NODE_TYPE_HANDS, *KNI_DEV->getInstance().getHandsGenerator());
// 
     //KNI_DEV->getInstance().g_Scene.GetMetaData(KNI_DEV->getInstance().g_SceneMD );

    XnCallbackHandle hUserCallbacks, hCalibrationStart, hCalibrationComplete, hPoseDetected;
    if (!KNI_DEV->getInstance().g_User.IsCapabilitySupported(XN_CAPABILITY_SKELETON))
    {
        printf("Supplied user generator doesn't support skeleton\n");
    }
    nRetVal = KNI_DEV->getInstance().g_User.RegisterUserCallbacks(User_NewUser, User_LostUser, NULL, hUserCallbacks);
    nRetVal = KNI_DEV->getInstance().g_User.GetSkeletonCap().RegisterToCalibrationStart(UserCalibration_CalibrationStart, NULL, hCalibrationStart);
    nRetVal = KNI_DEV->getInstance().g_User.GetSkeletonCap().RegisterToCalibrationComplete(UserCalibration_CalibrationComplete, NULL, hCalibrationComplete);
    nRetVal = KNI_DEV->getInstance().g_User.GetPoseDetectionCap().RegisterToPoseDetected(UserPose_PoseDetected, NULL, hPoseDetected);
    KNI_DEV->getInstance().g_User.GetSkeletonCap().GetCalibrationPose(g_strPose);

    KNI_DEV->getInstance().g_User.GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);

    
    

    
    // Create the Session Manager
		KNI_DEV->getInstance().pSessionGenerator = new XnVSessionManager();
		nRetVal = ((XnVSessionManager*)KNI_DEV->getInstance().pSessionGenerator)->Initialize(&KNI_DEV->getInstance().g_Context, "Wave", "RaiseHand");
		if (nRetVal != XN_STATUS_OK)
		{
			printf("Session Manager couldn't initialize: %s\n", xnGetStatusString(nRetVal));
			delete KNI_DEV->getInstance().pSessionGenerator;
		}else
		  printf("Session Manager initialized: %s\n", xnGetStatusString(nRetVal));
		
		
	nRetVal =  KNI_DEV->getInstance().g_Context.StartGeneratingAll();

	KNI_DEV->getInstance().pSessionGenerator->RegisterSession(NULL, &SessionStart, &SessionEnd, &SessionProgress);
	KNI_DEV->getInstance().wc.RegisterWave(NULL, OnWaveCB);
	KNI_DEV->getInstance().wc.RegisterPointUpdate(NULL, OnPointUpdate);
	KNI_DEV->getInstance().pSessionGenerator->AddListener(&KNI_DEV->getInstance().wc);
	
	
    XnUserID aUsers[MAX_NUM_USERS];
    XnUInt16 nUsers;

    XnSkeletonJointTransformation Joint[24];

    printf("Starting to run\n");
    if(g_bNeedPose)
    {
        printf("Assume calibration pose\n");
    }
    XnUInt32 epochTime = 0;

    IplImage* imgDepth16u=cvCreateImage(cvSize(640,480),IPL_DEPTH_16U,1);
    IplImage* imgRGB8u=cvCreateImage(cvSize(1280,1024),IPL_DEPTH_8U,3);
    IplImage* depthinfo=cvCreateImage(cvSize(640,480),IPL_DEPTH_8U,1);
    IplImage* imageinfo=cvCreateImage(cvSize(1280,1024),IPL_DEPTH_8U,3);

    IplImage* sceneinfo=cvCreateImage(cvSize(640,480),IPL_DEPTH_8U,3);



    XnUInt32 total_frames=0;
    
    //string action = "payAttention";
    
    for(;;)
    {

        KNI_DEV->getInstance().readFrame();
	KNI_DEV->getInstance().g_Context.WaitAnyUpdateAll();
	((XnVSessionManager*)KNI_DEV->getInstance().pSessionGenerator)->Update(&KNI_DEV->getInstance().g_Context);
	

        memcpy(imgDepth16u->imageData, KNI_DEV->getInstance().getDepthMetaData()->Data(),640*480*2);
        cvConvertScale(imgDepth16u,depthinfo,255/4096.0,0);


        memcpy(imgRGB8u->imageData,KNI_DEV->getInstance().getImageMetaData()->Data(),1280*1024*3);
        cvCvtColor(imgRGB8u,imageinfo,CV_RGB2BGR);

        sharedMemory->getInstance().kinectInfo->set_depth(depthinfo);
        sharedMemory->getInstance().kinectInfo->set_RGB(imageinfo);

        if(sharedMemory->getInstance().getAction()=="computePoint")
        {
          cout<<"Starting: "<< sharedMemory->getInstance().getAction() << "STATE in Kinect"<<endl;  
            do
            {
                usleep(5000);
            } while(sharedMemory->getInstance().getObjectPositionX()==0 || sharedMemory->getInstance().getObjectPositionY()==0);

            std::cout << "voy a calcular usando " << sharedMemory->getInstance().getObjectPositionX() << "   "  << sharedMemory->getInstance().getObjectPositionY() << "   " <<  std::endl;
           double x,y,z;
	    getdephtmm(sharedMemory->getInstance().getObjectPositionX(), sharedMemory->getInstance().getObjectPositionY(),x, y,z);
	    sharedMemory->getInstance().setRealObjectPositionX(x);
	    sharedMemory->getInstance().setRealObjectPositionY(y);
	    sharedMemory->getInstance().setRealObjectPositionZ(z);
            std::cout << "ya calcule el punto y obtuve " << sharedMemory->getInstance().getRealObjectPositionX() << "   " << sharedMemory->getInstance().getRealObjectPositionY() << "   " << sharedMemory->getInstance().getRealObjectPositionZ()  << std::endl;
	    
	    //si da un valor atípico 
	    //TODO revisar, si el objeto si esta en esta coordenadas, esto s epodría ciclar
	    //if(sharedMemory->getInstance().getRealObjectPositionX()>750 || sharedMemory->getInstance().getRealObjectPositionZ()<200)
	    //{
	      //sharedMemory->getInstance().setAction("recognizeObject");
	    //}
	    //else{
	      sharedMemory->getInstance().setObjectPositionX(0);
	      sharedMemory->getInstance().setObjectPositionY(0);
	       //sharedMemory->getInstance().setAction(cambiar_estado("punto_calculado", "si"));
	      sharedMemory->getInstance().setAction("graspObject");
	    //}
	    
	
           
        }

       
        if(sharedMemory->getInstance().getAction()=="payAttention")
        {
	  if (firstTime){ 
	    t_ini = clock();
	    firstTime=false;
            Human::getInstance().gesture_detected=false;
	  }
	  
          cout<<"Starting: "<<sharedMemory->getInstance().getAction() << " STATE in Kinect"<<endl;  
           if(Human::getInstance().gesture_detected)
	   {
	     cout << "**GESTURE DETECTED in payAttention" << endl;
	     sharedMemory->getInstance().setGestureDepthPosition(Human::getInstance().gesture[2]);
	     sharedMemory->getInstance().startDownToRotations=false;
	     
	     if (sharedMemory->getInstance().getTestRunning()=="Emergency"){
	      sharedMemory->getInstance().sintetizer.set_Phrase("Emergency Situation Detected");
	      //saving image of victim
	      cv::imwrite("../data/EmergencyReport/imgPeersonHurt.png" ,cv::Mat( sharedMemory->getInstance().kinectInfo->get_RGB()));
	      cv::Mat mapa;
	      mapa= cv::imread("../data/map.png");
	      
	      //saving victim on map
              cv::Scalar color= cv::Scalar(0,0,255);
	      std::cout << "sharedMemory->getInstance().getRobotPosition().get_X()=" << sharedMemory->getInstance().getRobotPosition().get_X() <<std::endl;
	      std::cout << "sharedMemory->getInstance().getRobotPosition().get_Y()=" << sharedMemory->getInstance().getRobotPosition().get_Y() <<std::endl;
	      std::cout << "PIXEL_X=" << (sharedMemory->getInstance().getRobotPosition().get_X()/50)+ORIGIN_X << std::endl;
	      std::cout << "PIXEL_Y=" << (sharedMemory->getInstance().getRobotPosition().get_Y()/50)+ORIGIN_Y << std::endl;
	      
	      cv::circle(mapa, cv::Point((sharedMemory->getInstance().getRobotPosition().get_X()/50)+ORIGIN_X,(sharedMemory->getInstance().getRobotPosition().get_Y()/50)+ORIGIN_Y), 7, color, 10, 8, 0);
	      cv::imwrite("../data/EmergencyReport/locationPeersonHurt.png",mapa);
	      
	      sharedMemory->getInstance().setStringDestination("bedroom1");
	      sharedMemory->getInstance().setAction("navigateCloseTo");
	     }else{
	       sharedMemory->getInstance().sintetizer.set_Phrase("I have seen a guest requesting");
// 	       cv::Mat mapa;
// 	       mapa= cv::imread("../data/map.png");
// 	       cv::Scalar color= cv::Scalar(0,0,255);
// 	       cv::circle(mapa, cv::Point((sharedMemory->getInstance().getRobotPosition().get_X()/50)+170,(sharedMemory->getInstance().getRobotPosition().get_Y()/50)+170), 7, color, 10, 8, 0);
// 	       cv::imwrite("../data/EmergencyReport/locationPeersonHurt.png",mapa);
// 	       sleep(1);
	       //la función ya esta restando un valor (100) a la profundidad dadda por el kinec 
	       Location temp=getPointInMap(sharedMemory->getInstance().getRobotPosition());
	       sharedMemory->getInstance().lastObjective->setObjectivePosition(temp);
	       sharedMemory->getInstance().setAction("navigateToPoint");
	     }
	     firstTime=true;
	   }else{
	     t_fin = clock();
	     cout << "**NO Gesture in payAttention" << endl;
	     //supone que la diferencia la da en segundos
	     //std::cout << "TIME  " << t_ini << "    " << t_fin << std::endl;
	     //nanosegundosf
	     firstTime = false;
	     if ((t_fin/1000000)-(t_ini/1000000)>30){
	       cout << "**Time OVER" << endl;
	       firstTime=true;
	       sharedMemory->getInstance().setAction("turn");
	    }
	       
	  }
	     
	   //cout << "gesture NO detected" << endl;
	   //sleep(1);
        }
        
        if(sharedMemory->getInstance().getAction()=="Find_person")
        {
          cout<<"Starting: "<< sharedMemory->getInstance().getAction() << " STATE in Kinect"<<endl;  
            KNI_DEV->getInstance().g_User.GetUserPixels(2, KNI_DEV->getInstance().g_SceneMD);
            const XnLabel* pLabels = KNI_DEV->getInstance().g_SceneMD.Data();
	    //TODO Error?
            cvSet(sceneinfo, cvScalar(0,0,0));

            for (XnUInt y = 0; y < KNI_DEV->getInstance().g_DepthMD.YRes(); ++y)
                for (XnUInt x = 0; x < KNI_DEV->getInstance().g_DepthMD.XRes(); ++x, ++pLabels)
                {
                    if(*pLabels)
                    {
                        CV_IMAGE_ELEM(sceneinfo, uchar, y, (x*3)+0)=255;
                        CV_IMAGE_ELEM(sceneinfo, uchar, y, (x*3)+1)=255;
                        CV_IMAGE_ELEM(sceneinfo, uchar, y, (x*3)+2)=255;
                    }
// 		    if(*pLabels==2)
// 		    {
// 		    CV_IMAGE_ELEM(sceneinfo, uchar, y, (x*3)+1)=255;
// 		    }
// 		    if(*pLabels==3)
// 		    {
// 		    CV_IMAGE_ELEM(sceneinfo, uchar, y, (x*3)+2)=255;
// 		    }
                }

           // sharedMemory->getInstance().kinectInfo->set_user(sceneinfo);
// 		cvShowImage("polo" ,sceneinfo);
// 		cvWaitKey(100);

        }
	if(sharedMemory->getInstance().getAction()=="transformKinectToMapPoint")
        {
	  cout<<"Starting: "<< sharedMemory->getInstance().getAction() << " STATE in Kinect"<<endl; 
	  //supone que es en mm
	  float robotx=sharedMemory->getInstance().getRobotPosition().get_X();
	  float roboty=sharedMemory->getInstance().getRobotPosition().get_Y();
	  float robotth=sharedMemory->getInstance().getRobotPosition().get_Angle() * DEG_TO_RAD;

	  float humanx=Human::getInstance().gesture[2]; //con respecto a robot es X y con respecto a kinect Z
	  float humany=Human::getInstance().gesture[0]*-1; //con respecto a robot Y y con respecto a kinect X

	  float X=robotx+((humanx)*cos(robotth)-(humany)*sin(robotth));
	  float Y=roboty+((humanx)*sin(robotth)+(humany)*cos(robotth)); 
	  //TODO Guardarlo en memoria compartida
	}

        if(sharedMemory->getInstance().getAction()=="follow")
        {


          cout<<"Starting: "<< sharedMemory->getInstance().getAction() << " STATE in Kinect"<<endl;  

            nUsers=MAX_NUM_USERS;
            KNI_DEV->getInstance().g_User.GetUsers(aUsers, nUsers);
            int numTracked=0;
            int userToPrint=-1;
            XnPoint3D pt;

            for(XnUInt16 i=0; i<nUsers; i++)
            {
                skeletonJoint Torso;
                if(KNI_DEV->getInstance().g_User.GetSkeletonCap().IsTracking(aUsers[i])==FALSE)
                {
                    Human::getInstance().tracking=-1;
                    continue;
                }

                else
                {
                    //patrick
		    // g_UserGenerator.GetSkeletonCap().SetSmoothing(.1);
                    std::map<std::string, skeletonJoint>::iterator iter;
                    for(iter=Human::getInstance().Skeleton[i].begin(); iter !=Human::getInstance().Skeleton[i].end(); ++iter)
                    {

                        KNI_DEV->getInstance().g_User.GetSkeletonCap().GetSkeletonJoint(aUsers[i], (XnSkeletonJoint) iter->second.Get_ID() ,Joint[iter->second.Get_ID()]);
                        iter->second.Set_pos(Joint[iter->second.Get_ID()].position.position.X, Joint[iter->second.Get_ID()].position.position.Y, (Joint[iter->second.Get_ID()].position.position.Z));
                        rotate(Joint[iter->second.Get_ID()].orientation.orientation.elements);
                        iter->second.heading=heading;
                        iter->second.attitude=attitude;
                        iter->second.bank=bank;
                        // std::cout << heading << attitude << bank << std::endl;

                        if ( iter->second.Get_name()=="TORSO" ) Torso=iter->second;
                        {
                            if(Torso.Get_x() < -500 || Torso.Get_x()> 500)
                            {
                                Human::getInstance().tracking=-1;
                            }
                            else
                            {
                                Human::getInstance().tracking=i;

                            }
                        }

                    }
                }
            }

        }
    }



    return;
}

void Kinect_Plugin::run()
{
    pthread_create(&thread_id, NULL, &IPlugin::IncWrapper, this);
}

void Kinect_Plugin::stop()
{
    KNI_DEV->getInstance().closeDevice();
}


