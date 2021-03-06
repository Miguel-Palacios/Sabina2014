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


#define PLUGIN_NAME "NavigationClient"

#include "../Plugin_API/pluginapi.h"
#include "../SharedMemory/SharedMemory.h"
#include "../SharedMemory/Location.h"


#include "ArNetworking.h"

#define Living "living"
#define Kitchen "kitchen"
#define Dinning "dinning"
#define Exit "exit"
#define TRUE 1
#define FALSE 0

char textData[64];
char currentGoal[64];
vector<int> headingsForBedroom;
vector<int> headingsForLiving;
int indexHeading=0;

bool openDoor = false;
// int robotYPosition = 0;
// double robotThPosition = 0.0;
SharedMemory *sharedMemory;
bool voiceRecognizerSelection=false;
Location tempLocation;

void handlePathPlannerStatus(ArNetPacket *packet) {
  char buf[64];

  packet -> bufToStr(buf, 63);
  //printf(".. Path planner status: \"%s\"\n", buf);
}


void handleGoalName(ArNetPacket* packet) {

  packet->bufToStr(currentGoal, 63);
  //printf(".. Current goal: \"%s\"\n", currentGoal);

}

void handleRobotUpdate(ArNetPacket* packet) {

  char buf[64];

  packet->bufToStr(textData, 63);
  //printf("... Robot server status: \"%s\"\n", textData);
  
  packet -> bufToStr(buf, 63);
  
  packet->bufToByte2();

  tempLocation.set_X(packet->bufToByte4());
  tempLocation.set_Y(packet->bufToByte4());
 
  int i =packet -> bufToByte2();
  
  tempLocation.set_Angle(i);
 
  //printf(".. Robot's forward velocity: %d\n", packet -> bufToByte2());

  //printf(".. Robot's rotation velocity: %d\n\n", packet -> bufToByte2());
  
  
// 
//   packet->bufToStr(buf, 63);
//   packet->bufToByte2();
// 
//    tempLocation.set_X(packet->bufToByte4());
//     tempLocation.set_Y(packet->bufToByte4());
//     tempLocation.set_Angle(packet->bufToByte2());
     sharedMemory->getInstance().setRobotPosition(tempLocation);
//   
//    
  // printf("Robot position: (%d, %d, %f)\n", tempLocation.get_X(), tempLocation.get_Y(), tempLocation.get_Angle());
//   printf("Robot TETA position: %d)\n", i);
//printf("Robot float TETA position: %f)\n", tempLocation.get_Angle());
}


void handleGoalList(ArNetPacket *packet) {

  printf(".. Server has these goals:\n");
  char goal[256];

  for(int i = 0; packet -> getReadLength() < packet -> getLength(); i++) {
    packet -> bufToStr(goal, 255);

    if(strlen(goal) == 0)
        return;

    //printf("      %s\n", goal);
  }
}

void handleSensorCurrent(ArNetPacket *packet) {
	char buf[64];
	int readings, nreadings;
	openDoor = false;
	nreadings = packet->bufToByte2();
	int laserXReadings[nreadings];
  int laserYreadings[nreadings];

  float distance = 0.0;
  float minDistance = 5000.0;
	// nreadings = packet -> bufToByte2();
	//printf("Number of readings: %d\n", nreadings);

	packet -> bufToStr(buf, 63);
	//printf("Sensor's Name: %s\n", buf);

	for (readings = 0; readings < nreadings; readings++) {
	      laserXReadings[readings] = packet->bufToByte4();
	      laserYreadings[readings] = packet->bufToByte4();
		// printf("(%d, %d)  ", packet -> bufToByte4(), packet -> bufToByte4());
	}

	for (readings = 80; readings <= 100; readings++) {
	  distance = sqrt(pow((laserXReadings[readings] - tempLocation.get_X()), 2) + pow((laserYreadings[readings] -tempLocation.get_Y()), 2));

	  if (distance <= minDistance)
	minDistance = distance;
	}

	if (minDistance > 1800) {
	  openDoor = true;
	  printf("Door is open\n");
	  //printf("minDistance (%f), Distance (%f)", minDistance, distance);
	}
	else {
	  openDoor = false;
	  printf("Door is closed\n");
	  printf("\n");
	}
}

void handleSensorList(ArNetPacket *packet) {
	char buf[64];
	int i;

	printf("Number of sensors: %d\n", packet -> bufToByte2());

	printf(".. Server has these sensors:\n");

	for (i = 0; packet -> getDataReadLength() < packet -> getLength(); i++) {
		packet -> bufToStr(buf, 63);

		if (strlen(buf) == 0)
			return;

		printf("	%s\n", buf);
	}
}

void handleLocState(ArNetPacket *packet) {

	printf("Localization state: %d\n", packet -> bufToUByte());
	printf("Localization Score: %d\n", packet -> bufToUByte2());
}

void navigateTo(string destination, ArClientBase *client){
  
  string speech = "Starting navigation to " + destination;
  sharedMemory->getInstance().sintetizer.set_Phrase(speech);
  client->requestOnceWithString("gotoGoal", destination.c_str());
  
  sleep(10);
  printf("Before while Navigation");
  while (strncmp(textData, "Arrived at", 10) != 0){
        sleep(10);
  }
  sleep(2);
}



/**
 * @brief NavigationClient plugin
 * 
 * This plugin is a network server that accepts client conections to comunicate with other programs (running on the same computer or over the network) 
 * @author     Patrick Heyer, patrickhey@prodigy.net.mx, Juan Herrera juan_antonio_@hotmail.com, Manuel Oropeza zodiacanimations@msn.com
 * @date       jul 04, 2012
 * @version    1.0
 **/
class NavigationClient : public IPlugin
{
public:
    void Main();
    void run();
	void stop();
};

PLUGIN_FUNC IPlugin *CreatePlugin()
{
    return new NavigationClient;
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

void NavigationClient::Main()
{

	std::cout << "Navigation client started" << std::endl;
	int argsNumber;
	argsNumber = 3;
    char *arguments[argsNumber];
    arguments[0]="./arg_test";
    arguments[1]="-host";
    //arguments[2]="10.41.42.1";
    //se puede poner también patrolbot
    arguments[2]="77.7.27.1";

  int robotCase, counter;
	
  ArClientBase client;
  ArPose pose(0, 0, 0);
  ArPose GoToPose(3000.0, 0.0, -90.0);
  ArNetPacket posePacket, directGoToPosePacket;

  ArArgumentParser parser(&argsNumber, arguments);posePacket.empty();
		 
  ArClientSimpleConnector clientConnector(&parser);
  parser.loadDefaultArguments();
  
  headingsForBedroom.push_back(45);
  headingsForBedroom.push_back(25);
  headingsForBedroom.push_back(0);
  
 
  headingsForLiving.push_back(-20);
  headingsForLiving.push_back(-55);
  headingsForLiving.push_back(-80);
  headingsForLiving.push_back(-110);
  headingsForLiving.push_back(-140);
  
  openDoor = false;
  if (!clientConnector.parseArgs() || !parser.checkHelpAndWarnUnparsed()) {
    clientConnector.logOptions();
    exit(0);
  }
  
  printf("Connecting...\n");
  if (!clientConnector.connectClient(&client)) {
    if (client.wasRejected())
      printf("Server rejected connection, exiting\n");
    else
      printf("Could not connect to server, exiting\n");
    
    exit(1);
  } 

  printf("Connected to server.\n");
  client.addHandler("pathPlannerStatus", new ArGlobalFunctor1<ArNetPacket*>(&handlePathPlannerStatus));
  client.addHandler("update", new ArGlobalFunctor1<ArNetPacket*>(&handleRobotUpdate));
  client.addHandler("goalName", new ArGlobalFunctor1<ArNetPacket*>(&handleGoalName));
  client.addHandler("getGoals", new  ArGlobalFunctor1<ArNetPacket*>(&handleGoalList));
  client.addHandler("getSensorCurrent", new ArGlobalFunctor1<ArNetPacket*>(&handleSensorCurrent));
  client.addHandler("getSensorList", new ArGlobalFunctor1<ArNetPacket*>(&handleSensorList));
  client.addHandler("getLocState", new ArGlobalFunctor1<ArNetPacket*>(&handleLocState));

  client.runAsync();

  client.requestOnce("getGoals");
  client.requestOnce("getSensorList");
  client.requestOnceWithString("getSensorCurrent", "lms2xx_1");
  // client.request("pathPlannerStatus", 5000);
  client.request("goalName", 1000);
  client.request("update", 1000);
  client.requestOnce("getLocState");
  
  sleep(2);
  int cont =0;
  while (!openDoor) {
    cont++;
    ArUtil::sleep(2000);
    client.requestOnceWithString("getSensorCurrent", "lms2xx_1");
  }

  printf("*** Door has been OPENED *** \n");
  sleep(2);

  if (client.dataExists("localizeToPose")) {
	  printf(".. Server does have \"localizeToPose\" request.\n");
	  posePacket.byte4ToBuf(sharedMemory->getInstance().getLocalizationRobotPosition().get_X());
	  posePacket.byte4ToBuf(sharedMemory->getInstance().getLocalizationRobotPosition().get_Y());
	  posePacket.byte4ToBuf(sharedMemory->getInstance().getLocalizationRobotPosition().get_Angle());
	  
	  client.requestOnce("localizeToPose", &posePacket);
	  ArUtil::sleep(1500);
  }
  else
	  printf(".. Server doesn't have that request.\n");

  
  for(;;){
		string action = sharedMemory->getInstance().getAction();
			
		if (action=="navigate"){
		    cout<<"Starting: "<< action << "STATE in NavigationClient"<<endl;  
		    navigateTo(sharedMemory->getInstance().getStringDestination(), &client);
                   sharedMemory->getInstance().setAction("turn");
		 
			
		}if (action=="navigateToParty"){
		    cout<<"Starting: "<< action << "STATE in NavigationClient"<<endl;  
		    navigateTo(sharedMemory->getInstance().getStringDestination(), &client);
		    sleep(6);
		    sharedMemory->getInstance().startDownToRotations=false;
		    sharedMemory->getInstance().sintetizer.set_Phrase("If you need something please wave your hand to my bottom kinect");
		    sleep(8);
		    indexHeading=0;
		    sharedMemory->getInstance().setAction("turn");
		   
		}
		else if (action=="navigateBackToEmergency"){
		    
		    cout<<"Starting: "<< action << "STATE in NavigationClient"<<endl;  
		    
		    navigateTo(sharedMemory->getInstance().getStringDestination(), &client);
		     // sharedMemory->sintetizer.set_Phrase("Emergency Situation resolved");
		    sharedMemory->getInstance().setAction("createReport");
			
		}else if (action=="navigateToEntrance"){
		    cout<<"Starting: "<< action << "STATE in NavigationClient"<<endl;  
		    sharedMemory->getInstance().sintetizer.set_Phrase("Do not worry, I have called the ambulance");
			  sleep(2);
		    sharedMemory->getInstance().sintetizer.set_Phrase("Please wait a moment, I willl wait for them");
			  sleep(2);
	  
		    navigateTo(sharedMemory->getInstance().getStringDestination(), &client);
		    sharedMemory->getInstance().setAction("waitForAmbulance");
		}
		else if (action=="navigateCloseTo"){
		    cout<<"Starting: "<< action << "STATE in NavigationClient"<<endl;  
		    navigateTo(sharedMemory->getInstance().getStringDestination(), &client);
	            sharedMemory->getInstance().setAction("requestEmergencyObjects");
			
		}
		else if (action=="navigateToHome"){
		  cout<<"Starting: "<< action << " STATE in NavigationClient"<<endl;  
		  navigateTo(sharedMemory->getInstance().getStringDestination(), &client);
		  sharedMemory->getInstance().setAction("requestCommand");
		}
		else if (action=="navigateToQuestions"){
		  cout<<"Starting: "<< action << " STATE in NavigationClient"<<endl;  
		  navigateTo(sharedMemory->getInstance().getStringDestination(), &client);
		  sharedMemory->getInstance().setAction("requestQuestions");
		}
		else if (action=="navigateToObject"){
		  //solo es utilizado por cocktail Party
		  //Si se quita la indicación de lugar en requestOptions aqui debe mandarse el destino predefinido (kitchen?)
		  cout<<"Starting: "<< action << " STATE in NavigationClient"<<endl;  
		  navigateTo(sharedMemory->getInstance().getStringDestination(), &client);
		  sharedMemory->getInstance().setAction("recognizeObject");
		}
		else if (action=="navigateToObjectCategory"){
		  //considera que la posición de la categoria de un objeto (en pick and place) es la misma posición que la de donde esta el objeto en emergencia.
		  cout<<"Starting: "<< action << " STATE in NavigationClient"<<endl; 
		  //por default ahorita esta dining como el la categoria del objeto
		  navigateTo(sharedMemory->getInstance().getStringDestination(), &client);
		  if (sharedMemory->getInstance().getTestRunning()=="pick and place" || sharedMemory->getInstance().getTestRunning()=="Emergency" )
		    sharedMemory->getInstance().setAction("deliverObject");
		  else
		  sharedMemory->getInstance().setAction("userRecognize");
			
		}else if (action=="navigateToPoint"){
		    
		    cout<<"Starting: "<< action << " STATE in NavigationClient"<<endl;  
		    //TODO verificar que esto limpia el objeto
		    posePacket.empty();
		    posePacket.byte4ToBuf(sharedMemory->getInstance().lastObjective->getObjetivePosition().get_X());
		    posePacket.byte4ToBuf(sharedMemory->getInstance().lastObjective->getObjetivePosition().get_Y());
		    posePacket.byte4ToBuf(sharedMemory->getInstance().lastObjective->getObjetivePosition().get_Angle());
		    cout << "Enviando punto a navegación: "<< sharedMemory->getInstance().lastObjective->getObjetivePosition().get_X() << "," << sharedMemory->getInstance().lastObjective->getObjetivePosition().get_Y() << "," << sharedMemory->getInstance().lastObjective->getObjetivePosition().get_Angle()<<endl;
		    client.requestOnce("gotoPose", &posePacket);
		  
		    sleep(10);
		    printf("Before while Navigation");
		    while (strncmp(textData, "Arrived at", 10) != 0){
			sleep(10);
		    }
		 
		    printf("Navigation ended");
	           if (sharedMemory->getInstance().getTestRunning()=="CocktailParty")
		   sharedMemory->getInstance().setAction("userLearn");
		   else
		   sharedMemory->getInstance().setAction("requestEmergencyObjects");
	
		}else if (action=="navigateForward"){
		  
		  stringstream command;
		  cout<<"Starting: "<< action << " STATE in NavigationClient"<<endl;  
		  command<<"8 " << sharedMemory->getInstance().getGestureDepthPosition();
		  cout<< "******  AVANZA "<<command.str().c_str()<<" mm"<<endl;
		  client.requestOnceWithString("MicroControllerMotionCommand",command.str().c_str());
		  sleep(10);
		  printf("Before while Navigation");
		  while (strncmp(textData, "Stopped", 10) != 0){
			sleep(10);
			
		  }
		  sharedMemory->getInstance().setAction("turn");
		}else if (action=="turn"){
		  
		  int heading=0;
		  stringstream command;
                  cout<<"Starting: "<< action << " STATE in NavigationClient"<<endl;
		  if (sharedMemory->getInstance().startDownToRotations==false){
		    if (sharedMemory->getInstance().getStringDestination()=="bedroom"){
		      cout<<"Entrando BEDROOM 1"<<endl;
		      if (indexHeading < headingsForBedroom.size()){
			heading=headingsForBedroom[indexHeading];
			indexHeading++;
			cout<<"Entrando a If UNO bedroom"<<endl;
		      }else{
			sharedMemory->getInstance().startDownToRotations=true;
			indexHeading=headingsForBedroom.size()-2;
			heading=(-1000);//valor dado para detectar que no se obtuvo un valor válido para el heading, dado que se cambia la forma en como se recorre el arreglo
			cout<<"Entrando a else UNO bedroom"<<endl;
		      }
		    }else {//if (sharedMemory->getInstance().getStringDestination()=="living"){
		      cout<<"Entrando a LIVING 1"<<endl;
		      if (indexHeading < headingsForLiving.size()){
			heading=headingsForLiving[indexHeading];
			indexHeading++;
			cout<<"Entrando a If UNO living"<<endl;
		      }else{
			sharedMemory->getInstance().startDownToRotations=true;
			indexHeading=headingsForLiving.size()-2;//no menos uno porque ya el proceso anterior permition visitar este indice
			heading=(-1000);
			cout<<"Entrando a else UNO Living"<<endl;
		      }
		    }
		    
		  }else{
		    if (sharedMemory->getInstance().getStringDestination()=="bedroom"){
		      cout<<"Entrando BEDROoM 2"<<endl;
		      if (indexHeading >= 0){
			heading=headingsForBedroom[indexHeading];
			indexHeading--;
			cout<<"Entrando a if DOS bedroom"<<endl;
		      }else{
			sharedMemory->getInstance().startDownToRotations=false;
			indexHeading=1;
			heading=(-1000);
			cout<<"Entrando a else DOS bedroom"<<endl;
		      }
		    }else {//if (sharedMemory->getInstance().getStringDestination()=="living"){
		      cout<<"Entrando a LIVING 2"<<endl;
		      if (indexHeading>= 0){
			heading=headingsForLiving[indexHeading];
			indexHeading--;
			cout<<"Entrando a if DOS living"<<endl;
		      }else{
			sharedMemory->getInstance().startDownToRotations=false;
			indexHeading=1;//no 0 porque ya el proceso anterior permitió visitar este indice
			heading=(-1000);
			cout<<"Entrando a else DOS living"<<endl;
		      }
		    }
		  }
		    
		  if (heading>(-1000)){
		    command<<"12 " << heading;
		    cout<< "******  ROTAR "<<command.str().c_str()<<" grades con INDEXHEADING: "<<indexHeading<<"valorArray"<< headingsForLiving[indexHeading]<<endl;
		    client.requestOnceWithString("MicroControllerMotionCommand",command.str().c_str());
		    //sharedMemory->getInstance().sintetizer.set_Phrase("If you need something, please wave your hand to my bottom kinect");
	            sleep(1);
		    cout<<"*INVERSA al hacer el heading: "<< sharedMemory->getInstance().startDownToRotations << endl;
		    sharedMemory->getInstance().setAction("payAttention"); 
		  }
		}else if (action=="navigateToExit"){
		    //éste estado solo llamarlo para terminar la prueba
		    cout<<"Starting: "<< action << "STATE in NavigationClient"<<endl;  
		    navigateTo("Exit", &client);
		   sharedMemory->getInstance().setAction("turnOff");;		
		}
		else if (action=="turnOff"){
                       cout<<"Starting: "<< action << " STATE in NavigationClient"<<endl;  
			//ArUtil::sleep(60000);
			printf("Server disconnected.\n");
			Aria::shutdown();
		}
	
	}
	return ;
  
}

void NavigationClient::run()
{
    pthread_create(&thread_id, NULL, &IPlugin::IncWrapper, this);
}

void NavigationClient::stop()
{
	
}

