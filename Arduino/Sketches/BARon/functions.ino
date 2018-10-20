
//==========================================================================//
//========================Function activatePump=============================//
//  activatePump will activate the corresponding pump.                      //
//  Input: pump number count from 1, speed (0-10), and ON time in milli sec.//
//==========================================================================//

void activatePump(byte pumpNumber, byte analogSpeed, int timeOn) {
  
    pumpNumber  = (pumpNumber-1);          // Makes it count from 0 in array
    analogSpeed = (analogSpeed * 25);      // Speed range 0 - 10
    
    analogWrite(pump[pumpNumber], analogSpeed);
    delay(timeOn);
    digitalWrite(pump[pumpNumber], LOW);
}


//==========================================================================//
//========================Function openValve================================//
//  openValve will activate the servo attached to the corresponding valve.  //
//  Input: servo number counting from 1.                                    //
//==========================================================================//

void openValve(byte servoNumber) {

    servoNumber = (servoNumber-1);            // Makes it count from 0 in array
  
    servo[servoNumber].writeMicroseconds(2400);     // Open
    delay(5000);                                      
    servo[servoNumber].writeMicroseconds(1550);     // hold
    delay(5000);
    servo[servoNumber].writeMicroseconds(544);      // Close
    delay(5000);
    servo[servoNumber].writeMicroseconds(1500);     // Still
  }
//==========================================================================//






//========================Function posSense================================//
//  Finner nåværende posisjon ved å sjekke status for 
//
//==========================================================================//
   
byte posSense(){                               //Funksjonsstart
  
  byte memPos = 0;                             //Minne for å lese posisjon til
  boolean mem[9];                              //Minner å lese knappestatus til
  

for (byte i = 1; i<=7; i++){                   //Sjekk status posisjon sensor 1-8
  mem[i] = digitalRead (Pos[i]);               
 }

                                                //Sjekker kombinasjonsmønster på posisjonssensorene
  if      (mem[1]==LOW  & mem[2]==LOW  & mem[3]==LOW  & mem[4]==LOW  & mem[5]==LOW  & mem[6]==LOW  & mem[7]==LOW  & mem[8]==LOW ) {memPos = 0;}    //Ikke ved en fast posisjon
  else if (mem[1]==HIGH & mem[2]==LOW  & mem[3]==LOW  & mem[4]==LOW  & mem[5]==LOW  & mem[6]==LOW  & mem[7]==LOW  & mem[8]==LOW ) {memPos = 1;}    //Ved posisjon 1
  else if (mem[1]==LOW  & mem[2]==HIGH & mem[3]==LOW  & mem[4]==LOW  & mem[5]==LOW  & mem[6]==LOW  & mem[7]==LOW  & mem[8]==LOW ) {memPos = 2;}    //Ved posisjon 2
  else if (mem[1]==LOW  & mem[2]==LOW  & mem[3]==HIGH & mem[4]==LOW  & mem[5]==LOW  & mem[6]==LOW  & mem[7]==LOW  & mem[8]==LOW ) {memPos = 3;}    //Ved posisjon 3
  else if (mem[1]==LOW  & mem[2]==LOW  & mem[3]==LOW  & mem[4]==HIGH & mem[5]==LOW  & mem[6]==LOW  & mem[7]==LOW  & mem[8]==LOW ) {memPos = 4;}    //Ved posisjon 4
  else if (mem[1]==LOW  & mem[2]==LOW  & mem[3]==LOW  & mem[4]==LOW  & mem[5]==HIGH & mem[6]==LOW  & mem[7]==LOW  & mem[8]==LOW ) {memPos = 5;}    //Ved posisjon 5
  else if (mem[1]==LOW  & mem[2]==LOW  & mem[3]==LOW  & mem[4]==LOW  & mem[5]==LOW  & mem[6]==HIGH & mem[7]==LOW  & mem[8]==LOW ) {memPos = 6;}    //Ved posisjon 6
  else if (mem[1]==LOW  & mem[2]==LOW  & mem[3]==LOW  & mem[4]==LOW  & mem[5]==LOW  & mem[6]==LOW  & mem[7]==HIGH & mem[8]==LOW ) {memPos = 7;}    //Ved posisjon 7
  else if (mem[1]==LOW  & mem[2]==LOW  & mem[3]==LOW  & mem[4]==LOW  & mem[5]==LOW  & mem[6]==LOW  & mem[7]==LOW  & mem[8]==HIGH) {memPos = 8;}    //Ved posisjon 8
  else                                                                                                                            {memPos = 9;}    //Ved to posisjoner samtidig, FEIL!, ulovlig!
  
  if (memPos == 9) ugyldigPos();                 //Kjør funksjon for ulovlig posisjon hvis ulovlig posisjon
  
  return memPos;                                 //Avslutt funksjon, returner posisjons nummer
 }   

//==========================================================================//




//========================Function stepMove=================================//
//  stepMove tar imot adressen til neste posisjon, sjekker nåværende posisjon 
//  og bestemmer hvilken retning den må flytte glidebrettet for å nå posisjonen.
//  Stepperen klokkes 20 stepp før det sjekkes om ønsket posisjon er oppnådd
//  er den ikke det sendes 20 nye klokkepulser. 
//  Input: posisjons ID som en byte                                         
//==========================================================================//

void stepMove(byte pos){                      //Funksjon for å flytte til neste posisjon
   byte sistPos = posSense();                 //Sjekk hva som er nåværende posisjon
   boolean dir = posDirSense(pos,sistPos);    //Sjekk i hvilken retning neste posisjon ligger
     
   while ( sistPos != pos){                   //Mens nåværende posisjon ulik neste posisjon
    digitalWrite(stepDir,dir);                //Sett dreieretningen til step motoren
    digitalWrite(stepEnable,HIGH);            //Aktiver step motoren
    
    for (byte i=0; i<=20; i++){               // Send 20 klokkepulser til stepmotoren,
      digitalWrite(stepClk,HIGH);             // den vil flytte seg enten 20 helstep eller 20 halvstep
      delayMicroseconds (1500);               // avhengig av stillingen til jumperen på stepkontroller kortet.
      digitalWrite(stepClk,LOW);
      delayMicroseconds (100);
     }
    digitalWrite(stepEnable,LOW);             //Deakitver stepperen
    sistPos = posSense();                     //Oppdater nåværende posisjon
   }
   sistePosisjon = sistPos;                   //Oppdater global variabel
  }                                           //Avslutt funksjon, ikke returner noe
//==========================================================================//




//========================Function posDirSense==============================//
//  Tar imot to posisjons adresser som to byte og bestemmer hvilken retning
//  stepperen må bevege seg for å nå neste posisjon.
//==========================================================================//

  boolean posDirSense(byte nestePos, byte sistePos){      //Funksjonsstart
    if (nestePos < sistePos) return HIGH;                 //Hvis neste posisjon venstra fra forrige, returner kjør venstre.
    else return LOW;                                      //Ellers returner kjør høyre
   }                                                      //Avslutt funksjon
//==========================================================================//




//========================Function ugyldigPos==============================//
//  Gir alarm og stopper hvis glidebrettet oppnår en ulovlig posisjon
//  stepperen må bevege seg for å nå neste posisjon.
//==========================================================================//

void ugyldigPos(){                                //Funksjonsstart

  digitalWrite(stepEnable,LOW);                   //Deaktiver stepperen

  lcd.setCursor(9,0);                             //Gi alarm på kontrollpanel LCD 
  lcd.print("ULOVLIG");
  lcd.setCursor(0,1);
  lcd.print("!!!!NODSTOPP!!!!");
  
  for (int i=0; i<=20; i++){                      //Gi alarm med buzzer og lysdiode på kontrollpanel
    if (i < 5) analogWrite(BUZ1,150);
    digitalWrite(LED[1],HIGH);
    delay(200);
    
    analogWrite(BUZ1,0);
    digitalWrite(LED[1],LOW);
    delay(100);
    }
   
 }                                                //Funksjonsslutt, ikke returner noe
 
//==========================================================================//






//========================Function menuHandler==============================//
//  Gir alarm og stopper hvis glidebrettet oppnår en ulovlig posisjon
//  stepperen må bevege seg for å nå neste posisjon.
//==========================================================================//

void menuHandler(){                                //Funksjonsstart
  byte pusButton = 0;                              //Minne å lese trykket knapp til
  boolean button[5];                               //Minner å lese knappestatus til
  
  
  for (byte i = 1; i<=7; i++){                     //Sjekk status Back, Prev, Next, Select knapp
  button[i] = digitalRead (SW[i]);               
 }
  
  if       (button[1] == LOW & lastButton != LOW)           { pusButton = 1, lastButton = LOW;  }       //Back knapp trykket
  else if  (button[2] == LOW & lastButton != LOW)           { pusButton = 2, lastButton = LOW;  }       //Prev knapp trykket
  else if  (button[3] == LOW & lastButton != LOW)           { pusButton = 3, lastButton = LOW;  }       //Next knapp trykket
  else if  (button[4] == LOW & lastButton != LOW)           { pusButton = 4, lastButton = LOW;  }       //Sele knapp trykket
  else if  (button[1] & button[2] & button[3] & button[4] == HIGH){ pusButton = 0, lastButton = HIGH; } //Ingen knapp trykket
  else                                                        pusButton = 0;                            //Ingen knapp default

 
  switch (pusButton){
    case 1:          //Back trykket
      ms.back();
      displayMenu();
      break;
    case 2:          //Prev trykket
      ms.prev();
      displayMenu();
      break;
    case 3:          //Next trykket
      ms.next();
      displayMenu();
      break;
    case 4:          //Sele trykket
      ms.select();
      displayMenu();
      break;
    default:
      break;
 
  }

}                                                    //Avslutt funksjon
//==========================================================================//





//========================Function displayMenu==============================//
//  
//==========================================================================//
void displayMenu() {
  lcd.clear();
  lcd.setCursor(0,0);
  // Display the menu
  Menu const* cp_menu = ms.get_current_menu();

  //lcd.print("Current menu name: ");
  lcd.print(cp_menu->get_name());
  
  lcd.setCursor(0,1);
  
  lcd.print(cp_menu->get_selected()->get_name());
}

//==========================================================================//

 void skrivPosisjon(){               //Funksjon for å skrive nåværende posisjon på skjermen
 
    if (sistePosisjon > 8){          //Hvis to posisjoner samtidig, gi alarm.
      ugyldigPos();
     }
    else {    
      lcd.setCursor(9,0);            //Gå til karakter 9, linje 0
      lcd.print(sistePosisjon);      //Skriv ut ID til nåværende posisjon
     }
  }
