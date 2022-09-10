#include "Headers.h"

void High_Pressure_Detected(){
	Set_Alarm_actuator(ON);
	Delay(1000);
	Set_Alarm_actuator(OFF);

}
