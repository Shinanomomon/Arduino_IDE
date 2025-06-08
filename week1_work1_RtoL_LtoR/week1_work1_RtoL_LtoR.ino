void controlLED(int pat){
  int a =0b00000001;
  for(int i=6;i<=13;i++){
    digitalWrite(i,pat&a);
    a = a << 1;
  }
}
void LtoR(){
int a= 0b10000000;
  for(int i=6;i<14;i++){
    controlLED(a);
    a = a >> 1;
    delay(100);
  }
}
void RtoL(){
  int b= 0b00000001;
  for(int i=6;i<14;i++){
    controlLED(b);
    b = b << 1;
    delay(100);
  }
}

void setup() {
  for(int pin=13; pin>5;pin--){
  pinMode(pin,OUTPUT);}

}

void loop() {
  RtoL();
  LtoR();

}
