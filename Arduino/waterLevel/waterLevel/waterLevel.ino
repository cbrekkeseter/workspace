
#include "pitches.h"
#include "melody.h"

const int ledPin[] = {0,7,8,9};
const int sensor[] = {0,2,3,4};
const int buzzerPin = 10;

void setup() {
  
  for(int i=0; i<3; i++) pinMode(sensor[i+1], INPUT); 
  for(int i=0; i<3; i++) pinMode(ledPin[i+1], OUTPUT); 
  pinMode(buzzerPin, OUTPUT);
  
}  

  void loop() {
    
    if (digitalRead(sensor[2]) == HIGH) {
      digitalWrite(ledPin[2], HIGH); 
      sing(2);
    }
    else if (digitalRead(sensor[1]) == HIGH) {
      digitalWrite(ledPin[1], HIGH); 
      sing(1);
    }
    else  for(int i=0; i<3; i++) digitalWrite(ledPin[i+1], LOW);

}
