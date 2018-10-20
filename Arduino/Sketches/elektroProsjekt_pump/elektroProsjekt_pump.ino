

//========================Ceates array of pumps==============================//
const int numberOfPumps = 3;             // Number of pumps, max is 4
int pump[numberOfPumps - 1];             // Creates array, counting from 0
//===========================================================================//



void setup() {
//========================Attach pumps=======================================//
  for(int i=0; i < (numberOfPumps-1); i++) {  
    pump[i]=(9+i);                             // Available pins: 9 - 12
    pinMode(pump[i], OUTPUT);                  // Set pins as output
  }
//==========================================================================//
}



void loop() {

  // Execute code here
  
}



//========================Function activatePump=============================//
//  activatePump will activate the corresponding pump.
//  Input: pump number count from 1, speed (0-10), and ON time in milli sec.
//==========================================================================//

void activatePump(int pumpNumber, int analogSpeed, int timeOn) {
  
    pumpNumber  = (pumpNumber-1);          // Makes it count from 0 in array
    analogSpeed = (analogSpeed * 25);      // Speed range 0 - 10
    
    analogWrite(pump[pumpNumber], analogSpeed);
    delay(timeOn);
    digitalWrite(pump[pumpNumber], LOW);
}
//==========================================================================//
