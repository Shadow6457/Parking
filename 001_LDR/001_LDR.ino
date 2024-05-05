/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   20/01/24                                    **
**                 Prueba LDR i ajustar el OFFSET de luz entre ellos             **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************

//********** Variables ************************************************************
const int LDR1 = A1; //Definimos LDR's en sus respectivos pines
const int LDR2 = A2;
const int LDR3 = A3;
const int LDR4 = A0;

int Valor_LDR1, Valor_LDR2, Valor_LDR3, Valor_LDR4; //Creamos Variables para almacenar el valor de los LDR
int llindar_LDR1 = 700; //Guardamos el valor en el cual queremos que se activen nuestros leds 
int llindar_LDR2 = 600;
int llindar_LDR3 = 700;
int llindar_LDR4 = 400;

//********** Setup ****************************************************************
void setup() 
{
  pinMode(LDR1, INPUT); //Definimos entradas y salidas
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(LDR4, INPUT);
  Serial.begin(9600); //Iniciamos el puerto serial
}

//********** Loop *****************************************************************
void loop()

//********** Funcions *************************************************************
{
  Valor_LDR1=analogRead(LDR1); //Leemos el valor de los LDR y los almacenamos en la variable
  Valor_LDR2=analogRead(LDR2);
  Valor_LDR3=analogRead(LDR3);
  Valor_LDR4=analogRead(LDR4);

  Serial.print("LDR1 = "); 
  Serial.println(Valor_LDR1); //Observamos el valor de los LDR en el puerto serial
  Serial.print("LDR2 = ");
  Serial.println(Valor_LDR2);
  Serial.print("LDR3 = ");
  Serial.println(Valor_LDR3);
  Serial.print("LDR4 = ");
  Serial.println(Valor_LDR4);
  delay(2000); //Esperamos 2s

}
