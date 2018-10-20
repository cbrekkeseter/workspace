
/*****************************************************************************
  This pogram is made for the project
  
                                BARon
                        automatic cocktail mixer.
                    
  It will contain functions for controlling cont. rotation servos, pumps,
  stepper motors, LCD etc.
  
  The project is done @ Høgskolen i Gjøvik and is created by:
  
                          Thomas Krokengen
                          Martin Furuseth
                          Christoffer Brekkeseter
                      
*****************************************************************************/
//==========================================================================//
//=============================Libraries====================================//

#include <Servo.h>
#include <LiquidCrystal.h>
#include <MenuSystem.h>


//==========================================================================//
//===========================Global variables===============================//

const byte numberOfServos = 3;       // Number of servos
const byte numberOfPumps = 3;        // Number of pumps, max is 4
byte pump[numberOfPumps];        // Creates array of pumps, counting from 0
Servo servo[numberOfServos];     // Creates array of servos, counting from 0

boolean lastButton = HIGH;           //Var en knapp trykket siste scan?
byte sistePosisjon = 0;

//==========================Definisjon av innganger==========================//

const byte SW[5]={0,A12,A13,A14,A15};                //Innganger fra knapper på kontrollpanel

const byte Pos[9]={0,A0,A1,A2,A3,A4,A5,A6,A7};       //Innganger fra posisjons-sensor kort


//==========================Definisjon av utganger===========================//

const byte BUZ1 = 13;                                //Utgang til buzzer på kontrollpanel

const byte LED[4] ={0,40,38,36};                     //Utganger til LED påkontrollpanel

LiquidCrystal lcd(52,50,48,46,44,42);                //Utganger til LCD på kontrollpanel

const byte  stepClk=22, stepEnable=24, stepDir=26;   //Utganger til stepper kontroller


//=======================*****Meny variable*****=============================//

//==============================Hovedmeny====================================//

MenuSystem ms;
Menu mm    (" BARon er klar! ");                      //Hovedmeny toppnivå
Menu mm_muD("Drink Meny      ");                      //Drink meny
Menu mm_muS("Shots Meny      ");                      //Shots meny
//Menu mm_muA     ("Admin Meny      ");               //Admin meny (må kreve passord, ikke prioritert enda, kan bli fjernet)


//=============================Drink meny===================================//
//Undermeny valg for Drink meny
MenuItem muD_mD1("Gin & Tonic    G");                  //Meny item, 
MenuItem muD_mD2("Cuba Libre     R");
MenuItem muD_mD3("Screwdriver    V");

//=============================Shots meny===================================//
//Undermeny valg for Shots meny
MenuItem muS_mS1("25ml Gin shot   ");
MenuItem muS_mS2("25ml Rom shot   ");
MenuItem muS_mS3("25ml Vodka shot ");

//***************************************************************************//
void setup() {
  
//=====================Initialisering av innganger===========================//

for (byte i=1; i<=4; i++){                              //Sett SW1-4 knapper til å være input med pullup
  pinMode(SW[i],INPUT_PULLUP); 
 }

for (byte i=1; i<=8; i++){                              //Sett Pos1-8 sensorer til å være input
  pinMode(Pos[i],INPUT); 
 }

//=====================Initialisering av utganger============================//

for (byte i=1; i<=3; i++){                              //Sett LED1-3 på kontrollpanel til å være output
  pinMode(LED[i],OUTPUT); 
 }

pinMode(BUZ1,OUTPUT);                                   //Sett buzzer på kontrollpanel til å være output

pinMode(stepEnable,OUTPUT);                             //Sett Enable, Dir, Clk signaler til stepp kontrolleren til å være output
pinMode(stepDir,OUTPUT); 
pinMode(stepClk,OUTPUT);
digitalWrite(stepEnable,LOW);                           //Initialiser stepp kontrolleren som deaktivert.
  
//========================Attach pumps=======================================//

  for(byte i=1; i < (numberOfPumps); i++) {  
    pump[i]=(9+i);                             // Available pins: 9 - 12
    pinMode(pump[i], OUTPUT);                  // Set pins as output
  }
//==========================================================================//
//========================Attach servos=====================================//

  for(byte i=1; i < (numberOfServos); i++) {  
    servo[i].attach(2+i);                       //Available pins: 2 - 8
    servo[i].writeMicroseconds(1500);           // Initializing stand still
  }
//==========================================================================//


//============Initialisering av LCD display og bygging av meny==============//

lcd.begin(16,2);

  mm.add_menu(&mm_muD);
  mm_muD.add_item(&muD_mD1, &on_Drink1_selected);
  mm_muD.add_item(&muD_mD2, &on_Drink2_selected);
  mm_muD.add_item(&muD_mD3, &on_Drink3_selected);
  
  mm.add_menu(&mm_muS);
  mm_muS.add_item(&muS_mS1, &on_Shot1_selected);
  mm_muS.add_item(&muS_mS2, &on_Shot2_selected);
  mm_muS.add_item(&muS_mS3, &on_Shot3_selected);
  
  ms.set_root_menu(&mm);

  displayMenu();

}

void loop() {
  
sistePosisjon = posSense();
 
skrivPosisjon();
boolean statSW1 = HIGH;
while (statSW1 == HIGH){
   statSW1 = digitalRead(SW[1]);
}
   
 if      (sistePosisjon == 1){
           stepMove(2);
           skrivPosisjon();
           delay(1000);}
 else if (sistePosisjon == 2){
           stepMove(3);
           skrivPosisjon();
           delay(1000);}
 else if (sistePosisjon == 3){
           stepMove(4);
           skrivPosisjon();
           delay(1000);}           
 else if (sistePosisjon == 4){
           stepMove(8);
           skrivPosisjon();
           delay(1000);}
 else if (sistePosisjon == 8){
           stepMove(1);
           skrivPosisjon();
           delay(1000);}
 else;
   
  
}
