/*
    <one line to give the program's name and a brief idea of what it does.>
    2012  J. Irving Vasquez  ivasquez@ccc.inaoep.mx

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "armkatanaforsabina.h"


ArmKatanaForSabina::ArmKatanaForSabina(): ArmKatana()
{
  currentArmPosition = UNKNOWN;
}


bool ArmKatanaForSabina::init(const char* host, const char* confFile)
{
  ArmKatana::init(host, confFile);
  sensorsCtrl= &katana->GetBase()->GetSCT()->arr[0];
  
  carriying_enc.resize(5);
  carriying_enc[0] = -6454;
  carriying_enc[1] =  2400;
  carriying_enc[2] = -5270;
  carriying_enc[3] = 30500;
  carriying_enc[4] = -6323;
  
  
  hanging_enc.resize(5);
  hanging_enc[0] = 6370;
  hanging_enc[1] = -4876;
  hanging_enc[2] = -16604;
  hanging_enc[3] = 15969;
  hanging_enc[4] = 5447;
      
  
  currentArmPosition = UNKNOWN;
}


bool ArmKatanaForSabina::init()
{
  ArmKatana::init();
  
  sensorsCtrl= &katana->GetBase()->GetSCT()->arr[0];
  
  carriying_enc.resize(5);
  carriying_enc[0] = -6454;
  carriying_enc[1] =  2400;
  carriying_enc[2] = -5270;
  carriying_enc[3] = 30500;
  carriying_enc[4] = -6323;
  
  
  hanging_enc.resize(5);
  hanging_enc[0] = 6370;
  hanging_enc[1] = -4876;
  hanging_enc[2] = -16604;
  hanging_enc[3] = 15969;
  hanging_enc[4] = 5447;
      
  
  currentArmPosition = UNKNOWN;
}



bool ArmKatanaForSabina::detectCurrentConfiguration()
{
    vector<int> encoders;
    encoders = katana->getRobotEncoders(true);
    
    if(equalVectors(encoders,carriying_enc,5,5)){
      currentArmPosition = CARRYING;
    }
}


void ArmKatanaForSabina::deliverObject()
{
  cout << "Delivering object" << endl;
  if(currentArmPosition == CARRYING){
    katana->moveMotorToEnc(3,23561,true);
    katana->openGripper(true);
    //katana->closeGripper(true, 15);
    katana->moveMotorToEnc(3,30500,true);
  }
}


bool ArmKatanaForSabina::moveToCarriyingPos(bool force)
{
  //cout << "Moving to carriying position ..." << endl;
  if(force){
    cout << "WARNING: No previous configuration detected" << endl;
    katana->moveRobotToEnc(carriying_enc.begin(), carriying_enc.end(), true);
    currentArmPosition = CARRYING;
    return true;
  }
  
  if(currentArmPosition == CALIBRATED){
    katana->moveRobotToEnc(carriying_enc.begin(), carriying_enc.end(), true);
    currentArmPosition = CARRYING;
    return true;
  }
  
  return false;
}


bool ArmKatanaForSabina::moveToHanging()
{
  if(currentArmPosition == HANGING)
    return true;
  
  if(currentArmPosition == CALIBRATED){
    try {
      vector<int> encoders(5);
      
      encoders[0] = 6705;
      encoders[1] = -30500;
      encoders[2] = -30500;
      encoders[3] = 30500;
      encoders[4] = 30500;
      katana->moveRobotToEnc(encoders.begin(), encoders.end(), true);
      
      katana->moveRobotToEnc(hanging_enc.begin(), hanging_enc.end(), true);
      
      currentArmPosition = HANGING;
      return true;
    }
    
    catch(Exception &e) {
	std::cout << "ERROR: " << e.message() << std::endl;
	return false;
    }
    
  }
  
  if(currentArmPosition == CARRYING){
    vector<int> encoders(5);
    
    try{
      katana->moveMotorToEnc(0,6370,true);
      
      encoders[0] = 6370;
      encoders[1] = -4876;
      encoders[2] = -16604;
      encoders[3] = 15969;
      encoders[4] = 5447;
      katana->moveRobotToEnc(encoders.begin(), encoders.end(), true);
      
      currentArmPosition = HANGING;
      return true;
    } catch(Exception &e) {
	std::cout << "ERROR: " << e.message() << std::endl;
	return false;
    }
  }
  
  if(currentArmPosition == UNKNOWN);
  {
    cout << "WARNING: I will move but auto collision could occurr!!!" << endl;
    try {
      vector<int> encoders(5);
      
      encoders[0] = 6370;
      encoders[1] = -4876;
      encoders[2] = -16604;
      encoders[3] = 15969;
      encoders[4] = 5447;
      katana->moveRobotToEnc(encoders.begin(), encoders.end(), true);
      
      currentArmPosition = HANGING;
      return true;
    }
    catch(Exception &e) {
	std::cout << "ERROR: " << e.message() << std::endl;
	return false;
    }
  }

  if(currentArmPosition == STORED)
    return false;
}



void ArmKatanaForSabina::store()
{
  if(currentArmPosition == STORED)
    return;
  
  if(currentArmPosition != HANGING)
    moveToHanging();
  
  if(currentArmPosition == HANGING){
    vector<int> encoders(6);
    
    try{
      // 1
      encoders[0] = 6370 ;
      encoders[1] = -11037 ;
      encoders[2] = -16604 ;
      encoders[3] = 15969 ;
      encoders[4] = 5447 ;
      encoders[5] = 12240 ;
      cout << "1/8" << endl;
      katana->moveRobotToEnc(encoders, true);
      
      // 2
      cout << "2/8" << endl;
      katana->moveMotorToEnc(3,7012,true);
      
      // 3
      cout << "3/8" << endl;
      katana->moveMotorToEnc(1,-17098,true);
      
      // 4
      cout << "4/8" << endl;
      katana->moveMotorToEnc(3,-418,true);
      
      // 5
      cout << "5/8" << endl;
      katana->moveMotorToEnc(1,-1887,true);
      
      // 6
      cout << "6/8" << endl;
      katana->moveMotorToEnc(3, 2574, true);
      
      // 7
      cout << "7/8" << endl;
      katana->moveMotorToEnc(1, 1085,true);
      
      // 8
      cout << "8/8" << endl;
      katana->moveMotorToEnc(3, 4263, true);
      
      katana->switchRobotOff();
      currentArmPosition = STORED;
    } catch(Exception &e) {
	std::cout << "ERROR: " << e.message() << std::endl;
	return;
    }
  }
}


bool ArmKatanaForSabina::equalVectors(std::vector< int > A, std::vector< int > B, int tolerance, int max_dim)
{
  if(A.size() != B.size())
    return false;
  
  for(int i = 0;i < A.size() && i <max_dim; i++){
    //cout << A[i] << " " << B[i] << endl;
    if( abs(A[i] - B[i])>tolerance )
      return false;
  }
  
  return true;
}


bool ArmKatanaForSabina::graspByApproachingAt(double x, double y, double z)
{
  try{
    
  if(!approachToGrasp(x,y,z))
    return false;
  
  if(approximateToTheObject()){
    //close the gripper;
    katana->closeGripper(false);
    sleep(9);
    int grip_enc = katana->getMotorEncoders(5,true);
    katana->moveMotorToEnc(5,grip_enc,true);
  }
  
  // return to carriying
  moveToCarriyingPos(true);
  
  } catch(Exception &e) {
	std::cout << "ERROR: " << e.message() << std::endl;
	//return -1;
	katana->unBlock();
	return false;
  }
  
  return true;
}

bool ArmKatanaForSabina::moveToYZPoint(double y, double z, double theta_target)
{
   //asumption
  double x = 0.0;

  // increments to test different approaching angles, over theta
  int k = 10;
  int i = 0;
  double increment = M_PI /( 2* (double)k);
  double signo = -1;
  
  double phi = 0;
  double theta = 0;
  double psi = M_PI/2;
  
  vector<int> enc0, enc1; 
      
  try{
    
  katana->openGripper(false);
  bool orientationKnown = false;

  /// Move to grasping position
  i = 0;
  
  signo = 1;
  while(i<k){
      signo = signo * -1;
      //signo = 1;
      theta = theta_target + signo * i * increment;
      
      cout << "Goal Grasping" << x << " " << y << " " << z << " " << phi << " " << theta << " " << psi << endl;
      
      enc0 = katana->getRobotEncoders(true);
      katana->moveRobotTo(x,y,z,phi,theta, psi, true);
      usleep(300000);
      enc1 = katana->getRobotEncoders(true);
      
      if(!equalVectors(enc0,enc1,5,5)){
	  //cout << "Was a movement, I guess i reach the object" << endl;
	  return true;
	  //break;
      }
      
      if(signo == 1){
	i++;
      } 
  }
  
  } catch(Exception &e) {
	std::cout << "ERROR: " << e.message() << std::endl;
	//return -1;
	katana->unBlock();
	return 0;
  }
  
  return false;
}


bool ArmKatanaForSabina::moveToYZPoint(double y, double z)
{
   //asumption
  double x = 0.0;

  // increments to test different approaching angles, over theta
  int k = 10;
 // int m = 1; // number of intermediate points
 // int j = m; //iterator for intermediate points
  int i = 0;
  double increment = M_PI /( 2* (double)k);
  double signo = -1;
  
  double phi = 0;
  double theta = 0;
  double psi = M_PI/2;
  
  vector<int> enc0, enc1; 
  
  //double h,ha,angulo;
  //double dist_approaching = 150;
  //double dist_current;
  //double za ;
  //double ya ;
  //double xa ;
    
  try{
    
  katana->openGripper(false);
  bool orientationKnown = false;

  /// Move to grasping position
  i = 0;
  
  while(i<k){
      //signo = signo * -1;
      signo = 1;
      theta = signo * i * increment;
      
      cout << "Goal Grasping" << x << " " << y << " " << z << " " << phi << " " << theta << " " << psi << endl;
      
      enc0 = katana->getRobotEncoders(true);
      katana->moveRobotTo(x,y,z,phi,theta, psi, true);
      usleep(300000);
      enc1 = katana->getRobotEncoders(true);
      
      if(!equalVectors(enc0,enc1,5,5)){
	  //cout << "Was a movement, I guess i reach the object" << endl;
	  return true;
	  //break;
      }
      
      if(signo == 1){
	i++;
      } 
  }
  
  } catch(Exception &e) {
	std::cout << "ERROR: " << e.message() << std::endl;
	//return -1;
	katana->unBlock();
	return 0;
  }
  
  return false;
}


bool ArmKatanaForSabina::graspAt(double x, double y, double z)
{
 //asumption
  x = 0.0;
  
  //corregir punto a uno mas lejano
  double ytemp, ztemp;
  calculateNewPoint(y,z,50,ytemp,ztemp);
  cout << "New coordinates:" << ytemp << " " << ztemp << endl;
  y = ytemp;
  z = ztemp;
  
  approachToGrasp(x,y,z);
  
  katana->closeGripper(false);
  sleep(9);
  int grip_enc = katana->getMotorEncoders(5,true);
  katana->moveMotorToEnc(5,grip_enc,true);
  
  moveToCarriyingPos();
  
  cout << "done grasping" << endl;
  currentArmPosition = CARRYING;
  
  return true;
}



void ArmKatanaForSabina::bringOut()
{
  
  vector<int> encoders(6);
    
    try{
      katana->switchRobotOn();
 /*   cout << "8/8" << endl;
      katana->moveMotorToEnc(3, 4263, true);
      
      // 6
      cout << "6/8" << endl;
      katana->moveMotorToEnc(3, 2574, true);
      
      // 7
      cout << "7/8" << endl;
      katana->moveMotorToEnc(1, 1085,true);
      

      
      // 5
      cout << "5/8" << endl;
      katana->moveMotorToEnc(1,-1887,true);
      
      // 4
      cout << "4/8" << endl;
      katana->moveMotorToEnc(3,-418,true);
      
            // 3
      cout << "3/8" << endl;
      katana->moveMotorToEnc(1,-17098,true);
      
      // 2
      cout << "2/8" << endl;
      katana->moveMotorToEnc(3,7012,true);

      
      // 1
      encoders[0] = 6370 ;
      encoders[1] = -11037 ;
      encoders[2] = -16604 ;
      encoders[3] = 15969 ;
      encoders[4] = 5447 ;
      encoders[5] = 12240 ;
      cout << "1/8" << endl;
      katana->moveRobotToEnc(encoders, true);
 */     

      currentArmPosition = HANGING;
    } catch(Exception &e) {
	std::cout << "ERROR: " << e.message() << std::endl;
	return;
    }
}


void ArmKatanaForSabina::calculateNewPoint(double y1, double z1, double d, double &y2, double &z2 )
{
    double h1 = sqrt( pow(y1,2.0) + pow(z1,2.0) );
    //cout << " h1 " << h1;
    double h2 = h1 + d;
    //cout << " h2 " << h1;
    double alpha = asin(y1 / h1);
    //cout << " alpha " << h1;
    y2 = sin(alpha) * h2;
    //cout << " y2 " << h1;
    z2 = cos(alpha) * h2;
    //cout << " z2 " << h1;
}


bool ArmKatanaForSabina::approachToGrasp(double x, double y, double z)
{
  //asumption
  x = 0.0;
  
  //corregir punto a uno mas lejano
  //double ytemp, ztemp;
  //calculateNewPoint(y,z,30,ytemp,ztemp);
  //cout << "New coordinates:" << ytemp << " " << ztemp << endl;
  //y = ytemp;
  //z = ztemp;
  
  // increments to test different approaching angles, over theta
  int k = 10;
  int m = 2; // number of intermediate points
  int j = m; //iterator for intermediate points
  int i = 0;
  double increment = M_PI /( 2* (double)k);
  double signo = -1;
  
  double phi = 0;
  double theta = 0;
  double psi = M_PI/2;
  
  vector<int> enc0, enc1; 
  
  double h,ha,angulo;
  double dist_approaching = 150;
  double dist_current;
  double za ;
  double ya ;
  double xa ;
    
  try{
    
  katana->openGripper(false);
  bool orientationKnown = false;
  
  // Aproximate by m intermediate positions
  
  // while m different from zero
  // calculate p
  // save angles
  
  while(j!=0){
    
    //approaching point
    dist_current = ((double)j/(double)m) * dist_approaching;
    cout << j << " ";
    cout << "Dist current:" << dist_current << endl;
    
    angulo = atan2(y,z);
    h = sqrt(pow(z,2)+pow(y,2));
    ha = h - dist_current;
    double za = ha * cos(angulo);
    double ya = ha * sin(angulo);
    double xa = x;
    
    moveToYZPoint(ya,za);
 
//     // Calculate angles
//     if(orientationKnown){
//       cout << "ya se los angulos" << endl;
//       cout << "Testing goal approaching " << xa << " " << ya << " " << za << " " << phi << " " << theta << " " << psi << endl;
// 
//       enc0 = katana->getRobotEncoders(true);
//       katana->moveRobotTo(xa,ya,za,phi,theta, psi, true);
//       sleep(1);
//       enc1 = katana->getRobotEncoders(true);
// 	
//       if(!equalVectors(enc0,enc1,5,5)){
// 	    cout << "Was a movement, I guess I reach the approaching position" << endl;
// 	    //getchar();
//       } 
//       
//     }else {
//       i = 0;
//       while(i<k){
// 	//signo = signo * -1;
// 	signo = 1;
// 	theta = signo * i * increment;
// 	
// 	cout << "Testing goal approaching " << xa << " " << ya << " " << za << " " << phi << " " << theta << " " << psi << endl;
// 
// 	enc0 = katana->getRobotEncoders(true);
// 	katana->moveRobotTo(xa,ya,za,phi,theta, psi, true);
// 	sleep(1);
// 	enc1 = katana->getRobotEncoders(true);
// 	
// 	if(!equalVectors(enc0,enc1,5,5)){
// 	    cout << "Was a movement, I guess I reach the approaching position" << endl;
// 	    orientationKnown = true;
// 	   // getchar();
// 	    i = k;
// 	}
// 	
// 	if(signo == 1){
// 	  i++;
// 	} 
//       }
//     }
    j--;
  }
  
  if (moveToYZPoint(y,z))
    return true;
  
  /// Move to grasping position
//   i = 0;
  
//   // First try with previous angles
//   if(orientationKnown){
//       enc0 = katana->getRobotEncoders(true);
//       katana->moveRobotTo(x,y,z,phi,theta, psi, true);
//       sleep(1);
//       enc1 = katana->getRobotEncoders(true);
//       if(equalVectors(enc0,enc1,5,5)){
// 	  // no hubo movimiento asi que hay que tratar otros angulos
// 	  cout << "No funcionaron los ángulos anteriores" << endl;
// 	  while(i<k){
// 	    //signo = signo * -1;
// 	    signo = 1;
// 	    theta = signo * i * increment;
// 	    cout << "Goal Grasping" << x << " " << y << " " << z << " " << phi << " " << theta << " " << psi << endl;
// 	    enc0 = katana->getRobotEncoders(true);
// 	    katana->moveRobotTo(x,y,z,phi,theta, psi, true);
// 	    sleep(1);
// 	    enc1 = katana->getRobotEncoders(true);
// 	    if(!equalVectors(enc0,enc1,5,5)){
// 		cout << "Was a movement, I guess i am ready to grasp" << endl;
// 		return true;
// 		break;
// 	    }
// 	    if(signo == 1){
// 	      i++;
// 	    } 
// 	  }
//      }
//   } else {
//     while(i<k){
//       //signo = signo * -1;
//       signo = 1;
//       theta = signo * i * increment;
//       
//       cout << "Goal Grasping" << x << " " << y << " " << z << " " << phi << " " << theta << " " << psi << endl;
//       
//       enc0 = katana->getRobotEncoders(true);
//       katana->moveRobotTo(x,y,z,phi,theta, psi, true);
//       sleep(1);
//       enc1 = katana->getRobotEncoders(true);
//       
//       if(!equalVectors(enc0,enc1,5,5)){
// 	  cout << "Was a movement, I guess i am ready to grasp" << endl;
// 	  return true;
// 	  break;
//       }
//       
//       if(signo == 1){
// 	i++;
//       } 
//     }
//   }
  
  } catch(Exception &e) {
	std::cout << "ERROR: " << e.message() << std::endl;
	//return -1;
	katana->unBlock();
	return false;
  }
  
  return false;
}


void ArmKatanaForSabina::calculateNextPoint(vector_boost P, double theta, double k, vector_boost& Y)
{
  // this conversion is due to the arm coordinates
  double beta = - theta;
  vector_boost V(3);
  V(0) = 0;
  V(1) = sin(beta);
  V(2) = cos(beta);
  
  Y = P + (k * V);
}



bool ArmKatanaForSabina::approximateToTheObject()
{
  
  int graspable_distance = 70; // distancia a la que sujeta la mano
  int k = 5; // numero de incrementos
  double advance = 20; // avance en cada intento mm
  
  int i = 0;
  bool atCenter = false;
  double x,y,z,phi,theta,psi;
  
  const TSctDAT* data	= sensorsCtrl->GetDAT();
  
  cout << "Approximating to the object." << endl;
  while (i<k){
    i++;
    cout << i << "/" << k ;
    sensorsCtrl->recvDAT();	//update sensor data7
        
    //------------------------------- Se puede suejetar?
    if(data->arr[11] < graspable_distance){
      //katana->closeGripper(true);
      return true;
    }
    
    //------------------------------- Centrar 
    centerObject();
    
    //------------------------------- Se puede sujetar?
    if(data->arr[11] < graspable_distance){
      //katana->closeGripper(true);
      return true;
    }
    
    //--------------------- Avanzar
    katana->getCoordinates(x, y, z, phi, theta, psi);
    vector_boost P(3), P1(3);
    P(0) = 0;
    P(1) = y;
    P(2) = z;
    calculateNextPoint(P, theta, advance, P1);
    cout << " " << P1 << endl;
    moveToYZPoint(P1(1),P1(2),theta);
  }
  
  return false;
}



bool ArmKatanaForSabina::centerObject()
{
  float w = 0.7;
  float gap = 40.0;
  float diff;
  float s1,s2,s4,s5;
  int current_enc;
  int new_enc;
  int motor = 3;
  int increment;
  
  int graspable_distance = 70;
  bool notAtCenter = true;
  
  const TSctDAT* data	= sensorsCtrl->GetDAT();  
  while (notAtCenter){
    notAtCenter = false;
    sensorsCtrl->recvDAT();							//update sensor data7
//     cout << "Sensors data:" << endl;
//     for (int i=0; i<data->cnt; i++) {
//       std::cout.width(5);
//       std::cout << data->arr[i] << " ";				//printout data	
//     } std::cout << "\n";
    
    s1 = (float) data->arr[9];
    s5 = (float) data->arr[1];
    s2 = (float) data->arr[8];
    s4 = (float) data->arr[0];
       
    // first pair of sensors
    diff = (s1 - s5);
    if(abs(diff)>gap){
      current_enc = katana->getMotorEncoders(motor);
      increment = (int) (w * diff);
      new_enc = current_enc + increment;
      katana->moveMotorToEnc(motor, new_enc, true);
      notAtCenter = true;
    }
    
    // second pair of sensors
//     diff = (s2 - s4);
//     if(abs(diff)>gap){
// 	current_enc = katana->getMotorEncoders(motor);
// 	increment = (int) (w * diff);
// 	new_enc = current_enc + increment;
// 	katana->moveMotorToEnc(motor, new_enc, true);
// 	notAtCenter = true;
//     }
  }
  
  return true;
}