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
#include "userRobert.h"
#include "displayRobert.h"
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


vex::controller Controller1 = vex::controller();
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
//displayRobert robertController(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21, Elevator, Elevator1, Elevator2, Controller1 );
userRobert robertControl(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21, Elevator, Elevator1, Elevator2, Controller1 );

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


//TESTING CONTROLLER DISPLAY

// Run the pre-autonomous function.
pre_auton();
// Prevent main from exiting with an infinite loop.
while (true) {
  wait(100, msec);
}
}
 
