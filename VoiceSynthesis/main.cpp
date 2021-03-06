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
#include <unistd.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>

//#include "../Gui/gui.h"
//#include "../Gui/video.h"
#include "../Plugin_API/pluginapi.h"
#include "../SharedMemory/SharedMemory.h"

//#include "../Gui/input_singleton.h"
//#include "../Gui/gui.h"
//#include "../Gui/tab.h"
//#include "../Gui/console.h"
//#include "../Gui/video.h"

SharedMemory *sharedMemory;

//Console *cons;
//Tab *pluginTab;
//InputSingleton *teclado;

//TODO revisar opencv
//#include <opencv/cv.h>
//#include <opencv/highgui.h>

#define PLUGIN_NAME "VoiceSynthesis"

/**patrol
 * @brief Voice_Synthesis plugin
 *
 * This plugin uses a system call to festival to synthesize voice. (To modify the voice change festivals system settings).
 * @author     Patrick Heyer, patrickhey@prodigy.net.mx
 * @date       jul 04, 2012
 * @version    1.0
 **/
class VoiceSynthesis : public IPlugin
{
public:
    void Main();
    void stop();
    void run();
};

PLUGIN_FUNC IPlugin *CreatePlugin()
{
    return new VoiceSynthesis;
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

void VoiceSynthesis::Main()
{
    //Gui::getInstance();
    //pluginTab = new Tab("Voice_Synthesis");
    //cons= new Console(WIDTH/2,HEIGHT*.02,WIDTH/2,HEIGHT/2, "Error", pluginTab);
    while (true)
    {

        if (sharedMemory->getInstance().sintetizer.get_Phrase()!="")
        {
            std::stringstream ss;
            ss << "echo  '" << sharedMemory->getInstance().sintetizer.get_Phrase() << "' | festival --tts &";
            std::string temp=ss.str();
            std::cout <<temp << std::endl;
            system (temp.c_str());
//             string str=sharedMemory->getInstance().sintetizer.get_Phrase();
//             int emotion=0;
// 
//             for ( int i = 0 ; i < str.length(); i++)
//             {
// 
//                 char temp=str[i];
//                 switch(temp)
//                 {
//                 case 'a':
//                     sharedMemory->getInstance().faceFrame=1+emotion;
//                     break;
//                 case 'e':
//                     sharedMemory->getInstance().faceFrame=2+emotion;
//                     break;
//                 case 'f':
//                     sharedMemory->getInstance().faceFrame=11+emotion;
//                     break;
//                 case 'i':
//                     sharedMemory->getInstance().faceFrame=3+emotion;
//                     break;
//                 case 'o':
//                     sharedMemory->getInstance().faceFrame=4+emotion;
//                     break;
//                 case 's':
//                     sharedMemory->getInstance().faceFrame=17+emotion;
//                     break;
//                 case 't':
//                     sharedMemory->getInstance().faceFrame=3+emotion;
//                     break;
//                 case 'u':
//                     sharedMemory->getInstance().faceFrame=5+emotion;
//                     break;
//                 case 'y':
//                     sharedMemory->getInstance().faceFrame=3+emotion;
//                     break;
//                 default:
//                     sharedMemory->getInstance().faceFrame=0;
//                     break;
//                 }
// 
// //                 patrol->getInstance().face_frame=i;
//                 usleep(73000);
//             }
            sharedMemory->getInstance().sintetizer.set_Phrase("");
            sharedMemory->getInstance().faceFrame=0;
        }

        else
        {

        }
    }

}


void VoiceSynthesis::run()
{
    pthread_create(&thread_id, NULL, &IPlugin::IncWrapper, this);
}


void VoiceSynthesis::stop()
{

}
