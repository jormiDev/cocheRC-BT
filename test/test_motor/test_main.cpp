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

 
	// VELOCIDAD_BAJA		80			    //Velocidades 0..255
	// VELOCIDAD_MEDIA		160
	// VELOCIDAD_MAXIMA		240
	// VELOCIDAD_GIRO		40
	// GIRO_45				200				//Tiempo de maniobra
	// GIRO_90				400
	// GIRO_180				400
	
	
// Test D/I avance
void test_Motor01()
{
	mensaje.texto("test_Motor01 * \t  D/I avance");
	mensaje.salto();							delay(5000);

	//Motor A - DERECHO
	mensaje.texto("* motor A - DERECHO");
	mensaje.salto();							delay(2000);
	
	mensaje.texto("	Stop A");
	driverMotor.stopA();						delay(2000);
	mensaje.texto("	Fwd A	BAJA");
	driverMotor.avanteA(VELOCIDAD_BAJA);		delay(2000);

	mensaje.texto("	Stop A");
	driverMotor.stopA();						delay(2000);
	mensaje.texto("	Fwd A	MEDIA");
	driverMotor.avanteA(VELOCIDAD_MEDIA);		delay(2000);

	mensaje.texto("	Stop A");
	driverMotor.stopA();						delay(2000);
	mensaje.texto("	Fwd A	MAXIMA");
	driverMotor.avanteA(VELOCIDAD_MAXIMA);		delay(2000);

	mensaje.texto("Stop A");
	driverMotor.stopA();

	//Motor B - IZQUIERDO
	mensaje.texto("* motor B - IZQUIERDO");
	mensaje.salto();							delay(2000);
	
	mensaje.texto("Stop B");
	driverMotor.stopB();						delay(2000);
	mensaje.texto("Fwd B	BAJA");
	driverMotor.avanteB(VELOCIDAD_BAJA);		delay(2000);

	mensaje.texto("Stop B");
	driverMotor.stopB();						delay(2000);
	mensaje.texto("Fwd B	MEDIA");
	driverMotor.avanteB(VELOCIDAD_MEDIA);		delay(2000);

	mensaje.texto("Stop B");
	driverMotor.stopB();						delay(2000);
	mensaje.texto("Fwd B	MAXIMA");
	driverMotor.avanteB(VELOCIDAD_MAXIMA);		delay(2000);

	mensaje.texto("Stop B");
	driverMotor.stopB();

	mensaje.salto();
}	
	
	
// Test D/I Retroceso
void test_Motor02()
{
	mensaje.texto("* test_Motor02 * \t  D/I Retroceso");
	mensaje.salto();

	//Motor A - DERECHO
	mensaje.texto("* motor A - DERECHO");
	mensaje.salto();							delay(2000);
	
	mensaje.texto("Stop A");
	driverMotor.stopA();						delay(2000);
	mensaje.texto("Atras A	BAJA");
	driverMotor.atrasA(VELOCIDAD_BAJA);			delay(2000);

	mensaje.texto("Stop A");
	driverMotor.stopA();						delay(2000);
	mensaje.texto("Atras A	MEDIA");
	driverMotor.atrasA(VELOCIDAD_MEDIA);		delay(2000);

	mensaje.texto("Stop A");
	driverMotor.stopA();						delay(2000);
	mensaje.texto("Atras A	MAXIMA");
	driverMotor.atrasA(VELOCIDAD_MAXIMA);		delay(2000);

	mensaje.texto("Stop A");
	driverMotor.stopA();


	//Motor B - IZQUIERDO
	mensaje.texto("* motor B - IZQUIERDO");
	mensaje.salto();							delay(2000);
	
	mensaje.texto("Stop B");
	driverMotor.stopB();						delay(2000);
	mensaje.texto("Atras B	BAJA");
	driverMotor.atrasB(VELOCIDAD_BAJA);			delay(2000);

	mensaje.texto("Stop B");
	driverMotor.stopB();						delay(2000);

	mensaje.texto("Atras B	MEDIA");
	driverMotor.atrasB(VELOCIDAD_MEDIA);		delay(2000);
	mensaje.texto("Stop B");
	driverMotor.stopB();						delay(2000);

	mensaje.texto("Atras B	MAXIMA");
	driverMotor.atrasB(VELOCIDAD_MAXIMA);		delay(2000);
	mensaje.texto("Stop B");
	driverMotor.stopB();

	mensaje.salto();
}


// Test giro 45
void test_Motor03()
{

	mensaje.texto("* test_Motor03 * \t  giro 45 a D/I");
	mensaje.salto();		delay(5000);

	mensaje.texto("* parar motores");
	
	driverMotor.stopB();
	driverMotor.stopB();					delay(5000);
	
	//Giro DERECHA
	mensaje.texto("* 45 grados DERECHA ");
	delay(2000);
	
	driverMotor.avanteA(VELOCIDAD_GIRO);
	delay(GIRO_45);
	driverMotor.stopA();					delay(2000);
	
	//Giro IZQUIERDA
	mensaje.texto("* 45 grados IZQUIERDA");
	delay(2000);
	
	driverMotor.avanteB(VELOCIDAD_GIRO);
	delay(GIRO_45);
	driverMotor.stopB();					delay(2000);
}

// Test giro 90
void test_Motor04()
{

	mensaje.texto("* test_Motor04 * \t  giro 90 a D/I");
	mensaje.salto();		delay(5000);

	mensaje.texto("* parar motores");
	
	driverMotor.stopB();
	driverMotor.stopB();					delay(5000);
	
	//Giro DERECHA
	mensaje.texto("* 90 grados DERECHA");
	delay(2000);
	
	driverMotor.avanteA(VELOCIDAD_GIRO);
	delay(GIRO_90);
	driverMotor.stopA();					delay(2000);
	
	//Giro IZQUIERDA
	mensaje.texto("* 90 grados IZQUIERDA");
	delay(2000);
	
	driverMotor.avanteB(VELOCIDAD_GIRO);
	delay(GIRO_90);
	driverMotor.stopB();					delay(2000);
}
  


// Test giro 180
void test_Motor05()
{

	mensaje.texto("* test_Motor05 * \t  giro 180");
	mensaje.salto();		delay(5000);

	mensaje.texto("* parar motores");
	
	driverMotor.stopA();
	driverMotor.stopB();
	
	mensaje.texto("* iniciar giro 180");	delay(2000);
	
	driverMotor.avanteA(VELOCIDAD_GIRO);
	driverMotor.atrasB(VELOCIDAD_GIRO);
	delay(GIRO_180);

	driverMotor.stopA();
	driverMotor.stopB();					delay(2000);
}  
    
  
/*
 * ********   S E T U P   ***************
 */


void setup()
{
  Serial.begin(9600);

  motorSetup();       // motores

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
  
  RUN_TEST(test_Motor01);	
  delay(5000);
  //RUN_TEST(test_Motor02);	
  delay(5000);
  //RUN_TEST(test_Motor03);	
  delay(5000);
  //RUN_TEST(test_Motor04);	
  delay(5000);
  //RUN_TEST(test_Motor05);	
  delay(5000);

  UNITY_END();
  
} // loop
