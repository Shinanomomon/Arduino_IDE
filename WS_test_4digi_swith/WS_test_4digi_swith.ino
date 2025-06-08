int font[11]{
  //font[0]=1
  0x3f,  //0
  0x06,  //1
  0x5b,  //2
  0x4f,  //3
  0x66,  //4
  0x6d,  //5
  0x7d,  //6
  0x07,  //7
  0x7f,  //8
  0x6f,  //9
  0x00,  //off
};

void send7Seg(int ch) {
  int a = 0b00000001;
  for (int i = 7; i <= 14; i++) {
    digitalWrite(i, ch & a);
    a = a << 1;
  }
}

void setup() {
  Serial.begin(9600);
  for (int pin = 14; pin > 2; pin--) {
    pinMode(pin, OUTPUT);  //Output 3-14 7-Secment
  }

  pinMode(15, INPUT);  //Swith 1
  pinMode(16, INPUT);  //Swith 2

  for (int pin = 6; pin > 2; pin--) {
    digitalWrite(pin, 0);
    send7Seg(font[9]);
  }
}
  int number = 9;
  void loop() {
    Serial.println(digitalRead(15));//อ่านค่า siwthเมื่อกดเป็น 1
    Serial.println(digitalRead(16));
    send7Seg(font[8]); //แสดงผลเลข 8



      /*if (digitalRead(2) == 0) {
        delay(20);  // DEBounce
        if (digitalRead(2) == 0) {
          while (!digitalRead(2)) {}
          number--;
          for (int i = 0; i < 3; i++) {
            digitalWrite(6, 1);
            delay(100);
            digitalWrite(6, 0);
            delay(100);
          }
        }
        send7Seg(font[number]);
      }
      if (number == 0) {
        number = 9;
      }*/
  }
