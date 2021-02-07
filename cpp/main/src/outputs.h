#include "Arduino.h"
#include "inputs.h"

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

// 24v Isolated Signal Outputs
#define OUT_ENCODER_A   13          //  OUTPUT ENCODER_PIN A (Green)
#define OUT_ENCODER_B   12          //  OUTPUT ENCODER_PIN B (White)

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