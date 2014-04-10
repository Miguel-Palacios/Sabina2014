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


#ifndef ARMKATANAFORSABINA_H
#define ARMKATANAFORSABINA_H

#include "armkatana.h"
//#include "vpfilereader.h"
#include <ctime>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>


//using namespace boost::numeric::ublas; 
using namespace std;

typedef boost::numeric::ublas::vector<double> vector_boost;

/**
 * Object to work with markovito.
 * 
 * Capabilities:
 * 	-	Grasp a object.
 * 	- 	Movement to simple poses.
 * 
 * Requirements:
 * 	- 	The object to grasp must be inside the reachable space.
 * 	-	Vertical position of the arm.
 * 
 * Notes:	
 * 	-	There is no collision checking. So the provided positions must be tested before.
 */
class ArmKatanaForSabina : public ArmKatana
{

public:
ArmKatanaForSabina();

  /**
   * grasp by approaching
   * x,y,z are in arm coordinates. milimeters
   */
  bool graspByApproachingAt(double x, double y, double z);
  
  /**
   * Direct grasping
   * x,y,z are in arm coordinates. milimeters
   */
  bool graspAt(double x, double y, double z);
  
  bool moveToYZPoint(double y, double z);
  
  /**
   * Moves triying to match theta
   */
  bool moveToYZPoint(double y, double z, double theta_target);
    
  bool moveToCarriyingPos(bool force=false);
  
  void deliverObject();
  
  void store(); 
  
  void bringOut();
  
  bool moveToHanging();
  
  bool detectCurrentConfiguration();
  
  bool centerObject();

  virtual bool init(const char* host, const char* confFile);

protected:
  
  /**
   * Aproximates to the object by making a small swept of the area in front of the hand
   */
  bool approximateToTheObject(); 
  
  CSctBase* sensorsCtrl;
  
  /**
   * Compare two vector
   * @param max_dim is the maximun dimension to compare for example 2 compare the elements 1 and 2 (starting from 1)
   */
  bool equalVectors(vector<int> A, vector<int> B, int tolerance, int max_dim);
  
  /**
   * Calculates a new point (far) in order to reach the original point.
   * Requires the point and the distance to the new point
   */
  void calculateNewPoint(double y1, double z1, double d, double &y2, double &z2);
  
  
  /**
   * Deja el efector final casi para agarrar el objeto
   */
  bool approachToGrasp(double x, double y, double z);
  
  /**
   * Vector equation of the line
   */
  void calculateNextPoint(vector_boost P, double theta, double k, vector_boost &Y);
  
private:
  vector<int> carriying_enc;
  vector<int> hanging_enc;
};

#endif // ARMKATANAFORSABINA_H