#ifndef __JORMAZ_CBASICOMOTOR_HPP__
#define __JORMAZ_CBASICOMOTOR_HPP__ 


 #include "Arduino.h"
 #include "TimerOne.h"
 #include "Servo.h"
 
 #include "jormazLib.h"
 #include "constantes.h"


 /*
  * 	Objetos y variables 
  */

extern jormiDepura mensaje;

extern volatile unsigned int pulsosDerecha;    
extern volatile unsigned int pulsosIzquierda;  
extern float rpmDerecha;           
extern float rpmIzquierda;  
extern jormiL293D driverMotor;       
extern int velDeseadaDerecha;
extern int velActualDerecha;
extern int velDeseadaIzquierda;
extern int velActualIzquierda;
extern Servo myservo;

/*
 * 	* * * * * Funciones * * * * *
 */


/*
  Setup motorSetup
  
  inicia el calculor de rpm de ambos motores
  activa ambos motores
  selecciona velocidad 0 para ambos motores
*/
void motorSetup();


/*	
  Funcion IRS 0 - Motor derecho 
  
  función para calculo de RPMS
*/
void ISR_CountDerecha();   
 

/*
  Funcion IRS 1 - Motor izquierdo
  
  función para calculo de RPMS  
*/
void ISR_CountIzquierda();  
 

/*
   TimerOne ISR
   
   (Interrupción) Se llama cada segundo y recalcula RPMs
*/
void ISR_timerone();


/*
	Serial motorSerial
	
	muestra por Serial de ambos motores
		valor actual RPMs 
		
		valor seleccionado de RPMs
*/
void motorSerial();


/*
	motorUpdate
	
	actualiza las velocidades de ambos motores 0..255
*/
void motorUpdate();


/*
	motorGiro
	
	realiza un giro de angulo (180, -90, -45, 45, 90)
*/
void motorGiro(int ang);


#endif //__JORMAZ_CBASICOMOTOR_HPP__