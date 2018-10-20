int redPin = 3;
int greenPin = 5;
int bluePin = 6;

void setup() 
  {
    pinMode(redPin , OUTPUT);
    pinMode(greenPin , OUTPUT);
    pinMode(bluePin , OUTPUT);
  }

void loop() 
  { 
    setColor(255, 0, 0);                    // Red   
    delay(500);
    setColor(0, 255, 0);                    // Green
    delay(500);
    setColor(0, 0, 255);                    // Blue
    delay(500);
    setColor(0,255,255);                    // Aqua  
    delay(500);
    setColor(255, 255, 0);                  // Yellow
    delay(500);
    setColor(128,0,128);                    // Purple
    delay(500);
    randomColor();                          // Random Color
    delay(500);
    randomColor();                          // Random Color
    delay(500);
    randomColor();                          // Random Color
    delay(500);
  }

//*********************************************************

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
