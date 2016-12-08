#include<SoftwareSerial.h>
#include "Keyboard.h"
SoftwareSerial RC(9, 8);

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
  RC.begin(9600);
}

void loop() {
  if (RC.available() > 0) {  
    if(RC.read() == '1')
       payload();
  }
}
