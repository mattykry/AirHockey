/* MSG.cpp */

#include <Arduino.h>
#include "MSG.h"

MSG::MSG(int content){
  this->content = content;
}

void MSG::sendMessage(){
  Serial.println(this->content);
  
}

int MSG::getMessage(){
  return this->content;
}
