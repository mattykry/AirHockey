/* Photoresistor.cpp*/

#include "Photoresistor.h"
#include "Arduino.h"
#include "Photoresistor.h"



Photoresistor::Photoresistor(int pin){
	
    this->pin = pin;
    this->intensity = analogRead(pin);
    pinMode(pin, INPUT);
    limit = this->intensity - 100;
}

void Photoresistor::checkIntensity(int pin){

	 this->intensity = analogRead(pin);

}
bool Photoresistor::isGoal(int pin){


    this->checkIntensity(pin);
    //Serial.println(intensity); /* check the intensity */
    
    if ( this->intensity <= limit ){
        delay(50);
        return true;
    }

    return false; 
}

int Photoresistor::getIntensity(){

    return this->intensity;
}


		
