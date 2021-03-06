#include <iostream>
#include <fstream>

#include "Human.h"

Human	*Human::Singleton = 0;

Human::Human()
{
    Initialize();
}

Human::Human(const Human& other)
{

}

Human::~Human()
{

}

Human& Human::operator=(const Human& other)
{
    return *this;
}

void Human::Initialize()
{
    std::string name="headJoint";
    skeletonJoint temp;
    temp.Set_pos(0,0,-10);
//     this->Skeleton=new std::map<std::string, skeletonJoint>;
    this->Skeleton[0].insert(std::make_pair( name,temp));

}

void Human::Initialize(std::string value)
{

    std::string name;
    tracking=-1;
    this->write=false;
    int temp_ID;
    skeletonJoint temp;
    temp.Set_pos(0,0,0);
    std::ifstream myfile (value.c_str());
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            myfile >> name;
            myfile >>  temp_ID;
            temp.Set_ID(temp_ID);
            temp.Set_name(name);
	    for(int i=0; i<16; i++)
	    {
	      this->Skeleton[i].insert(std::make_pair( name,temp));
	    }
        }
        myfile.close();
    }
    gesture_detected=false;
}





Human& Human::getInstance(void )
{
    if ( Singleton == 0 )
        Singleton = new Human;

    return *Singleton;
}

void Human::freeInstance(void )
{
    if ( Singleton != 0 )
    {
        delete Singleton;
        Singleton = 0;
    }
}
