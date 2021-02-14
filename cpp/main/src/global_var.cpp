#include "global_var.h"

static float *rpm;
static motor_direction_t *dir;

void setGlobalRPM(float *rpm_var)
{
    rpm = rpm_var;
}

void setGlobalDir(motor_direction_t *dir_var)
{
    dir = dir_var;
}

float retGlobalRPM(void)
{
    return(*rpm);
}

motor_direction_t retGlobalDir(void)
{
    return(*dir);
}