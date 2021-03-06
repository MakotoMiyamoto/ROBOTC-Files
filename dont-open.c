#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in3,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl3,  quad,           sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           servoMotor,    tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
  Project Title: Vex testbed
  Team Members: Azael Guerra, Miguel Garcia
  Date: 4/26/19
  Section: 3.1.5


  Task Description: Test inputs and outputs on the testbed


  Pseudocode:

*/

task main()
{                                     //Program begins, insert code within curly braces
int motorCount;
 motorCount = 0;
 while (motorCount < 3)
 {
 startMotor(rightMotor, 30);
 wait(2);
 stopMotor(rightMotor);
 wait(2);
 motorCount = motorCount + 1;
 }
int count;
 count = 0;
 while (count < 20)
 {
  startMotor(rightMotor, 30);
  waitInMilliseconds(500);
  startMotor(rightMotor, -30);
  waitInMilliseconds(500);
  count = count + 1;
 }



}

task main() //*remember the biggest value recorded by the potentiometer//
{
 int biggest;
 while (1==1)
 {
 biggest = 0;
 while (SensorValue(bumpSwitch)==0) //*keeps track of biggest only if bumpswitch is zero//
 {
 if (SensorValue(potentiometer)>biggest) //*keeps track of biggest potentiometer value//
 {
biggest=SensorValue(potentiometer); //*the value to be monitored//
 }
 }
 }


}

task main()
{
 int closest;
 while (1==1)
 {
 closest = 4095;
 while (SensorValue(bumpSwitch)==0)
 {
 if (SensorValue(potentiometer)<closest)
 {
closest=SensorValue(potentiometer);
 }
 }
 }




}

 void LEDControl(); //this is a function declaration
 task main()
 {
while (1==1)
 {
 LEDControl(); //function call
 }
 }
 void LEDControl() //function definition
 {
 if (SensorValue(bumpSwitch)==1)
 {
 turnLEDOn(green);
 }
 else
 {
 turnLEDOff(green);
 }
 }
//*bumpswitch turns led on/off//
