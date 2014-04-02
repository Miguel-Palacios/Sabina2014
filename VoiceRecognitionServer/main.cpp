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
int numberOfUsersToLearn=0;

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


    // ERROR HANDLINGii

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
            buffer[k] = (1 / ((float) exp(2*k / 880.0))) * sin(2 * M_PI * f / fs * k);                 //sine wave value generation                        

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
	
			do{
				net->messages.clear();	
				net->Write(request);
				net->Read();
				usleep(500*1000);
					
				if (net->GetStatus()>0){
					
					Speech = net->GetIncoming();
					net->messages.clear();
					while(Speech =="?" || Speech =="??" || Speech =="" || Speech =="yes" || Speech =="no")
					{
						usleep(500*1000);
						net->Write("REQsendingWord");
												
						net->Read();
						if (net->GetStatus()>0){
						Speech = "";  
						Speech = net->GetIncoming();
						net->messages.clear();
						}
						
						counter++;
							
							if(counter == 10)
							{
								repeat = "Repeat please the "+ subject;
								TextToSpeech(repeat,2);
								counter = 1;

							}
							if(counter == 1)
							{
								beepStartSpeech();
							}
					}
					
					counter = 2;
					sleep(1);
					// Here makes a confirmation
					std::cout << "Makes a confirmation"<<std::endl;
					// Here makes a request from confirmation
					net->messages.clear();
					net->Write("REQstartConfirmation");
					received = "Did you tell me " + Speech + "?";
					TextToSpeech(received,round(received.length()/12));
					usleep(500*1000);
					net->Read();
					conf = net->GetIncoming();
					conf = "?";
					net->messages.clear();
					CleanSpeech(net);
					
						while(conf =="?" || conf =="??" || conf =="")
						{							
							usleep(500*1000);
							net->Write("REQsendingWord");
							
							net->Read();
							if (net->GetStatus()>0){
							conf = "";  
							conf = net->GetIncoming();
							net->messages.clear();
							}
							
							counter++;
							
							if(counter == 14)
							{
								TextToSpeech(received,2);
								counter = 3;
							}
							if(counter == 3)
							{
								beepStartSpeech();
							}
						}
						if(conf == "no")
						{
							repeat = "Can you repeat please the "+subject;
							TextToSpeech(repeat,2);
							counter = 0;
						}
					}
			}while(conf=="no");
			
			CleanSpeech(net);
			net->messages.clear();
			
			std::cout << "REQUEST: " << request << "WORD: " << Speech <<std::endl;
			return Speech;
}

string LoopPhrase(char *request, NetThread *net)
{
	string Speech = "";
	int counter = 0;
	string received = "";
	
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
						usleep(500*1000);
						net->Write("REQsendingPhrases");
												
						net->Read();
						if (net->GetStatus()>0){
						Speech = "";  
						Speech = net->GetIncoming();
						net->messages.clear();
						}
						
						counter++;
						
							if(counter == 1)
							{
								beepStartSpeech();
								//sleep(5);
								counter = -12;
							}
					}
					
					counter = 0;
					sleep(1);
					// Here makes a confirmation
					std::cout << "Makes a confirmation"<<std::endl;
					// Here makes a request from confirmation
					net->messages.clear();
					//received =  Speech + "?";
					//TextToSpeech(received,round(received.length()/12));
					
					}
			}while(Speech =="?" || Speech =="??" || Speech =="");
			
			CleanSpeech(net);
			net->messages.clear();
			
			std::cout << "REQUEST: " << request << "WORD: " << Speech <<std::endl;
			return Speech;
}

string LoopStart(char *request, NetThread *net)
{
	string Speech = "";
	int counter = 0;
	string received = "";
	string repeat = "";
	
			do{
				net->messages.clear();	
				net->Write(request);
				net->Read();
				usleep(1000*1000);
					
				if (net->GetStatus()>0){
					
					Speech = net->GetIncoming();
					net->messages.clear();
					
					while(counter<=6)
					{
						usleep(500*1000);
						net->Write("REQsendingWord");
												
						net->Read();
						if (net->GetStatus()>0)
						{
							Speech = "";  
							Speech = net->GetIncoming();
							net->messages.clear();
						}
						if(Speech == "?")
						{
							counter++;
						}
						
					}
										
					}
			}while(counter<=6);
			
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
		
		if (action=="getInto"){
		  	string place = "";
			string init = "";
			cout<<"Starting: "<< action << " STATE in VoiceRecognitionServer"<<endl;  

    		       init = LoopStart("REQstartPlaces",net);
			speech = "I am ready";
			TextToSpeech(speech,2);
			
			//TODO
			speech ="Please, answer after a beep like this";
			TextToSpeech(speech,3);
			beepStartSpeech();
			
			speech ="Can you tell me, where i go ?";
			TextToSpeech(speech,2);
			// Request for a place
			place = LoopRecognize("REQstartPlaces",net, "place");
			
			speech = "Ok. I go to the " + place;
			TextToSpeech(speech,1);
			
			sharedMemory->getInstance().setStringDestination(place);
			sharedMemory->getInstance().setAction("navigate");
				
		}
		else if (action=="getIntoObject"){
		    string place = "";
			string init = "";
			cout<<"Starting: "<< action << " STATE in VoiceRecognitionServer"<<endl;  
			
			init = LoopStart("REQstartPlaces",net);
			speech = "I am ready";
			TextToSpeech(speech,2);
			
			//TODO
			speech ="Please, answer after a beep like this";
			TextToSpeech(speech,3);
			beepStartSpeech();
			
			speech ="Can you tell me, where i go ?";
			TextToSpeech(speech,2);
			// Request for a place
			place = LoopRecognize("REQstartPlaces",net, "place");
			
			speech = "Ok. I go to the " + place;
			TextToSpeech(speech,1);
			
			sharedMemory->getInstance().setStringDestination(place);
			sharedMemory->getInstance().setAction("navigateToObject");
				
		}
		else if (action=="getIntoQuestions"){
		      string place = "";
			string init = "";
			cout<<"Starting: "<< action << " STATE in VoiceRecognitionServer"<<endl;  
			
			init = LoopStart("REQstartPlaces",net);
			speech = "I am ready";
			TextToSpeech(speech,2);
			
			//TODO
			speech ="Please, answer after a beep like this";
			TextToSpeech(speech,3);
			beepStartSpeech();
			
			speech ="Can you tell me, where i go ?";
			TextToSpeech(speech,2);
			// Request for a place
			place = LoopRecognize("REQstartPlaces",net, "place");
			
			speech = "Ok. I go to the " + place;
			TextToSpeech(speech,1);
			
			sharedMemory->getInstance().setStringDestination(place);
			sharedMemory->getInstance().setAction("navigateToQuestions");
				
		}
		else if (action =="requestOptions"){			
			
			string name = "";
			string drink = "";
			string place = "";
		        
			cout<<"Starting: "<< action << " STATE in VoiceRecognitionServer"<<endl;  
			numberOfUsersToLearn++;
// 			string init = LoopStart("REQstartPlaces",net);
// 			speech = "I am ready";
// 			TextToSpeech(speech,2);
			
			//TODO
			
			speech ="Please, answer after a beep like this?";
			TextToSpeech(speech,3);
			beepStartSpeech();
			
			// Request for name
			string order = "Can you tell me your Name?";
			printf("Starting PEDIR_ORDEN");
			
			
			TextToSpeech(order,2);
			name = LoopRecognize("REQstartNames",net,"name");
			
			// Request for a drink
			
 			order = "Hi " + name + ", what do you want to drink?";
			CleanSpeech(net);
			net->messages.clear();
			TextToSpeech(order,2);
			drink = LoopRecognize("REQstartObjects",net, "drink");
			
			// Request for a place
			
			order = name + ", Can you tell me the place where the " + drink + " is?" ;
			CleanSpeech(net);
			net->messages.clear();
			TextToSpeech(order,round(order.length()/12));
			place = LoopRecognize("REQstartPlaces",net, "place");
			
// 			order = "Well "+ name + ", you want a " + drink + ", that is in the " + place;
// 			TextToSpeech(order,2);
// 			
			sharedMemory->getInstance().setStringDestination(place); ;
			sharedMemory->getInstance().setRequestedObject(drink);
			
			sharedMemory->getInstance().lastObjective->setName(name);
			sharedMemory->getInstance().lastObjective->setOrder(drink);
			Objective *tempObjective = new Objective();
			tempObjective->setName(sharedMemory->getInstance().lastObjective->getName());
			tempObjective->setObjectivePosition(sharedMemory->getInstance().lastObjective->getObjetivePosition());
			tempObjective->setOrder(sharedMemory->getInstance().lastObjective->getOrder());
			tempObjective->setType(sharedMemory->getInstance().lastObjective->getType());
			tempObjective->setVisualID(sharedMemory->getInstance().lastObjective->getVisualID());
			//se le guarda la posición del robot y no del kinect al momento de tomar una orden ya esta enfrente del usuario
			tempObjective->setObjectivePosition(sharedMemory->getInstance().getRobotPosition());
			//sharedMemory->getInstance().lastObjective;
			sharedMemory->getInstance().addUser(*tempObjective);
			
			order = "Well "+ name + ", you want a " + drink + ", that is in the " + place;
			TextToSpeech(order,5);
			
			//el mayor esta en caso de que se inicie mal el sistema y no se indique en memoria compartida el número de usuarios, i.. es cero.
			if (numberOfUsersToLearn >= sharedMemory->getInstance().getNumberOfUsersToLearn()){
			 cout<<"USERS learnd"<< sharedMemory->getInstance().getNumberOfUsersToLearn()<< endl; 
			 for (int i=0;i<sharedMemory->getInstance().getNumberOfUsersToLearn();i++){
			  cout<< "***USER: "<< i<<" Name: "<< sharedMemory->getInstance().getUser(i).getName()<<" Order: "<< sharedMemory->getInstance().getUser(i).getOrder()<<endl;
			 }
			  numberOfUsersToLearn=0;
			  sharedMemory->getInstance().setAction("navigateToObject");
			}else{
			  sharedMemory->getInstance().setAction("userLearn");
			  
			}
				
		}else if (action =="requestQuestions"){
			
			string phrase = "";
			
			cout<<"Starting: "<< action << " STATE in VoiceRecognitionServer"<<endl;  
			
			speech ="Please, close to me";
			TextToSpeech(speech,3);	
		  
			speech ="Please, answer after a beep like this?";
			TextToSpeech(speech,3);
			beepStartSpeech();
			// Request for name
			string order = "Ask me ";
			printf("Starting ASKING");
			
			//TODO
			int cont=0;
			while(cont<10)
			{
			CleanSpeech(net);
			net->messages.clear();
			sleep(1);	
			TextToSpeech(order,round(order.length()/12));
			net->messages.clear();
			phrase = LoopPhrase("REQstartPhrases",net);
									
			TextToSpeech(phrase,round(phrase.length()/7));
			std::cout << "FINAL " <<phrase << " final detected "<<std::endl;
			cont++;
			//sharedMemory->getInstance().stringDestination= &place;
			//sharedMemory->getInstance().setAction("navegar");
			}
			
			//sharedMemory->getInstance().stringDestination= &phrase;
	
			sharedMemory->getInstance().setAction("getInto");
				
		}else if (action =="requestCommand"){
			string command = "";
			string init = "";
          cout<<"Starting: "<< action << " STATE in VoiceRecognitionServer"<<endl;  
			
			init = LoopStart("REQstartCommand",net);
			// Request for a command
			command = LoopRecognize("REQstartCommand",net, "command");
			
			if (command=="avoid that"){
			  sharedMemory->getInstance().setTestRunning("avoid that");
			  //esto debe cambiar al destino donde se encuentre las dos puertas
			  sharedMemory->getInstance().setStringDestination("dining");
			  //Funcionan igual que los home, al final se queda esperando un comando
			  sharedMemory->getInstance().setAction("navigateToHome");
			}else if (command=="what did you say"){
			  sharedMemory->getInstance().setTestRunning("what did you say");
			  //sharedMemory->stringDestination = (string*)"bedroom";
			  sharedMemory->getInstance().setAction("getIntoQuestions");
			}else if (command=="go home three"){
			  sharedMemory->getInstance().setTestRunning("none");
			  sharedMemory->getInstance().setStringDestination("trash");
			  sharedMemory->getInstance().setAction("navigateToHome");
			}else if (command=="go home four"){
			  sharedMemory->getInstance().setTestRunning("none");
			  sharedMemory->getInstance().setStringDestination("trash");
			  sharedMemory->getInstance().setAction("navigateToHome");
			}
					  
		} else if (action =="payAttention"){
// 			string helping = "";
// 			string init = "";
// 			cout<< "Iniciando: " << action <<endl;
// 			
// 			init = LoopStart("REQstartHelping",net);
// 			// Request for a command
// 			helping = LoopRecognize("REQstartHelping",net, "Do you need help?");
// 			
// 			sharedMemory->getInstance().setStringDestination("bedroom1");
// 			sharedMemory->getInstance().setAction("navigateCloseTo");
		}
		else if (action =="requestEmergencyObjects"){
			string object = "";
			string init = "";
          cout<<"Starting: "<< action << " STATE in VoiceRecognitionServer"<<endl;  
							
			sharedMemory->getInstance().sintetizer.set_Phrase("I have detected an emergency");
			sleep(3);
			
			sharedMemory->getInstance().sintetizer.set_Phrase("what would you like that i bring you?");
			sleep(4);
						
			object = LoopRecognize("REQstartEmergency",net, "object");
			
			if (object!="anything"){
			  sharedMemory->getInstance().sintetizer.set_Phrase(object);
			  //TODO the real object is changed for coke because test (object recognition) 
			  sharedMemory->getInstance().setRequestedObject("coke");
			  
			  sharedMemory->getInstance().setStringDestination("dining");
			  sharedMemory->getInstance().setAction("navigateToObject");
			}else{
			
			  sharedMemory->getInstance().setStringDestination("entrance");
			  sharedMemory->getInstance().setAction("navigateToEntrance");
			}
				
	
		}else if (action =="waitForAmbulance"){
			string response = "";
			string init = "";
			sleep(3);
          cout<<"Starting: "<< action << " STATE in VoiceRecognitionServer"<<endl;  
			//response = LoopStart("REQstartConfirmation",net);
			sharedMemory->getInstance().sintetizer.set_Phrase("Are you a Doctor ?");
			sleep(2);

			response = LoopPhrase("REQstartConfirmation",net);
			
			if (response == "yes"){
			  sharedMemory->getInstance().sintetizer.set_Phrase("Please , follow me ?");
			  sleep(1);
			  sharedMemory->getInstance().setStringDestination("bedroom1");
			  sharedMemory->getInstance().setAction("navigateBackToEmergency");
			}
			
				
	
		}
		else if (action =="navigateBackToEmergency"){
			string object = "";
			string init = "";
			cout<<"Starting: "<< action << " STATE in VoiceRecognitionServer"<<endl;  
			sleep(2);
			sharedMemory->getInstance().sintetizer.set_Phrase("My boss had an accident ?");
			sleep(4);
			
			
				
	
		}
	}
    usleep(100);
}



void VoiceRecognitionServer::run()
{
    pthread_create(&thread_id, NULL, &IPlugin::IncWrapper, this);
}

void VoiceRecognitionServer::stop()
{

}
