void setup() {
  Serial3.begin (9600);
}

void loop() {
  char btRead;
  if (Serial3.available ()) {  
    btRead = Serial3.read();
    if(btRead == 'h'){
       Serial3.println("\r\nOptions:\r\n1: Press Capslock\r\n2: Press F11\r\n3: Press Alt+Shift (change language option)\r\n4: Press Alt+Capslock(change language option)\r\n5: Press Alt+Ctrl(change language option)\r\n6: Load PIKOTARO - PPAP Video");
    }
    if(btRead == '1'){
       Keyboard.press(KEY_CAPS_LOCK);
       Keyboard.releaseAll();
       Serial3.print("\r\nCapsLock sent sent\r\n");
    }
    else if(btRead == '2'){
       Keyboard.press(KEY_F11);
       Keyboard.releaseAll();
       Serial3.print("\r\F11 sent sent\r\n");
    }
    else if(btRead == '3'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_LEFT_SHIFT);
       Keyboard.releaseAll();
       Serial3.print("\r\Alt+Shift sent sent\r\n");
    }
    else if(btRead == '4'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_CAPS_LOCK);
       Keyboard.releaseAll();
       Serial3.print("\r\Alt+CapsLock sent sent\r\n");
    }
    else if(btRead == '5'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_LEFT_CTRL);
       Keyboard.releaseAll();
       Serial3.print("\r\Alt+CapsLock sent sent\r\n");
    }
    else if(btRead == '6'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_F2);
       Keyboard.releaseAll();
       delay(200);
       Keyboard.println("https://www.youtube.com/watch?v=ASO_zypdnsQ");
       Serial3.print("\r\Alt+CapsLock sent sent\r\n");
    }
  }
}
