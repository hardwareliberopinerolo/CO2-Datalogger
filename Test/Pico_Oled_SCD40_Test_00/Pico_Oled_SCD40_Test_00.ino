
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


void setup()
{
  Serial.begin(9600);
  delay(500);


Serial.println(F("SCD4x Example"));
Serial.println("Avvio Oled...");
    
    //Wire.begin(DSDA,DSCL);
        // Initialize display

Wire1.setSDA(6);
Wire1.setSCL(7);
  
  Wire1.begin(); // In this example, let's use Wire1 instead of Wire

        
  u8x8.begin();
  Serial.println("ok...");
  u8x8.setFont(u8x8_font_8x13B_1x2_f);
 delay(50);
 u8x8.clearLine(2);
 u8x8.setCursor(0, 2);
  u8x8.print("Test");
  Serial.println("Oled Test...");

  //mySensor.enableDebugging(); // Uncomment this line to get helpful debug messages on Serial
  
  //mySensor.enableDebugging(Serial1); // Uncomment this line instead to get helpful debug messages on Serial1

  if (mySensor.begin(Wire1) == false) // .begin the sensor on Wire1 instead of Wire
  {
    Serial.println(F("Sensor not detected. Please check wiring. Freezing..."));
    while (1)
      ;
  }


}


void loop(){

  if (mySensor.readMeasurement()) // readMeasurement will return true when fresh data is available
  {
    Serial.println();

    Serial.print(F("CO2(ppm):"));
int CO2data = mySensor.getCO2();
    Serial.print(CO2data);

 u8x8.clearLine(2);
  u8x8.clearLine(3);
 u8x8.setCursor(0, 2);

  u8x8.print(CO2data);


    Serial.print(F("\tTemperature(C):"));

    int Tdata = mySensor.getTemperature();
    Serial.print(Tdata, 1);

 u8x8.clearLine(4);
  u8x8.clearLine(5);
 u8x8.setCursor(0, 4);
   u8x8.print(Tdata);

    Serial.print(F("\tHumidity(%RH):"));
    int Hdata = mySensor.getHumidity();
    Serial.print(Hdata, 1);
    
 u8x8.clearLine(6);
  u8x8.clearLine(7);
 u8x8.setCursor(0, 6);
   u8x8.print(Hdata);

    Serial.println();
  }
  else
    Serial.print(F("."));

  delay(500);




}


//  -- END OF FILE --
