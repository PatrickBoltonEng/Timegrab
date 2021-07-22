/*
 * Project Timegrab
 * Description:
 * Author:
 * Date:
 */

#include "Particle.h"

SYSTEM_THREAD(ENABLED);

#define UPDATE_INTERVAL 10000  //1 sec = 15000 millis

unsigned long updateInterval;

int hr_i, min_i, ampm_i, weekday_i, month_i, day_i;
String ampm_s, weekday_s, month_s;


void setup() 
{
  Serial.begin(9600);
  delay(100);
  updateInterval = millis();
}

void loop() 
{
  if ((millis() - updateInterval) > UPDATE_INTERVAL)
  {
    grabtime(hr_i, min_i, ampm_i, ampm_s, weekday_i, weekday_s, month_i, month_s, day_i);

    Serial.printlnf("Hour: %d", hr_i);
    Serial.printlnf("Min: %d", min_i);
    Serial.printlnf("Is PM: %d", ampm_i);
    Serial.println(ampm_s);
    Serial.printlnf("Weekday: %d", weekday_i);
    Serial.println(weekday_s);
    Serial.printlnf("Month: %d", month_i);
    Serial.println(month_s);
    Serial.printlnf("Day: %d", day_i);
         
    updateInterval = millis(); 
  }
}

void grabtime(int &hr_i, int &min_i, int &ampm_i, String &ampm_s, int &weekday_i, String &weekday_s, int &month_i, String &month_s, int &day_i)
{
  Time.zone(-7);

  hr_i=Time.hourFormat12();

  min_i=Time.minute();

  ampm_i = Time.isPM();

  if(ampm_i==1){ampm_s=String("PM");}
  else{ampm_s=String("AM");}

  weekday_i=Time.weekday();

  if(weekday_i==1){weekday_s=String("SUN");}
  if(weekday_i==2){weekday_s=String("MON");}
  if(weekday_i==3){weekday_s=String("TUES");}
  if(weekday_i==4){weekday_s=String("WED");}
  if(weekday_i==5){weekday_s=String("THUR");}
  if(weekday_i==6){weekday_s=String("FRI");}
  if(weekday_i==7){weekday_s=String("SAT");}
            
  month_i=Time.month();

  if(month_i==1){month_s=String("JAN");}
  if(month_i==2){month_s=String("FEB");}
  if(month_i==3){month_s=String("MAR");}
  if(month_i==4){month_s=String("APR");}
  if(month_i==5){month_s=String("MAY");}
  if(month_i==6){month_s=String("JUNE");}
  if(month_i==7){month_s=String("JULY");}
  if(month_i==8){month_s=String("AUG");}
  if(month_i==9){month_s=String("SEPT");}
  if(month_i==10){month_s=String("OCT");}
  if(month_i==11){month_s=String("NOV");}
  if(month_i==12){month_s=String("DEC");}
  day_i=Time.day();

  return;
}