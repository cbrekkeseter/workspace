#include <IRremote.h>

int RECV_PIN = 11;
int ledPin = 6;
int brightness = 255;

IRrecv irrecv(RECV_PIN);

decode_results results;


void setup() {
  irrecv.enableIRIn(); // Start the receiver
  pinMode (ledPin, OUTPUT);

}

void loop() {
  
  analogWrite(ledPin, brightness);
  if(irrecv.decode(&results)) //this checks to see if a code has been received
{
    if(results.value == 0x10EF58A7 && brightness < 255) //if the button press equals the hex value 0xC284
    {
        brightness = brightness + 51;  
        delay(100);
       while( results.value == 0xFFFFFFFF){
         brightness = brightness + 51;
         }
     
    }
    if(results.value == 0x10EF708F && brightness > 0) //if the button press equals the hex value 0xC284
    {
        brightness = brightness - 51;
    }
    
    irrecv.resume(); //receive the next value
}


}
