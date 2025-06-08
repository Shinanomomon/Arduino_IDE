#include"Timer.h"
Timer t;
int count = 24  , oldcount =0;
int font[12]{
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
};int disBuf[3];
void send7Seg_digit(int ch, int digit) {
    for (int i = 4; i <= 6; i++) {
      digitalWrite(i, HIGH);  
    }
    int a = 0b00000001;
    for (int i = 7; i <= 14; i++) {
      digitalWrite(i, ch & a);
      a = a << 1;
    }
    switch (digit) {
      case 1:
        digitalWrite(4, LOW);
        break;
      case 2:
        digitalWrite(5, LOW);
        break;
      case 3:
        digitalWrite(6, LOW);
        break;
    }
    delay(1);
  }       
void scanX(int num){
  if(num<100){
    disBuf[0] = 10; //หลักร้อย ปิด 
  }else{
    disBuf[0]=num/100;
  }
  if(num<10){
    disBuf[1] = 10; //หลักlb[] ปิด 
  }else{
    disBuf[1]=(num/10)%10;
  }
  disBuf[2]=num%10;
  send7Seg_digit(font[disBuf[0]], 1);
  send7Seg_digit(font[disBuf[1]], 2);
  send7Seg_digit(font[disBuf[2]], 3);
}                      
int id ;
void setup() {
  for (int pin = 19; pin > 3; pin--) {
  pinMode(pin, OUTPUT);  }
   id = t.every(1000,ISR_timer);
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), ISR_Blink,FALLING);
}
void loop() {
  t.update();
  scanX(count);
  if(count != oldcount){
    oldcount = count;
    Serial.println(count);
  }
  if(count==10){t.stop(id);}
  
}
void ISR_timer(){
  count--;

}
void ISR_Blink(){
  delay(30);
  while(!digitalRead(2));
  count =24; 
}

