/* MyLiquidCrystal.h */

#ifndef __MYLIQUIDCRYSTAL__
#define __MYLIQUIDCRYSTAL__

#include <LiquidCrystal.h>
#include "Arduino.h"

class MyliquidCrystal {

	public:

		MyliquidCrystal(int pin1,int pin2,int pin3, int pin4, int pin5, int pin6);
		~MyliquidCrystal();
   
   void printIntestation();
   void printIntestationGame(int playerOneScore, int playerTwoScore);
   void printEndGame(int playerOneScore, int playerTwoScore);
   void digitalClock(long timeNow);
   void printDigits(int digits);
   
	private:

	LiquidCrystal* _display;


};
#endif
