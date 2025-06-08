/** GetDateTime.cpp
 * Example of getting the date and time from the RTC.
 * @version 1.0.1
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU Affero General Public License v3.0
 * @see https://github.com/Treboada/Ds1302
 *
 */
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Ds1302.h>
// DS1302 RTC instance
Ds1302 rtc(2, 3, 4);//rst,dat,clk
LiquidCrystal_I2C lcd(0x27,16,2);
const static char* WeekDays[] =
{
    "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"
};

void getTM(){
    Ds1302::DateTime now;
      rtc.getDateTime(&now);
      static uint8_t last_second = 0;
      if (last_second != now.second){
        Serial.print("20");
        Serial.print(now.year);    // 00-99
        Serial.print('-');
        if (now.month < 10) Serial.print('0');
        Serial.print(now.month);   // 01-12
        Serial.print('-');
        if (now.day < 10) Serial.print('0');
        Serial.print(now.day);     // 01-31
        Serial.print(' ');
        Serial.print(WeekDays[now.dow - 1]); // 1-7
        Serial.print(' ');
        if (now.hour < 10) Serial.print('0');
        Serial.print(now.hour);    // 00-23
        Serial.print(':');
        if (now.minute < 10) Serial.print('0');
        Serial.print(now.minute);  // 00-59
        Serial.print(':');
        if (now.second < 10) Serial.print('0');
        Serial.print(now.second);  // 00-59
        Serial.println();
      }
}

void getTIC(){
      Ds1302::DateTime now;
      rtc.getDateTime(&now);
      static uint8_t last_second = 0;
      
      if (last_second != now.second){
        lcd.clear();
        lcd.print("20");
        lcd.print(now.year);    // 00-99
        lcd.print('-');
        if (now.month < 10) lcd.print('0');
        lcd.print(now.month);   // 01-12
        lcd.print('-');
        if (now.day < 10) lcd.print('0');
        lcd.print(now.day);     // 01-31
        lcd.print(' ');
        lcd.setCursor(0,1);
        lcd.print(WeekDays[now.dow - 1]); // 1-7
        lcd.print(' ');
        if (now.hour < 10) lcd.print('0');
        lcd.print(now.hour);    // 00-23
        lcd.print(':');
        if (now.minute < 10) lcd.print('0');
        lcd.print(now.minute);  // 00-59
        lcd.print(':');
        if (now.second < 10) lcd.print('0');
        lcd.print(now.second);  // 00-59  
        }
    delay(1000);
}

void setup()
{
    Serial.begin(9600);
    //rtc.init();

    lcd.init();
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.clear();
    lcd.print("Hello, world!");
    lcd.setCursor(0,1);
    lcd.print("KMUTNB");
    
  }

void loop()
{
    Ds1302::DateTime now;
      rtc.getDateTime(&now);
      static uint8_t last_second = 0;
      if (last_second != now.second){
        Serial.print("20");
        Serial.print(now.year);    // 00-99
        Serial.print('-');
        if (now.month < 10) Serial.print('0');
        Serial.print(now.month);   // 01-12
        Serial.print('-');
        if (now.day < 10) Serial.print('0');
        Serial.print(now.day);     // 01-31
        Serial.print(' ');
        Serial.print(WeekDays[now.dow - 1]); // 1-7
        Serial.print(' ');
        if (now.hour < 10) Serial.print('0');
        Serial.print(now.hour);    // 00-23
        Serial.print(':');
        if (now.minute < 10) Serial.print('0');
        Serial.print(now.minute);  // 00-59
        Serial.print(':');
        if (now.second < 10) Serial.print('0');
        Serial.print(now.second);  // 00-59
        Serial.println();
        
      }
    
}
