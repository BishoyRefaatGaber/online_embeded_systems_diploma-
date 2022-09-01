#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"

#define STATE_define(_stateFUN_) void ST##_stateFUN_()
#define STATE_CASE(_stateFUN_) ST##_stateFUN_

void US_Set_distance(int D);
void DC_motor(int S);

#endif /* STATE_H_ */
