#ifndef __LIGHTDETCTOR__
#define __LIGHTDETCTOR__

#define PHOTORES_PIN A0
#define FREQ 5
#define PERIOD 1000/FREQ

//#include "Light.h"

class LightDetector{ 
public:
  LightDetector(int pin);
  double light_detect();
private:
  int pin;  
};

#endif
