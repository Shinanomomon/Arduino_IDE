int SWL = 14;//Switch Led Left
int SWR = 15;//Switch Led Right
int count = 0;
//              0   1   2   3   4   5   6   7
char Sdata[8]={':','L','E','D','0','0','#','\0'};
//":LED00#"
//index  4 = LED Left 5 = LED Right

void setup() {
  Serial.begin(9600);  // pin (hardware)0, 1
  pinMode(SWL, INPUT);
  pinMode(SWR, INPUT);
}
void loop() {
  if (digitalRead(SWL) == 0) {
    delay(20);  //debounce
    Sdata[4]='1';
    while (!digitalRead(SWL)) {}
    Serial.print(Sdata);
    Sdata[4]='0';
  }
  if (digitalRead(SWR) == 0) {
    delay(20);  //debounce
    Sdata[5]='1';
    while (!digitalRead(SWR)) {}
    Serial.print(Sdata);
    Sdata[5]='0';
  }
}
/*
//a=10 b=01 c=11 d=00
  if (digitalRead(SW) == 0) {
    delay(20);  //debounce
    count++;
    if (count == 1) {
      Serial.print("A");
    } else if (count == 2) {
      Serial.print("B");
    } else if (count == 3) {
      Serial.print("C");
    } else if (count == 4) {
      Serial.print("D");
      count = 0;
    }
    while (!digitalRead(SW)) {}
  }
  /*
  if(digitalRead(SW)==0){
    delay(20); //debounce
    Serial.print("H");
    while(!digitalRead(SW)){}
    Serial.print("L");
  }*/

