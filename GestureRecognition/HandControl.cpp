#include "HandControl.h"

#define SAMPLE_XML_FILE_LOCAL "../data/Sample-Tracking.xml"

using namespace xn;
using namespace std;
	
	std::string Hand_Position;
	XnVSessionGenerator* pSessionGenerator;
	xn::Context context;
	xn::ScriptNode scriptNode;
	XnStatus rc;
	XnVWaveDetector wc;	
	
// Callback for when the focus is in progress
void XN_CALLBACK_TYPE SessionProgress(const XnChar* strFocus, const XnPoint3D& ptFocusPoint, XnFloat fProgress, void* UserCxt)
{
	printf("Session progress (%6.2f,%6.2f,%6.2f) - %6.2f [%s]\n", ptFocusPoint.X, ptFocusPoint.Y, ptFocusPoint.Z, fProgress,  strFocus);
}
// callback for session start
void XN_CALLBACK_TYPE SessionStart(const XnPoint3D& ptFocusPoint, void* UserCxt)
{
	printf("Session started. Please wave (%6.2f,%6.2f,%6.2f)...\n", ptFocusPoint.X, ptFocusPoint.Y, ptFocusPoint.Z);
}
// Callback for session end
void XN_CALLBACK_TYPE SessionEnd(void* UserCxt)
{
	printf("Session ended. Please perform focus gesture to start session\n");
}
// Callback for wave detection
void XN_CALLBACK_TYPE OnWaveCB(void* cxt)
{
	printf("InitialWAVE!\n");
}
// callback for a new position of any hand
void XN_CALLBACK_TYPE OnPointUpdate(const XnVHandPointContext* pContext, void* cxt)
{

	if((pContext->ptPosition.X)>=-200 &&(pContext->ptPosition.X)<=200 && (pContext->ptPosition.Y)>=200){
               Hand_Position = "Arriba\n";
	
	}else if((pContext->ptPosition.X)>=400){
		/*pioneer.setVel2(30,110);
		sleep(7);
		pioneer.setVel2(0,0);*/
		Hand_Position = "Derecha\n";
		
	}
	else if((pContext->ptPosition.X)>=-200 &&(pContext->ptPosition.X)<=200){
		/*pioneer.setVel2(0,0);*/
		Hand_Position = "wave\n";
	}
	else if((pContext->ptPosition.X)<=-400){
		/*pioneer.setVel2(110,30);
		sleep(7);
		pioneer.setVel2(0,0);*/
		Hand_Position = "Izquierda\n";
	}else
	      Hand_Position = "none\n";
}

string HandControl::getGesture(){
	return Hand_Position;
	}

XnBool fileExists(const char *fn)
{
	XnBool exists;
	xnOSDoesFileExist(fn, &exists);
	return exists;
}


int HandControl::init_HandRecognizer(){
	const char *fn = NULL;
		if (fileExists(SAMPLE_XML_FILE_LOCAL)) fn = SAMPLE_XML_FILE_LOCAL;
		else {
			printf("Could not find '%s'. Aborting.\n" , SAMPLE_XML_FILE_LOCAL);
			return XN_STATUS_ERROR;
		}
		rc = context.InitFromXmlFile(fn, scriptNode);
		if (rc != XN_STATUS_OK)
		{
			printf("Couldn't initialize: %s\n", xnGetStatusString(rc));
			return 1;
		}

		// Create the Session Manager
		pSessionGenerator = new XnVSessionManager();
		rc = ((XnVSessionManager*)pSessionGenerator)->Initialize(&context, "Wave", "RaiseHand");
		if (rc != XN_STATUS_OK)
		{
			printf("Session Manager couldn't initialize: %s\n", xnGetStatusString(rc));
			delete pSessionGenerator;
			return 1;
		}
		
		
	context.StartGeneratingAll();
	pSessionGenerator->RegisterSession(NULL, &SessionStart, &SessionEnd, &SessionProgress);
	wc.RegisterWave(NULL, OnWaveCB);
	wc.RegisterPointUpdate(NULL, OnPointUpdate);
	pSessionGenerator->AddListener(&wc);

	return 0;
	}

int HandControl::run_HandRecognizer(void)
{

	context.WaitAnyUpdateAll();
	((XnVSessionManager*)pSessionGenerator)->Update(&context);

	return 0;
}

void HandControl::DeleteSession(){
	
	delete pSessionGenerator;
	}

void HandControl::NITE_context(){
	//xn::Context context;
			context.WaitAnyUpdateAll();
			((XnVSessionManager*)pSessionGenerator)->Update(&context);
	}
	
// 	int HandControl::Kbhit(void ) 
// {
//   struct termios oldt, newt;
//   int ch;
//   int oldf;
//  
//   tcgetattr(STDIN_FILENO, &oldt);
//   newt = oldt;
//   newt.c_lflag &= ~(ICANON | ECHO);
//   tcsetattr(STDIN_FILENO, TCSANOW, &newt);
//   oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
//   fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
//  
//   ch = getchar();
//  
//   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
//   fcntl(STDIN_FILENO, F_SETFL, oldf);
//  
//   if(ch != EOF)
//   {
//     ungetc(ch, stdin);
//     return 1;
//   } 
//   return 0;
// }

void HandControl::clearGesture(){
  Hand_Position = "";
	
	}
