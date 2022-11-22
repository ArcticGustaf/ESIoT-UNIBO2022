#ifndef __WATERLEVELTASK__
#define __WATERLEVELTASK__

#include "Task.h"
#include "Led.h"

class WaterLevelTask: public Task {

  int pin[3];
  int state;

public:

  WaterLevelTask(int pin0, int pin1, int pin2);  
  void init(int period);  
  void tick();
};

#endif
