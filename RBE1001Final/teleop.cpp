#include <DFW.h> // DFW library
#include "MyRobot.h" // MyRobot header file

void teleop( long time,DFW & dfw) { // function definition
	Serial.print("\r\nTeleop time remaining: ");
	Serial.print(time);
	Serial.print("\tright joystick: ");
	Serial.print(dfw.joystickrv());
	Serial.print("\tleft joystick: ");
	Serial.println(dfw.joysticklv());
 
	//Run functions in the robot class
  
  getBase().driverop(dfw.joysticklv(), dfw.joystickrv()); // running the chassis
  getArm().armop(dfw.one(), dfw.three(), dfw.l1(), dfw.l2()); // running the arm
  getBase().gobackwardsreallyfingfastuptheramp(dfw.two()); // running the base to get up the ramp and hook onto the PERCH
}
