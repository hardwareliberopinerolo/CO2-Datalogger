void loop() {
  // put your main code here, to run repeatedly:

	Pulsante_oled();
	if(tasto == 1 ){
	Oled_print();
		if((unsigned long)(millis() - time_now3) > period3){
			tasto = 0;
			Oled_off();
		}
	}

	if((unsigned long)(millis() - time_now1) > period1){
		time_now1 = millis();
		SCD40_read();
	}

	if((unsigned long)(millis() - time_now2) > period2){
		time_now2 = millis();
		Ch376_savedata();
	}

}
