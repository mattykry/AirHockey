/* MatchImpl.cpp */

#include "MatchImpl.h"
#include <Arduino.h>

 MatchImpl::MatchImpl(int scorePlayerOne, int scorePlayerTwo){
  this->playerOneScore = scorePlayerOne;
  this->playerTwoScore = scorePlayerTwo;
  
}
int MatchImpl::getScorePlayerOne(){

		return this->playerOneScore;
}
int MatchImpl::getScorePlayerTwo(){

		return this->playerTwoScore;
}
void MatchImpl::playerOneGoal(){

    playerOneScore++;
    
}
void MatchImpl::playerTwoGoal(){

		playerTwoScore++;
}
void MatchImpl::resetResults(){

      this->playerOneScore = 0;
      this->playerTwoScore = 0;
      
}



  
