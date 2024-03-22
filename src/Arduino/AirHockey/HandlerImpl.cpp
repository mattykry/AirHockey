/* HandlerImpl.cpp */

#include <Arduino.h>
#include "HandlerImpl.h"
#include "config.h"
#include "Led.h"
#include "ButtonImpl.h"
#include "MatchImpl.h"
#include "Photoresistor.h"
#include "MyliquidCrystal.h"
#include "arduino-timer.h"
#include "MSG.h"


  /* objects */

Light *lightStartGame;
Light *lightPlayerOneGoal;
Light *lightPlayerTwoGoal;

Button *buttonStartGame;

Match *match;

Photoresistor *photoResistorPlayerOne;
Photoresistor *photoResistorPlayerTwo;

MyliquidCrystal *_display;

MSG *msgScorePlayerOne;
MSG *msgScorePlayerTwo;

/* timer creating */
auto timerCheckButtonIsPressed = timer_create_default(); 
auto timerCheckGoalPlayerOne = timer_create_default(); 
auto timerCheckGoalPlayerTwo = timer_create_default(); 

/* check Led game */
bool lightGameOn = false;
bool lightPlayerOne = false;
bool lightPlayerTwo = false;

/* time for build the game time, timeNow is always = millis() */
long timeNow;
long totalGameTime;


/* for inizialing my fields objects */
int ScoreDefaultPlayerOne = 0;
int ScoreDefaultPlayerTwo = 0;

bool playedGame = false;

long waitForSeeResult = 2000;  /* millis() */
long timeGoal = 500;    /* millis() */

uint8_t gamestate; /* variable to handle FSM states */

bool pressed = false;       /*variable to handle the pressure of the button*/
bool goalPlayerOne = false;
bool goalPlayerTwo = false;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



/*setting up all my objects*/
void initialize(){

      /* inizialization of my objects */
    match = new MatchImpl(ScoreDefaultPlayerOne, ScoreDefaultPlayerOne);
    lightStartGame = new Led(LED_GAME);
    lightPlayerOneGoal = new Led(LED_PLAYER_ONE);
    lightPlayerTwoGoal = new Led(LED_PLAYER_TWO);
    buttonStartGame = new ButtonImpl(BUTTON_GAME);
    photoResistorPlayerOne = new Photoresistor(P_PLAYER_ONE);
    photoResistorPlayerTwo = new Photoresistor(P_PLAYER_TWO);
    _display = new MyliquidCrystal(12, 11, 5, 4, 3, 2);
    timerCheckButtonIsPressed.every(50,CheckButton);

    Serial.begin(9600);    /* rate baud */

    _display->printIntestation(); /* start with the first instestation of the display */

    timeNow = 0;

    totalGameTime = 30000;  /*millis() 120000 (2min) */ /*30 000 = 30 secondi*/

    
}

/*      ====== procedure game state ======       */
void waitStartGame(){

  timerCheckButtonIsPressed.every(50,CheckButton);
  timerCheckButtonIsPressed.tick();
  
  if( pressed ){
    pressed = false;
    gamestate = GAME_LOOP;
  }else{
 gamestate = WAIT_START_GAME;
  }
}

void gameLoop(){
  timerCheckButtonIsPressed.every(50,CheckButton); /* setting up time for calling CheckButton() */
  timerCheckButtonIsPressed.tick();               /* tick() the timer */
  
    if (!lightGameOn && pressed) {

 // Serial.println("Starting Match...\n");
  timeNow = millis(); /* get timeNow with millis() */
  lcd.clear();


  while (millis() < timeNow + totalGameTime) {  /* while my game time is going... */



      _display->printIntestationGame(match->getScorePlayerOne(), match->getScorePlayerTwo()); /* get the instestation game */
      _display->digitalClock(timeNow);  /* get scores inside the intestation game */
      lightStartGame->switchOn(); /* switch on led game */
      lightGameOn = true;
      playedGame = true;

    
  
    timerCheckGoalPlayerOne.every(1000,checkGoalPlayerOne);
    timerCheckGoalPlayerTwo.every(1000,checkGoalPlayerTwo);
    timerCheckGoalPlayerTwo.tick();
    timerCheckGoalPlayerOne.tick();
      /* if PlayerOne makes a goal... */

   
   if (goalPlayerOne) {

    goalPlayerOne = false;
    match->playerOneGoal();
    lightPlayerOneGoal->switchOn();
    lightPlayerOne = true;
    delay(timeGoal);
    lightPlayerOneGoal->switchOff();
    lightPlayerOne = false;

    lcd.clear();
    _display->printIntestationGame(match->getScorePlayerOne
                 (),
                 match->getScorePlayerTwo());


      } 


      /* if PlayerTwo makes a goal... */

    if (goalPlayerTwo) {
    goalPlayerTwo = false;
    match->playerTwoGoal();
    lightPlayerTwoGoal->switchOn();
    lightPlayerTwo = true;
    delay(timeGoal);
    lightPlayerTwoGoal->switchOff();
    lightPlayerTwo = false;

    lcd.clear();
    _display->printIntestationGame(match->getScorePlayerOne
                 (),
                 match->getScorePlayerTwo());

      }



  }     /* end while() */


  gamestate = GAME_END;

    }

  }
    

  void gameEnd(){
    lcd.clear();
  _display->printIntestationGame(match->getScorePlayerOne(),
            match->getScorePlayerTwo());
  _display->digitalClock(timeNow);
  lightStartGame->switchOff();
  lightGameOn = false;
  pressed = false;
  delay(waitForSeeResult);
  lcd.clear();

  
   

    /* end if-control button.... */
    if (playedGame != false) {

  _display->printEndGame(match->getScorePlayerOne(),
             match->getScorePlayerTwo());
  playedGame = false;
  _display->printIntestation();
  msgScorePlayerOne = new MSG(match->getScorePlayerOne());
  msgScorePlayerTwo = new MSG(match->getScorePlayerTwo());

 if(Serial.available() == 0){
   msgScorePlayerOne->sendMessage();
    msgScorePlayerTwo->sendMessage();
 }
   
  
 
  match->resetResults();/* reset scores, it will be ready for another game with a new scores*/
  gamestate = WAIT_START_GAME;
    }
  }


/* ====== procedure about timer ====== */

bool checkGoalPlayerOne(void *){
  if (photoResistorPlayerOne->isGoal(P_PLAYER_ONE) != false){
    goalPlayerOne = true;
  }
}

bool checkGoalPlayerTwo(void *){
   if (photoResistorPlayerTwo->isGoal(P_PLAYER_TWO) != false){
      goalPlayerTwo = true;
  }
  
}

 bool CheckButton(void *){
  if ( buttonStartGame->isPressed()) { 
    pressed = true;
    }
  else
  pressed = false;
}

  
