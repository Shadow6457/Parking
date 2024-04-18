
const int LDR_Entrada = A8;
const int LDR_Salida = A9;

//Variables 
int Valor_LDR_Entrada, Valor_LDR_Salida;
int llindar_LDR_Entrada = 600; //220-859
int llindar_LDR_Salida = 600; //220-861
void setup() 
{
  pinMode(LDR_Entrada, INPUT);
  pinMode(LDR_Salida, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Valor_LDR_Entrada=analogRead(LDR_Entrada);
  Valor_LDR_Salida=analogRead(LDR_Salida);

  Serial.print("LDR_Entrada = ");
  Serial.println(Valor_LDR_Entrada);
  Serial.print("LDR_Salida = ");
  Serial.println(Valor_LDR_Salida);
  delay(2000);

}
