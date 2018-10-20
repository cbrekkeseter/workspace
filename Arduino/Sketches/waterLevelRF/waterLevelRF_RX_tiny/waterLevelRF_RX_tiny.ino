//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//http://www.genotronex.com/
//..................................
#include <VirtualWire.h>



const int outputPin[] = {1,2,3,4};
const int RX_pin = 0;
int       prevCase = 0;
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds);

void setup()
{

  vw_set_rx_pin(RX_pin);
  vw_setup(4000);        // Bits per sec

  for (int i = 0; i < sizeof(outputPin) / sizeof(int); i++)
  {
    pinMode(outputPin[i], OUTPUT);
  }

  vw_rx_start();       // Start the receiver PLL running
}
void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    // switch dependent on data received
    switch (buf[0]) {

      /**************************ALL LEDS OFF************************/
      case '0' :
        for (int i = 0; i < sizeof(outputPin) / sizeof(int); i++)
        {
          digitalWrite(outputPin[i], LOW);
        }
        prevCase = 0;
        break; // case '0'

      /****************************LOSENSE**************************/
      case '1':
        for (int i = 0; i < 1; i++)
        {
          digitalWrite(outputPin[i], HIGH);
        }
        if (prevCase != 1)
        {
//          tone(11, 1200);
//          delay(100);
//          noTone(11);
        }
        prevCase = 1;
        break; // case '1'

      /****************************MEDSENSE*************************/
      case '2' :
        for (int i = 0; i < 2; i++)
        {
          digitalWrite(outputPin[i], HIGH);
        }
        if (prevCase != 2)
        {
//          tone(11, 1200);
//          delay(100);
//          noTone(11);
        }
        prevCase = 2;
        break; // case '2'

      /****************************HISENSE**************************/
      case '3' :
        for (int i = 0; i < 3; i++)
        {
          digitalWrite(outputPin[i], HIGH);
        }
        for (int i = 2000; i > 0; i -= 100)
        {
//          tone(11, 1200);
//          delay(100);
//          noTone(11);
//          delay(i);
        }
//
//        tone(11, 1200);
//        delay(5000);
//        noTone(11);

        break; // case '3'

      /****************************TESTFUNC**************************/
      case '4' :
        for (int i = 0; i < 6; i++)
        {
          for (int i = 0; i < 3; i++)   digitalWrite(outputPin[i], !digitalRead(outputPin[i]));

        beep(1, 8*4000, 20) ;
        delay(500*8);
        }
        break; // case '4'
    }
  }
  
}

void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{	 // http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
          int x;	 
          long delayAmount = (long)(1000000/frequencyInHertz);
          long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
          for (x=0;x<loopTime;x++)	 
          {	 
              digitalWrite(speakerPin,HIGH);
              delayMicroseconds(delayAmount);
              digitalWrite(speakerPin,LOW);
              delayMicroseconds(delayAmount*3);
          }	 
}
