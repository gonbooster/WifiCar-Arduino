#include "Drive.h"
#include "RC.h"

void setup()
{

	Serial.begin(19200); 
	Serial.println("Setup begin...");
  //DRIVE SETUP
  driveSetup();
  Serial.println("Setup end...");

}

void loop() 
{
  RC();
}
