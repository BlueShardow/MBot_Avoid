#include <MeMCore.h>
#include <Arduino.h>

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

uint8_t motorSpeed = 100;

MeLineFollower lineF (PORT_2);

MeRGBLed led(0, 30); // var for LED

MeUltrasonicSensor ultraS (PORT_1);

void forward () // forward
{
 motor1.run (100);
 motor2.run (-100);
 delay (50);
} // forward

void left () // left
{
 motor1.run (150);
 motor2.run (150);
 delay (65);
} // end of left

void right () // right
{
 motor1.run (-150);
 motor2.run (-150);
 delay (65);
} // end of right

void back () // back
{
 motor1.run (-100);
 motor2.run (100);
 delay (333);
} // end of back

void stopR () // back
{
 motor1.run (0);
 motor2.run (0);
 delay (100);
} // end of back

void check () // check
{
 if (ultraS.distanceCm () <= 3.5)
 { // if to close
  back ();
 }
 if (ultraS.distanceCm () > 12.5) 
 { // if far
  forward ();
 } // end of if far

 else 
 { // if close
  while ((ultraS.distanceCm () <= 12.50) && (ultraS.distanceCm () >= 3.5))
  { // while close
    left ();
  }
 } // end of if close
} // end of check

void setup () // setup
{
 Serial.begin (9600);
} // end of setup

void loop () // loop___
{
 Serial.print ("Distance: ");
 Serial.print (ultraS.distanceCm ());
 Serial.println (" cm");
 delay (25);

 check ();
} // end of loop