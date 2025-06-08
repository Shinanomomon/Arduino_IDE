unsigned long previousMillis = 0;
const long interval = 100;

void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);//switch 2
  pinMode(2,INPUT);//switch 1

}

void loop() {
  unsigned long currentMillis = millis();
  //(เวลาปจบ.-เวลาในอดีต)=> ช่วงเวลาที่เราต้องการ
  //      500       -   0            >= 1000 -->ไม่ทำ
  //      1600      -   500          >= 1000 -->ทำ
  //      2600      -   1600         >= 1000 -->ทำ
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    int switch1 =digitalRead(2);
    int switch2 =digitalRead(3); 
    Serial.println(switch1);
    Serial.println(switch2);
  }
  
  
}
