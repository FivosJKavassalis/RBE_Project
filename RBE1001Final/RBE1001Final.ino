/* 
 * 4/28/17
 * RBE 1001 Final Code
 * Kyle Heavey, Jivan Purutyan, and Fivos Kavassalis
 * This is our final code for our RBE 1001 Final, D term 2017
 * Made for the Robot "Penny" (Short for Penitentiary. She loves the name, don't worry)
 * Based on the Template given in class, availible through the DFW library
 */
 
#include <DFW.h> // DFW Library
#include "MyRobot.h" // includes MyRobot header file

int ledpindebug = 13; //Wireless controller Debug pin. If lit then there is no communication.
const int rightphotopin = 22;
const int leftphotopin = 23;
const int tiltpin = 28;
DFW dfw(ledpindebug, autonomous, teleop,robotShutdown); // Instantiates the DFW object and setting the debug pin. The debug pin will be set high if no communication is seen after 2 seconds

Base myBase;
Arm myArm;

void setup() {
	Serial.begin(9600); // Serial output begin. Only needed for debug
	dfw.begin(); // Serial 1 output begin for DFW library. Buad and port #."Serial 1 only"
	myBase.initializeBase(6, 7);
  myArm.initializeArm(8, 9, 13);
  pinMode(rightphotopin, INPUT); //photoresistor 1 (right)
  pinMode(leftphotopin, INPUT); //photoresistor 2 (left)
  pinMode(tiltpin, INPUT_PULLUP); // tilt sensor
}
void loop() {
	dfw.run();
}

void robotShutdown(void){
	// this function shuts down your robot
  myBase.motorstop(); // stops the chassis
  myArm.armstop(); // stops the arm
	myBase.robotShutdownFunction();
}

Base getBase(){
  return myBase;
}

Arm getArm(){
  return myArm;
}

