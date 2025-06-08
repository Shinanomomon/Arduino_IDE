#include"Timer.h"
Timer t;
int count = 0, oldcount =0;
void ISR_timer(){
  count++;
}
void setup() {
  t.every(1000,ISR_timer);
  Serial.begin(9600);

}

void loop() {
  t.update();
  if(count != oldcount){
    oldcount = count;
    Serial.println(count);
  
  }

}
