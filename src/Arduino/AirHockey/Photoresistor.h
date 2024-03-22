/* Photoesistor.h */

#ifndef __PHOTORESISTOR__
#define __PHOTORESISTOR__


class Photoresistor {

   public:

	Photoresistor(int pin);
	void checkIntensity(int pin);
	bool isGoal(int pin);
  int getIntensity();

   private:

  int limit;
	int pin;
	int intensity = 0;
};

#endif
