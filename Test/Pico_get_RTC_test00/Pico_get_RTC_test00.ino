/*
  Set and Get Time And Date
  Author: Denics Devices (Aaditya Dengle)
  Date: Sep 2024
*/

#include <DS1307.h>

#define pin_sda 6
#define pin_scl 7

DS1307 rtc(0x68,pin_sda,pin_scl,&Wire1);

void setup() {
  Serial.begin(115200);

  rtc.begin();
  //rtc.setFormat(24);        //Set 12 Hours Format
  //rtc.setAMPM(1);           //Set AM or PM    0 = AM  1 =PM

  /*
  rtc.setTime("15:06:00");  //Set Time    Hour:Minute:Seconds
  rtc.setDate("10/19/24");   //Set Date    Month/Date/Year
  */
}

void loop() {


  if (rtc.getTime()) {
    Serial.printf("Time %02d:%02d:%02d ", rtc.getHour(), rtc.getMinute(), rtc.getSeconds());

    if (rtc.getFormat() == 12) {  // returns 12 or 24 hour format

      if (rtc.getAMPM()) {  //return 0 = AM  1 = PM
        Serial.print("PM  ");
      } else {
        Serial.print("AM  ");
      }
    }

    Serial.printf("Date %s, %02d-%02d-%d \n ", rtc.getDay(),rtc.getMonth(), rtc.getDate(), rtc.getYear());
  }

  delay(1000);
}
