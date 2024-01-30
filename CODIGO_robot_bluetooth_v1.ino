#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);// TX,RX

int bt;

void setup() 
{
  bluetooth.begin(9600);
  pinMode(5,OUTPUT);//MOTOR A +
  pinMode(6,OUTPUT);//MOTOT A -
  pinMode(9,OUTPUT);//MOTOR B +
  pinMode(10,OUTPUT);//MOTOR B -
}

void loop() 
{
  if(bluetooth.available())//BLUETOOTH DISPONIBLE
  {    
      bt=bluetooth.read();//leer y guardar datos bluetooth
      if(bt=='F')//avanzar
      {
        digitalWrite(5,1);
        digitalWrite(6,0);
        digitalWrite(9,1);
        digitalWrite(10,0);
        delay(100);
      }
      if(bt=='B')//retroceder
      {
        digitalWrite(5,0);
        digitalWrite(6,1);
        digitalWrite(9,0);
        digitalWrite(10,1);
        delay(100);
      }
      if(bt=='R')//derecha
      {
        digitalWrite(5,1);
        digitalWrite(6,0);
        digitalWrite(9,0);
        digitalWrite(10,1);
        delay(100);
      }
      if(bt=='L')//IZQUIERDA
      {
        digitalWrite(5,0);
        digitalWrite(6,1);
        digitalWrite(9,1);
        digitalWrite(10,0);
        delay(100);
      }
      if(bt=='S')
      {
        digitalWrite(5,0);
        digitalWrite(6,0);
        digitalWrite(9,0);
        digitalWrite(10,0);
        delay(100);
      }
  }
}
