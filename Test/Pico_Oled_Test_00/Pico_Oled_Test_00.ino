
#include <Wire.h>        // Instantiate the Wire library
#include <U8x8lib.h> // https://github.com/olikraus/u8g2
#define DSDA 6
#define DSCL 7
//U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* clock=*/ DSCL, /* data=*/ DSDA, /* reset=*/ U8X8_PIN_NONE); //  Oled 1.3

//U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE); //  Oled 1.3

U8X8_SH1106_128X64_NONAME_2ND_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

//U8X8_SH1106_128X64_NONAME_SW_I2C u8x8(/* clock=*/ DSCL, /* data=*/ DSDA, /* reset=*/ U8X8_PIN_NONE); //  Oled 1.3

int i=0;
void setup()
{
  Serial.begin(9600);
  delay(500);

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

}


void loop(){


delay(500);
 u8x8.clearLine(2);
  u8x8.clearLine(3);
 u8x8.setCursor(0, 2);

  u8x8.print(i);
  i++;
  Serial.println("Oled Test...");

}


//  -- END OF FILE --
