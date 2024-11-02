void Pulsante_oled(){

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
	tasto=1;
	time_now3 = millis();
	}
}
