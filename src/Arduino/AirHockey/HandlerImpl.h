/* HandlerImpl.h */

#ifndef __HANDLERIMPL__
#define __HANDLERIMPL__

void initialize();
void waitStartGame();
void selectNames();
void gameLoop();
void gameEnd();


bool checkGoalPlayerOne(void *);
bool checkGoalPlayerTwo(void *);
bool CheckButton(void *);

#endif
