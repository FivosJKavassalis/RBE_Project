#include "MyRobot.h" // MyRobot header file
#include "Arduino.h" // arduino library
#include <DFW.h> // DFW library

/**
 * These are the execution runtions
 */
 
void Base::initializeBase(unsigned leftPin, unsigned rightPin) { // starts the base 
  leftmotor.attach(leftPin, 1000, 2000);
  rightmotor.attach(rightPin, 1000, 2000);
}

void Arm::initializeArm(unsigned armPin, unsigned intakePin, unsigned potPin) { // Starts the arm
  arm.attach(armPin, 1000, 2000);
  intake.attach(intakePin, 1000, 2000);
}

void Base::driverop(unsigned leftjoy, unsigned rightjoy){ //Driver control of base
  rightmotor.write(180 - leftjoy);     
  leftmotor.write(rightjoy);
}

void Arm::armop(unsigned liftup, unsigned liftdown, unsigned intakein, unsigned intakeout){ // Driver control of arm and intake
    if (liftup == 1 && liftdown == 0) {
      arm.write(180);
    }
    if (liftdown == 1 && liftup == 0) {
      arm.write(0); 
    }
    if (liftdown == 0 && liftup == 0) {
      arm.write(90);
    }
    if (intakein == 1 && intakeout == 0) {
      intake.write(180);
    }
    if (intakeout == 1 && intakein == 0) {
      intake.write(0);
    }
    if (intakeout == 0 && intakein == 0) {
      intake.write(90);
    }
}

void Base::robotShutdownFunction(void){ // robot shut down
  Serial.println("Here is where I shut down my robot code");
}

void Base::linefollow(void) { // line follower UNUSED
  int leftPhoto = digitalRead(23);
  int rightPhoto = digitalRead(22);
  int bumper = digitalRead(28);
  if (leftPhoto == 0) { // leftphoto sees the carpet
    rightmotor.write(120);
  }
  if (rightPhoto == 0) { // rightphot on carpet
    leftmotor.write(60);
  }
  if (leftPhoto == 1) { // left on tape
    rightmotor.write(90);
    leftmotor.write(40);
  }
  if (rightPhoto == 1) { // right on tape
    leftmotor.write(90);
    rightmotor.write(140);
  }
  leftPhoto = digitalRead(23);
  rightPhoto = digitalRead(22);
  bumper = digitalRead(28);
  Serial.println(bumper);
  if (bumper == 0) { // stop with a bump sensor
    Base::motorstop();
  }
}

void Arm::setposition(unsigned desiredpot) { // Sets the arm to a specific position UNUSED
  int armPotval = analogRead(5);
  int error = armPotval - desiredpot;
  while(abs(error) > 100) {
     if(armPotval != desiredpot) {  
       error = armPotval - desiredpot;
       arm.write(150 - 0.3*error);
       armPotval = analogRead(5);
      }
  }
  arm.write(90);
}

void Base::motorstop() { // stops the base
  leftmotor.write(90);
  rightmotor.write(90);
}

void Arm::armstop() { // stops the arm
  intake.write(90);
  arm.write(90);
}

void Base::goramp() { // auto-code to drive up the ramp and stop
  int leftPhotor = digitalRead(23);
  
  int rightPhotor = digitalRead(22);
  int bumperr = digitalRead(28);

  if (leftPhotor == 0 && rightPhotor == 0) { // left and right photo on carpet
    rightmotor.write(120);
    leftmotor.write(60);
  }
  if (leftPhotor == 1 && rightPhotor == 0) { // left on carpet and right on tape
    leftmotor.write(90);
    rightmotor.write(120);
  }
  if (rightPhotor == 1 && leftPhotor == 0) { // right on carpet and left on tape
    rightmotor.write(90);
    leftmotor.write(60);
  }
  if (rightPhotor == 1 && leftPhotor == 1) { // right and left on tape
    leftmotor.write(40);
    rightmotor.write(140);
  }
  leftPhotor = digitalRead(23);
  rightPhotor = digitalRead(22);
  bumperr = digitalRead(28);
  if (bumperr == 0){ // tilt sensor is hit
    Base::motorstop();
  }
}

void Base::gobackwardsreallyfingfastuptheramp(unsigned fullspeedahead){ // runs up the ramp really fast to hook the PERCH
  if (fullspeedahead == 1){
    leftmotor.write(180); // gotta go fast
    rightmotor.write(0);
  }
}
