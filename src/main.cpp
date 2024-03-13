#include <Arduino.h>

#include <jormazLib.h>
#include "TimerOne.h"
#include "HCSR04.h"
#include "Servo.h"

#include <constantes.h>
#include "CBasicoMotor.hpp"
#include "CBasicoRemoto.hpp"
#include "CBasicoSensorDist.hpp"
#include "logicaRC.hpp"

/* INICIO SECCION TEST  */
#include "test_SensorDist.hpp"
/* FIN SECCION TEST     */


 
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

// CBasicoTes

/*
 * ********   S E T U P   ***************
 */

void setup()
{

  Serial.begin(9600);

  maquinaEstados = 0;

  distanciaSetup();   // HC-SR04 + SG90
  //motorSetup();       // motores
 // remotoSetup();




  tiempoPrevio = millis();
  tiempoActual = tiempoPrevio;

  // Fin setup
  mensaje.texto(" loop ");
  delay(1000);

  mensaje.texto("inicio loop");
}



/*
 * ********   L O O P   ***************
 */

void loop()
{

  tiempoActual = millis();                          // tiempo del sistema
  delay(2000);


  /* INICIO SECCION TEST  */

  //mensaje.texto("TEST HC-SR04");
  // test_Ultrasonidos01();
  // test_Ultrasonidos02();
  // test_Ultrasonidos03();

  mensaje.texto("TEST SG90");
  void test_Servo01();
  // void test_Servo02();

  /* FIN SECCION TEST  */



  //comando = remotoLeer();                           // leer el buffer BT y almacenar el comando


  // switch (maquinaEstados)
  // /*
  //   0     tiempo transcurrido <= TIEMPO_PERIODO
  //   1     tiempo transcurrido > TIEMPO_PERIODO        
  //   2     evaluar velocidad según distancia frontal
  //   3     velocidad > 0
  //   4     velocidad = 0 (STOP)


  // */


  // {
  // case 0:
  //   // Mira si ha transcurrido "tiempoPeriodo"		->	1
  //   if ((tiempoActual - tiempoPrevio) > TIEMPO_PERIODO)
  //   {
  //     maquinaEstados = 1;
  //     tiempoPrevio = tiempoActual;
  //   }
  //   break;

  // case 1:
  //   // Medir distancia (frontal)			-> 	2
  //   distanciaUpdate();
  //   maquinaEstados = 2;
  //   break;

  // case 2:
  //   // Mantener dirección		-> 	3
  //   // Cambio de dirección		->	4
  //   maquinaEstados = logicaBasica();
  //   break;

  // case 3:
  //   // Actualizar motores		-> 	0
  //   motorSerial();
  //   motorUpdate();
  //   maquinaEstados = 0;
  //   break;

  // case 4:
  //   // Calcular nueva dirección
  //   // Aplicar giro				->	5
  //   distanciaUpdate();
  //   motorGiro(logicaGiro());
  //   maquinaEstados = 5;
  //   break;

  // case 5:
  //   // Empezar avance lento		->	0
  //   velDeseadaDerecha = VELOCIDAD_BAJA;
  //   velDeseadaIzquierda = VELOCIDAD_BAJA;
  //   motorSerial();
  //   motorUpdate();
  //   maquinaEstados = 0;
  //   break;

  // default:
  //   maquinaEstados = 0;
  //   break;

  // } // maquinaEstados
  
} // loop
