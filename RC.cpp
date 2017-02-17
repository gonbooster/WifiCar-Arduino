#include "RC.h"
#include "Drive.h"

int chS;
int chT;
int steering_value = 0;
int thottle_value = 0;


void RC()
{
  steering();
  thottle();
}

void getPulse_T(int d){
  chT = pulseIn(CHN_THROTTLE, HIGH);
  Serial.println("chT: " + String(chT));
  delay(1000* d);
}

void getPulse_S(int d){
  chS = pulseIn(CHN_STEERING, HIGH);
  Serial.println("chnS: " + String(chS));
  delay(1000* d);
}

void steering()
{
  getPulse_S(0);
	if (chS >= (S_MIN - S_DEADBAND) && chS <= (S_MAX + S_DEADBAND))
	{
		steering_value = map(chS, (S_MIN - S_DEADBAND), (S_MAX + S_DEADBAND), CONTROL_MIN, CONTROL_MAX);

		if (steering_value > CONTROL_MIN && steering_value < CONTROL_MAX){//Evitamos valores negativos.    
			runST(steering_value);
		}
	}
}

void thottle()
{
  getPulse_T(0);
	if ((chT >= (T_NEUTRAL - T_DEADBAND)) && (chT <= (T_NEUTRAL + T_DEADBAND))){ // MID
		calm(0);
		runTH(0);
	}
	else if ((chT > (T_NEUTRAL + T_DEADBAND)) && (chT <= (T_MAX + T_DEADBAND))){
    forward(0);
		thottle_value = map(chT, (T_NEUTRAL + T_DEADBAND + 1), (T_MAX + T_DEADBAND), SPEED_MIN, SPEED_MAX);
		runTH(thottle_value);
	}
	else if ((chT >= (T_MIN - T_DEADBAND)) && (chT < (T_NEUTRAL - T_DEADBAND))){
  reverse(0);
		thottle_value = map(chT, (T_NEUTRAL - T_DEADBAND - 1), (T_MIN - T_DEADBAND), SPEED_MIN, SPEED_MAX);
		runTH(thottle_value);
	}
}

