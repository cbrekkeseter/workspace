// Nikon Remote Emulator by Gough Lui (http://goughlui.com)
// A1 = IR +
// A0 = IR -

int count=0;

void setup() {
  pinMode(A0,OUTPUT);
  digitalWrite(A0,LOW);
  pinMode(3,OUTPUT);
  digitalWrite(A1,LOW);
}

void loop() {
  // Send code three times, as the clone remote does
  // Delays are tuned to account for overhead of library code.
  for(count = 0; count <3; count ++) {
    tone(A1,38000);
    delay(2);
    noTone(A1);
    delay(28);
    tone(A1,38000);
    delayMicroseconds(200);
    noTone(A1);
    delayMicroseconds(1500);
    tone(A1,38000);
    delayMicroseconds(200);
    noTone(A1);
    delayMicroseconds(3300);
    tone(A1,38000);
    delayMicroseconds(200);
    noTone(A1);
    delayMicroseconds(100);    
    delay(63);     
  }
  count = 0;
}
