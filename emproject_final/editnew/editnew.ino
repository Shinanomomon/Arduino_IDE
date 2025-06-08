
int latchPin = D7;  // ST_CP
int clockPin = D6;  // SH_CP
int dataPin = D8;   // DS

int numR[] = { 0xF6, 0x6, 0xBA, 0x9E, 0x4E, 0xDC, 0xFC, 0x86, 0xFF, 0xDF, 0x0 };
int numG[] = { 0b11101111, 0b10000011, 0b01110111, 0b11010111, 0b10011101, 0b11011011,
               0b11111011, 0b10000111, 0xFF, 0b11011111, 0b00000001 };
int num2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int sNumR = 0;
int sNumG = 0;
void DataOut(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}
void callCuG(int num) {
  if (num <= 9) {
    DataOut(numG[10]);
    DataOut(numG[num]);
  } else if (num <= 99) {
    DataOut(numG[num / 10]);
    DataOut(numG[num % 10]);
  } else {  //FF
    DataOut(0b11101000);
    DataOut(0b11101000);
  }
}

void callCuR(int num) {
  if (num <= 9) {
    DataOut(numR[10]);
    DataOut(numR[num]);
  } else if (num <= 99) {
    DataOut(numR[num / 10]);
    DataOut(numR[num % 10]);
  } else {  //FF
    DataOut(0b11101000);
    DataOut(0b11101000);
  }
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, HIGH);
  for (int i = 0; i < 4; i++) { DataOut(numR[8]); }
  delay(1500);
}

void loop() {
  //callCuG(sNumR);
  callCuR(sNumR);

  sNumR++;
  delay(1000);
  if (sNumR == 100) { sNumR = 0; };
}
