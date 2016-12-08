void payload() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("iexplore.exe https://www.youtube.com/watch?v=5j-sY41ru4M");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void setup() {
  Serial3.begin (9600);
}

void loop() {
  if (Serial3.available ()) {  
    if(Serial3.read() == '1')
       payload();
  }
}
