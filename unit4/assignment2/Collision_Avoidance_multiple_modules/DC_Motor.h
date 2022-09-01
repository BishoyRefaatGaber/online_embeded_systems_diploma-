#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "stdio.h"
#include "stdlib.h"
#include "state.h"
enum DC_STATE{
	DC_IDLE,
	DC_BUSY
};

STATE_define(_DC_IDLE) ;
STATE_define(_DC_BUSY) ;
void DC_INIT();
#endif
