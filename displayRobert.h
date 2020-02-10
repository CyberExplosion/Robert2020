#ifndef DISPLAYROBERT_H
#define DISPLAYROBERT_H
#include "vex.h"
#include "vex_controller.h"
class displayRobert
{
private:

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

int displayInfo = 0;

public:
displayRobert(vex::motor _LM1,vex::motor _LM11,
vex::motor _LM2,vex::motor _LM21,
vex::motor _RM1,vex::motor _RM11,
vex::motor _RM2,vex::motor _RM21,
vex::motor _Elevator,vex::motor _Elevator1, vex::motor _Elevator2,
vex::controller _Controller1);

void display(int choice);
int screenSelect(int max);
void velocityDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21);
void clearscreen();    
void rotationDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21);
void currentDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21);
void powerDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21);
void torqueDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21);
void efficiencyDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21);
void temperatureDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21);
void batteryDisplay();    

};

#endif