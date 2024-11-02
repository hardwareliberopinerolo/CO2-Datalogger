#include <Wire.h>        // Instantiate the Wire library
#include <U8x8lib.h> // https://github.com/olikraus/u8g2
#define DSDA 6
#define DSCL 7
//U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* clock=*/ DSCL, /* data=*/ DSDA, /* reset=*/ U8X8_PIN_NONE); //  Oled 1.3

//U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE); //  Oled 1.3

U8X8_SH1106_128X64_NONAME_2ND_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

//U8X8_SH1106_128X64_NONAME_SW_I2C u8x8(/* clock=*/ DSCL, /* data=*/ DSDA, /* reset=*/ U8X8_PIN_NONE); //  Oled 1.3

int i=0;


#include "SparkFun_SCD4x_Arduino_Library.h" //Click here to get the library: https://github.com/sparkfun/SparkFun_SCD4x_Arduino_Library
SCD4x mySensor;


//dati da sensore
int CO2data=0; 
int Tdata=0;
int Hdata=0;


#include <DS1307.h>//https://github.com/denicsdevices/DS1307
DS1307 rtc(0x68,DSDA,DSCL,&Wire1); 
//DS1307 rtc(0x68);




#define period1 20000 //lettura sensore
#define period2 120000 //salva dati
#define period3 30000 //oled on

unsigned long time_now1 = 0;
unsigned long time_now2= 0;
unsigned long time_now3= 0;

#define buttonPin 2  //  pushbutton pin GPIO 2

int buttonState = 0;  // variable for reading the pushbutton status
int tasto=0;
int oled_on =0;
