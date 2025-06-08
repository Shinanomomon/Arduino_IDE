int latchPin = 8; // ST_CP
int clockPin = 12; // SH_CP
int dataPin = 11; // DS

int numR[] = {0b11110111,0b11000010,0b10111011,0b11101011, 0b11001110,
              0b11101101,0b11111101,0b11000011,0b11111111,0b11101111,0b10000000};
int numG[] = {0b11110111,0b10100001,0b11101110,0b11101011,0b10111001,0b11011011,
	      0b11011111,0b11100001,0b11111111,0b11111011,0b10000000};
int num2[] = {0,1,2,3,4,5,6,7,8,9,10};
int sNum = 0;
void DataOut(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
  
}

void callCuR(int num){
  if(num<=9){
    DataOut(numR[10]);
    DataOut(numR[num]);
    Serial.print("0");
    Serial.println(num);
  }
  else if(num<=99){
    DataOut(numR[num/10]);
    DataOut(numR[num%10]);
    Serial.print("FL.");
    Serial.println(num);
  }
  else if(num>=100){//FF.
    DataOut(0b00011101);
    DataOut(0b01011110);
    Serial.print("F.H.");
    Serial.println(num);
  }
  else{//FF.
    DataOut(0b00011101);
    DataOut(0b00011101);
    Serial.print("F.F.");
    Serial.println(num);
  }
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, HIGH);
  DataOut(numR[8]);
  DataOut(numR[8]);
  Serial.begin(9600);
  Serial.println(num2[sNum]);
  delay(1500);
}

void loop() {
  callCuR(10);
  sNum++;
  delay(500);
  Serial.println(sNum);
  if(sNum==100){sNum=0;};
}
