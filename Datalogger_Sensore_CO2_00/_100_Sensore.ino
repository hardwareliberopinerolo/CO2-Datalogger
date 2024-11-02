


void SCD40_setup(){


  //mySensor.enableDebugging(); // Uncomment this line to get helpful debug messages on Serial
  
  //mySensor.enableDebugging(Serial1); // Uncomment this line instead to get helpful debug messages on Serial1

  if (mySensor.begin(Wire1) == false) // .begin the sensor on Wire1 instead of Wire
  {
    Serial.println(F("Sensor not detected. Please check wiring. Freezing..."));
    while (1)
      ;
  }
}


void SCD40_read(){
  if (mySensor.readMeasurement()) // readMeasurement will return true when fresh data is available
  {
    Serial.println();

    Serial.print(F("CO2(ppm):"));
	CO2data = mySensor.getCO2();
    Serial.print(CO2data);

 
    Serial.print(F("\tTemperature(C):"));

    Tdata = mySensor.getTemperature();
    Serial.print(Tdata, 1);



    Serial.print(F("\tHumidity(%RH):"));
    Hdata = mySensor.getHumidity();
    Serial.print(Hdata, 1);
    


    Serial.println();
  }
  else
    Serial.print(F("."));



}
