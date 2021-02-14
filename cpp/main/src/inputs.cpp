#include "inputs.h"

void InitInputs(void)
{
    pinMode(ENCODER_A, INPUT);
    pinMode(ENCODER_B, INPUT);
    attachInterrupt(0, IntRout0, RISING);
    attachInterrupt(1, IntRout1, RISING);
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
    static float rpmArr[ARR_SIZE], rpm;
    for(int i=0;i<ARR_SIZE;i++)
    {
        randNum = random(1450, 1650);
        rpmArr[i] = (float)randNum / (float)100;
    }
    rpm = filterData(&rpmArr[0]);
    setGlobalRPM(&rpm);
}

float filterData(float *rpm_var)
{
    static int rpmX10[ARR_SIZE], modeBase, modeAdv, divRPM;
    static float sumRPM, calcRPM;
    memset(rpmX10, 0, ARR_SIZE);
    sumRPM = 0;
    divRPM = 0;
    modeBase = findMode(rpm_var);
    for(int i=0;i<ARR_SIZE;i++)
    {   
        if(modeBase == (int)*(rpm_var+i))    
            rpmX10[i] = (int)(*(rpm_var+i)*10);
        else
            rpmX10[i] = -1;
    }
    modeAdv = findMode(&rpmX10[0]);
    for(int i=0;i<ARR_SIZE;i++)
    {
        if(modeAdv == (int)(*(rpm_var+i)*10))
        {
            sumRPM = sumRPM + *(rpm_var+i);
            divRPM++;
        }
    }
    calcRPM = sumRPM / (float)divRPM;
    return(calcRPM);
}

int findMode(float *inArr)
{
    int number = (int)*inArr;
    int mode = number;
    int count = 1;
    int countMode = 1;

    for (int i=1;i<ARR_SIZE;i++)
    {
        if((int)*(inArr+i) > 0)
        {
            if ((int)*(inArr+i) == number) 
            ++count;
            else
            { 
                if (count > countMode) 
                {
                    countMode = count;
                    mode = number;
                }
                count = 1; 
                number = (int)*(inArr+i);
            }
        }
    }
    return(mode);
}

int findMode(int *inArr)
{
    int startVar = 0;
    while(*(inArr + startVar) < 0)
        startVar++;
    int number = *(inArr + startVar);
    int mode = number;
    int count = 1;
    int countMode = 1;

    for (int i=(startVar+1);i<ARR_SIZE;i++)
    {
        if(*(inArr+i) > 0)
        {
            if (*(inArr+i) == number) 
                ++count;
            else
            { 
                if (count > countMode) 
                {
                    countMode = count;
                    mode = number;
                }
                count = 1; 
                number = *(inArr+i);
            }
        }
    }
    return(mode);
}