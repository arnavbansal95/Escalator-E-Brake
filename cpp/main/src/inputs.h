#include "Arduino.h"
#include "global_var.h"

#ifndef INPUTS_H_
#define INPUTS_H_

#define DEFAULT_INPUT     128                   //  Default Value for ReadInput
#define ARR_SIZE          50                    //  Array size for statistics calclulations

#define ENCODER_A    A0                         //  ENCODER_PIN A (Green)
#define ENCODER_B    A1                         //  ENCODER_PIN B (White)

void InitInputs(void);                          //  Initialize Inputs
uint8_t ReadInput(int Input);                   //  Read Inputs
void CalcRPM(void);                             //  Calculate RPM
float filterData(float *rpm_var);               //  Data filters for stable output
int findMode(float *inArr);                     //  Returns mode (statistics) from inArr
int findMode(int *inArr);                       //  Returns mode (statistics) from inArr

void IntRout0(void);                            //  Interrupt Routine for INT.0
void IntRout1(void);                            //  Interrupt Routine for INT.1

#endif