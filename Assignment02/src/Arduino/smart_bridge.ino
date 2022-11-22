#include "Scheduler.h"
#include "SmartLightingTask.h"
#include "WaterLevelTask.h"
#define PIN_LED1 13
#define PIN_PIR 2
//#define PIN_LIGHT_SENSOR A0


Scheduler sched;
//Timer timer;

void setup(){

  Serial.begin(9600);
  sched.init(100);
 
  Task* t0 = new SmartLightingTask(PIN_LED1,PIN_PIR,PIN_LIGHT_SENSOR);
  t0->init(100);

  Task* t1 = new WaterLevelTask();
  t1->init(100);
  
  sched.addTask(t0);
  sched.addTask(t1);
   
}

void loop(){
  sched.schedule();
}
