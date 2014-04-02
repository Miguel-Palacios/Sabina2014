#ifndef HANDCONTROL_H
#define HANDCONTROL_H

// General headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
// OpenNI headers
#include <XnOpenNI.h>
// NITE headers
#include <XnVSessionManager.h>
#include "XnVMultiProcessFlowClient.h"
#include <XnVWaveDetector.h>
//Aria headers


class HandControl{
	
public:	

	/*Methods*/
	void DeleteSession();
	int run_HandRecognizer(void);
	int init_HandRecognizer();
	std::string getGesture();
	void clearGesture();
	void NITE_context();
	//int Kbhit(void);
};
#endif
