#include "LDImpl.h"
#include "Arduino.h"

LDImpl::LDImpl(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);    
}

double LDImpl::light_detect(){

  int value = analogRead(pin);
  double valueInVolt = ((double) value) * 5/1024;
  Serial.println(String(value) + " -> in volt: " + valueInVolt );
  //valueInVolt =     DO SOME CALCULATION?
  return valueInVolt;
}


void LDImpl::sync(){
  detected = digitalRead(pin) == HIGH;
  updateSyncTime(millis());
}
