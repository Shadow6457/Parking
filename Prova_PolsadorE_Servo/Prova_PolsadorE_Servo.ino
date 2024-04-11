#include <Servo.h>
Servo Servo1;

const int Polsador_Ext=A0;
const int Polsador_Int=A5;

void setup() 
{
  pinMode(Polsador_Int, INPUT);
  pinMode(Polsador_Ext, INPUT);

  Servo1.attach(12);
  Servo1.write(0);
  Serial.begin(9600);
}

void loop() 
{

   Servo1.write(0);
  
}
