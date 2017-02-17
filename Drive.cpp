#include "Drive.h"
Servo control_servo;

void driveSetup(){
  pinMode(VELOCITY, OUTPUT);
  pinMode(REVERSE, OUTPUT);
  pinMode(FORWARD, OUTPUT);
  control_servo.attach(CONTROL_SERVO);
}


//GEAR 
void runCMD(String c){
    if (c.equalsIgnoreCase("stop"))
      calm(0);
    else if (c.equalsIgnoreCase("forward"))
      forward(0);
    else if (c.equalsIgnoreCase("back"))
      reverse(0);
}

//STEERING
void runST(int s){ 
    control_servo.write(s);
    Serial.print("Servo: " + String(s) + "\r\n");
 }

//THOTTLE
void runTH(int t){
    analogWrite(VELOCITY, t);
    Serial.print("Speed: " + String(t) + "\r\n");
}


void calm(int d){
	Serial.println("Stop");
	digitalWrite(REVERSE, LOW);
	digitalWrite(FORWARD, LOW);
	delay(d * 100);
}

void reverse(int d){
	Serial.println("REVERSE");
	digitalWrite(REVERSE, HIGH);
	digitalWrite(FORWARD, LOW);
	delay(d * 100);
}

void forward(int d){
	Serial.println("Forward");
	digitalWrite(REVERSE, LOW);
	digitalWrite(FORWARD, HIGH);
	delay(d * 100);
}

