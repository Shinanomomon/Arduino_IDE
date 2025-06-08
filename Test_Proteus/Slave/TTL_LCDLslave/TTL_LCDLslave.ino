#include<string.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);
char buffer[50];
int index = 0;
char name[20] ;
char last[20] ;
void setup() {
  Serial.begin(9600);  // opens serial port, sets data rate to 9600 bps
  lcd.init();
  lcd.backlight();
}

void loop() {
bool check = false;
  if (Serial.available() > 0) {
    // read the incoming byte:
    char Byte = Serial.read();
    //Serial.print  (Byte);
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
  //"name09NAPHAPHON_last09KLAIMANEE"
  if(check == true){
    int sizename = (buffer[5]-48)*10;
    sizename += (buffer[6]-48);
    int i = 7;
    for(i;i<=sizename+6;i++){
      name[i-7] = buffer[i];     
    }
    name[i]='\0';

    int sizelast  = (buffer[i+5]-48)*10;
    sizelast += (buffer[i+5+1]-48);
    int j = i+5+2;
    int j2 = j;
    for(j;j<sizelast+j2;j++){
      last[j-j2] = buffer[j];     
    }
    last[j-j2+1]='\0';
    lcd.print(name);
    lcd.setCursor(0, 1);// (col,row)//start at 0
    lcd.print(last);
  }
}