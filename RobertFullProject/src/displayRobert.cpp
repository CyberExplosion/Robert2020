#include "vex.h"
#include "displayRobert.h"
#include "vex_controller.h"
displayRobert::displayRobert(vex::motor _LM1,vex::motor _LM11,
vex::motor _LM2,vex::motor _LM21,
vex::motor _RM1,vex::motor _RM11,
vex::motor _RM2,vex::motor _RM21,
vex::motor _Elevator,vex::motor _Elevator1, vex::motor _Elevator2,
vex::controller _Controller1)
{
vex::motor LM1 = _LM1;
vex::motor LM11 = _LM11;

vex::motor LM2 = _LM2;
vex::motor LM21 = _LM21;

vex::motor RM1 = _RM1;
vex::motor RM11 = _RM11;

vex::motor RM2 = _RM2;
vex::motor RM21 = _RM21;

vex::motor Elevator=_Elevator;
vex::motor Elevator1=_Elevator1;
vex::motor Elevator2=_Elevator2;
vex::controller Controller1= _Controller1;

displayInfo = 0;



if(Controller1.ButtonR1.pressing())
{
  
  clearscreen();
}

//screenSelect(10);



}

void displayRobert::display(int choice)
{
	clearscreen();

	switch(choice)
	{
	case 1:
		velocityDisplay(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21);
		break;

	case 2:
		rotationDisplay(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21);
		break;

	case 3:
		currentDisplay(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21);
		break;

	case 4:
		powerDisplay(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21);
		break;

	case 5:
		torqueDisplay(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21);
		break;

	case 6:
		efficiencyDisplay(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21);
		break;

	case 7:
		temperatureDisplay(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21);
		break;

	default:
		batteryDisplay();
	}
}

//Brain.timer(vex::timeUnits::msec);

int displayRobert::screenSelect(int max)
{
	int rPic = 430, lPic = 50;
	if(Brain.Screen.pressing())
	{ //If the Brain is pressed...


		if (Brain.Screen.xPosition()< lPic)
		{
			if (displayInfo < 1)
				displayInfo = max;
			else
				displayInfo--;
		}
		else if (Brain.Screen.xPosition()> rPic)
		{
			if (displayInfo > max)
				displayInfo = 1;
			else
				displayInfo++;
		}
		else
		{

		}

	}
	else if (Controller1.ButtonR1.pressing())
	{
		if (displayInfo > max)
			displayInfo = 1;
		else
			displayInfo++;
	}
	else if (Controller1.ButtonL1.pressing())
	{
		if (displayInfo < 1)
			displayInfo = max;
		else
			displayInfo--;
	}
	else
	{

	}
	return displayInfo;
}

void displayRobert::clearscreen()
{
	Controller1.Screen.clearLine(1);
	Controller1.Screen.clearLine(2);
	Controller1.Screen.clearLine(3);
	Brain.Screen.clearLine(1,"#FF0000");
	Brain.Screen.clearLine(2,"#FF0000");
	Brain.Screen.clearLine(3,"#FF0000");
}

void displayRobert::velocityDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21)
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("velocity");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f rpm",LM1.velocity(vex::velocityUnits::rpm));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f rpm",LM2.velocity(vex::velocityUnits::rpm));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f rpm",RM1.velocity(vex::velocityUnits::rpm));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f rpm",RM2.velocity(vex::velocityUnits::rpm));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("velocity");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f rpm",LM1.velocity(vex::velocityUnits::rpm));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f rpm",LM2.velocity(vex::velocityUnits::rpm));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f rpm",RM1.velocity(vex::velocityUnits::rpm));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f rpm",RM2.velocity(vex::velocityUnits::rpm));
}

void displayRobert::rotationDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21)
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("rotation");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f deg",LM1.rotation(vex::rotationUnits::deg));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f deg",LM2.rotation(vex::rotationUnits::deg));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f deg",RM1.rotation(vex::rotationUnits::deg));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f deg",RM2.rotation(vex::rotationUnits::deg));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("rotation");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f deg",LM1.rotation(vex::rotationUnits::deg));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f deg",LM2.rotation(vex::rotationUnits::deg));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f deg",RM1.rotation(vex::rotationUnits::deg));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f deg",RM2.rotation(vex::rotationUnits::deg));
}

void displayRobert::currentDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21)
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("current");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f amp",LM1.current(vex::currentUnits::amp));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f amp",LM2.current(vex::currentUnits::amp));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f amp",RM1.current(vex::currentUnits::amp));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f amp",RM2.current(vex::currentUnits::amp));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("current");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f amp",LM1.current(vex::currentUnits::amp));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f amp",LM2.current(vex::currentUnits::amp));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f amp",RM1.current(vex::currentUnits::amp));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f amp",RM2.current(vex::currentUnits::amp));
}

void displayRobert::powerDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21)
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("power");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f watts",LM1.power(vex::powerUnits::watt));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f watts",LM2.power(vex::powerUnits::watt));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f watts",RM1.power(vex::powerUnits::watt));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f watts",RM2.power(vex::powerUnits::watt));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("power");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f watts",LM1.power(vex::powerUnits::watt));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f watts",LM2.power(vex::powerUnits::watt));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f watts",RM1.power(vex::powerUnits::watt));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f watts",RM2.power(vex::powerUnits::watt));
}

void displayRobert::torqueDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21)
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("torque");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f Nm",LM1.torque(vex::torqueUnits::Nm));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f Nm",LM2.torque(vex::torqueUnits::Nm));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f Nm",RM1.torque(vex::torqueUnits::Nm));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f Nm",RM2.torque(vex::torqueUnits::Nm));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("torque");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f Nm",LM1.torque(vex::torqueUnits::Nm));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f Nm",LM2.torque(vex::torqueUnits::Nm));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f Nm",RM1.torque(vex::torqueUnits::Nm));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f Nm",RM2.torque(vex::torqueUnits::Nm));
}

void displayRobert::efficiencyDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21)
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("efficiency");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f pct",LM1.efficiency(vex::percentUnits::pct));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f pct",LM2.efficiency(vex::percentUnits::pct));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f pct",RM1.efficiency(vex::percentUnits::pct));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f pct",RM2.efficiency(vex::percentUnits::pct));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("efficiency");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f pct",LM1.efficiency(vex::percentUnits::pct));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f pct",LM2.efficiency(vex::percentUnits::pct));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f pct",RM1.efficiency(vex::percentUnits::pct));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f pct",RM2.efficiency(vex::percentUnits::pct));
}

void displayRobert::temperatureDisplay(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21)
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("temperature");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f pct",LM1.temperature(vex::percentUnits::pct));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f pct",LM2.temperature(vex::percentUnits::pct));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f pct",RM1.temperature(vex::percentUnits::pct));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f pct",RM2.temperature(vex::percentUnits::pct));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("temperature");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f pct",LM1.temperature(vex::percentUnits::pct));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f pct",LM2.temperature(vex::percentUnits::pct));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f pct",RM1.temperature(vex::percentUnits::pct));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f pct",RM2.temperature(vex::percentUnits::pct));
}

void displayRobert::batteryDisplay()
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("Battery");
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("Temperature %f C",Brain.Battery.temperature());

	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("Capacity %f pct",Brain.Battery.capacity());

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("Battery");
	Brain.Screen.setCursor(2,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("Temp %f C",Brain.Battery.temperature());

	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("Capacity %f pct",Brain.Battery.capacity());
}



