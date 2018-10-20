const int pulsePin = 22;
const int dirPin = 23;

int rev = 5;
int dir = 0;

void setup() {
  
  pinMode(pulsePin , OUTPUT);
  pinMode(dirPin , OUTPUT);
}

void loop() {
  
  digitalWrite (pulsePin, HIGH);
  
  delay(rev);
  
  digitalWrite (pulsePin, LOW);
  
  delay(rev);
  
  }
  
