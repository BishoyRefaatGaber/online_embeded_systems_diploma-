#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_
#include "stdio.h"
#include "stdlib.h"
#include "state.h"
enum CA_STATE{
	CA_waiting,
	CA_driving
};

STATE_define(_CA_waiting);
STATE_define(_CA_driving);

#endif /* COLLISION_AVOIDANCE_H_ */
