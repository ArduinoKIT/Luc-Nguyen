#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x3F,16,2);

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void setup () 
{
  Serial.begin(9600);
  lcd.init();   
  lcd.backlight();
  if (! rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
  }
  
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manualy 
  
}

void loop () 
{
    DateTime now = rtc.now();
    
    lcd.setCursor(4, 1);
    if(now.hour()<=9)
    {
      lcd.print("0");
      lcd.print(now.hour());
    }
    else {
     lcd.print(now.hour()); 
    }
    lcd.print(':');
    if(now.minute()<=9)
    {
      lcd.print("0");
      lcd.print(now.minute());
    }
    else {
     lcd.print(now.minute()); 
    }
    lcd.print(':');
    if(now.second()<=9)
    {
      lcd.print("0");
      lcd.print(now.second());
    }
    else {
     lcd.print(now.second()); 
    }
    lcd.print("   ");

    lcd.setCursor(1, 0);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(",");
    if(now.day()<=9)
    {
      lcd.print("0");
      lcd.print(now.day());
    }
    else {
     lcd.print(now.day()); 
    }
    lcd.print('/');
    if(now.month()<=9)
    {
      lcd.print("0");
      lcd.print(now.month());
    }
    else {
     lcd.print(now.month()); 
    }
    lcd.print('/');
    if(now.year()<=9)
    {
      lcd.print("0");
      lcd.print(now.year());
    }
    else {
     lcd.print(now.year()); 
    }
   
}
