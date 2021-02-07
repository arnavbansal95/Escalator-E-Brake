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

float ReadRPM(motor_direction_t* dir)
{
    static volatile int lastEncoded = 0;
    static volatile long encoderValue = 0;
    static volatile long prevEncoderValue = 0;
    static unsigned long prevTime = 0;
    static unsigned long currTime = 0;
    static int MSB;
    static int LSB;
    static int encoded;
    static int sum;
    static motor_direction_t dir_var = STOP;
    static float rpm = 0;

    MSB = ReadInput(ENCODER_A);                                         //MSB = most significant bit
    LSB = ReadInput(ENCODER_B);                                         //LSB = least significant bit
    encoded = (MSB << 1) | LSB;                                         //converting the 2 pin value to single number
    sum = (lastEncoded << 2) | encoded;                                 //adding it to the previous encoded value
    if((sum != 0b0000) && (sum != 0b1111) && (sum != 0b0101) && (sum != 0b1010))
    {
        /*if((sum == 0b1101) || (sum == 0b0100) || (sum == 0b0010) || (sum == 0b1011))
            encoderValue ++;
        if((sum == 0b1110) || (sum == 0b0111) || (sum == 0b0001) || (sum == 0b1000))
            encoderValue --;*/
        encoderValue++;
        Serial.println(encoderValue);
    }
    lastEncoded = encoded;                                                  //store this value for next time
    
    /*currTime = millis();
    if((currTime - prevTime) > 1000)
        long diff = EncoderDataDecoder((encoderValue - prevEncoderValue), &dir_var);
        Serial.println(diff);
        rpm = ((float)diff / (float)1024) * 60;
        prevEncoderValue = encoderValue;
        prevTime = currTime;
    }*/
    *dir = dir_var;
    return(rpm);
}

long EncoderDataDecoder(long encodedVal, motor_direction_t* dir)
{
    if(encodedVal < 0)
    {
        *dir = FWD;
        return((-1)*encodedVal);
    }
    else 
    {
        if(encodedVal > 0)
            *dir = REV;
        else
            *dir = STOP;
        return(encodedVal);
    }
}