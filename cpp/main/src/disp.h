#include "Arduino.h"
#include "lib/U8glib/src/U8glib.h"
#include "inputs.h"
#include "outputs.h"

#ifndef DISP_H_
#define DISP_H_

// LCD Control Pins
#define GR_LCD_RS  53
#define GR_LCD_RW  51
#define GR_LCD_E   52
static U8GLIB_ST7920_128X64_1X u8g(GR_LCD_E, GR_LCD_RW, GR_LCD_RS);

void RPMWrite(float rpm_var);                       //  Generates RPM print string and Writes it on Screen 
void CMDWrite(motor_direction_t dir);               //  Generates CMD print string and Writes it on Screen  


void InitLCD(void);                                 //  Initialize LCD
void Display(void);                                 //  Main Display Function 
void BasicFrame(void);                              //  Line Frame
void ReportingScreen(void);                         //  Info Reporting Screen

#endif