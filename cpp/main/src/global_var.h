#ifndef GLOBAL_VAR_H_
#define GLOBAL_VAR_H_

typedef enum
{
    FWD,
    REV,
    STOP
} motor_direction_t;

void setGlobalRPM(float *rpm_var);
void setGlobalDir(motor_direction_t *dir_var);

float retGlobalRPM(void);
motor_direction_t retGlobalDir(void);

#endif