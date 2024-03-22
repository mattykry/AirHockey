 /* AirHockey.ino */
/***************************************
 *  Air Hockey Arduino uno + Raspberry *
 *                                     *
 *     Matteo Cristello Mat 730976     *
 ***************************************/

 
#include <Arduino.h>
#include "HandlerFSM.h"

HandlerFSM *fsm;


void setup(){

  fsm = new HandlerFSM();
  fsm->setUp();
}

void loop(){

 
  fsm->schedule();
  
}
