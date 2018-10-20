//RX module on water level system
//Written By : Christoffer Brekkeseter
// 1buzzer.03.201blueLed


#include <VirtualWire.h>

/************Defines***************/
#define  ledPin         13
#define  buzzer         7
#define  blueLed        6
#define  loSensor        5
#define  midSensor       4
#define  highSensor      3
#define  RX_pin         2

/************Constants************/
const int outputPin[] = {loSensor, midSensor, highSensor, blueLed, buzzer};
const int timerLimit = 20000;
const int blinkTimerLimit = 2000;
/************Variables************/
int       prevCase = 0;
int currentCommand, previousCommand;
long      timer, blinkTimer;

void setup()
{
  vw_set_rx_pin(RX_pin);
  vw_setup(2000);        // Bits per sec

  // set output pins
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
    timer = millis();
    digitalWrite(ledPin, HIGH);
    digitalWrite(blueLed, LOW);



    /**************************ALL LEDS OFF************************/
    if (buf[0] == '0') {

      for (int i = 0; i < sizeof(outputPin) / sizeof(int); i++)
      {
        digitalWrite(outputPin[i], LOW);
      }
      currentCommand = 0;
    }
    /****************************loSensor**************************/
    if (buf[0] == '1') currentCommand = 1;

    /****************************midSensor*************************/
    if (buf[0] == '2') currentCommand = 2;

    /****************************highSensor**************************/
    if (buf[0] == '3') currentCommand = 3;

    /****************************TESTFUNC**************************/
    if (buf[0] == '4') {
      for (int i = 0; i < 6; i++)
      {
        digitalWrite(blueLed, !digitalRead(blueLed));
        tone(buzzer, 1200);
        delay(500);
      }
      noTone(buzzer);
    }

      // indicating led on board
      delay(20);
      digitalWrite(ledPin, LOW);


    
  }



  if (currentCommand != previousCommand) {

    tone(buzzer, 1200);
    delay(100);
    noTone(buzzer);
  }

  // If tank is getting full
  if (currentCommand == 3)
  {
    for (int i = 0; i < 2; i++)
    {
      for (int i = 0; i < currentCommand; i++)
      {
        digitalWrite(outputPin[i], HIGH);
      }
      delay(50);
      for (int i = 0; i < currentCommand; i++)
      {
        digitalWrite(outputPin[i], LOW);
      }
      tone(buzzer, 1200);
      delay(100);
      noTone(buzzer);
    }
  }

  // // if no signal is received
  if ((millis() - timer) > timerLimit) {

    timer = millis();

    digitalWrite(blueLed, HIGH);
    for (int i = 0; i < 3; i++)
    {
      tone(buzzer, 1200);
      delay(50);
      noTone(buzzer);
      delay(50);
    }
  }


  if ((previousCommand != currentCommand) || (millis() - blinkTimer) > blinkTimerLimit) {    
    // light leds
    for (int i = 0; i < currentCommand; i++)
    {
      digitalWrite(outputPin[i], HIGH);
      delay(50);
    }
  
    // shut off leds
    delay(150);
    for (int i = 0; i < currentCommand; i++)
    {
      digitalWrite(outputPin[i], LOW);
    }
    blinkTimer = millis();

  }
      previousCommand = currentCommand;
}




