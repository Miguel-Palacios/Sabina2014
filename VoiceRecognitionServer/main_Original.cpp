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
#include <map>
#include <pthread.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>

//#include "../Gui/gui.h"
//#include "../Gui/video.h"
#include "../Plugin_API/pluginapi.h"
#include "../SharedMemory/SharedMemory.h"
#include "../SharedMemory/Location.h"

//#include "../Gui/input_singleton.h"
//#include "../Gui/gui.h"
//#include "../Gui/tab.h"
//#include "../Gui/console.h"

//#include "../MDP/MDP.h"

#include <cstdlib>
#include <iostream>

#include "Thread.h"
#include "NetThread.h"
#include "gsNetPoll_g++.h"
//#include "beepStartSpeech.h"
#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <math.h>
#define BUFFER_LEN 88000

SharedMemory *sharedMemory;

//Video *videoDisplay;
//Tab *pluginTab;
//Console *cons;

//#define PLUGIN_NAME "Net_server"
#define PLUGIN_NAME "VoiceRecognitionServer"

static char device[] = "default";
snd_output_t *output = NULL;
float buffer [BUFFER_LEN];

void TextToSpeech(string speech, unsigned int counter)
{
	sharedMemory->getInstance().sintetizer.set_Phrase(speech);
	sleep(counter);
}

void CleanSpeech(NetThread *net)
{
	net->messages.clear();	
	net->Write("REQstartClean");
	net->Read();
	net->GetIncoming();
}

void beepStartSpeech(void)
{
    int err;
    int j,k;

    int f = 2000;                //frequency 1
    int fs = 48000;             //sampling frequency

    snd_pcm_t *handle;
    snd_pcm_sframes_t frames;


    // ERROR HANDLING

    if ((err = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
            printf("Playback open error: %s\n", snd_strerror(err));
            exit(EXIT_FAILURE);
    }

    if ((err = snd_pcm_set_params(handle, SND_PCM_FORMAT_FLOAT, SND_PCM_ACCESS_RW_INTERLEAVED, 1, 48000, 1, 500000)) < 0) {   
            printf("Playback open error: %s\n", snd_strerror(err));
            exit(EXIT_FAILURE);
    }

    // SINE WAVE
    printf("Sine tone at %dHz", f);

        for (k = 0; k < BUFFER_LEN; k++)
            buffer[k] = (1 / ((float) exp(k / 4500.0))) * sin(2 * M_PI * f / fs * k);                 //sine wave value generation                        

        for (j = 0; j < 1; j++)
            frames = snd_pcm_writei(handle, buffer, BUFFER_LEN);    //sending values to sound driver
            

    snd_pcm_close(handle);

}

string LoopRecognize(char *request, NetThread *net, string subject)
{
	
	string Speech = "";
	string conf = "no";
	int counter = 0;
	string received = "";
	string repeat = "";
	//CleanSpeech(net);
	
			do{
				net->messages.clear();	
				net->Write(request);
				net->Read();
				usleep(500*1000);
				
				
				if (net->GetStatus()>0){
					
					Speech = net->GetIncoming();
					net->messages.clear();
					while(Speech =="?" || Speech =="??" || Speech =="")
					{
						sleep(1);
						net->Write("REQsending");
												
						net->Read();
						if (net->GetStatus()>0){
						Speech = "";  
						Speech = net->GetIncoming();
						net->messages.clear();
						}
						
						counter++;
							
							if(counter == 7)
							{
								repeat = "Repeat please the "+ subject;
								TextToSpeech(repeat,2);
								counter = 0;
								//Speech = "?";
								//CleanSpeech(net);
							}
							if(counter == 2)
							{
								beepStartSpeech();
							}
					}
					
					counter = 0;
					sleep(1);
					// Here makes a confirmation
					std::cout << "Makes a confirmation"<<std::endl;
					// Here makes a request from confirmation
					net->messages.clear();
					net->Write("REQstartConfirmation");
					received = "Did you tell me " + Speech + "?";
					TextToSpeech(received,2);
					net->Read();
					//if (net->GetStatus()>0){
					conf = net->GetIncoming();
					conf = "?";
					net->messages.clear();
					CleanSpeech(net);
					
						while(conf =="?" || conf =="??" || conf =="")
						{							
							sleep(1);
							net->Write("REQsending");
							
							net->Read();
							if (net->GetStatus()>0){
							conf = "";  
							conf = net->GetIncoming();
							net->messages.clear();
							}
							
							counter++;
							
							if(counter == 7)
							{
								//repeat = "Make a confirmation ";
								TextToSpeech(received,2);
								counter = 0;
								//conf = "?";
								//CleanSpeech(net);
							}
							if(counter == 2)
							{
								beepStartSpeech();
							}
						}
						
						if(conf == "no")
						{
							repeat = "Can you repeat please the "+subject;
							TextToSpeech(repeat,1);
							counter = 0;
						}
					}
				
				
			}while(conf=="no");
			
			CleanSpeech(net);
			net->messages.clear();
			
			std::cout << "REQUEST: " << request << "WORD: " << Speech <<std::endl;
			return Speech;
}



/**
 * @brief Net_server plugin
 *
 * This plugin is a network server that accepts client conections to comunicate with other programs (running on the same computer or over the network)
 * @author     Patrick Heyer, ickhey@prodigy.net.mx, Juan Herrera juan_antonio_@hotmail.com, Manuel Oropeza zodiacanimations@msn.com
 * @date       jul 04, 2012
 * @version    1.0
 **/
class VoiceRecognitionServer : public IPlugin
{
public:
    void Main();
    void stop();
    void run();
	//void LoopRecognize(char *,string,NetThread *);
};

PLUGIN_FUNC IPlugin *CreatePlugin()
{
    return new VoiceRecognitionServer;
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

int contao=0;

void VoiceRecognitionServer::Main()
{
    /**
     * \sa print
     **/
    //Gui::getInstance();
    //pluginTab = new Tab("Net_server");
    //cons= new Console(WIDTH-600,HEIGHT*.02,600,HEIGHT/2, "net_console", pluginTab);

    NetThread *net = new NetThread();
    string speech= "";

    sharedMemory->getInstance().Microphone.set_Words("");
	
    net->SetOutputStream(stdout);
    net->OpenReadPort(2070);
    net->start();
    net->Accept();
    sleep(10);


    ifstream infile("../data/Names");
    vector<string> names;
    string line;
    while (getline(infile, line))
    {
        names.push_back(line);
    }

    ifstream infile3("../data/Objects");
    vector<string> objects;
    while (getline(infile3, line))
    {
        objects.push_back(line);
    }

    int name_count=0;
    string accion;
    std::stringstream orden;
    orden << "i will bring ";

    int nothing=0;
    int room=0;
    int tries=0;
	
	for (;;){
		string action = sharedMemory->getInstance().getAction();
		
		if (action=="entrar"){
     		string place = "";
			
			
			speech ="Please, can you tell me, where i go ?";
			TextToSpeech(speech,3);
			beepStartSpeech();
			// Request for a place
			place = LoopRecognize("REQstartPlaces",net, "place");
			
			speech = "Ok. I go to the " + place;
			TextToSpeech(speech,1);
			
			sharedMemory->getInstance().stringDestination= &place;
			sharedMemory->getInstance().setAction("navegar");
				
		}else if (action =="pedirOrden"){			
			
			string name = "";
			string drink = "";
			string place = "";
			
			// Request for name
			//sleep(2);
			string order = "Can you tell me your Name?";
			printf("Starting PEDIR_ORDEN");
			
			//TODO
			TextToSpeech(order,2);
			name = LoopRecognize("REQstartNames",net,"name");
									
 			order = "Hi " + name + ", what do you want to drink?";
			TextToSpeech(order,2);
			// Request for a drink
			drink = LoopRecognize("REQstartObjects",net, "drink");
			
			order = name + ", Can you tell me the place where te " + drink + " is?" ;
			TextToSpeech(order,3);
			// Request for a place
			place = LoopRecognize("REQstartPlaces",net, "place");
			
			order = "Well "+ name + ", you want a " + drink + ", that is in the " + place;
			TextToSpeech(order,2);
			
			std::cout << "FINAL" <<name << " final detected "<<std::endl;
			std::cout << "FINAL" <<name << " final detected "<<std::endl;
			
			
			sharedMemory->getInstance().stringDestination= &place;
			//TODO verficar si el siguiente estado es el adecuado
			sharedMemory->getInstance().setAction("navegar");
				
		}
	
		
	}
    
//    if (sharedMemory->get_Action() == "entrar"){   
      
     /* net->Write("OK");
      net->Read();
      string speech = "?";//net->GetIncoming();
      
      while(speech=="?")
      {
		net->Write("REC");
		
		net->Read();
		if(net->GetStatus()>0){
			speech = net->GetIncoming();
			net->messages.clear();
		}
		//sleep(1);
	  }
      sharedMemory->getInstance().Sintetizer.set_Phrase(speech);
      std::cout << speech+"resultado" << std::endl;
      sharedMemory->set_Action("navegar") ;*/
  //  }
    usleep(100);
}



void VoiceRecognitionServer::run()
{
    pthread_create(&thread_id, NULL, &IPlugin::IncWrapper, this);
}

void VoiceRecognitionServer::stop()
{

}


