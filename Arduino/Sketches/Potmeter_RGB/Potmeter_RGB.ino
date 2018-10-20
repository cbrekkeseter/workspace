const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

const int buttonPin = 8;

const int redAnalog = 0;
const int greenAnalog = 1;
const int blueAnalog = 2;

int red = 0;
int green = 0;
int blue = 0;

int buttonState = 0;

void setup() 
  {
    pinMode(redPin , OUTPUT);
    pinMode(greenPin , OUTPUT);
    pinMode(bluePin , OUTPUT);
    pinMode(buttonPin , INPUT);
  }  

void loop() 
  {
    buttonState = digitalRead(buttonPin);
    if(digitalRead(buttonPin) == HIGH)
    {
      randomColor();
      delay(250);
    }

    red = analogRead(redAnalog)/4;
    green = analogRead(greenAnalog)/4;
    blue = analogRead(blueAnalog)/4;
    
    delay(50);
    
    setColor(red, green, blue);

  }

void setColor(int red, int green, int blue)
  {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
  }
  
  void randomColor()
  {
    analogWrite(redPin, random(255));
    analogWrite(greenPin, random(255));
    analogWrite(bluePin, random(255));
  }
