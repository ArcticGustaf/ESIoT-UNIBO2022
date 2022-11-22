#include "WaterLevelTask.h""
#include "Arduino.h"

WaterLevelTask::WaterLevelTask(int pin0, int pin1, int pin2){
  this->pin = pin0;    
  this->pin = pin1;    
  this->pin = pin2;    
}
  
void WaterLevelTask::init(int period){
  Task::init(period);

}
  
void WaterLevelTask::tick(){

}
