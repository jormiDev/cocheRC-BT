#include <Arduino.h>
#include <unity.h>

#include <jormazLib.h>
#include "TimerOne.h"
#include "HCSR04.h"
#include "Servo.h"

#include <constantes.h>
#include "CBasicoMotor.hpp"
#include "CBasicoRemoto.hpp"
#include "CBasicoSensorDist.hpp"
#include "logicaRC.hpp"

 
/*
 * Objetos y variables
 */


jormiDepura mensaje;
int maquinaEstados;

// CBasicoMotor.hpp
volatile unsigned int pulsosDerecha;                        // Contador pulsos lado derecho
volatile unsigned int pulsosIzquierda;                      // Contador pulsos lado izquierdo
float rpmDerecha;                                           // RPM motor derecho
float rpmIzquierda;                                         // RPM motor izquierdo
jormiL293D driverMotor(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4); // Motor coche
int velDeseadaDerecha;                                      // Valor deseado del motor derecho -255..0..255
int velActualDerecha;                                       // Valor actual motor derecho -255..0..255
int velDeseadaIzquierda;                                    // Valor deseado del motor izquierdo -255..0..255
int velActualIzquierda;                                     // Valor actual motor izquierdo -255..0..255

// CBasicoSensorDist.hpp
int distValores[5];           // Array de distancias 0 .. 180
float tiempoActual;           // tiempo actual
float tiempoPrevio;           // tiempo de la ultima lectura sensor distancia
HCSR04 distHCSR04 (PIN_HCSR04_TRIGGER, PIN_HCSR04_ECHO);      //HC-SR04
Servo myservo;                //SG90

// CBasicoRemoto.hpp
char comando;                 // Comando leido de la appMIT inventor


/*
 * ********   T E S T    ***************
 */
 
 
//Calculo de la distancia (medida simple)  
 void test_Ultrasonidos01(){
	delay(2500);
	mensaje.texto("* TestingHC-SR04 * \t Medida simple ");
	mensaje.salto();
	mensaje.vble("* Distancia medida (cms) = \t ", distHCSR04.dist());
 }	 


//Calculo de la distancia (medida multiple)  
 void test_Ultrasonidos02(){
	delay(2500);
	mensaje.texto("* TestingHC-SR04 * \t Medida multiple ");
	mensaje.salto();
	
	unsigned long myTime, myDiff;
	myTime = millis();
	
	int dist;
	mensaje.texto("* Distancias medidas (cms) y periodo (ms)");
	for (int i = 0; i < 10; i++) {
		dist = distHCSR04.dist();
		//mensaje.vble("*", i);
		mensaje.vble("*cms = \t ", dist);	 
	}

	myDiff = millis();
	myTime = (myDiff - myTime)/10;
	mensaje.vble("*ms  media = \t", myTime);
	myTime = myDiff;
 }


 // Mide todas las distancias (distanciaUpdate)
 void test_Ultrasonidos03(){
	mensaje.texto("* TestingHC-SR04 * \t Medida en todas las direcciones ");
	mensaje.salto();

	distValores[0] = distanciaMide(0);
	distValores[1] = distanciaMide(45);
	distValores[2] = distanciaMide(90);
	distValores[3] = distanciaMide(135);
	distValores[4] = distanciaMide(180);

	mensaje.vble("dist   0 -		", distValores[0]);
	mensaje.vble("dist  45 -		", distValores[1]);
	mensaje.vble("dist  90 -		", distValores[2]);
	mensaje.vble("dist 135 -		", distValores[3]);
	mensaje.vble("dist 180 -		", distValores[4]);
	delay(2500);
 }

 
/*
 * ********   S E T U P   ***************
 */


void setup()
{
  Serial.begin(9600);

  distanciaSetup();   // HC-SR04 + SG90

  tiempoPrevio = millis();
  tiempoActual = tiempoPrevio;

  // Fin setup
  mensaje.texto(" loop ");
  delay(1000);
}

void tearDown(void)
{
  // after test
}


/*
 * ********   L O O P   ***************
 */

//void loop()
int main(int argc, char **argv) 
{

  mensaje.texto("inicio loop");

  tiempoActual = millis();                          // tiempo del sistema
  delay(2000);

  UNITY_BEGIN();
  
  RUN_TEST(test_Ultrasonidos01);
  //RUN_TEST(test_Ultrasonidos02);
  //RUN_TEST(test_Ultrasonidos03);

  UNITY_END();
  
} // loop
