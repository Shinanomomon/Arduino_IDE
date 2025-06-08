int font[11]{//font[0]=1
  0x3f,//0
  0x06,//1
  0x5b,//2
  0x4f,//3
  0x66,//4
  0x6d,//5
  0x7d,//6
  0x07,//7
  0x7f,//8
  0x6f,//9
  0x00,//off
};

void send7Seg(int ch){
  int a =0b00000001;
  for(int i=7;i<=13;i++){
    digitalWrite(i,ch&a);
    a = a << 1;
    
  }

}

void setup() {
    for(int pin=13;pin>5;pin--){
    pinMode(pin,OUTPUT);
  }
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  send7Seg(font[9]);
  digitalWrite(6,0);// digital 1 on
}
int number= 0;
void loop() {
    while(number!=0){
    if(digitalRead(2) == 0){
    delay(20);// DEBounce
    if(digitalRead(2) == 0){
      while(!digitalRead(2)){}
      number--;
    }
  }
  send7Seg(font[number]);
    }
  while(number!=5){
    if(digitalRead(3) == 0){
    delay(20);// DEBounce
    if(digitalRead(3) == 0){
      while(!digitalRead(3)){}
      number++;
    }
  }
  send7Seg(font[number]);
  }
}

