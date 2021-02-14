#include "disp.h"

void InitLCD(void)
{
    // assign default color value
    u8g.begin();
}

void Display(void)
{
    static int delayVar = 50;
    u8g.firstPage();  
    do 
    {
        ReportingScreen();
    } while(u8g.nextPage());
    delay(delayVar); 
}

void BasicFrame(void)
{
    u8g.drawFrame(0, 0, 128, 64);
    u8g.drawFrame(1, 1, 126, 62);
    u8g.drawFrame(1, 1, 126, 19);
    u8g.drawFrame(1, 1, 126, 18);
    u8g.drawFrame(80, 19, 48, 64);
    u8g.drawFrame(81, 19, 48, 64);
}

void ReportingScreen(void)
{
    BasicFrame();
    u8g.setFont(u8g_font_helvB08);
    u8g.drawStr(8, 14, "Escalator E-Brake 1.0");
    u8g.setFont(u8g_font_helvB08);
    RPMWrite(retGlobalRPM());
    CMDWrite(retGlobalDir());
    u8g.drawStr(9, 57, "BRK: OFF");
    u8g.setFont(u8g_font_helvB24);
    u8g.drawStr(99, 53, "!");
    u8g.drawCircle(104, 40, 16);
    u8g.drawCircle(104, 40, 15);
}


void RPMWrite(float rpm_var)
{
    static char **rtn_ch;
    rtn_ch = malloc(sizeof(char*)*11);
    rtn_ch[0] = "RPM: XX.XX";
    int rpm_var_str = rpm_var * 100;
    uint8_t pos = 9;
    for(int i=0;i<5;i++)
    {
        if(pos == 7)
            rtn_ch[0][pos] = 46;                       
        else
        {
            rtn_ch[0][pos] = (rpm_var_str % 10) + 48; 
            rpm_var_str = rpm_var_str / 10;
        }
        pos--;
    }
    u8g.drawStr(7, 32, ("%s", rtn_ch[0]));
    free(rtn_ch);
}

void CMDWrite(motor_direction_t dir_var)
{
    static char **rtn_ch;
    rtn_ch = malloc(sizeof(char*)*11);
    rtn_ch[0] = "CMD: ----";
    if(dir_var == FWD)
        rtn_ch[0] = "CMD: FWD";
    if(dir_var == REV)
        rtn_ch[0] = "CMD: REV";
    if(dir_var == STOP)
        rtn_ch[0] = "CMD: STOP";    
    u8g.drawStr(6, 45, ("%s", rtn_ch[0]));
    free(rtn_ch);
}
