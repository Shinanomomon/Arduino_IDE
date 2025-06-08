int ledr = 3;
int ledg = 5;
int ledb = 6;


void setup() {
  pinMode(ledr,OUTPUT);
  pinMode(ledg,OUTPUT);
  pinMode(ledb,OUTPUT);

}

void RGB(int VR,int VG,int VB){
  int R = map(VR,0,255,255,0);
  analogWrite(ledr,R);
  int G = map(VG,0,255,255,0);
  analogWrite(ledg,G);
  int B = map(VB,0,255,255,0);
  analogWrite(ledb,B);
}



void loop() {
  RGB(255, 0, 0);
  delay(100);     
  RGB(255, 165, 0);
  delay(100);   
  RGB(255, 255, 0);
  delay(100);   
  RGB(0, 128, 0);
  delay(100);     
  RGB(0, 0, 255);
  delay(100);     
  RGB(75, 0, 130);
  delay(100);    
  RGB(148, 0, 211);
  delay(100);
}
