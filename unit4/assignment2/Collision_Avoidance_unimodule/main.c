#include "Collision_Avoidance.h"
extern void (*CA_STATE)();

void setup(){

	//init all drivers
	//init IRQ
	//init HAL
	//init Bleck
	//init pointers
	CA_STATE = ST_CA_waiting;


}
int main (){
	setup();
while(1){
	CA_STATE();
}
	return 0;
}
