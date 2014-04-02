
#include "Objective.h"

bool name_escribible=true;
bool visualIDobj_escribible=true;
bool Type_escribible=true;
bool objectivePosition_escribible=true;


bool order_escribible=true;

///*! \brief Gets the Visual_ID of the objective
// *
// *  Gets the Visual_ID of the objective \return Visual_ID
// */
int Objective::getVisualID() {
    return visualID;
}

///*! \brief Sets the visual_ID of the objective
// *
// *  Sets the visual_ID of the objective
// */
void Objective::setVisualID(int value) {
    do
    {
    } while (!visualIDobj_escribible);
    visualIDobj_escribible=false;
    visualID = value;
    visualIDobj_escribible=true;
}

///*! \brief Gets the type of the objective
// *
// *  Gets the type of the objective person, object \return Type
// */
string Objective::getType() {
    return *type;
}

///*! \brief Sets the type of the objective
// *
// *  Sets the type of the objective person, object
// */
void Objective::setType(string value) {
    if (type==NULL) type=new string;
    *type = value;
}

///*! \brief Gets the last_x of the objective
// *
// *  Gets the last X position of the objective \return Last_x
// */
Location Objective::getObjetivePosition() {
    return objectivePosition;
}

///*! \brief Sets the position of the robot
// *
// *  Sets the position of the robot (x, y, angle)
// */
void Objective::setObjectivePosition(Location value) {
    {
    } while (!objectivePosition_escribible);
    objectivePosition_escribible=false;
    objectivePosition = value;
    objectivePosition_escribible=true;
}

///*! \brief Gets the name of the objective
// *
// *  Gets the name of the objective \return Name
// */
string Objective::getName() {
    return *Name;
}

///*! \brief Sets the name of the objective
// *
// *  Sets the name of the objective
// */
void Objective::setName(string value) {
    do
    {
    } while (!name_escribible);
    name_escribible=false;
    if (Name==NULL) Name=new string;
    *Name = value;
    name_escribible=true;
}

///*! \brief Gets the name of the objective
// *
// *  Gets the order of the objective \return order
// */
string Objective::getOrder() {
    return *order;
}

///*! \brief Sets the name of the objective
// *
// *  Sets the order of the objective
// */
void Objective::setOrder(string value) {
    do
    {
    } while (!order_escribible);
    order_escribible=false;
    if (order==NULL) order=new string;
    *order = value;
    order_escribible=true;
}

