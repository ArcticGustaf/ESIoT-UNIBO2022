#include "LightDetector.h"
#include "Arduino.h"

LightDetector::LightDetector(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);    
}

double LightDetector::light_detect(){

  int value = analogRead(pin);
  double valueInVolt = ((double) value) * 5/1024;
  Serial.println(String(value) + " -> in volt: " + valueInVolt );
  //valueInVolt =     DO SOME CALCULATION?
  return valueInVolt;
}


