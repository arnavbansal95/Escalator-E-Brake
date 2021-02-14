#include "inputs.h"

void InitInputs(void)
{
    pinMode(ENCODER_A, INPUT);
    pinMode(ENCODER_B, INPUT);
}

uint8_t ReadInput(int Input)
{
    uint8_t ret = DEFAULT_INPUT;
    if((Input <= 49) && (Input >= 37))
    {
        ret = digitalRead(Input);
    }
    if((Input >= 54) && (Input <= 69))
    {
        if(analogRead(Input) > 200)
        {
            ret = HIGH;
        }
        else
        {
            ret = LOW;
        }
    } 
    return ret;
}

void CalcRPM(void)
{
    static int randNum;
    static float rpm;
    randNum = random(1400, 1700);
    rpm = (float)randNum / (float)100;
    setGlobalRPM(&rpm);
}