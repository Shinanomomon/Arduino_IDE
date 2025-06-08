#include <Servo.h>



//#include <Arduino.h>
//#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#define SERVO_PIN  A0
#define l1 11
#define l2 12

LiquidCrystal_I2C lcd(0x27,16,2);
char value = '0';
const  byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns
Servo servo;
// Define  the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS]  = { 9, 8, 7, 6};// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte  colPins[COLS] = { 5, 4, 3, 2 }; // Connect keypad COL0, COL1 and COL2 to these Arduino  pins.
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS  ); //  Create the Keypad

int num(char c){
  if(c == '0'){return 0;}
  if(c == '1'){return 1;}
  if(c == '2'){return 2;}
  if(c == '3'){return 3;}
  if(c == '4'){return 4;}
  if(c == '5'){return 5;}
  if(c == '6'){return 6;}
  if(c == '7'){return 7;}
  if(c == '8'){return 8;}
  if(c == '9'){return 9;}
}
void setup(){
    pinMode(l1,OUTPUT);
    pinMode(l2,OUTPUT);
    digitalWrite(l1,0);
    digitalWrite(l2,1);
    servo.attach(SERVO_PIN);
    servo.write(0); // rotate servo motor to 0°
    lcd.init();
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.clear();
    lcd.print("Hello");
    lcd.setCursor(0,1);
    lcd.print("KMUTNB");
    delay(2000);
    lcd.clear();
}
void loop(){
  
  value = kpd.getKey(); 
  if(value != false){
  lcd.clear();
  lcd.print("put = ");
  lcd.print(value);
  delay(1000);
  }
  else{
    lcd.setCursor(2,0);
    lcd.print("Welcome,Ready");
    lcd.setCursor(5,1);
    lcd.print("KMUTNB");
  }
  if(value != num(value)){
    for(int p = 1;p<=num(value);p++){
    digitalWrite(l1,1);
    digitalWrite(l2,0);
    lcd.clear();
   	lcd.print("Put = ");
    lcd.print(value);
    lcd.setCursor(0,1);
    lcd.print("Working : ");
    lcd.print(p);
    servo.write(135);
		delay(500); 
    servo.write(0);
    delay(1000); 
    }
    lcd.clear();
    digitalWrite(l1,0);
    digitalWrite(l2,1);
  }
}