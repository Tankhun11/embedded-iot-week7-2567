#include <Arduino.h>
byte pin[] = {5, 18, 19, 3, 1, 23, 22}; //PIN 5, 18, 19, 3, 1, 23, 22 to a,b,c,d,e,f,g

const byte count[10] = {
  //ABCDEFG
  B00111111, //0
  B00000110, //1
  B01011011, //2
  B01001111, //3
  B01100110, //4
  B01101101, //5
  B01111101, //6
  B00000111, //7
  B01111111, //8
  B01101111, //9
};
#define DP 17

void SevenSeg(byte Bit);
void setup()
{
  pinMode(pin[0],OUTPUT);
  pinMode(pin[1],OUTPUT);
  pinMode(pin[2],OUTPUT);
  pinMode(pin[3],OUTPUT);
  pinMode(pin[4],OUTPUT);
  pinMode(pin[5],OUTPUT);
  pinMode(pin[6],OUTPUT);
}

void loop()
{
  digitalWrite(DP,HIGH);
  // LED states to display number 'one
  for (int i =0; i<10;i++) //printing the number on seven segment
  {
    SevenSeg(count[i]);
    delay(1000);
  }
}

void SevenSeg(byte Bit){//sending data on each pin
  for (int i = 0; i < 8 ;i++)
  {
    digitalWrite(pin[i],bitRead(Bit,i));
  }
}