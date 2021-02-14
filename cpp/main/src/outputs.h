#include "Arduino.h"
#include "inputs.h"

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

// Relay Outputs
#define OUTPUT_BRK1     23          //  Brake 1 Relay 
#define OUTPUT_RLY2     25          //  Spare 2 Relay
typedef enum
{
    ON,
    OFF
} relay_status_t;

void InitOutputs(void);             //  Initialize Outputs

#endif