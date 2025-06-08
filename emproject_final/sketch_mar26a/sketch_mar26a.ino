int latchPin = D7;
int clockPin = D6;
int dataPin = D8;
int hex[11]= {0xF6,0xC0,0xBA,0xEA,0xCC,0x6E,0x7E,0xC2,0xFE,0xEE,0x00};
int num = 0;
void DataOut(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, HIGH);
  DataOut(hex[11]);
  delay(500);
}

void loop() {
  int x =0b00000001;
  for(int i = 0;i<9;i++){
  DataOut(x);
  delay(500);
  x= x<<1;}

}

