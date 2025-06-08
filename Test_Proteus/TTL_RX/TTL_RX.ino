int led1 = 13;//lED L 
int led2 = 12;//led R
char buffer[8];
int index = 0;
void setup() {
  Serial.begin(9600);  // opens serial port, sets data rate to 9600 bps
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
bool check = false;
  if (Serial.available() > 0) {
    // read the incoming byte:
    char Byte = Serial.read();
    Serial.print  (Byte);
    if (Byte == ':') {
      index = 0;
      buffer[index]= Byte;
    }else if (Byte != '#'){
      index++;
      buffer[index]= Byte;
    }
    else if (Byte == '#'){
      index++;
      buffer[index]= Byte;//#
      index++;
      buffer[index]= '\0';//Last array
      check =true;
    }
  }
  //\//
  //              0   1   2   3   4   5   6   7
//char Sdata[8]={':','L','E','D','0','0','#','\0'};
//":LED00#"
//index  4 = LED Left 5 = LED Right
  if(check ==true){
    digitalWrite(led1,buffer[4] - 48);//convert char to int
    digitalWrite(led2,buffer[5] - 48);//convert char to int 

  }
  
  
}
  /*
  if (Serial.available() > 0) {
    // read the incoming byte:
    char Byte = Serial.read();
    Serial.print  (Byte);
    if (Byte == 'A') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    } else if (Byte == 'B') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
    } else if (Byte == 'C') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
    } else if (Byte == 'D') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
  }



  /*
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    char Byte = Serial.read();
    Serial.println(Byte);
    if(Byte=='H'){
      digitalWrite(led,HIGH);
    }
    else if(Byte=='L'){
      digitalWrite(led,LOW);
    }
  }*/
