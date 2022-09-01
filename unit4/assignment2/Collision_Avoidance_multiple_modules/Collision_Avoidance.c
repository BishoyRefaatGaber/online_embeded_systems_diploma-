#include "Headers.h"

enum CA_STATE CA_STATUS;
extern int Speed ;
extern int Distance ;
int Threshold = 50;

void (*CA_STATE)();

void US_Set_distance(int D){
	Distance = D;
	(Distance <= Threshold)?(CA_STATE = STATE_CASE(_CA_waiting) ) : (CA_STATE =  STATE_CASE(_CA_driving));
	printf("US -----distance=%d-----> CA\n",Distance);
}

STATE_define(_CA_waiting){
	//state name
	CA_STATUS = CA_waiting;

	//state action
	Speed = 0;
	//DC_Motor
	DC_motor(Speed);
	printf("CA_Waiting_State : Distance = %d , Speed = %d\n",Distance,Speed);

};
STATE_define(_CA_driving)
{
	//state name
		CA_STATUS = CA_driving;
		//state action
		Speed = 30;
		//DC_Motor
		DC_motor(Speed);
		printf("CA_Driving_State : Distance = %d , Speed = %d\n",Distance,Speed);


};












