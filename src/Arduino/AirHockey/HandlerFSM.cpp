/* HandlerFSM.cpp */

#include <Arduino.h>
#include "MyLiquidCrystal.h"
#include "config.h"
#include "HandlerFSM.h"
#include "HandlerImpl.h"


HandlerFSM::HandlerFSM(){
  this->game = WAIT_START_GAME;
 
}

void HandlerFSM::setUp(){
  initialize();
}
void HandlerFSM::schedule(){

  switch (this->game){
    case WAIT_START_GAME:
          waitStartGame();
          this->game = gamestate;
          break;
    case GAME_LOOP:
          gameLoop();
          this->game = gamestate;
          break;
    case GAME_END:
          gameEnd();
          this->game = gamestate;
          break;

  }
}
