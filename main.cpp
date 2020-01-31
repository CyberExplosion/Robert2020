/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       El Camino College Robotics                                */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Robert        FORKLIFT
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include "autonomousRobert.h"
#include <algorithm>
#include <cmath>
using namespace vex;
vex::motor RM1 = vex::motor(vex::PORT10, false);
vex::motor RM11 = vex::motor(vex::PORT9, true);

vex::motor RM2 = vex::motor(vex::PORT20, false);
vex::motor RM21 = vex::motor(vex::PORT19, true);

vex::motor LM1 = vex::motor(vex::PORT15, true);
vex::motor LM11 = vex::motor(vex::PORT16, false);

vex::motor LM2 = vex::motor(vex::PORT13, true);
vex::motor LM21 = vex::motor(vex::PORT12, false);


vex::controller Controller2 = vex::controller();
vex::motor Elevator = vex::motor(vex::PORT5, false);
vex::motor Elevator1 = vex::motor(vex::PORT6, true);
vex::motor Elevator2 = vex::motor(vex::PORT7, true);

// A global instance of competition
competition Competition;
// define your global instances of motors and other devices here
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton(void) {
// Initializing Robot Configuration. DO NOT REMOVE!
vexcodeInit();
// All activities that occur before the competition starts
// Example: clearing encoders, setting servo positions, ...
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void autonomous(void) {
autonomousRobert newRobert(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21);

}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
// User control code here, inside the loop
while (1) {
  // This is the main execution loop for the user control program.
  // Each time through the loop your program should update motor + servo
  // values based on feedback from the joysticks.
  // ........................................................................
  // ........................................................................
  // drivetrain
 LM2.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
LM21.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
LM1.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
LM11.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
RM2.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
RM21.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
RM1.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
RM11.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
  int speed = 100;

  // lift
  if (Controller2.ButtonL2.pressing()) {
    Elevator.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
    Elevator1.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
    Elevator2.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  } else if (Controller2.ButtonL1.pressing()) {
    Elevator.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
    Elevator1.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
    Elevator2.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
  } else {
    Elevator.stop(vex::brakeType::hold);
    Elevator1.stop(vex::brakeType::hold);
    Elevator2.stop(vex::brakeType::hold);
  }
  //wheel popping
  if (Controller2.ButtonB.pressing()) {
  LM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  vex::task::sleep( 550 );
  LM1.stop();
  LM11.stop();
  LM2.stop();
  LM21.stop();
RM1.stop();
RM11.stop();
RM2.stop();
RM21.stop();
LM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
LM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
LM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
LM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
RM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
RM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
vex::task::sleep( 500 );
LM1.stop();
LM11.stop();
LM2.stop();
LM21.stop();
RM1.stop();
RM11.stop();
RM2.stop();
RM21.stop();
  }

  if (Controller2.ButtonA.pressing()) {
  LM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  vex::task::sleep( 550 );
  LM1.stop();
  LM11.stop();
  LM2.stop();
  LM21.stop();
RM1.stop();
RM11.stop();
RM2.stop();
RM21.stop();
LM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
LM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
LM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
LM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
RM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
RM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
RM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
RM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
vex::task::sleep( 500 );
LM1.stop();
LM11.stop();
LM2.stop();
LM21.stop();
RM1.stop();
RM11.stop();
RM2.stop();
RM21.stop();
  }
  
  vex::task::sleep(20); // Sleep the task for a short amount of time to
                        // prevent wasted resources.
}
vexcodeInit();
}
//     wait(20, msec); // Sleep the task for a short amount of time to
//                     // prevent wasted resources.
//   }
// }
//
// Main will set up the competition functions and callbacks.
//
int main() {
// Set up callbacks for autonomous and driver control periods.
Competition.autonomous(autonomous);
Competition.drivercontrol(usercontrol);
// Run the pre-autonomous function.
pre_auton();
// Prevent main from exiting with an infinite loop.
while (true) {
  wait(100, msec);
}
}
 

