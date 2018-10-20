const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

const int buttonPin = 8;

int count = 0;
int buttonState = 0;
int lastState = 0;

void setup() {
    pinMode(redPin , OUTPUT);
    pinMode(greenPin , OUTPUT);
    pinMode(bluePin , OUTPUT);
    pinMode(buttonPin , INPUT);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  
  if(buttonState != lastState) {
    if(buttonState == HIGH) {
      count ++;
      }
  }
  lastState = buttonState;
  if(count > 3)
  count = 0;
  
  switch(count){
    case 1:
    setColor(255,0,0);
    tone(2,220,10);
    break;
    case 2:
    setColor(0,255,0);
    tone(2,247,10);
    break;
    case 3:
    setColor(0,0,255);
    tone(2,277,10);
    break;
    default:
    setColor(0,0,0);
  }
}

void setColor(int red, int green, int blue)
  {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
  }
