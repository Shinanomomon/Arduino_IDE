int ledPin1 = 3;
int ledPin2 = 5;
int ledPin3 = 6;
int analogPin = A0;
int val = 0;
void setup(){
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
}
void loop(){
  val = analogRead(analogPin);
  analogWrite(ledPin1,val / 4);
  analogWrite(ledPin2,val / 4);
  analogWrite(ledPin3,val / 4);
}