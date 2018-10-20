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
#include "Adafruit_WS2801.h"
#include "SPI.h"


//==========================================================================//
//===========================Global variables===============================//

const byte numberOfServos = 3;         // Number of servos
const byte numberOfPumps = 3;          // Number of pumps, max is 4
      byte pump[numberOfPumps];    // Creates array of pumps, counting from 0
     Servo servo[numberOfServos];  // Creates array of servos, counting from 0

boolean lastButton = HIGH;             //Var en knapp trykket siste scan?
byte    sistePosisjon = 10;            //Hva var siste posisjon for glidebrettet, initialiseres som 10 for å flagge at posisjonen er 
                                       //ukjent før første gang "stepMove(Hjem)" funksjonen skal kjøres i "Setup(){}" og finne startposisjonen


//==========================Definisjon av innganger==========================//

const byte SW[5]={0,A12,A13,A14,A15};                //Innganger fra knapper på kontrollpanel

const byte Pos[9]={0,A0,A1,A2,A3,A4,A5,A6,A7};       //Innganger fra posisjons-sensor kort


//==========================Definisjon av utganger===========================//

const byte BUZ1 = 13;                                //Utgang til buzzer på kontrollpanel

const byte LED[4] ={0,40,38,36};                     //Utganger til LED påkontrollpanel

LiquidCrystal lcd(52,50,48,46,44,42);                //Utganger til LCD på kontrollpanel

const byte  stepClk=22, stepEnable=24, stepDir=26;   //Utganger til stepper kontroller


const byte strip1_Clk = 28;                                 //Clk utgang til LED strip 1, over flasker
const byte strip1_SDA = 30;                                 //Data utgang til LED strip 1, over flasker
const byte strip1_Pix =  3;                                 //Antall pixler på LED strip 1 (antall RGB dioder)
WS2801 strip1 = WS2801(strip1_Pix, strip1_SDA, strip1_Clk); //Lag objektet LED strip1 og definer antall pixler og utganger



//=======================*****Meny variable*****=============================//

//==============================Hovedmeny====================================//

MenuSystem ms;
  Menu mm    (" BARon er klar! ");                    //Hovedmeny toppnivå
  Menu mm_muD("Drink Meny      ");                    //Drink meny
  Menu mm_muS("Shots Meny      ");                    //Shots meny
//Menu mm_muA     ("Admin Meny      ");               //Admin meny (må kreve passord, ikke prioritert enda, kan bli fjernet)


//=============================Drink meny===================================//
//Undermeny valg for Drink meny
MenuItem muD_mD1("Gin & Tonic    G");                   
MenuItem muD_mD2("Cuba Libre     R");                  
MenuItem muD_mD3("Screwdriver    V");

//=============================Shots meny===================================//
//Undermeny valg for Shots meny
MenuItem muS_mS1("25ml Gin shot   ");
MenuItem muS_mS2("25ml Rom shot   ");
MenuItem muS_mS3("25ml Vodka shot ");

//***************************************************************************//

//==========================Posisjon for flasker=============================//

const byte Gin           = 2;
const byte Rom           = 3;
const byte Vodka         = 4;

//***************************************************************************//
//=========================Pumpe nr. for blandevann==========================//

const byte Tonic         = 1;    //Pumpe for Tonic Water
const byte Cola          = 2;    //Pumpe for Cola 
const byte Appelsinjuice = 3;    //Pumpe for Appelsinjuice

//const int  tidTonic         =;  //Pumpe tid for å få rett mengde med denne ingrediensen
//const int  tidCola          =;  //Pumpe tid for å få rett mengde med denne ingrediensen
//const int  tidAppelsinjuice =;  //Pumpe tid for å få rett mengde med denne ingrediensen

//***************************************************************************//
//============================Øvrige Posisjoner==============================//

const byte Hjem       = 1;
const byte Blandevann = 8;

//***************************************************************************//






void loop() {

rainbowCycle(20);                          //Scanner gjennom farger for LED strip1 når BARon ikke jobber
menuHandler();                             //Menynavigering, hovedrutine

}
