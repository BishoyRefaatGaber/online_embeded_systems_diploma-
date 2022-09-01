#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_
#include "stdio.h"
#include "stdlib.h"
enum STATE{
	CA_waiting,
	CA_driving
};

void ST_CA_waiting();
void ST_CA_driving();
#endif /* COLLISION_AVOIDANCE_H_ */
