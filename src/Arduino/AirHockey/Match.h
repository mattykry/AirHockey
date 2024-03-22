/* interface Match.h */

#ifndef __MATCH__
#define __MATCH__

class Match {

   public:

	virtual int getScorePlayerOne();
	virtual int getScorePlayerTwo();
	virtual void playerOneGoal();
	virtual void playerTwoGoal();
  virtual void resetResults();



};

#endif
