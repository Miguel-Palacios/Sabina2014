#include <iostream>
#include <pthread.h>
#include <vector>

#include "kintoarmtransf.h"

//#include "../Gui/gui.h"
//#include "../Gui/tab.h"
//#include "../Gui/console.h"
#include "../Plugin_API/pluginapi.h"
#include "../SharedMemory/SharedMemory.h"

#include "armkatana.h"
#include "armkatanaforsabina.h"

//#include "../MDP/MDP.h"


SharedMemory *sharedMemory;
//Tab *pluginTab;
//Console *logTerminal;

#define PLUGIN_NAME "Manipulacion"

/**
 * @brief Manipulacion plugin
 *
 * This plugin is used for object manipulation using the Katana 6M arm.
 * @author     Patrick Heyer, patrickhey@prodigy.net.mx, Irving V&aacute;squez ivasquez@inaoep.mx
 * @date       jul 04, 2012
 * @version    1.0
 **/
class Manipulacion : public IPlugin
{
public:
    void Main();
    void stop();
    void run();
};

PLUGIN_FUNC IPlugin *CreatePlugin()
{
    return new Manipulacion;
}

PLUGIN_FUNC void DestroyPlugin(IPlugin *r)
{
    delete r;
}

PLUGIN_DISPLAY_NAME(PLUGIN_NAME);

PLUGIN_INIT()
{
    // register our new plugin
    RegisterPlugin(PLUGIN_NAME, CreatePlugin, DestroyPlugin);
    return 0;
}

void Manipulacion::Main()
{
    /**
     * \sa cambiar_estado
     **/
    //Gui::getInstance();
    //pluginTab = new Tab("Manipulacion");
    //logTerminal = new Console(0,HEIGHT*.02,500,HEIGHT/2,"error", pluginTab);
    ArmKatanaForSabina brazo;
    brazo.init( "192.168.168.232", "../data/configfiles450/katana6M180_G.cfg");
    
    if (sharedMemory->getInstance().getActionCalibration())
    brazo.calibrate();
    
    sleep(5);
    brazo.setVelocity(20);
    brazo.moveToHanging();
    brazo.moveToCarriyingPos();
    
    

    std::string action;
    for (;;)
    {
        action=sharedMemory->getInstance().getAction();
        if(action=="graspObject")
        {

	   KinToArmTransf T;
	  cout<<"Starting: "<< action << "STATE in Manipulation"<<endl;  	  
           //parametros calculados el dia 9 de diciembre de 2013
	  //ANGLE- angulo medidoS
	  #define ANGLE 90
	  //TODO Hacer cambio de coordenada
	  T.setKinectPosition(-.140,0,-.130,(ANGLE-0)*3.1416/180);
    
	  float x,y,z;
	  T.tranformToArm(sharedMemory->getInstance().getRealObjectPositionX(),sharedMemory->getInstance().getRealObjectPositionY(), sharedMemory->getInstance().getRealObjectPositionZ(), x,y,z);
          brazo.moveToCarriyingPos();
// 	  x=x*1000;
// 	  y=y*1000;
// 	  z=z*1000;
	  std::cout << "intentare agarrar el objeto en " <<  x << "    " << y << "    " << z << "MILIMETROS" << std::endl;
         // brazo.testGrasping(0, 180,  500);
	  //sleep(4);
	  //brazo.testGrasping(0, -180,  500);
	  
	  brazo.Grasping(0,y,z);
	  //brazo.openGripper();
	  //sleep(4);	
	  sharedMemory->getInstance().sintetizer.set_Phrase("I have it");
	  //brazo.closerGripper();
	  sleep(2);
	  brazo.moveToCarriyingPos();
	  
	  
          
	 // if (sharedMemory->getInstance().testRunning->compare("pick and place")==0){
	    //Aqui debe indicarse la posición en donde se encuentra la categoria del objeto agarrado
	  
	    if (sharedMemory->getInstance().getTestRunning()=="Emergency"){
	      //TODO destino predefinido hay que cambiarlo según la prueba emergency, puede establecerse desde el archivo de configutación
	      sharedMemory->getInstance().setStringDestination("bedroom1");
	      sharedMemory->getInstance().setAction("navigateToObjectCategory");
	    }else if (sharedMemory->getInstance().getTestRunning()=="CocktailParty"){
	      //TODO destino predefinido hay que cambiarlo según la prueba, puede establecerse desde el archivo de configutación
	      //o segun el punto donde encontró al usuario.
	      sharedMemory->getInstance().setStringDestination("living");
	      sharedMemory->getInstance().setAction("navigateToObjectCategory");
	    }else{
	      //TODO destino predefinido hay que cambiarlo según la prueba, puede establecerse desde el archivo de configutación
	      sharedMemory->getInstance().setStringDestination("dining");
	      sharedMemory->getInstance().setAction("navigateToObjectCategory");
	    }
	    
	    
	    
	 // }else{
	   // sharedMemory->getInstance().stringDestination = (string*) "living";
	    //sharedMemory->getInstance().setAction("navegar");
	 // }
          // cambiar_estado("ruta_planeada", "no");
          // cambiar_estado("destino_alcanzado", "no");
	  //TODO Llamado al método de MDP (en estos momentos no existe).
          // sharedMemory->getInstance().setAction(cambiar_estado("objeto_sujeto","si"));
	    

        }
        else if(action=="giveObject")
        {
	cout<<"Starting: "<< action << " STATE in Manipulation"<<endl;  
            sharedMemory->getInstance().sintetizer.set_Phrase("here is a little present so you remember your visit");
            sleep(5);
            brazo.deliverObject();
            sharedMemory->getInstance().sintetizer.set_Phrase("please let me introduce myself i am Sabina a service robot developed at the INAOE by the team Markovito that won the mexican tournament of robotics two thousand 13");
            brazo.moveToHanging();
            //Cuando se tengan que entregar varios objetos no usar store
            //brazo.store();
            sharedMemory->getInstance().setAction("getInto");

        }
        else if(action=="deliverObject")
        {
	  cout<<"Starting: "<< action << " STATE in Manipulation"<<endl;  
	    sharedMemory->getInstance().sintetizer.set_Phrase("Delivering object");
	    sleep(2);
	    string phrase;
	    if (sharedMemory->getInstance().getTestRunning()=="Emergency" || sharedMemory->getInstance().getTestRunning()=="CocktailParty"){
	      phrase= sharedMemory->getInstance().getLastObjective().getName() + " Please take the "+ sharedMemory->getInstance().getLastObjective().getOrder()+ " from my gripper";
	    }else
	      phrase= "This is the right position for the "+ sharedMemory->getInstance().getRequestedObject();
	    
	    cout<< "FRASE " << phrase<<endl;
	    sharedMemory->getInstance().sintetizer.set_Phrase(phrase);
	    sleep(3);
	    
	    brazo.deliverObject();
            brazo.moveToCarriyingPos();
	    brazo.closerGripper();;
            //brazo.moveToHanging();
            //Cuando se tengan que entregar varios objetos no usar store
            //brazo.store();
	    if (sharedMemory->getInstance().getTestRunning()=="Emergency"){
	      sharedMemory->getInstance().setStringDestination("entrance");
	      sharedMemory->getInstance().setAction("navigateToEntrance");
	      
	    }else if (sharedMemory->getInstance().getTestRunning()=="CocktailParty"){
	     
	      if (sharedMemory->getInstance().getNumberOfUsersToLearn()==sharedMemory->getInstance().getLastObjective().getVisualID()){
		sharedMemory->getInstance().setStringDestination("Exit");
		sharedMemory->getInstance().setAction("navigateTo");
	      }else{
		  //TEST Destino predefinido en donde se encuentran los objetos
		  sharedMemory->getInstance().setStringDestination("Kitchen");
		  sharedMemory->getInstance().setAction("navigateToObject");
	      }
	      
	    }else{
              phrase= sharedMemory->getInstance().getTestRunning()+" has been finished";
	      cout<< "FRASE " << phrase<<endl;
	      sharedMemory->getInstance().sintetizer.set_Phrase(phrase);
	      sleep(2);
	      sharedMemory->getInstance().setAction("requestCommand");
	   }

        }
        
    }
}

void Manipulacion::run()
{
    pthread_create(&thread_id, NULL, &IPlugin::IncWrapper, this);
}

void Manipulacion::stop()
{

}


