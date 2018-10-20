void setup() {
  
//=====================Initialisering av innganger===========================//

for (byte i=1; i<=4; i++){                     //Sett SW1-4 knapper til å være input med pullup
  pinMode(SW[i],INPUT_PULLUP); 
 }

for (byte i=1; i<=8; i++){                     //Sett Pos1-8 sensorer til å være input
  pinMode(Pos[i],INPUT); 
 }

//=====================Initialisering av utganger============================//

for (byte i=1; i<=3; i++){                     //Sett LED1-3 på kontrollpanel til å være output
  pinMode(LED[i],OUTPUT); 
 }

pinMode(BUZ1,OUTPUT);                          //Sett buzzer på kontrollpanel til å være output

pinMode(stepEnable,OUTPUT);                    //Sett Enable, Dir, Clk signaler til stepp kontrolleren til å være output
pinMode(stepDir,OUTPUT); 
pinMode(stepClk,OUTPUT);
digitalWrite(stepEnable,LOW);                  //Initialiser stepp kontrolleren som deaktivert.
  
//========================Attach pumps=======================================//

  for(byte i=0; i < (numberOfPumps); i++) {  
    pump[i]=(9+i);                             // Available pins: 9 - 12
    pinMode(pump[i], OUTPUT);                  // Set pins as output
  }
//==========================================================================//
//========================Attach servos=====================================//

  for(byte i=0; i < (numberOfServos); i++) {  
    servo[i].attach(2+i);                       //Available pins: 2 - 8
    servo[i].writeMicroseconds(1500);           // Initializing stand still
  }
//==========================================================================//


//======Initialisering av LED strip1, LCD display og bygging av meny========//


strip1.begin();                  //Initialiser LED strip1                             

lcd.begin(16,2);                 //Initialiser LCD display og setter størrelsen (her 16 karakterer på hver av de 2 linjene)

  // Meny setup - Bygger menyen etter følgende herarki modell
          /*
            Meny Struktur:
             -Drink meny
             --Drink1
             --Drink2
             --Drink3
             -Shots meny
             --Shot1
             --Shot2
             --Shot3
   
           */
  mm.add_menu(&mm_muD);
    mm_muD.add_item(&muD_mD1, &on_Drink1_selected);
    mm_muD.add_item(&muD_mD2, &on_Drink2_selected);
    mm_muD.add_item(&muD_mD3, &on_Drink3_selected);
  
  mm.add_menu(&mm_muS);
    mm_muS.add_item(&muS_mS1, &on_Shot1_selected);
    mm_muS.add_item(&muS_mS2, &on_Shot2_selected);
    mm_muS.add_item(&muS_mS3, &on_Shot3_selected);
  
  ms.set_root_menu(&mm);

  lcd.setCursor(0,0);
  lcd.print(" BARon starter  ");
  lcd.setCursor(0,1);
  lcd.print(" Vennligst vent ");
 
  stepMove(Hjem);                           //Kjør til startposisjon.

  displayMenu();                            //Vis menyen
}
