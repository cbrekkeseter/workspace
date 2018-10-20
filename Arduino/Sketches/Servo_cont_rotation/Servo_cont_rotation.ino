/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
//--------------------Creates Servoobjects--------------------//
Servo servo_01;
Servo servo_02; 
Servo servo_03; 

const int valve_01 = 42;
const int valve_02 = 43;
const int valve_03 = 44;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

//------------------------------------------------------------//

void setup() {
//--------------------attaches servos to pins-----------------// 
  servo_01.attach(8);   
  servo_02.attach(9);
  servo_03.attach(10);  
  
  pinMode(valve_01, INPUT);
  pinMode(valve_02, INPUT);      // Knapp1, 2 og 3
  pinMode(valve_03, INPUT);
//------------------------------------------------------------//
//--------------------Calibrates servos-----------------------//
//  servo_01.writeMicroseconds(1500);
//  servo_02.writeMicroseconds(1500);      // Brukes for kalibrering
//  servo_03.writeMicroseconds(1500);  
//------------------------------------------------------------//
}

 
void loop() 
{  
   buttonState1 = digitalRead(valve_01);
  if (buttonState1 == HIGH) {
     openValve(1);
  }
    buttonState2 = digitalRead(valve_02);
  if (buttonState2 == HIGH) {
    openValve(2);
  }
    buttonState3 = digitalRead(valve_03);
  if (buttonState3 == HIGH) {
    openValve(3);
  }
} 

void openValve(int servoNumb) {
  
  switch (servoNumb) {
    case 1:
        servo_01.writeMicroseconds(2400);
        delay(650);
        servo_01.writeMicroseconds(1550);
        delay(2000);
        servo_01.writeMicroseconds(544);
        delay(400);
        servo_01.writeMicroseconds(1500);
        delay(500);
      break;
    case 2:
        servo_02.writeMicroseconds(2400);
        delay(700);
        servo_02.writeMicroseconds(1600);
        delay(2000);
        servo_02.writeMicroseconds(544);
        delay(400);
        servo_02.writeMicroseconds(1500);
        delay(500);
      break;
    default: 
        servo_03.writeMicroseconds(2400);
        delay(700);
        servo_03.writeMicroseconds(1600);
        delay(2000);
        servo_03.writeMicroseconds(600);
        delay(300);
        servo_03.writeMicroseconds(1500);
        delay(500);
    break;
    }
  }
