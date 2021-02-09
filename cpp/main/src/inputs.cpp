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

    MSB = ReadInput(ENCODER_A);                                                     //MSB = most significant bit
    LSB = ReadInput(ENCODER_B);                                                     //LSB = least significant bit
    encoded = (MSB << 1) | LSB;                                                     //converting the 2 pin value to single number
    if(encoded == 0b00)
    {
        prevTime = millis();
        while(encoded!=0b10)
            encoded = (MSB << 1) | LSB;
        Serial.println(millis() - prevTime);
    }

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