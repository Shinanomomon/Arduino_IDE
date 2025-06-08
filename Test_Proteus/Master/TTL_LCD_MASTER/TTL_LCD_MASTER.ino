//":name10ABCDEFGHIJ#"
#include <string.h>
void setup() {
  Serial.begin(9600);
  pinMode(14,INPUT);
}

String name1 = "NAPHAPHON";
String last1 = "KLAIMANEE";
String name2 = "Hikikomali";
String last2 = "kandathblood";
int i=0;
//"name09NAPHAPHON_last09KLAIMANEE"
void loop() {
  if(digitalRead(14)== 0){
    delay(20);
    while(digitalRead(14)==0){}
    int sizename = name1.length();
    int sizelast = last1.length();
    char sizepat1[3] ={'0','0','\0'};
    char sizepat2[3] ={'0','0','\0'};
    if(sizename<10){
      sizepat1[1] = sizename + 48;
    }else{
      sizepat1[0] = (sizename / 10) + 48;
      sizepat1[1] = (sizename % 10) + 48;
    }
    if(sizelast<10){
      sizepat2[1] = sizelast + 48;
    }else{
      sizepat2[0] = (sizelast / 10) + 48;
      sizepat2[1] = (sizelast % 10) + 48;
    }
    String Senddata = ":n"+String(i)+"me"+String(sizepat1)+name1+"_last"+String(sizepat2)+last1+"#";
    Serial.print(Senddata);
    i=+1;
    if(i=2){i=0;}
  }
}
