/**********************************************************************************
**                                                                               **
**                           Iker Clemente Palacios                              **
**                                   15/04/24                                    **
**                Prueba con LDR's, LED's, Servomotor i Pulsadores               **
**              En esta versión automatizamos el cierre de la puerta             **
**********************************************************************************/

//********** Includes *************************************************************
#include <Servo.h> //Incluimos la libreria del servomotor
Servo Servo1; //Definimos el nombre de nuestro servo

//********** Variables ************************************************************
const int LDR4 = A0; //Definimos LDR's, LED's i Pulsadores en sus respectivos pines
const int LDR1 = A1;
const int LDR2 = A2;
const int LDR3 = A3;
const int Polsador_Int=A4;
const int Polsador_Ext=A5;
const int LDR_Salida= A8;
const int LDR_Entrada= A9;

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

int Valor_LDR1, Valor_LDR2, Valor_LDR3, Valor_LDR4; //Creamos Variables para almacenar el valor de los LDR
int llindar_LDR1 = 700; //Guardamos el valor en el cual queremos que se activen nuestros leds
int llindar_LDR2 = 600;
int llindar_LDR3 = 700;
int llindar_LDR4 = 400;
int Valor_LDR_Entrada = 700; //Creamos Variables para almacenar el valor de los LDR i LED's de entrada y salida
int Valor_LDR_Salida = 700;
int Valor_LedVentrada;
int Valor_LedRentrada;

int Valor_Polsador_Ext; //Creamos Variables para almacenar el valor de los Pulsadores
int Valor_Polsador_Int;
int numero_coches; //Variable para almacenar el numero de coches de nuestro parking

//********** Setup ****************************************************************
void setup() 
{
  pinMode(LDR1, INPUT); //Definimos entradas y salidas
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(LDR4, INPUT);
  pinMode(Polsador_Int, INPUT);
  pinMode(Polsador_Ext, INPUT);
  pinMode(LDR_Entrada, INPUT);
  pinMode(LDR_Salida, INPUT);

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


  Servo1.write(51); //Posicion del servo inicial
  Servo1.attach(12); //Definimos el PIN en el que se encuentra nuestro servomotor
  Serial.begin(9600); //Iniciamos el puerto serial
}

//********** Loop *****************************************************************
void loop()

//********** Funcions *************************************************************
{
  Serial.print("Número_coches = ");
  Serial.println(numero_coches); //Observamos el numero de coches en el puerto serial
  numero_coches=0; //Ponemos el contador de coches a 0

  Valor_LDR1=analogRead(LDR1); //Leemos el valor de los LDR y los almacenamos en la variable
  Valor_LDR2=analogRead(LDR2);
  Valor_LDR3=analogRead(LDR3);
  Valor_LDR4=analogRead(LDR4);
  Valor_LDR_Entrada=analogRead(LDR_Entrada);
  Valor_LDR_Salida=analogRead(LDR_Salida);

  Serial.print("LDR1 = ");
  Serial.println(Valor_LDR1); //Observamos el valor de los LDR en el puerto serial
  Serial.print("LDR2 = ");
  Serial.println(Valor_LDR2);
  Serial.print("LDR3 = ");
  Serial.println(Valor_LDR3);
  Serial.print("LDR4 = ");
  Serial.println(Valor_LDR4);
  Serial.println();
  Serial.print("Valor_LDR_Entrada = ");
  Serial.println(Valor_LDR_Entrada);
  Serial.println();
  Serial.print("Valor_LDR_Salida = ");
  Serial.println(Valor_LDR_Salida); 
  Serial.println();
  Serial.print("Valor_Polsador_Ext = ");
  Serial.println(Valor_Polsador_Ext);
  Serial.print("Valor_Polsador_Int = ");
  Serial.println(Valor_Polsador_Int);
  Serial.println();

  delay(300); //Esperamos 300ms
  Servo1.write(51); //Ponemos el servo en posición inicial

  Valor_Polsador_Ext = digitalRead (Polsador_Ext); //Leemos el valor de los Pulsadores y los almacenamos en la variable
  Valor_Polsador_Int = digitalRead (Polsador_Int);

  
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
    digitalWrite(LedRentrada,HIGH); //Enciende el LED rojo de entrada
    digitalWrite(LedVentrada,LOW); //Apaga el LED verde de entrada
  }
  else //sino
  {
    digitalWrite(LedRentrada,LOW); //Apaga el LED rojo de entrada
    digitalWrite(LedVentrada,HIGH); // Enciende el LED verde de entrada
  }

  Valor_LedVentrada=digitalRead(LedVentrada); //Leemos el valor de los LED's y los almacenamos en la variable
  Valor_LedRentrada=digitalRead(LedRentrada);


  if(Valor_LDR_Entrada > 600 && Valor_Polsador_Ext == LOW && Valor_LedVentrada == 1){ //Si el valor del LDR es mas grande que el de la variable que hemos creado, 3l valor del polsador es igual a 0 i el Led Verde es igual a 1
    Servo1.write(145); //Pon el servomotor a 145º
    Valor_LDR_Entrada=analogRead(LDR_Entrada); //Leemos el valor de los LDR's y los almacenamos en la variable
    Valor_LDR_Salida=analogRead(LDR_Salida);

    while(Valor_LDR_Entrada > 600 || Valor_LDR_Salida > 600) //Mientras el valor de los LDR's es mas grande que el de la variable que hemos creado
    {
    Servo1.Write(145); //Mantén el servomotor a 145º
    Valor_LDR_Entrada=analogRead(LDR_Entrada); //Leemos el valor de los LDR's y los almacenamos en la variable 
    Valor_LDR_Salida=analogRead(LDR_Salida);
    }

  }

  Valor_LedVentrada=digitalRead(LedVentrada); //Leemos el valor de los LED's y los almacenamos en la variable
  Valor_LedRentrada=digitalRead(LedRentrada);
  
  if(Valor_LDR_Salida > 600 && Valor_Polsador_Int == LOW && Valor_LedVentrada == 1){ //Si el valor del LDR es mas grande que el de la variable que hemos creado, 3l valor del polsador es igual a 0 i el Led Verde es igual a 1
    Servo1.write(145); //Pon el servomotor a 145º
    Valor_LDR_Salida=analogRead(LDR_Salida); //Leemos el valor de los LDR's y los almacenamos en la variable
    Valor_LDR_Entrada=analogRead(LDR_Entrada);

    while(Valor_LDR_Entrada > 600 || Valor_LDR_Salida > 600) //Mientras el valor de los LDR's es mas grande que el de la variable que hemos creado
    {
     Servo1.Write(145); //Mantén el servomotor a 145º
    Valor_LDR_Salida=analogRead(LDR_Salida); //Leemos el valor de los LDR's y los almacenamos en la variable 
    Valor_LDR_Entrada=analogRead(LDR_Entrada);
    }
    
  }
  
}
