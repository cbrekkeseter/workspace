// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
    for (i=0; i < strip1.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 96-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 96 is to make the wheel cycle around
      strip1.setPixelColor(i, Wheel( ((i * 256 / strip1.numPixels()) + j) % 256) );
    }  
    strip1.show();   // write all the pixels out
    menuHandler();   //Sjekker om noe har skjedd med menyknappene i mellomtiden
    delay(wait);
  }
}



// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}



//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}



void setColorPixel(byte pix, char col){
  uint32_t color;
  if      (col =='r') color = Color(0,0,255);      //Hvis 'r' for rød
  else if (col =='b') color = Color(255,0,0);      //Hvis 'b' for blå
  else if (col =='g') color = Color(0,255,0);      //Hvis 'g' for grønn
  else if (col =='h') color = Color(255,255,255);  //Hvis 'h' for hvit, alle farger på
  else if (col =='s') color = Color(0,0,0);        //Hvis 's' for svart, ingen farger på
  else return;
  
  strip1.setPixelColor(pix, color);                  //Fyll medsendt pixel med medsendt farge
  strip1.show();                                     //Oppdater LED strip1
  delay(1);                                          //Vent på at LED strip1 skal bli oppdatert
}



void setColorAllPixels(char col){

  for (byte i=0; i<=2; i++){
    setColorPixel(i,col);
   } 
 }
