#ifndef __JORMAZ_CBASICOTESTING_HPP__
#define __JORMAZ_CBASICOTESTING_HPP__

#include "Arduino.h"
#include "TimerOne.h"
#include <Servo.h>
#include <HCSR04.h>

#include "jormazLib.h"
#include "constantes.h"
#include "CBasicoSensorDist.hpp"

/*
 * 	Objetos y variables
 */


//main
extern jormiDepura mensaje;
extern int maquinaEstados;

//remoto
extern char comando;

//motor
extern volatile unsigned int pulsosDerecha;
extern volatile unsigned int pulsosIzquierda;
extern float rpmDerecha;
extern float rpmIzquierda;
extern jormiL293D driverMotor;
extern int velDeseadaDerecha;
extern int velActualDerecha;
extern int velDeseadaIzquierda;
extern int velActualIzquierda;

//sensor distancia
extern int distValores[5];
extern int velDeseadaIzquierda;
extern int velActualIzquierda;
extern Servo myservo;
extern HCSR04 distHCSR04;


/*
 *	Testing Servomotor SG90 
 */


void TestingServo01 ();
void TestingServo02 ();
void TestingServo03 ();


/*
 *	Testing Ultrasonic sensor HC SR04
 */
 

void TestingUltrasonidos01();
void TestingUltrasonidos02();
void TestingUltrasonidos03();


/*
 *	Testing Motores 
 */


void TestingMotor01();
void TestingMotor02();







#endif //__JORMAZ_CBASICOTESTING_HPP__