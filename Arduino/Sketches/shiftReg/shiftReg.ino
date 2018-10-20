
//**************************************************************//
//  Name    : shiftOutCode, Dual One By One                      //
//  Author  : Christoffer Brekkeseter                            //
//  Date    : 19.11.2015                                         //
//  Version : 0.1                                                //
//  Notes   : Code for using a 74HC595 Shift Register            //
//**************************************************************//

//Pin connected to ST_CP of 74HC595
int latchPin = 3;
//Pin connected to SH_CP of 74HC595
int clockPin = 4;
////Pin connected to DS of 74HC595
int dataPin = 0;
////Pin connected to OE of 74HC595
int enablePin = 1;

int data = random(65535);
int meetSplitPattern[]= {32769, 16386, 8196, 4104, 2064, 1056, 576, 384};
unsigned int damPatternArray[]= 
  {1,4,2,8,4,16,8,32,16,64,32,128,64,256,
   128,512,256,1024,512,2048,1024,4096,2048,
   8192,4096,16384,8192,32768,16384};
unsigned int allLight = 65535;

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {
  }

  
////--------------------------Random Number Generator--------------------------

void randomNumber(int repeat, int delayTime)  {
  
  for(int i = 0; i < repeat; i++) {
    data = random(65535);  
    
    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);  
    
    // shift out highbyte
    shiftOut(dataPin, clockPin, MSBFIRST, (data >> 8));  
    // shift out lowbyte
    shiftOut(dataPin, clockPin, MSBFIRST, data);
    
    digitalWrite(latchPin, HIGH);
    delay(delayTime);
    }
}

////---------------------------------------------------------------------------  
////--------------------------16 bit counter-----------------------------------

void sixteenBitCountUp()  {
  
  for (int numberToDisplay = 0; numberToDisplay < 65636; numberToDisplay++) {
    
     digitalWrite(clockPin, LOW);
     digitalWrite(latchPin, LOW);
     
     // shift out highbyte 
     shiftOut(dataPin, clockPin, MSBFIRST, (numberToDisplay >> 8));
     // shift out lowbyte    
     shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
      
     digitalWrite(latchPin, HIGH);
     delay(50);
   }
}

////---------------------------------------------------------------------------  
////------------------------16 bit count down----------------------------------

void sixteenBitCountDown()  {
  
    for (int numberToDisplay = 65636; numberToDisplay >= 0; numberToDisplay--) {
      
      digitalWrite(clockPin, LOW);
      digitalWrite(latchPin, LOW);
      
      // shift out highbyte
        shiftOut(dataPin, clockPin, MSBFIRST, (numberToDisplay >> 8));   
      // shift out lowbyte
      shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
       
      digitalWrite(latchPin, HIGH);
      delay(50);
   }
}

////---------------------------------------------------------------------------
////--------------------------Alternate high and low bits----------------------

void lowHighAlternate(int repeat)  {
  
  for(int i = 0; i < repeat; i++) {

    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);
    
    // shift out highbyte
    shiftOut(dataPin, clockPin, MSBFIRST, (255 >> 8));  
    // shift out lowbyte
    shiftOut(dataPin, clockPin, MSBFIRST, 255);
   
    digitalWrite(latchPin, HIGH);
    delay(500);
    
    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);

    // shift out highbyte
    shiftOut(dataPin, clockPin, MSBFIRST, (65280 >> 8));    
    // shift out lowbyte
    shiftOut(dataPin, clockPin, MSBFIRST, 65280);  
    
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}

////---------------------------------------------------------------------------
////-----------------------Alternate every second LED--------------------------

void alternateSecondLed(int repeat)  {
  
  for(int i = 0; i < repeat; i++) {

    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);
    
    // shift out highbyte
    shiftOut(dataPin, clockPin, MSBFIRST, (43690 >> 8));  
    // shift out lowbyte
    shiftOut(dataPin, clockPin, MSBFIRST, 43690);
   
    digitalWrite(latchPin, HIGH);
    delay(500);

    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);

    // shift out highbyte
    shiftOut(dataPin, clockPin, MSBFIRST, (21845 >> 8));  
    // shift out lowbyte
    shiftOut(dataPin, clockPin, MSBFIRST, 21845);  
    
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}
    
////---------------------------------------------------------------------------
////------------------------------LED Race-------------------------------------

void ledRace(int repeat)  {

  for (int i = 0; i < repeat; i++) {
    
    for (unsigned int i = 1; i <= 32767; i *= 2) {
      
      digitalWrite(clockPin, LOW);
      digitalWrite(latchPin, LOW);
      
      // shift out highbyte
      shiftOut(dataPin, clockPin, MSBFIRST, (i >> 8));  
      // shift out lowbyte
      shiftOut(dataPin, clockPin, MSBFIRST, i);
      
      digitalWrite(latchPin, HIGH);
      delay(20);
      }
      
    for (unsigned int i = 32768; i > 1; i /= 2) {
      
      digitalWrite(clockPin, LOW);
      digitalWrite(latchPin, LOW);
      
      // shift out highbyte
      shiftOut(dataPin, clockPin, MSBFIRST, (i >> 8));  
      // shift out lowbyte
      shiftOut(dataPin, clockPin, MSBFIRST, i);
      
      digitalWrite(latchPin, HIGH);
      delay(20);
    }
  }
}

////---------------------------------------------------------------------------
////--------------------------Meet and split----------------------------------- 

void meetAndSplit(int repeat)  {
  
  for(int i = 0; i < repeat; i++) {
   
    for (int i = 0; i < 8; i++) {

      digitalWrite(clockPin, LOW);
      digitalWrite(latchPin, LOW);
      
      // shift out highbyte
      shiftOut(dataPin, clockPin, MSBFIRST, (meetSplitPattern[i] >> 8));   
      // shift out lowbyte
      shiftOut(dataPin, clockPin, MSBFIRST, meetSplitPattern[i]);
      
      digitalWrite(latchPin, HIGH);
      delay(50);
    } 
      
    for (int i = 6; i >= 0; i--) {
    
      digitalWrite(clockPin, LOW);
      digitalWrite(latchPin, LOW);
      
      // shift out highbyte
      shiftOut(dataPin, clockPin, MSBFIRST, (meetSplitPattern[i] >> 8));  
      // shift out lowbyte
      shiftOut(dataPin, clockPin, MSBFIRST, meetSplitPattern[i]);
      
      digitalWrite(latchPin, HIGH);
      delay(50);
    } 
  }
} 
//---------------------------------------------------------------------------
//-----------------------------damPattern------------------------------------

void damPattern()  {
  
  for (int i = 0; i < sizeof(damPattern)/sizeof(unsigned int) ; i++) {
    
      digitalWrite(clockPin, LOW);
      digitalWrite(latchPin, LOW);
      
      // shift out highbyte
      shiftOut(dataPin, clockPin, MSBFIRST, (damPattern[i] >> 8));  
      // shift out lowbyte
      shiftOut(dataPin, clockPin, MSBFIRST, damPattern[i]);
      
      digitalWrite(latchPin, HIGH);
      delay(200);
  } 
}

//---------------------------------------------------------------------------
//-------------------------------allFade-------------------------------------
void allFade(int repeat)  {
  
      digitalWrite(clockPin, LOW);
      digitalWrite(latchPin, LOW);
     
      // shift out highbyte
      shiftOut(dataPin, clockPin, MSBFIRST, (allLight >> 8));  
      // shift out lowbyte
      shiftOut(dataPin, clockPin, MSBFIRST, allLight);
      
      digitalWrite(latchPin, HIGH);
      
  for (int i = 0; i < repeat; i++) {
    
    for (int i = 0; i < 255; i++) {  
      analogWrite(enablePin, i);   
      delay(5);
    }
    
    delay(50);
    
    for (int i = 255; i > 0; i--) {   
      analogWrite(enablePin, i);   
      delay(7);
    }
  }
  
  digitalWrite(enablePin, LOW);
}

//---------------------------------------------------------------------------
//--------------------------8 by 8 fade--------------------------------------
void eightFade(int repeat)  {
  
  for(int i = 0; i < 5; i++) {

    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);
    
    // shift out highbyte
    shiftOut(dataPin, clockPin, MSBFIRST, (255 >> 8));   
    // shift out lowbyte
    shiftOut(dataPin, clockPin, MSBFIRST, 255);
   
    digitalWrite(latchPin, HIGH);
    
      for (int i = 255; i > 0; i--) {     
        analogWrite(enablePin, i);   
        delay(5);
      }
      
      delay(50);
      
      for (int i = 0; i < 255; i++) {     
        analogWrite(enablePin, i);   
        delay(7);
      }
      
    digitalWrite(enablePin, HIGH);
    delay(50);
    
    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);

    // shift out highbyte
    shiftOut(dataPin, clockPin, MSBFIRST, (65280 >> 8));    
    // shift out lowbyte
    shiftOut(dataPin, clockPin, MSBFIRST, 65280);  
    
    digitalWrite(latchPin, HIGH);
    
      for (int i = 255; i > 0; i--) {    
        analogWrite(enablePin, i);   
        delay(5);
      }
      
      delay(50);
      
      for (int i = 0; i < 255; i++) {     
        analogWrite(enablePin, i);   
        delay(7);
      }
      
    digitalWrite(enablePin, HIGH);
    delay(50);
  }
    digitalWrite(enablePin, LOW);
}
