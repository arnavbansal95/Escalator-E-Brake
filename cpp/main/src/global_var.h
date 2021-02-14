#ifndef GLOBAL_VAR_H_
#define GLOBAL_VAR_H_

typedef enum
{
    FWD,
    REV,
    STOP
} motor_direction_t;

void setGlobalRPM(float *rpm_var);                  //  Set Global RPM Variable
void setGlobalDir(motor_direction_t *dir_var);      //  Set Global Direction Variable

float retGlobalRPM(void);
motor_direction_t retGlobalDir(void);

#endif