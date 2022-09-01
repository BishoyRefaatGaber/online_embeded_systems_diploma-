#include "Headers.h"


enum DC_STATE DC_STATUS;
int Speed = 0;

void (*DC_STATE)();

void DC_INIT(){
	printf("DC_INIT\n");
}

void DC_motor(int S){
	Speed = S;
	DC_STATE = STATE_CASE(_DC_BUSY);
	printf("CA -----speed=%d-----> DC\n",Speed);

}


STATE_define(_DC_IDLE){
	//state name
	DC_STATUS = DC_IDLE;

	printf("DC_IDLE_State : speed = %d \n",Speed);
};
STATE_define(_DC_BUSY){
	//state name
		DC_STATUS = DC_BUSY;
		DC_STATE = STATE_CASE(_DC_IDLE);
		printf("DC_BUSY_State : speed = %d \n",Speed);

};

















