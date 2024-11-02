void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
Serial.println(F("SCD4x Datalogger"));


//setup I2C
Wire1.setSDA(DSDA);
Wire1.setSCL(DSCL);
Wire1.begin(); 


//setup SCD40
SCD40_setup();

//setup Oled
Oled_setup();

// setup RTC
RTC_setup();

//setup CH376
Ch376_setup();


}
