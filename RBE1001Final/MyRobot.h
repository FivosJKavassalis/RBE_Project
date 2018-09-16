#pragma once

#include "Servo.h" // Servo library
#include <DFW.h> // DFW library

class Base {
private:
	Servo leftmotor; // left motor
  Servo rightmotor; // right motor
  
public:
	void initializeBase(unsigned armMotorPin, unsigned armPotPin); // starts the base
	void robotShutdownFunction(void); // robot shut down (post auto and post tele-op)
  void driverop(unsigned leftjoyval, unsigned rightjoyval); // driver operation
  void linefollow(void); // line following UNUSED
  void motorstop(void); // stops the chassis
  void goramp(void); // auto ramp function
  void gobackwardsreallyfingfastuptheramp(unsigned speedbutton); // PERCH hook function
};

Base getBase();

class Arm {
  private:
    Servo arm; // arm motor
    Servo intake; // intake motor

  public:
    void initializeArm(unsigned armPin, unsigned intakePin, unsigned potPin); // starts the arm
    void armop(unsigned r1val, unsigned r2val, unsigned l1val, unsigned l2val); // tele-op arm code
    void setposition(unsigned armposition); // sets the arm to a specific position UNUSED
    void armstop(void);
};

Arm getArm();

