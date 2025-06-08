
//uno

int latchPin = 8; // ST_CP
int clockPin = 12; // SH_CP
int dataPin = 11; // DS

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
  DataOut(hex[num]);
/*
  for(int i=0;i<10;i++){
    DataOut(hex[i]);
  delay(500);
  }*/
  delay(500);
  num++;
  if(num==10){num=0;}
}

