#include "outputs.h"

void InitOutputs(void)
{
    for(int i=2;i<14;i++)
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
    for(int i=23;i<34;i=i+2)
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
}

void ReplicateInputSignal(void)
{
    digitalWrite(OUT_ENCODER_A, !ReadInput(ENCODER_A));
    digitalWrite(OUT_ENCODER_B, !ReadInput(ENCODER_B));
}