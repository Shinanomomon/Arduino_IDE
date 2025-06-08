int font[12]{
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
  0x80   // .dp
};
unsigned long previousMillis = 0;
const long interval = 1000;

void send7Seg(int ch) {
  int a = 0b00000001;
  for (int i = 7; i <= 14; i++) {
    digitalWrite(i, ch & a);
    a = a << 1;
  }
}

void send7Seg_digit(int ch, int digit) {
  for (int i = 3; i <= 6; i++) {
    digitalWrite(i, HIGH);  //clear all digi
  }
  // ชุดจัดเรียงแต่ละsegment//
  int a = 0b00000001;
  for (int i = 7; i <= 14; i++) {
    digitalWrite(i, ch & a);
    a = a << 1;
  }
  switch (digit) {
    case 1:
      digitalWrite(3, LOW);
      break;
    case 2:
      digitalWrite(4, LOW);
      break;
    case 3:
      digitalWrite(5, LOW);
      break;
    case 4:
      digitalWrite(6, LOW);
      break;
  }
  delay(1);
}

void setup() {
  Serial.begin(9600);
  for (int pin = 14; pin > 2; pin--) {
    pinMode(pin, OUTPUT);  //Output 3-14 7-Secment
  }
  pinMode(15, INPUT);  //Swith 1
  pinMode(16, INPUT);  //Swith 2
}
int sec = 0;
void loop() {
  int d1 = sec / 10;
  int d2 = sec % 10;  //เอาเศษอย่างเดียว ==mod
  send7Seg_digit(font[d1], 1);
  send7Seg_digit(font[d2], 2);
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    sec++;
  }
  if (sec == 60) {
    sec = 0;
  }


}
