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
 
 
 //Mueve el servo en las 5 posiones 
void test_Servo01 (){
	mensaje.texto("* TestingSG90 * \t Posicionado SG90");
	mensaje.salto();
	delay(2500);
	int ang;

	sensorOrienta(45); 		delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(90); 		delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(0); 		delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(135); 	delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(180);		delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);
}


//Muestra el tiempo en ms para pasar de 0 a 180 - SERVO_DELAY_MS
void test_Servo02 (){
	unsigned long myTime, myDiff;

	mensaje.salto();
	mensaje.texto("* TestingSG90 * \t SERVO_DELAY_MS    de 0 a 180");
	mensaje.salto();
	delay(2500);

	myservo.write(0);
	delay(SERVO_DELAY_MS);
	myTime = millis();

	myservo.write(180);		
	delay(SERVO_DELAY_MS);
	myDiff = millis();
	
	myTime = myDiff-myTime;
	mensaje.vble("* ms = \t", myTime);
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
  
  RUN_TEST(test_Servo01);
  delay(5000);
  //RUN_TEST(test_Servo02);
  delay(5000);

  UNITY_END();
  
} // loop
