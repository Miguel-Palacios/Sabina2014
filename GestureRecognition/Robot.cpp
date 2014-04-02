#include "Robot.h"

	ArActionGoto action;
	
	ArArgumentParser *parser;
	
	ArSimpleConnector *connector;
	
	ArRobot pioneer;

void Robot::Robot_Init(){
	system("clear");
	printf("Parsing XML file\n");
	printf("Connection with Kinect established!\n");
	printf("Initializing virtual robot\n------------------\n");

	int argc = 3;
	char *argv[10];
	argv[0] = "./aria_test";
	argv[1] = "-rp";
	argv[2] = "/dev/ttyUSB0";

	parser  = new ArArgumentParser(&argc,argv);
	connector  = new ArSimpleConnector(parser);

	parser->loadDefaultArguments();
	if(!connector->parseArgs()){
		printf("Unknown settings\n");
		Aria::exit(0);
		exit(1);
	}
	
	if(!connector->connectRobot(&pioneer)){
		printf("Can't achieve connection with robot\n");
		Aria::exit(0);
		exit(1);
	}
	
	pioneer.setTransAccel(200);
	pioneer.setTransDecel(200);

	pioneer.runAsync(true);
	pioneer.lock();
	pioneer.comInt(ArCommands::ENABLE, 1);
	pioneer.unlock();

	pioneer.resetTripOdometer();
	pioneer.setAbsoluteMaxTransVel(250);
	pioneer.setAbsoluteMaxRotVel(35);

}

void Robot::RobotLeft(){
	pioneer.setVel2(30,110);
	sleep(7);
}

void Robot::RobotRight(){
	pioneer.setVel2(110,30);
	sleep(7);
}
