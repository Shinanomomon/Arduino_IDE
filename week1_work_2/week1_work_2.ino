void controlLED(int pat){
  int a =0b00000001;
  for(int i=6;i<=13;i++){
    digitalWrite(i,pat&a);
    a = a << 1;
  }
}

void RandHold(){
  int pat;
  int hold = 0b00000000;
  for(int i=1;i<=8;i++){
    int pat = 0b00000001;
    for(int j=i;j<8;j++){
    controlLED(hold| pat);
    delay(50);
    pat =pat << 1;
  }
  hold = hold + pat;
  controlLED(hold);
  delay(50);
}
}
void RandHoldb(){
  int pat;
  int hold = 0b00000000;
  for(int i=1;i<=8;i++){
    int pat = 0b10000000;
    for(int j=i;j<8;j++){
    controlLED(hold| pat);
    delay(50);
    pat =pat >> 1;
  }
  hold = hold + pat;
  controlLED(hold);
  delay(50);
}
}

void setup() {
  for(int pin=13; pin>5;pin--){
  pinMode(pin,OUTPUT);}
}

void loop() {
 RandHold();
 RandHoldb();

}
