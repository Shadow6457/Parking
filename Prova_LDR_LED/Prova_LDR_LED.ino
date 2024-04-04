
const int LDR1 = A1;
const int LDR2 = A2;
const int LDR3 = A3;
const int LDR4 = A0;
const int LedVentrada = 2;
const int LedRentrada = 3;
const int LedVerde1 = 5;
const int LedRojo1 = 4;
const int LedVerde2 = 6;
const int LedRojo2 = 7;
const int LedVerde3 = 8;
const int LedRojo3 = 9;
const int LedVerde4 = 10;
const int LedRojo4 = 11;

//Variables 
int Valor_LDR1, Valor_LDR2, Valor_LDR3, Valor_LDR4;
int llindar_LDR1 = 700;
int llindar_LDR2 = 600;
int llindar_LDR3 = 700;
int llindar_LDR4 = 400;
void setup() 
{
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(LDR4, INPUT);
  pinMode(LedVentrada,OUTPUT);
  pinMode(LedRentrada,OUTPUT);
  pinMode(LedVerde1,OUTPUT);
  pinMode(LedRojo1,OUTPUT);
  pinMode(LedVerde2,OUTPUT);
  pinMode(LedRojo2,OUTPUT);
  pinMode(LedVerde3,OUTPUT);
  pinMode(LedRojo3,OUTPUT);
  pinMode(LedVerde4,OUTPUT);
  pinMode(LedRojo4,OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  Valor_LDR1=analogRead(LDR1);
  Valor_LDR2=analogRead(LDR2);
  Valor_LDR3=analogRead(LDR3);
  Valor_LDR4=analogRead(LDR4);

  Serial.print("LDR1 = ");
  Serial.println(Valor_LDR1);
  Serial.print("LDR2 = ");
  Serial.println(Valor_LDR2);
  Serial.print("LDR3 = ");
  Serial.println(Valor_LDR3);
  Serial.print("LDR4 = ");
  Serial.println(Valor_LDR4);
  Serial.println();
  delay(500);

  if (Valor_LDR1 > llindar_LDR1) 
  {
    digitalWrite(LedRojo1,HIGH);
    digitalWrite(LedVerde1,LOW);
  }
  else
  {
    digitalWrite(LedVerde1,HIGH);
    digitalWrite(LedRojo1,LOW);
  } 
  
}
