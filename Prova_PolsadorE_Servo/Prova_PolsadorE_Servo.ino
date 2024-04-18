#include <Servo.h>
Servo Servo1;

const int Polsador_Ext=A0;
const int Polsador_Int=A5;
const int LED_PLAZAS;
const int LED_LLENO;
const int LDR_Entrada= A8;
const int LDR_Salida= A9;

//Variables

int LDR_Valor = 700;
int LDR_Valor2 = 700;

//0-13 MEGA I/O 

void setup() 
{
  pinMode(Polsador_Int, INPUT);
  pinMode(Polsador_Ext, INPUT);
  pinMode(LDR_Entrada, INPUT);
  pinMode(LDR_Salida, INPUT);

  Servo1.attach(12);
  Servo1.write(0);
  Serial.begin(9600);
}

void loop() 
{

  Serial.print("LDR_Entrada");
  Serial.println(LDR_Entrada);
  Serial.print("LDR_Salida");
  Serial.println(LDR_Salida);
  Serial.print("Polsador_Int");
  Serial.println(Polsador_Int);
  Serial.print("Polsador_Ext");
  Serial.println(Polsador_Ext);

  if(LDR_Entrada > LDR_Valor && Polsador_Int > 200)
    Servo1.write(0);
  
}
