#include <iostream>
#include <fstream>
#include <string>

#include "SharedMemory.h"
#include "Destination.h"
#include "Objective.h"

#include "ConfigFile.h"
#include "Triplet.h"

bool Main_system_escribible=true;
bool Position_escribible=true;
bool Lineal_velocity_escribible=true;
bool Angular_velocity_escribible=true;
bool Action_escribible=true;
bool Aria_port_escribible=true;
bool Laser_port_escribible=true;
bool PTZ_port_escribible=true;
bool Last_objective_escribible=true;
bool Current_destination_escribible=true;
bool Prev_destination_escribible=true;
bool Route_escribible=true;
bool estimatedPosition_escribible = true;
bool requestedObject_escribible=true;

bool objectPositionX_escribible=true;
bool objectPositionY_escribible=true;
bool realObjectPositionX_escribible=true;
bool realObjectPositionY_escribible=true;
bool realObjectPositionZ_escribible=true;
bool stringDestination_escribible=true;
bool testRunning_escribible =true;
bool doCalibration_escribible=true;
bool gestureDepthPosition_escribible=true;
bool numberOfUsersToLearn_escribible=true;
bool usersList_escribible=true;

bool doCalibration=false;

using std::string;
using std::cout;
using std::endl;
SharedMemory * SharedMemory::m_singleton=0;

///*! \brief Private constructor
// *
// *  The constructor has to be private or protected so the singleton patern works
// // 
SharedMemory::SharedMemory() {
}


void load_destinations ( char *filename, map<string,Destination> &mine)
{
    string name;
    int x, y, a;
    Location loc_temp;
    Destination temp;
    ifstream myfile (filename);
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            myfile >> name;
            myfile >> x;
            myfile >> y;
            myfile >> a;
            loc_temp.set(x,y,a);
            temp.set_Coordinate(loc_temp);

            temp.set_Name(name);
            mine.insert(std::make_pair( name,temp));
            cout <<temp.get_Name() << temp.get_Coordinate().get_X() <<endl;
        }
        myfile.close();
    }
}

void load_Names ( char *filename, map<string,Objective> &mine)
{
    string name;
    Objective temp;

    ifstream myfile (filename);
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            myfile >> name;

            mine.insert(std::make_pair( name,temp));
	    
        }
        myfile.close();
    }
}

///*! \brief Starts the singleton
// *
// *  Starts the singleton similar to a constructor. Its the only way to set initial values
// *  since the constructor is private. The initial values are read from the a configuration
// *  file given by filename
// */
void SharedMemory::Initialize(string filename) {
    if ( m_singleton == 0 )
        getInstance();

    ConfigFile config( filename );


    int temp_int;
    float temp_float;
    string temp_string;
    config.readInto( getInstance().mainSystem, "Main_system" );

    config.readInto( temp_int, "Position_x" );
    getInstance().robotPosition.set_X(temp_int);

    config.readInto( temp_int, "Position_y" );
    getInstance().robotPosition.set_Y(temp_int);

    config.readInto( temp_float, "Position_angle" );
    getInstance().robotPosition.set_Angle(temp_float);


	//For restaurant and followme test only
    config.readInto( getInstance().linealVelocity, "Lineal_velocity" );
    config.readInto( getInstance().angularVelocity, "Angular_velocity" );

    getInstance().ariaPort = new string;
    config.readInto( temp_string, "Aria_port" );
    getInstance().setAriaPort(temp_string);

    getInstance().laserPort = new string;
    config.readInto( temp_string, "Laser_port" );
    getInstance().setLaserPort(temp_string);

    getInstance().PTZ_port = new string;
    config.readInto( temp_string, "PTZ_port" );
    getInstance().setPTZPort(temp_string);

    config.readInto( temp_int, "Camera_index" );
    if (temp_int>=0)
      getInstance().ptzDevice.set_stream(cvCaptureFromCAM(temp_int));

    getInstance().enviroment.Image_path = new string;
    config.readInto( temp_string, "Enviroment_Image_path" );
    getInstance().enviroment.set_Image_path(temp_string);

    getInstance().destinations=new map<string, Destination>;
    config.readInto(temp_string, "Destinations_file" );
    load_destinations((char*) temp_string.c_str(), *getInstance().destinations);

    getInstance().objectives=new map<string, Objective>;
    config.readInto(temp_string, "Names_file" );
    load_Names((char*) temp_string.c_str(),*getInstance().objectives);

    getInstance().mdpAction = new string;
    getInstance().lastObjective = new Objective();
    getInstance().currentDestination = new string;
    getInstance().prevDestination= new string;
    getInstance().sintetizer.Phrase = new string;
   
    getInstance().route=new list<Location>;

    getInstance().seguir=false;

    getInstance().laser= new Laser();
    getInstance().localized = false;
	getInstance().stringDestination= new string();
	

    getInstance().kinectInfo= new Kinect();

    getInstance().requestedObject = new string;

    getInstance().testRunning =new string("pick and place");
    getInstance().objectPositionX =0;
    getInstance().objectPositionY =0;
    getInstance().realObjectPositionX =0.0;
    getInstance().realObjectPositionY =0.0;
    getInstance().realObjectPositionZ =0.0;
    getInstance().gestureDepthPosition=0 ;
    getInstance().numberOfusersToLearn=0;
    getInstance().users= new vector<Objective>();
  

}



///*! \brief Returns a pointer to the shared memory object
// *
// *  Returns a pointer to the only copy in memory of the Robot object. If no object exist it
// *  will initialize the instance befor returning the pointer \return Robot
// */
SharedMemory & SharedMemory::getInstance() {
    if ( m_singleton == 0 )
    {
        m_singleton = new SharedMemory;

    }

    return ((SharedMemory &) m_singleton);
}

///*! \brief Gets the position of the robot
// *
// *  Gets the position of the robot (x, y, angle) \return Position
// */
Location SharedMemory::getRobotPosition() {
    {
    } while (!Position_escribible);
    Position_escribible=false;
    Location temp=robotPosition;
    Position_escribible=true;

    return temp;
}

///*! \brief Sets the position of the robot
// *
// *  Sets the position of the robot (x, y, angle)
// */
void SharedMemory::setRobotPosition(Location value) {
    {
    } while (!Position_escribible);
    Position_escribible=false;
    robotPosition = value;
    Position_escribible=true;
}

///*! \brief Gets the Lineal velocity of the robot
// *
// *  Gets the Lineal velocity of the robot \return Lineal_velocity
// */
float SharedMemory::getLinealVelocity() {
    return linealVelocity;
}

///*! \brief Sets the Lineal velocity of the robot
// *
// *  Sets the Lineal velocity of the robot
// */
void SharedMemory::setLinealVelocity(float value) {
    do
    {
    } while (!Lineal_velocity_escribible);
    Lineal_velocity_escribible=false;bool doCalibration_escribible=true;
    linealVelocity = value;
    Lineal_velocity_escribible=true;
}

///*! \brief Gets the Angular velocity of the robot
// *
// *  Gets the Angular velocity of the robot \return Angular_velocity
// */
float SharedMemory::getAngularVelocity() {
    return angularVelocity;int objectPositionX;
  
}

///*! \brief Sets the Angular velocity of the robot
// *
// *  Sets the Angular velocity of the robot
// */
void SharedMemory::setAngularVelocity(float value) {
    do
    {
    } while (!Angular_velocity_escribible);
    Angular_velocity_escribible=false;
    angularVelocity = value;
    Angular_velocity_escribible=true;
}

///*! \brief Gets the name of the destination

// *  Gets the name of the destination of the robot. There is no safty check to see if the
// *  destination exists \return Current_destination
// */
string SharedMemory::getCurrentDestination() {
    return *currentDestination;
}

///*! \brief Sets the name of the destination
// *
// *  Sets the name of the destination of the robot. There is no safty check to see if the
// *  destination exists
// */
void SharedMemory::setCurrentDestination(string value) {
    do
    {
    } while (!Current_destination_escribible);
    Current_destination_escribible=false;
    *currentDestination = value;
    Current_destination_escribible=true;
}

void SharedMemory::setPrevDestination(string value) {
    do
    {
    } while (!Prev_destination_escribible);
    Prev_destination_escribible=false;
    *prevDestination = value;
    Prev_destination_escribible=true;
}

///*! \brief Gets the name of the last seen object
// *
// *  Gets the name of last seen of the last seen object. There is no safty check to
// *  see if the name of the object exists \return Last_objective
// */
// string SharedMemory::getLastObjective() {
//     return *lastObjective;
// }
Objective SharedMemory::getLastObjective() {
    return *lastObjective;
}

///*! \brief Sets the name of last seen of the last seen object
// *
// *  Sets the name of last seen of the last seen object. There is no safty check to
// *  see if the name of the object exists.
// */
// void SharedMemory::setLastObjective(string value) {
//     do
//     {
//     } while (!Last_objective_escribible);
//     Last_objective_escribible=false;
//     *lastObjective = value;
//     Last_objective_escribible=true;
// }

void SharedMemory::setLastObjective(const Objective &value) {
    do
    {
    } while (!Last_objective_escribible);
    Last_objective_escribible=false;
    *lastObjective = value;
    Last_objective_escribible=true;
}

///*! \brief Gets the route of the robot
// *
// *  Gets a list of Locations that form the route or path  \return Route
// */
list<Location> & SharedMemory::getRoute() {
    return *route;
}

///*! \brief Sets the route of the robot
// *
// *  Sets a list of Locations that form the route or path.
// */
void SharedMemory::setRoute(list<Location>  value) {
    do
    {
    } while (!Route_escribible);
    Route_escribible=false;
    *route = value;
    Route_escribible=true;
}

///*! \brief Gets the name of the action decided by the MDP
// *
// *   Gets the name of the action decided by the MDP \return Action
// */
string SharedMemory::getAction() {
    return *mdpAction;
}

///*! \brief Sets the name of the action decided by the MDP
// *
// *   Sets the name of the action decided by the MDP
// */
void SharedMemory::setAction(string value) {
    do
    {
    } while (!Action_escribible);
    Action_escribible=false;
    *mdpAction = value;
    Action_escribible=true;
}

///*! \brief Gets the name of the action decided by the MDP
// *
// *   Gets the name of the action decided by the MDP \return Action
// */
string SharedMemory::getRequestedObject() {
    return *requestedObject;
}

///*! \brief Sets the name of the action decided by the MDP
// *
// *   Sets the name of the action decided by the MDP
// */laser
void SharedMemory::setRequestedObject(string value) {
    do
    {
    } while (!requestedObject_escribible);
    requestedObject_escribible=false;
    *requestedObject = value;
    requestedObject_escribible=true;
}


///*! \brief Adds a location to the Route
// *
// *  Adds a location to the end of the list of locations containd in Route
// */
void SharedMemory::addLocationToPath(const Location & location) {
    route->push_back(location);
}

///*! \brief Loads the list of known locations from file
// *
// *  Loads the list of known locations from file \return false if file not found
// */
bool SharedMemory::loadDestinations(string filename) {
}

///*! \brief Deletes a location from the Route
// *
// *  Deletes the first element of the Route list
// */
void SharedMemory::deleteLocationFromPath() {
    route->pop_front();
}

void SharedMemory::clearPath()
{
    route->clear();
}


string SharedMemory::getAriaPort() {
    return *ariaPort;
}

void SharedMemory::setAriaPort(string value) {
    do
    {
    } while (!Aria_port_escribible);
    Aria_port_escribible=false;
    *ariaPort = value;
    Aria_port_escribible=true;
}

string SharedMemory::getLaserPort() {
    return *laserPort;
}

void SharedMemory::setLaserPort(string value) {
    do
    {
    } while (!Laser_port_escribible);
    Laser_port_escribible=false;
    *laserPort = value;
    Laser_port_escribible=true;
}

string SharedMemory::getPTZPort() {
    return *PTZ_port;
}

void SharedMemory::setPTZPort(string value) {
    do
    {
    } while (!PTZ_port_escribible);
    PTZ_port_escribible=false;
    *PTZ_port = value;
    PTZ_port_escribible=true;
}
///*! \brief Gets the Lineal velocity of the robot
// *
// *  Gets the Lineal velocity of the robot \return Lineal_velocity
// */
int SharedMemory::getObjectPositionX() {
    return objectPositionX;
}

///*! \brief Sets the Lineal velocity of the robot
// *
// *  Sets the Lineal velocity of the robot
// */
void SharedMemory::setObjectPositionX(int value) {
    do
    {
    } while (!objectPositionX_escribible);
    objectPositionX_escribible=false;
    objectPositionX = value;
    objectPositionX_escribible=true;
}

///*! \brief Gets the Lineal velocity of the robot
// *
// *  Gets the Lineal velocity of the robot \rint objectPositionX;
// */
int SharedMemory::getObjectPositionY() {
    return objectPositionY;
}

///*! \brief Sets the Lineal velocity of the robot
// *
// *  Sets the Lineal velocity of the robot
// */
void SharedMemory::setObjectPositionY(int value) {
    do
    {
    } while (!objectPositionY_escribible);
    objectPositionY_escribible=false;
    objectPositionY = value;
    objectPositionY_escribible=true;
}
///*! \brief Gets the Lineal velocity of the robot
// *
// *  Gets the Lineal velocity of the robot \return Lineal_velocity
// */
double SharedMemory::getRealObjectPositionX() {
    return realObjectPositionX;
}

///*! \brief Sets the Lineal velocity of the robot
// *
// *  Sets the Lineal velocity of the robot
// */
void SharedMemory::setRealObjectPositionX(double value) {
    do
    {
    } while (!realObjectPositionX_escribible);
    realObjectPositionX_escribible=false;
    realObjectPositionX = value;
    realObjectPositionX_escribible=true;
}
///*! \brief Gets the Lineal velocity of the robot
// *
// *  Gets the Lineal velocity of the robot \return Lineal_velocity
// */
double SharedMemory::getRealObjectPositionY() {
    return realObjectPositionY;
}

///*! \brief Sets the Lineal velocity of the robot
// *
// *  Sets the Lineal velocity of the robot
// */
void SharedMemory::setRealObjectPositionY(double value) {
    do
    {
    } while (!realObjectPositionY_escribible);
    realObjectPositionY_escribible=false;
    realObjectPositionY = value;
    realObjectPositionY_escribible=true;
}
///*! \brief Gets the Lineal velocity of the robot
// *
// *  Gets the Lineal velocity of the robot \return Lineal_velocity
// */
double SharedMemory::getRealObjectPositionZ() {
    return realObjectPositionZ;
}

///*! \brief Sets the Lineal velocity of the robot
// *
// *  Sets the Lineal velocity of the robot
// */
void SharedMemory::setRealObjectPositionZ(double value) {
    do
    {
    } while (!realObjectPositionZ_escribible);
    realObjectPositionZ_escribible=false;
    realObjectPositionZ = value;
    realObjectPositionZ_escribible=true;
}

void SharedMemory::setStringDestination(string value)
{
    do
    {
    } while (!stringDestination_escribible);
    stringDestination_escribible=false;
    *stringDestination = value;
    stringDestination_escribible=true;
}

string SharedMemory::getStringDestination()
{
     return *stringDestination;
}
void SharedMemory::setTestRunning(string value)
{
    do
    {
    } while (!testRunning_escribible);
    testRunning_escribible=false;
    *testRunning = value;
    testRunning_escribible=true;
}

string SharedMemory::getTestRunning()
{
     return *testRunning;
}

void SharedMemory::setGestureDepthPosition(int value)
{
    do
    {
    } while (!gestureDepthPosition_escribible);
    gestureDepthPosition_escribible=false;
    gestureDepthPosition = value;
    gestureDepthPosition_escribible=true;
}

int SharedMemory::getGestureDepthPosition()
{
     return gestureDepthPosition;
}

void SharedMemory::setActionCalibration(bool value)
{
    do
    {
    } while (!doCalibration_escribible);
    doCalibration_escribible=false;
    doCalibration = value;
    doCalibration_escribible=true;
}
bool SharedMemory::getActionCalibration()
{
     return doCalibration;
}
void SharedMemory::setNumberOfUsersToLearn(int value)
{
    do
    {
    } while (!numberOfUsersToLearn_escribible);
    numberOfUsersToLearn_escribible=false;
    numberOfusersToLearn = value;
    numberOfUsersToLearn_escribible=true;
}
int SharedMemory::getNumberOfUsersToLearn()
{
     return numberOfusersToLearn;
}
void SharedMemory::addUser(const Objective &value)
{
    do
    {
    } while (!usersList_escribible);
    usersList_escribible=false;
    users->push_back(value);
    usersList_escribible=true;
}
Objective SharedMemory::getUser(int i)
{
return users->at(i);
}

