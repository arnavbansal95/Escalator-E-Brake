#include "Arduino.h"
#include "inputs.h"

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

// 24v Isolated Signal Outputs
#define OUT_ENCODER_A   13          //  OUTPUT ENCODER_PIN A (Green)
#define OUT_ENCODER_B   12          //  OUTPUT ENCODER_PIN B (White)

// Relay Outputs
#define OUTPUT_RLY1     23          //  Spare 1 Relay 
#define OUTPUT_RLY2     25          //  Spare 2 Relay

void InitOutputs(void);             //  Initialize Outputs
void ReplicateInputSignal(void);    //  Replicates Input Signal from Input Encoder to Output Encoder Pins

#endif