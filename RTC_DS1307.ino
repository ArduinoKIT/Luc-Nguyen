#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void setup () 
{
  Serial.begin(9600);
  if (! rtc.begin()) 
  {
    Serial.print("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) 
  {
    Serial.print("RTC is NOT running!");
    Serial.println();
  }
  
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manualy 
  
}

void loop () 
{
    DateTime now = rtc.now();
    if(now.hour()<=9)
    {
      Serial.print("0");
      Serial.print(now.hour());
    }
    else {
     Serial.print(now.hour()); 
    }
    Serial.print(':');
    if(now.minute()<=9)
    {
      Serial.print("0");
      Serial.print(now.minute());
    }
    else {
     Serial.print(now.minute()); 
    }
    Serial.print(':');
    if(now.second()<=9)
    {
      Serial.print("0");
      Serial.print(now.second());
    }
    else {
     Serial.print(now.second()); 
    }
    Serial.println();
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(",");
    if(now.day()<=9)
    {
      Serial.print("0");
      Serial.print(now.day());
    }
    else {
     Serial.print(now.day()); 
    }
    Serial.print('/');
    if(now.month()<=9)
    {
      Serial.print("0");
      Serial.print(now.month());
    }
    else {
     Serial.print(now.month()); 
    }
    Serial.print('/');
    if(now.year()<=9)
    {
      Serial.print("0");
      Serial.print(now.year());
    }
    else {
     Serial.print(now.year()); 
    }
   
}
