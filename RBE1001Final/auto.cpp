#include <DFW.h> // DFW library
#include "MyRobot.h" // MyRobot header file

void autonomous( long time,DFW & dfw) { // function definition
	Serial.print("\r\nAuto time remaining: ");
	Serial.print(time);
  // run functions in MyRobot.cpp in auto

  getBase().goramp(); // runs the autonomous ramp code
}
