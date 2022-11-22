This project references mainly module-lab-2.2-button_led_synch_4_good_with_synch_moore, module-lab-2.3-led-show-scheduler
It is possible to change any code in the project to make the program run.

################################

smart_bridge.ino is the main program of the project. Here the initialization of the serial port, task Scheduler is performed. The task arrangement is also done here. 
For the task files, there are SmartLightingTask and WaterLevelTask.

SmartLightingTask: The subsystem used to realise the smart lighting behaviour.
WaterLevelTask: Not written.

For timer, task, Led, Scheduler. These are just copied from the Ricci's git repo. (Arduino/module-lab)

Pir.c Pir.h PirImpl.c PirImpl.h -- Basically, they are modified according based on the button of led_synch_4_good_with_synch_moore
LightDetector is the light sensor LS. it was written with reference to lab-1.3-test_photores. 
//There are also Non-Impl version of LightDetector in old_codes folder.



