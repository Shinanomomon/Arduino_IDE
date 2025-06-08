const byte ledPin =13;
const byte interruptPin = 2;//pin2,3 only
volatile byte State = LOW;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), ISR_Blink,FALLING);

}

void loop() {
  digitalWrite(ledPin,State);

}

void ISR_Blink(){
  delay(30);
  while(!digitalRead(interruptPin));
  State = !State; 
}
