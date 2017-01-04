void setup() {
  Serial3.begin (9600);
}

void loop() {
  char btRead;
  if (Serial3.available ()) {  
    btRead = Serial3.read();
    if(btRead == 'h'||btRead == 'H'){
       Serial3.println("\r\nOptions:\r\n1: Press Capslock\r\n2: Press F11\r\n3: Toggle Ctrl-Alt-Left/Ctrl-Alt-Right\r\n4: Press Alt+Shift\t(change language option 1)\r\n5: Press Alt+Capslock\t(change language option 2)\r\n6: Press Alt+Ctrl\t(change language option 3)\r\n7: Load Pen-Pineapple-Apple-Pen Video\r\n8: Load Win 10 Upgrade");
    }
    if(btRead == '1'){
       Keyboard.press(KEY_CAPS_LOCK);
       Keyboard.releaseAll();
       Serial3.println("\r\nCapsLock sent");
    }
    else if(btRead == '2'){
       Keyboard.press(KEY_F11);
       Keyboard.releaseAll();
       Serial3.println("\r\nF11 sent sent");
    }
    else if(btRead == '3'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_LEFT_CTRL);
       Keyboard.press(KEY_RIGHT_ARROW);
       Keyboard.releaseAll();
       delay(500);
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_LEFT_CTRL);
       Keyboard.press(KEY_LEFT_ARROW);
       Keyboard.releaseAll();
       
    }
    else if(btRead == '4'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_LEFT_SHIFT);
       Keyboard.releaseAll();
       Serial3.println("\r\nAlt+Shift sent");
    }
    else if(btRead == '5'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_CAPS_LOCK);
       Keyboard.releaseAll();
       Serial3.println("\r\nAlt+CapsLock sent");
    }
    else if(btRead == '6'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_LEFT_CTRL);
       Keyboard.releaseAll();
       Serial3.println("\r\nAlt+CapsLock sent");
    }
    else if(btRead == '7'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_F2);
       Keyboard.releaseAll();
       delay(200);
       Keyboard.println("https://www.youtube.com/watch?v=Ct6BUPvE2sM#t=5s");
       Serial3.println("\r\nLoad Pen-Pineapple-Apple-Pen Video");
    }
    else if(btRead == '8'){
       Keyboard.press(KEY_LEFT_ALT);
       Keyboard.press(KEY_F2);
       Keyboard.releaseAll();
       delay(200);
       Keyboard.println("https://i.imgsafe.org/c4d21a8ad4.png");
       Serial3.println("\r\nLoad Win 10 Upgrade Message");
    }
  }
}
