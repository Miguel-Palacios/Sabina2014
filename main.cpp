
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <iostream>
#include <dirent.h>
#include <vector>
#include <list>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Round_Button.H>

#include "Plugin_API/coreapi.h"
#include "Plugin_API/pluginmanager.h"
#include "SharedMemory/SharedMemory.h"


#include "ThirdParty/ConfigFile.h"
#include "ThirdParty/Triplet.h"

SharedMemory *sharedMemory;

char *mdp_path;
string face_dir="";
bool Load_Face=0;
bool accept_button=0;

int test_time = 0;
int exit_time = 0;

Fl_Window win( 600,500,"Configure Test" );
Fl_Choice *Test;
Fl_Input *MDP_path;
Fl_Input *Test_time;
Fl_Input *Exit_time;
Fl_Round_Button *rbutton[250];

Fl_Round_Button *use_Face;
Fl_Round_Button *doCalibrationButton;
bool doCalibration= false;
int num_rbuttons=0;
Fl_Button *Accept;

string testRunning="none";

char* itoa(int val, int base) {
    static char buf[32] = {0};
    int i = 30;
    for(; val && i ; --i, val /= base)
        buf[i] = "0123456789abcdef"[val % base];

    return &buf[i+1];
}

void Run_test(Fl_Widget* o, void*)
{
    for(int j=0; j<num_rbuttons; j++)
    {
        if(!rbutton[j]->value())
        {
            PluginManager::getInstance().Unload(rbutton[j]->label());
        }
    }
    
    if (doCalibrationButton->value())
      doCalibration=true;  
    
    testRunning =  Test->mvalue()->label();
    
    win.hide();
    Fl::flush();
    accept_button=true;
}


void Load_test(Fl_Widget* o, void*)
{
    std::stringstream ss;
    ss << "../data/" << Test->mvalue()->label();
    std::string test_path = ss.str();
    std::cout << test_path << std::endl;

    ConfigFile config ( test_path );
    

    PluginManager::getInstance().LoadFromFile ( "../data/TEST_plugins" );

    win.begin();
    int row=0;
    int column=0;
    for( PluginManager::TListItor itor = PluginManager::getInstance().m_pluginlist.begin(); itor != PluginManager::getInstance().m_pluginlist.end(); ++itor )
    {
        rbutton[row] = new Fl_Round_Button(20+(column*170), 120+(30*row), 150, 30, (*itor)->GetDisplayName().c_str());
        num_rbuttons++;
        row++;
        if(row%10==0)
        {
            column++;
            row=0;
        }

    }



    int temp_int;
    float temp_float;
    string temp_string;
    config.readInto ( temp_string, "MDP" );
    mdp_path = new char[temp_string.length() + 1];
    //TODO revisar el copiado de esta cadena
    //strcpy ( mdp_path, temp_string.c_str() );
     temp_string.copy(mdp_path,temp_string.length() -1);
    MDP_path->value(mdp_path);

    config.readInto ( test_time, "test_time" );
    Test_time->value(itoa (test_time,10));
    config.readInto ( exit_time, "exit_time" );
    Accept= new Fl_Button( 250, 450, 100, 30, "Run Test" );
    Accept->callback(Run_test);
    o->hide();
    win.end();

}



void Load_config ( string filename )
{

    win.begin();

    Test= new Fl_Choice(80,30, 150, 30, "Test to run");
    Test_time = new Fl_Input(480, 30, 100, 30, "Test Time");
    Exit_time = new Fl_Input(480, 60, 100, 30, "Exit Time");
    MDP_path = new Fl_Input(80, 60, 150, 30, "MDP");

    std::ifstream inFile;
    std::string Test_name;



    inFile.open(filename.c_str());
    if (!inFile) {
        std::cout << "Unable to open file" <<std::endl;
    }

    while (inFile >> Test_name) {
        Test->add(Test_name.c_str(),0,NULL);
    }


    Test->value(0);
    Fl_Button load_test( 300, 30, 100, 30, "Load Test" );

    use_Face=new Fl_Round_Button(80,90, 150, 30, "With FACE");
    doCalibrationButton=new Fl_Round_Button(230, 90, 100, 30, "Arm Calibration");
   
    load_test.callback( Load_test);

    inFile.close();
    win.end();

    win.show();
    Fl::run();
    while(!accept_button)
    {

    }

}


bool polo=true;

// void DrawGLScene ( void )
// {
// 
//     if(patrol->getInstance().get_Action()=="seguir" && polo)
//     {
//         polo=false;
// 
//     }
// 
// //     if ( startButton->state && startButton->Get_Active() )
// //     {
// // 
// //         patrol->getInstance().set_Action ( cambiar_estado ( "iniciado", "si" ) );
// //         patrol->getInstance().Main_system = true;
// //         startButton->SetActive ( false );
// // 
// //     }
// 
//     std::stringstream ss;
//     ss << "minutes left: " << patrol->getInstance().test_time / 60;
//    
//  
// }


void Clear_exit()
{
    std::cout << "EXITING" << std::endl;
    PluginManager::getInstance().UnloadAll();
}

int main ( int argc, char *argv[] )
{
    Load_config ( argv[1] );
//     std::cout << "Initializing MDP" << mdp_path << endl;
//     Init_MDP ( mdp_path );
//     std::cout << "MDP loaded" << endl;

     sharedMemory->Initialize ( "../data/conf" );
    
   
    sharedMemory->getInstance().seguir = false;
    
    cout<< "**Running: "<<testRunning<<"**"<<endl;
    if (testRunning == "BFunctionalities"){
      //assume that the first test is peak and place
      sharedMemory->getInstance().setTestRunning("peak and place");
      sharedMemory->getInstance().setAction("getIntoObject");
    }else{ 
       sharedMemory->getInstance().setTestRunning(testRunning);
       
       //Emergency y Cocktail Party entran desde la puerta preguntando destino
       //puede omitirse preguntar destino para ganar tiempo
       sharedMemory->getInstance().setAction("getInto");
    }
//     
    //TEST     para probar reconocimiento de rostros
   //sharedMemory->getInstance().setAction("userLearn");
    
   //TEST para probar reconocimiento de gesto 
   //  sharedMemory->getInstance().setAction("payAttention");
    //sharedMemory->getInstance().setAction("reconocer_objetor");
     sharedMemory->getInstance().mainSystem = true;
     sharedMemory->getInstance().setRequestedObject("coke");
     //sharedMemory->getInstance().setAction("createReport");
//     //Debe ser leido desde el archivo de configuración
     sharedMemory->getInstance().setNumberOfUsersToLearn(2);
     sharedMemory->getInstance().setActionCalibration(doCalibration);
     cout << "Calibracion: "<< doCalibration << endl;
     PluginManager::getInstance().ExecuteAll();
            
   for(;;)
   {
// 	   std::cout << patrol->getInstance().get_Action() << std::endl;
   }
}
