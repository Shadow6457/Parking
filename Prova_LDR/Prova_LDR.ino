
const int LDR1 = A1;
const int LDR2 = A2;
const int LDR3 = A3;
const int LDR4 = A0;

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
  delay(2000);

}
