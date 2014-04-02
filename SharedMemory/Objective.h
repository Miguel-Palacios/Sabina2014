#ifndef _OBJECTIVE_H
#define _OBJECTIVE_H


#include <string>
#include "Location.h"
using namespace std;

///*! \brief Contains a mixture of information
// *
// *  Contains a mixture of information about objects or persons the robot
// *  has seen but that where irelevant at that moment but could be usefull
// *  in the future
// */
class Objective {
private:
    ///*! \brief Name of the Objective
    // *
    // *
    // */
    string * Name;

    ///*! \brief Visual_ID of the Objective
    // *
    // *  Visual_ID of the Objective given by the vision system
    // */
    int visualID;

    ///*! \brief Type of the Objective
    // *
    // *  Type of the Objective person object or any new type
    // */
    string * type;

    ///*! \brief Last location where the Objective was seen
    // *
    // *
    // */
    Location objectivePosition;
    
     ///*! \brief Order of the Objective (if is a person type)
    // *
    // *
    // */
    string * order;


public:
    ///*! \brief Gets the Visual_ID of the objective
    // *
    // *  Gets the Visual_ID of the objective \return Visual_ID
    // */
    int getVisualID();

    ///*! \brief Sets the visual_ID of the objective
    // *
    // *  Sets the visual_ID of the objective
    // */
    void setVisualID(int value);

    ///*! \brief Gets the type of the objective
    // *
    // *  Gets the type of the objective person, object \return Type
    // */
    string getType();

    ///*! \brief Sets the type of the objective
    // *
    // *  Sets the type of the objective person, object
    // */
    void setType(string  value);

    ///*! \brief Gets the last_x of the objective
    // *
    // *  Gets the last X position of the objective \return Last_x
    // */
    Location getObjetivePosition();

    ///*! \brief Sets the last_x of the objective
    // *
    // *  Sets the last X position of the objective
    // */
    void setObjectivePosition(Location value);

    ///*! \brief Gets the name of the objective
    // *
    // *  Gets the name of the objective \return Name
    // */
    string getName();

    ///*! \brief Sets the name of the objective
    // *
    // *  Sets the name of the objective
    // */
    void setName(string value);
    
     ///*! \brief Gets the name of the objective
    // *
    // *  Gets the name of the objective \return Name
    // */
    string getOrder();

    ///*! \brief Sets the name of the objective
    // *
    // *  Sets the name of the objective
    // */
    void setOrder(string value);

    friend class Robot;
};
#endif
