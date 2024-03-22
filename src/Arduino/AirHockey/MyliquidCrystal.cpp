/* MyliquidCrystal.cpp */

#include "MyliquidCrystal.h"


MyliquidCrystal::MyliquidCrystal(int pin1,int pin2,int pin3, int pin4, int pin5, int pin6){

	_display = new LiquidCrystal(pin1,pin2,pin3,pin4,pin5, pin6);
	
}

MyliquidCrystal::~MyliquidCrystal(){

}

void MyliquidCrystal::printIntestation() {
  
  _display->begin(16, 2);
  _display->print("AIR HOCKEY 2022");
  _display->setCursor(0,1);
  _display->print("MATTEO CRISTELLO");  

  
}

void MyliquidCrystal::printIntestationGame(int playerOneScore, int playerTwoScore){

  _display->print("P1:");
  _display->print(playerOneScore);
  _display->print("  /  ");
  _display->print("P2:");
  _display->print(playerTwoScore);
  _display->setCursor(0,1);
  _display->print("Game time: ");

}

void MyliquidCrystal::digitalClock(long timeNow){
     
    long h,m,s;
    
    s = (millis() - timeNow ) / 1000;
    
    m = s / 60;
    h = s / 3600;
    s = s - m * 60;
    m = m - h * 60;
  
    
    printDigits(m);
    _display->print(":");
    printDigits(s);

}
void MyliquidCrystal::printDigits(int digits){
  
    if(digits < 10){

      _display->print('0');
      _display->print(digits);
    }
    else{
      _display->print(digits);
    }
  
}

void MyliquidCrystal::printEndGame(int playerOneScore, int playerTwoScore){

  _display->setCursor(2,0);
  _display->print("END GAME");
  _display->setCursor(0,1);
  _display->print("P1:");
  _display->print(playerOneScore);
  _display->print(" / ");
  _display->print("P2:");
  _display->print(playerTwoScore);
  delay(1000);

  for (int positionCounter = 0; positionCounter < 28; positionCounter++) {
  
    _display->scrollDisplayRight();
    delay(200);
  }
}
