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
#include <pthread.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>

//#include "../Gui/gui.h"
//#include "../Gui/video.h"
#include "../Plugin_API/pluginapi.h"
#include "../SharedMemory/SharedMemory.h"
#include "../SharedMemory/Objective.h"

//#include "../Gui/input_singleton.h"
//#include "../Gui/gui.h"
//#include "../Gui/tab.h"
//#include "../Gui/console.h"
//#include "../Gui/video.h"

#include "facedetect.h"
#include "recognize.h"
#include "learn.h"
#include "sift.h"

SharedMemory *sharedMemory;

//Video *videoDisplay;
//Console *cons;
//Tab *pluginTab;
//InputSingleton *teclado;

#define WIDTH 1366


#include <opencv/cv.h>
#include <opencv/highgui.h>

//#include "../MDP/MDP.h"

#define PLUGIN_NAME "FaceRecognition"
int userToRecognizeIndex=0;//None

/**
 * @brief FaceRecognition plugin
 *
 * This plugin is used to detect, learn and recognize human faces.
 * @author     Patrick Heyer, patrickhey@prodigy.net.mx
 * @date       jul 04, 2012
 * @version    1.0
 **/
class FaceRecognition : public IPlugin
{
public:
    void Main();
    void stop();
    void run();
};

PLUGIN_FUNC IPlugin *CreatePlugin()
{
    return new FaceRecognition;
}

PLUGIN_FUNC void DestroyPlugin(IPlugin *r)
{
    delete r;
}

PLUGIN_DISPLAY_NAME(PLUGIN_NAME);

PLUGIN_INIT()
{
    // register our new plugin

    RegisterPlugin(PLUGIN_NAME, CreatePlugin, DestroyPlugin);
    return 0;
}


void FaceRecognition::Main()
{

    /**
     * \sa detectFace
     * \sa learn
     * \sa recognize
     * \sa cambiar_estado
     **/
    int polo=0;

    //Gui::getInstance();

    IplImage *frame;
    //pluginTab = new Tab("FaceRecognition");
    //videoDisplay = new Video(0,HEIGHT*.02,WIDTH/2,HEIGHT/2,"FaceRecognition", pluginTab);

    //cons= new Console(WIDTH/2,HEIGHT*.02,WIDTH/2,HEIGHT/2, "Error", pluginTab);
    initFaceDet("../data/haarcascade_frontalface_default.xml");
    initEyeDet("../data/parojos.xml");
    initEyeDetD("../data/ojoD.xml");
    initEyeDetI("../data/ojoI.xml");




    std::map<std::string, Objective>::iterator iter;
    std::string name;

    std::string action;
    for (;;)
    {
        action=sharedMemory->getInstance().getAction();
        frame=sharedMemory->getInstance().ptzDevice.get_image();
        if (action=="detectUser")
        {
          cout<<"Starting: "<< action << " STATE in FaceRecognition"<<endl;  
	  //GUI::getInstance().Set_Active_Tab("FaceRecognition");
            if (detectFace(frame,&polo)!=NULL)
            {
                sharedMemory->getInstance().sintetizer.set_Phrase("hello DAVID i will take you to your therapy");
                sleep(5);
                //TODO revisar el estado al que transita una vez detectado el paciente
		//sharedMemory ->getInstance().setAction(cambiar_estado("detectada_p","si"));
            }
        }

        if (action=="userLearn")
        {
            //GUI::getInstance().Set_Active_Tab("FaceRecognition");
            int userID;
	    cout<<"Starting: "<< action << "STATE in FaceRecognition"<<endl;  
            sharedMemory->getInstance().sintetizer.set_Phrase("Hello i am sabina I am waiting for a new user please aproach me ");
            sleep(4);
	    sharedMemory->getInstance().sintetizer.set_Phrase("Please look at the camera with blue lights and do not move ");
            sleep(4);
            do
            {
                frame=sharedMemory->getInstance().ptzDevice.get_image();
                userID=learn(frame);
		//TODO activar desplegado de la imágen
                //videoDisplay->SetImage(frame);
            } while(userID==0);
	    
	    cout<<"USER ID learnd: "<< userID<<endl;
	    //Se almacena el tipo, ID del usuario y posición actual donde lo vió el robot 
 	    sharedMemory->getInstance().lastObjective->setType("person");
	    sharedMemory->getInstance().lastObjective->setVisualID(userID);
	    sharedMemory->getInstance().lastObjective->setObjectivePosition(sharedMemory->getInstance().getRobotPosition());
	    	    
            sharedMemory->getInstance().sintetizer.set_Phrase( "Ok i learnd your face. Thank you ");
            sleep(4);
            //sharedMemory->getInstance().sintetizer.set_Phrase( " ");
            
	    //TODO revisar el estado al que transita una vez detectado el paciente
	    //sharedMemory->getInstance().setAction(cambiar_estado("aprendida_p","si"));
	    sharedMemory->getInstance().setAction("requestOptions");

        }

        if (action=="userRecognize")
        {
            //GUI::getInstance().Set_Active_Tab("FaceRecognition");
            
            int userRecognizedID;
	    Objective userTemp= sharedMemory->getInstance().getUser(userToRecognizeIndex);
	    cout<<"Starting: "<< action << "STATE in FaceRecognition. Looking For userID "<< userTemp.getVisualID()<<endl;  
	    sharedMemory->getInstance().sintetizer.set_Phrase("Lookin for "+userTemp.getName());
	    sleep(2);
	    //TODO ¿Que pasa si no reconoce nunca?
            do
            {
                userRecognizedID=recognize(frame);
                frame=sharedMemory->getInstance().ptzDevice.get_image();

            } while(userRecognizedID==0 || userRecognizedID!=userTemp.getVisualID());
	    
	    cout<<"I found USER with ID "<< userRecognizedID<<endl;  

            std::stringstream ss;
	    
            //ss << "hello here is the " << sharedMemory->getInstance().Microphone.get_Phrase() << " you orderd";
	    ss << "hello " << userTemp.getName() << " here is the " << userTemp.getOrder() << " you orderd";
            sharedMemory->getInstance().sintetizer.set_Phrase(ss.str());
            sleep(3);
	    userToRecognizeIndex++;
            //TODO revisar el estado al que transita una vez detectado el paciente
	    sharedMemory->getInstance().setAction("deliverObject");

        }
        //TODO activar visualizacion
       //videoDisplay->SetImage(frame);
        cvReleaseImage(&frame);
    }

}

void FaceRecognition::run()
{
    pthread_create(&thread_id, NULL, &IPlugin::IncWrapper, this);
}

void FaceRecognition::stop()
{

}


