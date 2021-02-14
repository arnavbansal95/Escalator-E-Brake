#include "Arduino.h"

#ifndef INPUTS_H_
#define INPUTS_H_

#define DEFAULT_INPUT     128                   //  Default Value for ReadInput

#define ENCODER_A    A0                         //  ENCODER_PIN A (Green)
#define ENCODER_B    A1                         //  ENCODER_PIN B (White)

typedef enum
{
    FWD,
    REV,
    STOP
} motor_direction_t;

void InitInputs(void);                                                  //  Initialize Inputs
uint8_t ReadInput(int Input);                                           //  Read Inputs

#endif