#include "HandControl.h"
#include "Robot.h"

int main(){
	Robot sabina;
	HandControl mano;
	
	//sabina.Robot_Init();
	mano.init_HandRecognizer();
	while(!mano.Kbhit()){
		mano.run_HandRecognizer();
		printf("%s", mano.getGesture().c_str());
	}
	mano.DeleteSession();
	return 0;
	}
