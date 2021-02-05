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
    u8g.drawStr(7, 32, "RPM: 30.5");
    u8g.drawStr(6, 45, "CMD: FWD");
    u8g.drawStr(9, 57, "RLY: OFF");
    u8g.setFont(u8g_font_helvB24);
    u8g.drawStr(99, 53, "!");
    u8g.drawCircle(104, 40, 16);
    u8g.drawCircle(104, 40, 15);
}