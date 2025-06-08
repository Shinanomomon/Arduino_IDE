void controlLED(int pat){
  int a =0b000001;
  for(int i=7;i<=12;i++){
    digitalWrite(i,pat&a);
    a = a << 1;
  }
}
void LtoR(){
int a= 0b100000;
  for(int i=7;i<13;i++){
    controlLED(a);
    a = a >> 1;
    delay(100);
  }
}
void RtoL(){
  int b= 0b000001;
  for(int i=7;i<13;i++){
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
  digitalWrite(13,1);
  digitalWrite(6,1);
  RtoL();
  LtoR();

}
