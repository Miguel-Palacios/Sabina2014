/*
Adept MobileRobots Advanced Robotics Navigation and Localization (ARNL)
Version 1.7.5.2

Copyright (C) 2004, 2005 ActivMedia Robotics LLC
Copyright (C) 2006, 2007, 2008, 2009 MobileRobots Inc.
Copyright (C) 2010, 2011, 2012 Adept Technology, Inc.

All Rights Reserved.

Adept MobileRobots does not make any representations about the
suitability of this software for any purpose.  It is provided "as is"
without express or implied warranty.

The license for this software is distributed as LICENSE.txt in the top
level directory.

robots@mobilerobots.com
Adept MobileRobots
10 Columbia Drive
Amherst, NH 03031
800-639-9481

*/


// #include "Aria.h"
#include "ArNetworking.h"



void handlePathPlannerStatus(ArNetPacket *packet) {
  char buf[64];

  packet -> bufToStr(buf, 63);
  printf(".. Path planner status: \"%s\"\n", buf);
}


void handleGoalName(ArNetPacket* packet) {
  char buf[64];

  packet->bufToStr(buf, 63);
  printf(".. Current goal: \"%s\"\n", buf);
}

void handleRobotUpdate(ArNetPacket* packet) {
  char buf[64];

  packet -> bufToStr(buf, 63);
  printf(".. Robot server status: \"%s\"\n", buf);

  packet -> bufToStr(buf, 63);
  printf(".. Robot server mode: \"%s\"\n", buf);

  printf(".. Robot's battery voltage: %d\n", packet -> bufToByte2());

  printf(".. Robot's X position: %d\n", packet -> bufToByte4());

  printf(".. Robot's Y position: %d\n", packet -> bufToByte4());

  printf(".. Robot's Theta position: %d\n", packet -> bufToByte2());

  printf(".. Robot's forward velocity: %d\n", packet -> bufToByte2());

  printf(".. Robot's rotation velocity: %d\n\n", packet -> bufToByte2());
}


void handleGoalList(ArNetPacket *packet) {

  printf(".. Server has these goals:\n");
  char goal[256];

  for(int i = 0; packet -> getReadLength() < packet -> getLength(); i++) {
    packet -> bufToStr(goal, 255);

    if(strlen(goal) == 0)
        return;

    printf("      %s\n", goal);
  }
}

void handleSensorCurrent(ArNetPacket *packet) {
	char buf[64];
	int readings, nreadings;

	nreadings = packet -> bufToByte2();
	printf("Number of readings: %d\n", nreadings);

	packet -> bufToStr(buf, 63);
	printf("Sensor's Name: %s\n", buf);

	for (readings = 0; readings < nreadings; readings++)
		printf("(%d, %d)  ", packet -> bufToByte4(), packet -> bufToByte4());

	printf("\n");
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

int main(int argc, char **argv) {

  // Aria::init();

  ArClientBase client;
  ArPose pose(1530.0, -4770.0, 45.0);
  ArPose GoToPose(3000.0, 0.0, -90.0);
  ArNetPacket posePacket, directGoToPosePacket;

  ArArgumentParser parser(&argc, argv);
  ArClientSimpleConnector clientConnector(&parser);
  parser.loadDefaultArguments();

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
  client.requestOnce("getLocState");
  client.request("pathPlannerStatus", 5000);
  client.request("goalName", 5000);
  client.request("update", 5000);
  client.requestOnceWithString("getSensorCurrent", "lms2xx_1");



  if (client.dataExists("localizeToPose")) {
	  printf(".. Server does have \"localizeToPose\" request.\n");
	  posePacket.byte4ToBuf(pose.getX());
	  posePacket.byte4ToBuf(pose.getY());
	  posePacket.byte4ToBuf(pose.getTh());

	  client.requestOnce("localizeToPose", &posePacket);
  }
  else
	  printf(".. Server doesn't have that request.\n");



  ArUtil::sleep(5000);
  printf("Moving Xxxx.x meters ahead..\n");
  directGoToPosePacket.byte4ToBuf(GoToPose.getX());
  directGoToPosePacket.byte4ToBuf(GoToPose.getY());
  directGoToPosePacket.byte4ToBuf(GoToPose.getTh());

  client.requestOnce("gotoPose", &directGoToPosePacket);

  while(client.getRunningWithLock()) {

    char goal[128];
    printf("=> Enter a goal name, or * to tour all goals, or ? to list goals.\n");

    if(fgets(goal, 127, stdin) == NULL ) {
        // EOF, receives EOF Ctrl-D
        printf("goodbye.\n");
        Aria::shutdown();
        return 0;
    }

    goal[strlen(goal)-1] = '\0';  // replace position 127 with ??, and remove newline with other unknown character


    // Client's decision block
    if(strcmp(goal, "?") == 0) {
      client.requestOnce("getGoals");
      printf("=> Enter a goal name, or * to tour all goals, or ? to list goals.\n");
    }
    else if(strcmp(goal, "*") == 0) {
      if(client.dataExists("tourGoals")) {
        printf("=> Touring all goals...\n");
        client.requestOnce("tourGoals");
      }
      else {
        printf("=> Can't tour goals, server does not have that request.\n");
      }
    }
    else {
      printf("=> Sending goal \"%s\" to server...\n", goal);
      client.requestOnceWithString("gotoGoal", goal);
    }

  }
  // Client's decision block end

  printf("Server disconnected.\n");
  Aria::shutdown();
  return 0;
}
