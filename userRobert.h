#ifndef USERROBERT_H
#define USERROBERT_H
#include "vex.h"

class userRobert
{
private:
int slow=60;
int fast=100;
int slower=15;

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

public:
userRobert(vex::motor _LM1,vex::motor _LM11,
vex::motor _LM2,vex::motor _LM21,
vex::motor _RM1,vex::motor _RM11,
vex::motor _RM2,vex::motor _RM21,
vex::motor _Elevator,vex::motor _Elevator1, vex::motor _Elevator2,
vex::controller _Controller1);

void userWheelFwd( vex::motor LM1,vex::motor LM11,
                    vex::motor LM2,vex::motor LM21,
                    vex::motor RM1,vex::motor RM11,
                    vex::motor RM2,vex::motor RM21, int speed);

void userWheelStop(vex::motor LM1,vex::motor LM11,
                    vex::motor LM2,vex::motor LM21,
                    vex::motor RM1,vex::motor RM11,
                    vex::motor RM2,vex::motor RM21);

void userWheelPoppingRev(vex::motor LM1,vex::motor LM11,
                          vex::motor LM2,vex::motor LM21,
                          vex::motor RM1,vex::motor RM11,
                          vex::motor RM2,vex::motor RM21, int speed);

void userWheelPoppingFwd(vex::motor LM1,vex::motor LM11,
                          vex::motor LM2,vex::motor LM21,
                          vex::motor RM1,vex::motor RM11,
                          vex::motor RM2,vex::motor RM21, int speed);
//ELEVATOR FUNCTIONS
 void userElevatorStop(vex::motor Elevator,vex::motor Elevator1, vex::motor Elevator2);
 void userElevatorRev(vex::motor Elevator,vex::motor Elevator1, vex::motor Elevator2, int speed);
 void userElevatorFwd(vex::motor Elevator,vex::motor Elevator1, vex::motor Elevator2, int speed);
//END OF ELEVATOR FUNCTIONS

 void userMoveFwd(vex::motor LM1,vex::motor LM11,
                  vex::motor LM2,vex::motor LM21,
                  vex::motor RM1,vex::motor RM11,
                  vex::motor RM2,vex::motor RM21);
};

#endif