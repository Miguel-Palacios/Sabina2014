#include <XnCppWrapper.h>

//#include "../Gui/gui.h"
//#include "../Gui/tab.h"
//#include "../Gui/input_singleton.h"
//#include "../Gui/video.h"
//#include "../Gui/button.h"
#include "../Plugin_API/pluginapi.h"

#include "../SharedMemory/SharedMemory.h"
//#include "../SharedMmemory/Human.h"
// #include "../Human/Human.h"
// #include "../Human/joint.h"

#include "Ni_Device.h"
//#include <Fl/fl_file_chooser.h>
#define PLUGIN_NAME "Kinect_Plugin"
#define SAMPLE_XML_PATH "../data/Kinect/SamplesConfig.xml"

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
//#include "../MDP/MDP.h"

SharedMemory *patrol;

class Kinect_Plugin : public IPlugin
{
public:
    void Main();
    void run();
    void stop();
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

void getdephtmm(int u, int v, double &X, double &Y, double &Z)
{
    KNI_DEV->getInstance().g_Depth.GetIntProperty("ZPD", F_);

    const XnDepthPixel* pDepthMap = KNI_DEV->getInstance().g_Depth.GetDepthMap();

// get the pixel size in mm ("ZPPS" = pixel size at zero plane)
    KNI_DEV->getInstance().g_Depth.GetRealProperty ("ZPPS", pixel_size_);
    int depthIdx=v * XN_VGA_X_RES + u;
    X = (u - 320) * pDepthMap[depthIdx] * pixel_size_  / F_;
    Y = (v - 240) * pDepthMap[depthIdx] * pixel_size_  / F_;
    Z = pDepthMap[depthIdx]; 

    std::cout << "kinect says position in 3D= " << X << "  " << Y << "   " << Z << std::endl;


}

void Kinect_Plugin::Main()
{
    std::cout << "Starting plugin" << std::endl;
    XnStatus nRetVal = XN_STATUS_OK;
    xn::EnumerationErrors errors;
    KNI_DEV->getInstance().Initialize();

    std::cout << "Despues de initialize" << std::endl;
    
    //Gui::getInstance();
    //Tab *pluginTab;

    //pluginTab = new Tab("Kinect_Plugin");


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
    }

    nRetVal = KNI_DEV->getInstance().g_Context.FindExistingNode(XN_NODE_TYPE_IMAGE, *KNI_DEV->getInstance().getImageGenerator());
    nRetVal = KNI_DEV->getInstance().g_Context.FindExistingNode(XN_NODE_TYPE_DEPTH, *KNI_DEV->getInstance().getDepthGenerator());
    nRetVal = KNI_DEV->getInstance().g_Context.FindExistingNode(XN_NODE_TYPE_USER, *KNI_DEV->getInstance().getUserGenerator());



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

    nRetVal =  KNI_DEV->getInstance().g_Context.StartGeneratingAll();

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




    XnUInt32 total_frames=0;
    KNI_DEV->getInstance().g_Player.GetNumFrames(KNI_DEV->getInstance().g_Depth.GetName(),total_frames);

    for(;;)
    {

        KNI_DEV->getInstance().readFrame();

        memcpy(imgDepth16u->imageData, KNI_DEV->getInstance().getDepthMetaData()->Data(),640*480*2);
        cvConvertScale(imgDepth16u,depthinfo,255/4096.0,0);


        memcpy(imgRGB8u->imageData,KNI_DEV->getInstance().getImageMetaData()->Data(),1280*1024*3);
        cvCvtColor(imgRGB8u,imageinfo,CV_RGB2BGR);

        patrol->getInstance().kinectInfo->set_depth(depthinfo);
        patrol->getInstance().kinectInfo->set_RGB(imageinfo);



        if(patrol->getInstance().getAction()=="computePoint")
        {
	    //TODO revisaar condición de while
	    cout<< "Iniciando: " << patrol->getInstance().getAction() <<endl;
            do
            {
                usleep(5000);
            } while(patrol->getInstance().getObjectPositionX()==0 || patrol->getInstance().getObjectPositionY()==0);

            std::cout << "KINECT::voy a calcular usando " << patrol->getInstance().getObjectPositionX() << "   "  << patrol->getInstance().getObjectPositionY() << "   " <<  std::endl;
            double x,y,z;
	    getdephtmm(patrol->getInstance().getObjectPositionX(), patrol->getInstance().getObjectPositionY(),x,y,z);
	    patrol->getInstance().setRealObjectPositionX(x);  
	    patrol->getInstance().setRealObjectPositionY(y);  
	    patrol->getInstance().setRealObjectPositionZ(z);  
            std::cout << "ya calcule el punto y obtuve " << patrol->getInstance().getRealObjectPositionX() << "   " << patrol->getInstance().getRealObjectPositionY() << "   " << patrol->getInstance().getRealObjectPositionZ()  << std::endl;

            //patrol->getInstance().setAction(cambiar_estado("punto_calculado", "si"));
	    patrol->getInstance().setAction("graspObject");
        }

        if(patrol->getInstance().getAction()=="follow")
        {
	   cout<< "Iniciando: " << patrol->getInstance().getAction() <<endl;
            nUsers=MAX_NUM_USERS;
            KNI_DEV->getInstance().g_User.GetUsers(aUsers, nUsers);
            int numTracked=0;
            int userToPrint=-1;
            XnPoint3D pt;

//             for(XnUInt16 i=0; i<nUsers; i++)
//             {
//                 if(KNI_DEV->getInstance().g_User.GetSkeletonCap().IsTracking(aUsers[i])==FALSE)
//                 {
//                     patrol->getInstance().persons.Skeletons[i].is_tracking=false;
// //                     Human::getInstance().tracking=false;
//                     continue;
//                 }
//                 else
//                 {
//                     patrol->getInstance().persons.Skeletons[i].is_tracking=false;
//                     //patrick
//                     KNI_DEV->getInstance().g_User.GetSkeletonCap().SetSmoothing(.75);
//                     std::map<std::string, Bone>::iterator iter;
//                     for(iter=patrol->getInstance().persons.Skeletons[i].joints.begin(); iter !=patrol->getInstance().persons.Skeletons[i].joints.end(); ++iter)
//                     {
// 
//                         KNI_DEV->getInstance().g_User.GetSkeletonCap().GetSkeletonJoint(aUsers[i], (XnSkeletonJoint) iter->second.Get_ID() ,Joint[iter->second.Get_ID()]);
//                         iter->second.Set_pos(Joint[iter->second.Get_ID()].position.position.X, Joint[iter->second.Get_ID()].position.position.Y, (Joint[iter->second.Get_ID()].position.position.Z));
//                         rotate(Joint[iter->second.Get_ID()].orientation.orientation.elements);
//                         iter->second.heading=heading;
//                         iter->second.attitude=attitude;
//                         iter->second.bank=bank;
// 
//                     }
//                 }
//             }

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

