#include<IRremote.h>
const int chanRemote=8;
IRrecv irrecv(chanRemote);
decode_results results;
#set_up
int in3=9;
int in4=10;
int ctht1=2;
int ctht2=3;
int cbmua=7;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ctht1,INPUT);
  pinMode(ctht2,INPUT);
  pinMode(cbmua,INPUT);
}

void loop() {
  
    int trangthaict1=digitalRead(ctht1);
    int trangthaict2=digitalRead(ctht2);
    int thcbmua=digitalRead(cbmua);
    Serial.print(trangthaict1);
    Serial.println(trangthaict2);
    if(thcbmua==1) //Dang khong mua
    {
     if(irrecv.decode(&results))
      {
        if (results.value==0xFF18E7 )//Nhan lên
        { 
          while(trangthaict1!=1 )
          {
            len();
            trangthaict1=digitalRead(ctht1);
          }
          dung();
        }
        else if (results.value==0xFF4AB5 )//Nhấn nút xuống
        { 
          while(trangthaict2!=1 )
          {
            xuong();
            trangthaict2=digitalRead(ctht2);
          }
          dung();
        }
        else {dung();}
      irrecv.resume();
    }
    }
    else //Co Mua
    {
      if(trangthaict2!=1)//co mua va cua dang mo
    {
      xuong();
      }
      else {dung();}
    }
}
void len(){
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }
 void xuong(){
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }
 void dung(){
  
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
