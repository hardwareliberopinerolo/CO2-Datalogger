
void Oled_setup(){
	
        
  u8x8.begin();
  Serial.println("ok...");
  u8x8.setFont(u8x8_font_8x13B_1x2_f);
 delay(50);
 u8x8.clearLine(2);
 u8x8.setCursor(0, 2);
  u8x8.print("Test");
  Serial.println("Oled Test...");
	}


void Oled_print(){

 if (oled_on == 0){
 u8x8.clearLine(2);
  u8x8.clearLine(3);
 u8x8.setCursor(0, 2);
  u8x8.print(CO2data);

 u8x8.clearLine(4);
  u8x8.clearLine(5);
 u8x8.setCursor(0, 4);
   u8x8.print(Tdata);

    
 u8x8.clearLine(6);
  u8x8.clearLine(7);
 u8x8.setCursor(0, 6);
   u8x8.print(Hdata);

	oled_on =1;
	}
}
	

void Oled_off(){
	oled_on =0;
}
