// RC.h

#ifndef _RC_h
#define _RC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define CHN_STEERING A0
#define CHN_THROTTLE A1

#define T_NEUTRAL 1498
#define T_MAX 1810
#define T_MIN 1152
#define T_DEADBAND 20

#define S_NEUTRAL 1485
#define S_MAX 2010
#define S_MIN 1014
#define S_DEADBAND 20

#define SPEED_MIN 0
#define SPEED_MAX 255

#define CONTROL_MIN 0
#define CONTROL_MAX 179

void RC();
void steering();
void thottle();
void getPulse_T(int d);
void getPulse_S(int d);

#endif

