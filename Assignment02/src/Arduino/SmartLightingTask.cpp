#include "SmartLightingTask.h"
#include "PirImpl.h"
#include "LDImpl.h"

SmartLightingTask::SmartLightingTask(int pin_led,int pin_pir,int pin_light_sensor){ //init
  this->pin_led = pin_led;
  this->pin_pir = pin_pir;
  this->pin_light_sensor = pin_light_sensor;    
}
  
void SmartLightingTask::init(int period){
  Task::init(period);
  led = new Led(pin_led); 
  pir = new PirImpl(pin_pir);
  light_detector = new LDImpl(pin_light_sensor);
  double threshold;
  threshold = 0.3; //Threshold for ambient lighting. 
  state = OFF;    
}
  
void SmartLightingTask::tick(){
  pir->sync();    //I got this from module-lab-2.2. Idk if it can work well
  light_detector->sync();
  switch (state){    
    case OFF:
      if (pir->isDetected()){
        Serial.println("pedestain is detected");
        if (light_detector->light_detect() < threshold) { //When the sensor detects a brightness < threshold || pedestain is detected, state = SWITCHING_ON
          Serial.println("bridge light is turning on...");
          state = SWITCHING_ON;
        }
      }
      break;

    case SWITCHING_ON:
      led->switchOn();
      Serial.println("bridge light is ON");
      state = ON;
      break;

    case ON:
      if (!pir->isDetected()||light_detector->light_detect() > threshold){
        state = SWITCHING_OFF;
        Serial.println("bridge light is turning off...");
      }
      break;

    case SWITCHING_OFF:
      led->switchOff();
      Serial.println("bridge light is OFF");
      state = OFF;
      break;
  }
}

