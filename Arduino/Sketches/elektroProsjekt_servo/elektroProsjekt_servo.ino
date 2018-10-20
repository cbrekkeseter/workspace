
#include <Servo.h>

//========================Ceates Servo objects===============================//
const int numberOfServos = 3;            // Number of servos
Servo servo[numberOfServos];         // Creates array, counting from 0
//===========================================================================//



void setup() {
//========================Attach servos=====================================//
  for(int i=0; i < (numberOfServos); i++) {  
    servo[i].attach(2+i);                       //Available pins: 2 - 8
    servo[i].writeMicroseconds(1500);           // Initializing stand still
  }
//==========================================================================//  
}



void loop() {
  
  openValve(1);
  delay(3000);
  openValve(2);
  delay(3000);
  openValve(3);
delay(3000);  
}



//========================Function openValve================================//
//  openValve will activate the servo attached to the corresponding valve.
//  Input: servo number counting from 1.
//==========================================================================//

void openValve(int servoNumber) {

    int servoNum = (servoNumber-1);            // Makes it count from 0 in array
  
    servo[servoNum].writeMicroseconds(2400);     // Open
    delay(500);                                      
    servo[servoNum].writeMicroseconds(1550);     // hold
    delay(1000);
    servo[servoNum].writeMicroseconds(544);      // Close
    delay(300);
    servo[servoNum].writeMicroseconds(1500);     // Still
  }
//==========================================================================//
