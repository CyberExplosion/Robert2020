#include "vex.h"
#include "autonomousRobert.h"
autonomousRobert::autonomousRobert(vex::motor _LM1,vex::motor _LM11,
vex::motor _LM2,vex::motor _LM21,
vex::motor _RM1,vex::motor _RM11,
vex::motor _RM2,vex::motor _RM21)
{
vex::motor LM1 = _LM1; //left motor 1
vex::motor LM11 = _LM11; //left motor 1 of 1

vex::motor LM2 = _LM2; 
vex::motor LM21 = _LM21;

vex::motor RM1 = _RM1; //right motor 1
vex::motor RM11 = _RM11; //right motor 1 of 1

vex::motor RM2 = _RM2;
vex::motor RM21 = _RM21;

int slow=60;

int speed = slow;
//obtain distance per second
//1000ms = 1 sec

//RESET POSITION
resetAutonPosition(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21);




//COMPETITON GRIP


//MOVING TWO BLOCKS TO THE GOAL
botBackward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 27 );


// ~33inches
strafeRight(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 1500);
// ~8inches
botForward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 220 );
// ~33inches
strafeLeft(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 1000 );
// ~8inches
botBackward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 220 );
// ~12inches
strafeLeft(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 220);
// ~48inches
botForward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 1300 );
// ~24inches
botBackward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 650 );


botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);




//ONLY GETTING ONE BLOCK 
/*
botBackward(LM1,LM11, LM2, LM21, RM1, RM11,  RM2, RM21, speed);
vex::task::sleep( 1700 );
botStop(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21);
botForward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 1000 );
botStop(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21);
botForward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
vex::task::sleep( 1000 );
botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

//OTHER CODE IF AT OTHER SIDE?

LM2forward(LM2,LM21 ,speed);
LM1reverse(LM1,LM11 ,speed);
RM1reverse(RM1,RM11 ,speed);
RM2forward(RM2,RM21 ,speed);

vex::task::sleep( 1000 );
botStop(LM1,LM11,  
 LM2, LM21,  
 RM1, RM11,  
 RM2, RM21 );

*/





}

void autonomousRobert::resetAutonPosition(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21)
{
  LM1.setPosition(0, degrees);
  LM11.setPosition(0, degrees);
  LM2.setPosition(0, degrees);
  LM21.setPosition(0, degrees);
  RM1.setPosition(0, degrees);
  RM11.setPosition(0, degrees);
  RM2.setPosition(0, degrees);
  RM21.setPosition(0, degrees);

  return;
}

//MOTOR ROTATION

//MOTOR


//STOP
void autonomousRobert::LM1stop(vex::motor LM1,vex::motor LM11 )
{
  LM1.stop();
  LM11.stop();
  return;
}

void autonomousRobert::LM2stop(vex::motor LM2,vex::motor LM21 )
{
  LM2.stop();
  LM21.stop();
  return;
}

void autonomousRobert::RM1stop(vex::motor RM1,vex::motor RM11 )
{
  RM1.stop();
  RM11.stop();
  return;
}

void autonomousRobert::RM2stop(vex::motor RM2,vex::motor RM21 )
{
  RM2.stop();
  RM21.stop();
  return;
}
//STOP

//FORWARD
void autonomousRobert::LM1forward(vex::motor LM1,vex::motor LM11 ,int speed)
{
  LM1.spin(vex::directionType::fwd,slower,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd,slower,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::LM2forward(vex::motor LM2,vex::motor LM21 ,int speed)
{
  LM2.spin(vex::directionType::fwd,slower,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd,slower,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM1forward(vex::motor RM1,vex::motor RM11 ,int speed)
{
  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM2forward(vex::motor RM2,vex::motor RM21 ,int speed)
{
  RM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}
//FORWARD


//REVERSE
void autonomousRobert::LM1reverse(vex::motor LM1,vex::motor LM11 , int speed)
{
  LM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::LM2reverse(vex::motor LM2,vex::motor LM21 , int speed)
{
  LM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM1reverse(vex::motor RM1,vex::motor RM11 , int speed)
{
  RM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM2reverse(vex::motor RM2,vex::motor RM21 , int speed)
{
  RM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}
// REVERSE


//SPIN FORWARD
void autonomousRobert::LM1spinFwd(vex::motor LM1,vex::motor LM11 , int speed)
{
  LM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::LM2spinFwd(vex::motor LM2,vex::motor LM21 , int speed)
{
  LM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM1spinFwd(vex::motor RM1,vex::motor RM11 , int speed)
{
  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM2spinFwd(vex::motor RM2,vex::motor RM21 , int speed)
{
  RM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}
// SPIN FORWARD


// SPIN REVERSE
void autonomousRobert::LM1spinRev(vex::motor LM1,vex::motor LM11 , int speed)
{
  LM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::LM2spinRev(vex::motor LM2,vex::motor LM21 , int speed)
{
  LM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM1spinRev(vex::motor RM1,vex::motor RM11 , int speed)
{
  RM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM2spinRev(vex::motor RM2,vex::motor RM21 , int speed)
{
  RM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

//ALL THE MOTORS FORWARD
void autonomousRobert::botForward(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed)
{
  LM1spinFwd(LM1,LM11,speed);
  LM2spinFwd(LM2,LM21,speed);
  RM1spinFwd(RM1,RM11,speed);
  RM2spinFwd(RM2,RM21,speed);
  return;
}

void autonomousRobert::botBackward(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed)
{
  LM1spinRev(LM1,LM11,speed);
  LM2spinRev(LM2,LM21,speed);
  RM1spinRev(RM1,RM11,speed);
  RM2spinRev(RM2,RM21,speed);
  return;
}

void autonomousRobert::botStop(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 )
{
  LM1.stop();
  LM11.stop();
  LM2.stop();
  LM21.stop();
  RM1.stop();
  RM11.stop();
  RM2.stop();
  RM21.stop();
  return;
}

void autonomousRobert::strafeLeft(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed){

  LM2spinFwd(LM2,LM21,speed);
  LM1spinRev(LM1,LM11,speed);
  RM2spinRev(RM2,RM21,speed);
  RM1spinFwd(RM1,RM11,speed);
  return;
}

void autonomousRobert::strafeRight(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed)
{
  LM2spinRev(LM2,LM21,speed);
  LM1spinFwd(LM1,LM11,speed);
  RM2spinFwd(RM2,RM21,speed);
  RM1spinRev(RM1,RM11,speed);
  return;
}

void autonomousRobert::rotateLeftBlue(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed)
{
  LM2spinRev(LM2,LM21,speed);
  LM1spinRev(LM1,LM11,speed);
  RM2spinFwd(RM2,RM21,speed);
  RM1spinFwd(RM1,RM11,speed);
  return;
}

void autonomousRobert::rotateRightRed(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed)
{
  LM2spinFwd(LM2,LM21,speed);
  LM1spinFwd(LM1,LM11,speed);
  RM2spinRev(RM2,RM21,speed);
  RM1spinRev(RM1,RM11,speed);
  return;
}

