/* config.h */

#ifndef __CONFIG__
#define __CONFIG__

#include <Arduino.h>
/* my libraries */
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Led.h"
#include "ButtonImpl.h"
#include "MatchImpl.h"
#include "Photoresistor.h"
#include "MyliquidCrystal.h"

/*define machine states*/
#define WAIT_START_GAME 0
#define SELECT_NAMES 1
#define GAME_LOOP 2
#define GAME_END 3

/* CONSTANTS PIN CONFIGURATION */
#define LED_GAME 8
#define LED_PLAYER_ONE 9
#define LED_PLAYER_TWO 10
#define BUTTON_GAME 7
#define P_PLAYER_ONE A0
#define P_PLAYER_TWO A1

extern uint8_t gamestate;

#endif
