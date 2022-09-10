#include "Headers.h"
#include "main.h"

vuint_32 PVal;
int main (){
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(OFF);
	while (1){

		PVal = getPressureVal();
		if (PVal > Threshold){
			High_Pressure_Detected();
		}
		Delay(1000);
	}


}
