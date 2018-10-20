// Water level detection and transmit sensor levels over RF
// Written By : Christoffer Brekkeseter
// 12.03.2016
//.........................................................

#include <VirtualWire.h>

/************Defines***************/
#define  ledPin           6
#define  testButton       5
#define  lowSensor        2
#define  midSensor        3
#define  hiSensor         4
#define  txPin            13
#define  buttonHoldTime    3000
/************Constants************/
const int sensor[] = {lowSensor, midSensor, hiSensor, testButton};
const long txFreq = 10000;
/************Variables************/
char *command, *prevCommand;


long buttonTimer, timer = 0;
long longPressTime = 2000;

boolean buttonActive = false;
boolean longPressActive = false;

void setup() {

  // set what pin to transmit at
  vw_set_tx_pin(txPin);
  // speed of data transfer Kbps
  vw_setup(2000);

  // set LED pin to output
  pinMode(ledPin, OUTPUT);

  // set all sensors and test button to input
  for (int i = 0; i < sizeof(sensor) / sizeof(int); i++)
  {
    pinMode(sensor[i], INPUT);
  }
}

void loop()
{

  /********************read sensor value********************/
  if   (digitalRead(hiSensor)     == HIGH)    command = "3"  ;    // high level sensor active
  else if   (digitalRead(midSensor)    == HIGH)    command = "2"  ;    // mid level sensor active
  else if   (digitalRead(lowSensor)    == HIGH)    command = "1"  ;    // low level sensor active
  else                                            command = "0"  ;    // default value


    /********************button pressed/hold********************/
  if (digitalRead(testButton) == HIGH) {            //Button pressed
    if (buttonActive == false) {
      buttonActive = true;
      buttonTimer = millis();
    }

    if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)) {
      longPressActive = true;

      command = "5";

    }


  } else {      //Button not pressed
    if (buttonActive == true) {
      buttonActive = false;


      if (longPressActive == true) {
        longPressActive = false;
      } else {

        command = "4";

      }
    }
  }

  if((millis() - timer) > txFreq) {
    timer = millis();
    writeSensorValue(command);    
  }

  if(prevCommand != command) writeSensorValue(command);
  
  
  prevCommand = command;

}
  
  /*******************Writes sensor value*******************/


  void writeSensorValue(char *command) {

  digitalWrite(ledPin, HIGH);     // blink LED

  vw_send((uint8_t *)command, strlen(command));   // send command
  vw_wait_tx(); // wait until the whole message is gone

  digitalWrite(ledPin, LOW);      // blink LED
  }
