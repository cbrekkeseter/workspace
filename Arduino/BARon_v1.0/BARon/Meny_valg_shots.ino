
//=================================Gin shot==================================//
void on_Shot1_selected(MenuItem* p_menu_item)
{
  setColorAllPixels('b');
  lcd.setCursor(0,1);
  lcd.print("Shot 1 Valgt    ");
  buzzer(2,200);
  delay(1000);                            //Pauser for å vise teksten på skjermen.

  lcd.setCursor(0,0);
  lcd.print("Shot 1 Blandes  ");
  lcd.setCursor(0,1);
  lcd.print("Vennligst vent..");
   
  stepMove(Gin);                          //Flytt glidebrett til valgt dosør
  setColorPixel(sistePosisjon-2,'r');     //Farg valgt dosør rød

  openValve(Gin);                           //Erstattes med funksjon for servoer/pumper
 
  setColorPixel(sistePosisjon-2,'b');     //Farg valgt dosør blå igjen 
    
  stepMove(Hjem);                         //Flytt tilbake til HJEM posisjonen
  
  lcd.setCursor(0,0);
  lcd.print("Shot 1 Ferdig!  ");
  lcd.setCursor(0,1);
  lcd.print("**Bottoms up!!**");
  buzzer(2,200);
  delay(5000);                            //Pauser for å vise teksten på skjermen.

}

//***************************************************************************//

//=================================Rom Shot==================================//

void on_Shot2_selected(MenuItem* p_menu_item)
{
  setColorAllPixels('b');
  lcd.setCursor(0,1);
  lcd.print("Shot 2 Valgt    ");
  buzzer(2,200);
  delay(1000);                             //Pauser for å vise teksten på skjermen.

  lcd.setCursor(0,0);
  lcd.print("Shot 2 Blandes  ");
  lcd.setCursor(0,1);
  lcd.print("Vennligst vent..");
   
  stepMove(Rom);                          //Flytt glidebrett til valgt dosør
  setColorPixel(sistePosisjon-2,'r');     //Farg valgt dosør rød

  openValve(Rom);                           //Erstattes med funksjon for servoer/pumper
 
  setColorPixel(sistePosisjon-2,'b');     //Farg valgt dosør blå igjen 
    
  stepMove(Hjem);                         //Flytt tilbake til HJEM posisjonen
  
  lcd.setCursor(0,0);
  lcd.print("Shot 2 Ferdig!  ");
  lcd.setCursor(0,1);
  lcd.print("**Bottoms up!!**");
  buzzer(2,200);
  delay(5000);                            //Pauser for å vise teksten på skjermen.
}

//***************************************************************************//

//================================Vodka Shot=================================//

void on_Shot3_selected(MenuItem* p_menu_item)
{
  setColorAllPixels('b');
  lcd.setCursor(0,1);
  lcd.print("Shot 3 Valgt    ");
  buzzer(2,200);
  delay(1000);                            //Pauser for å vise teksten på skjermen.

  lcd.setCursor(0,0);
  lcd.print("Shot 3 Blandes  ");
  lcd.setCursor(0,1);
  lcd.print("Vennligst vent..");
  
  stepMove(Vodka);                        //Flytt glidebrett til valgt dosør
  setColorPixel(sistePosisjon-2,'r');     //Farg valgt dosør rød

  openValve(Vodka);                           //Erstattes med funksjon for servoer/pumper

  setColorPixel(sistePosisjon-2,'b');     //Farg valgt dosør blå igjen 
    
  stepMove(Hjem);                         //Flytt tilbake til HJEM posisjonen
    
  lcd.setCursor(0,0);
  lcd.print("Shot 3 Ferdig!  ");
  lcd.setCursor(0,1);
  lcd.print("**Bottoms up!!**");
  buzzer(2,200);
  delay(5000);                            //Pauser for å vise teksten på skjermen.

}
