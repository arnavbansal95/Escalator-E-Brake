#include "task.h"


void MainLoop(void)
{
    static motor_direction_t dir;
    ReadRPM(&dir);                  // Calls RPM Task regularly
}