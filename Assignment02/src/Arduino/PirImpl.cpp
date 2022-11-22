#include "PirImpl.h"
#include "Arduino.h"

PirImpl::PirImpl(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);  
  sync();   
} 
  
bool PirImpl::isDetected(){
  return detected;
}

void PirImpl::sync(){
  detected = digitalRead(pin) == HIGH;
  updateSyncTime(millis());
}
