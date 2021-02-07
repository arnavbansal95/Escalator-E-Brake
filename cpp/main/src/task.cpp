#include "task.h"


void MainTask(void)
{
    static motor_direction_t dir;
    ReadRPM(&dir);                  // Calls RPM Task regularly
}