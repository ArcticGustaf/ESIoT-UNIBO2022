#ifndef __SMARTLIGHTINGTASK__
#define __SMARTLIGHTINGTASK__

#include "Task.h"
#include "Led.h"
#include "Timer.h"
#include "Pir.h"
#include "LightDetector.h"

class SmartLightingTask: public Task {

  int pin_led, pin_pir, pin_light_sensor;
  Light* led;
  Pir* pir;
  LightDetector* light_detector;
  enum { ON, OFF, SWITCHING_ON, SWITCHING_OFF} state;

public:

  SmartLightingTask(int pin_led,int pin_pir,int pin_light_sensor);  
  void init(int period);  
  void tick();
  double threshold;
};

#endif

