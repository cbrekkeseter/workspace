 
// Meny callback funksjoner
// Kjøres når de forskjellige drinkene/shotene velges i menyen
// Instruksjonene for hvert menyvalg utgjør en oppskrift for en drink,
// Tilgjengelige ingredienser føres opp som konstanter i hovedfanen "BARon" 
// under dertil egnet avsnitt som er gjort lett synlig med kommentarer.



//***************************************************************************//

//================================Gin & Tonic================================//

void on_Drink1_selected(MenuItem* p_menu_item)
{


  setColorAllPixels('b');
  lcd.setCursor(0,1);
  lcd.print("Drink 1 Valgt   ");
  buzzer(2,200);
  delay(1000);                            //Pauser for å vise teksten på skjermen.

  lcd.setCursor(0,0);
  lcd.print("Drink 1 Blandes ");
  lcd.setCursor(0,1);
  lcd.print("Vennligst vent..");
  
  stepMove(Gin);                           //Flytt glidebrett til valgt dosør
  setColorPixel(sistePosisjon-2,'r');      //Farg valgt dosør rød
  
  openValve(Gin);                            //Erstattes med funksjon for servoer/pumper
  delay(1500); 
  openValve(Gin);
 
  setColorPixel(sistePosisjon-2,'b');      //Farg valgt dosør blå igjen
  stepMove(Blandevann);                    //Gå til blandevann stasjonen
  
  activatePump(Tonic, 7, 6000);                             //Erstattes med funksjon for servoer/pumper
  
  stepMove(Hjem);                          //Gå tilbake til HJEM posisjonen
  
  lcd.setCursor(0,0);
  lcd.print("Drink 1 Ferdig! ");
  lcd.setCursor(0,1);
  lcd.print("***Cheers!!!!***");
  buzzer(2,200);
  delay(5000);                            //Pauser for å vise teksten på skjermen.
}
//***************************************************************************//


//================================Cuba Libre=================================//

void on_Drink2_selected(MenuItem* p_menu_item)
{
  setColorAllPixels('b');
  lcd.setCursor(0,1);
  lcd.print("Drink 2 Valgt   ");
  buzzer(2,200);
  delay(1000);                           //Pauser for å vise teksten på skjermen.

  lcd.setCursor(0,0);
  lcd.print("Drink 2 Blandes ");
  lcd.setCursor(0,1);
  lcd.print("Vennligst vent..");
  
  stepMove(Rom);                          //Flytt glidebrett til valgt dosør
  setColorPixel(sistePosisjon-2,'r');     //Farg valgt dosør rød

  openValve(Rom);                           //Erstattes med funksjon for servoer/pumper
  delay(1500);
  openValve(Rom);                           //Erstattes med funksjon for servoer/pumper
  
  setColorPixel(sistePosisjon-2,'b');     //Farg valgt dosør blå igjen
  stepMove(Blandevann);                   //Gå til blandevann stasjonen
  
  activatePump(Cola, 7, 6000);                            //Erstattes med funksjon for servoer/pumper
  
  stepMove(Hjem);                         //Gå tilbake til HJEM posisjonen
  
  
  lcd.setCursor(0,0);
  lcd.print("Drink 2 Ferdig! ");
  lcd.setCursor(0,1);
  lcd.print("***Cheers!!!!***");
  buzzer(2,200);
  delay(5000);                            //Pauser for å vise teksten på skjermen.

}
//***************************************************************************//


//================================Screwdriver================================//

void on_Drink3_selected(MenuItem* p_menu_item)
{
 
  setColorAllPixels('b');
  lcd.setCursor(0,1);
  lcd.print("Drink 3 Valgt   ");
  buzzer(2,200);
  delay(1000);                            //Pauser for å vise teksten på skjermen.
 
  lcd.setCursor(0,0);
  lcd.print("Drink 3 Blandes ");
  lcd.setCursor(0,1);
  lcd.print("Vennligst vent..");
  
  stepMove(Vodka);                        //Flytt glidebrett til valgt dosør
  setColorPixel(sistePosisjon-2,'r');     //Farg valgt dosør rød

  openValve(Vodka);                           //Erstattes med funksjon for servoer/pumper
  delay(1500);
  openValve(Vodka);
 
  setColorPixel(sistePosisjon-2,'b');     //Farg valgt dosør blå igjen
  stepMove(Blandevann);                   //Gå til blandevann stasjonen
  
  activatePump(Appelsinjuice, 7, 6000);                            //Erstattes med funksjon for servoer/pumper
  
  stepMove(Hjem);                         //Gå tilbake til HJEM posisjonen
  
  
  lcd.setCursor(0,0);
  lcd.print("Drink 3 Ferdig! ");
  lcd.setCursor(0,1);
  lcd.print("***Cheers!!!!***");
  buzzer(2,200);
  delay(5000);                            //Pauser for å vise teksten på skjermen.
}

//***************************************************************************//
