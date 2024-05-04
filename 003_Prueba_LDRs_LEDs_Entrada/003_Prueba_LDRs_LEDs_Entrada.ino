/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   10/03/24                                     **
**                     Prueba LDR's i LED's estacionamiento                      **
**                         + LED's de entrada y salida                           **
**********************************************************************************/

//********** Includes *************************************************************

//********** Variables ************************************************************
const int LDR1 = A1; //Definimos LDR's i LED's en sus respectivos pines
const int LDR2 = A2;
const int LDR3 = A3;
const int LDR4 = A0;
const int LedVentrada = 2;
const int LedRentrada = 3;
const int LedVerde1 = 5;
const int LedRojo1 = 4;
const int LedVerde2 = 7;
const int LedRojo2 = 6;
const int LedVerde3 = 9;
const int LedRojo3 = 8;
const int LedVerde4 = 11;
const int LedRojo4 = 10;
const int LedVEntrada=2;
const int LedREntrada=3;

int Valor_LDR1, Valor_LDR2, Valor_LDR3, Valor_LDR4; //Creamos Variables para almacenar el valor de los LDR
int llindar_LDR1 = 700; //Guardamos el valor en el cual queremos que se activen nuestros leds 
int llindar_LDR2 = 600;
int llindar_LDR3 = 700;
int llindar_LDR4 = 400;
int numero_coches; //Variable para almacenar el numero de coches de nuestro parking

//********** Setup ****************************************************************
void setup() 
{
  pinMode(LDR1, INPUT); //Definimos entradas y salidas
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

  Serial.begin(9600); //Iniciamos el puerto serial
}

//********** Loop *****************************************************************
void loop()

//********** Funcions *************************************************************
{
  Serial.println(numero_coches); //Observamos el numero de coches en el puerto serial
  numero_coches=0; //Ponemos el contador de coches a 0

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
  Serial.println();
  delay(500); //Esperamos 500ms

  

  if (Valor_LDR1 > llindar_LDR1) //Si el valor del LDR es mas grande que el de la variable que hemos creado
  {
    digitalWrite(LedRojo1,HIGH); //Enciende el LED rojo 
    digitalWrite(LedVerde1,LOW); //Apaga el LED verde
    numero_coches=numero_coches+1; //Suma uno en nuestra variable
  }
  else //sino
  {
    digitalWrite(LedVerde1,HIGH); //Enciende el LED verde
    digitalWrite(LedRojo1,LOW); //Apaga el LED rojo
  } 
  if(Valor_LDR2 > llindar_LDR2 ) //Si el valor del LDR es mas grande que el de la variable que hemos creado
  {
   digitalWrite(LedRojo2,HIGH); //Enciende el LED rojo 
   digitalWrite(LedVerde2,LOW); //Apaga el LED verde
   numero_coches=numero_coches+1; //Suma uno en nuestra variable
  }
  else //sino
  {
   digitalWrite(LedRojo2,LOW); //Apaga el LED rojo
   digitalWrite(LedVerde2,HIGH); //Enciende el LED verde
  }
  if(Valor_LDR3 > llindar_LDR3) //Si el valor del LDR es mas grande que el de la variable que hemos creado
  {
   digitalWrite(LedRojo3,HIGH); //Enciende el LED rojo
   digitalWrite(LedVerde3,LOW); //Apaga el LED verde
   numero_coches=numero_coches+1; //Suma uno en nuestra variable
  }
  else //sino
  {
   digitalWrite(LedRojo3,LOW); //Apaga el LED rojo
   digitalWrite(LedVerde3,HIGH); //Enciende el LED verde
  }
  if(Valor_LDR4 > llindar_LDR4) //Si el valor del LDR es mas grande que el de la variable que hemos creado
  {
   digitalWrite(LedRojo4,HIGH); //Enciende el LED rojo
   digitalWrite(LedVerde4,LOW); //Apaga el LED verde
   numero_coches=numero_coches+1; //Suma uno en nuestra variable
  }
  else //sino
  {
   digitalWrite(LedRojo4,LOW); //Apaga el LED rojo
   digitalWrite(LedVerde4,HIGH); //Enciende el LED verde
  }

  if(numero_coches==4) //Si el numero de coches es igual a 4
  {
    digitalWrite(LedREntrada,HIGH); //Enciende el LED rojo de entrada
    digitalWrite(LedVEntrada,LOW);  //Apaga el LED verde de entrada
  }
  else //sino
  {
    digitalWrite(LedREntrada,LOW); //Apaga el LED rojo de entrada
    digitalWrite(LedVEntrada,HIGH); //Enciende el LED verde de entrada
  }
  
}
