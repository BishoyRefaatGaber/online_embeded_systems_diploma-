#include "Collision_Avoidance.h"
int Distance_Random (int l ,int r ,int count);
enum STATE CA_STATUS;
int Speed = 0;
int Distance = 0;
int Threshold = 50;

void (*CA_STATE)();

void ST_CA_waiting(){
	//state name
	CA_STATUS = CA_waiting;
	//state action
	Speed = 0;
	//DC_Motor
	//Get_Distance
	Distance = Distance_Random (45,55,1);
	//event check
	(Distance <= Threshold)?(CA_STATE = ST_CA_waiting) : (CA_STATE = ST_CA_driving);
	printf("CA_Waiting_State : Distance = %d , Speed = %d\n",Distance,Speed);

};
void ST_CA_driving(){
	//state name
		CA_STATUS = CA_driving;
		//state action
		Speed = 30;
		//DC_Motor
		//Get_Distance
		Distance = Distance_Random (45,55,1);
		//event check
		(Distance <= Threshold)?(CA_STATE = ST_CA_waiting) : (CA_STATE = ST_CA_driving);
		printf("CA_Driving_State : Distance = %d , Speed = %d\n",Distance,Speed);


};

int Distance_Random (int l ,int r ,int count){
	int i ;
	for(i = 0 ; i < count ; i++){
		int  rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
return 0;

}














