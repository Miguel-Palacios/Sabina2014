/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   plugin1.h
/// \author Martin Reddy
/// \brief  An example plugin built against the plugin API.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///


#include <iostream>
#include <cstdlib>


#define PLUGIN_NAME "GestureRecognition"

#include "../Plugin_API/pluginapi.h"
#include "../SharedMemory/SharedMemory.h"
#include "../SharedMemory/Location.h"

#include "HandControl.h"


//#include "ArNetworking.h"

#define Living "living"
#define Kitchen "kitchen"
#define Dinning "dinning"
#define Exit "exit"
#define TRUE 1
#define FALSE 0

char textData[64];
char currentGoal[64];
bool openDoor = false;
int robotXPosition = 0;
int robotYPosition = 0;
SharedMemory *sharedMemory;
bool voiceRecognizerSelection=false;


/**
 * @brief GestureRecognition plugin
 * 
 * This plugin is a network server that accepts client conections to comunicate with other programs (running on the same computer or over the network) 
 * @author     Patrick Heyer, patrickhey@prodigy.net.mx, Juan Herrera juan_antonio_@hotmail.com, Manuel Oropeza zodiacanimations@msn.com
 * @date       jul 04, 2012
 * @version    1.0
 **/
class GestureRecognition : public IPlugin
{
public:
    void Main();
    void run();
    void stop();
};

PLUGIN_FUNC IPlugin *CreatePlugin()
{
    return new GestureRecognition;
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

void GestureRecognition::Main()
{

	std::cout << "*** Gesture Recognition Initialized ***" << std::endl;
	
      HandControl mano;
	
	//sabina.Robot_Init();
	mano.init_HandRecognizer();
	while(1){
		mano.run_HandRecognizer();
		printf(" %s", mano.getGesture().c_str());
		mano.clearGesture();
	}
	mano.DeleteSession();
	  
	return ;
  
}

void GestureRecognition::run()
{
    pthread_create(&thread_id, NULL, &IPlugin::IncWrapper, this);
}

void GestureRecognition::stop()
{
	
}

