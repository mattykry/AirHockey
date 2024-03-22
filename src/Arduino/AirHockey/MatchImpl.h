/* MatchImpl.h */

#ifndef __MATCHIMPL__
#define __MATCHIMPL__

#include <Arduino.h>
#include "Match.h"

class MatchImpl: public Match {

   public:

  MatchImpl(int scorePlayerOne,int scorePlayerTwo);
	int getScorePlayerOne();
	int getScorePlayerTwo(); 
  void playerOneGoal();
	void playerTwoGoal();
  void resetResults();




   private:

	int playerOneScore = 0;
	int playerTwoScore = 0;

};
#endif
