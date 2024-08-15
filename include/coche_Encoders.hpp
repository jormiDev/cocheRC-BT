#ifndef __COCHE_ENCODERS__
#define __COCHE_ENCODERS__

#include "Arduino.h"
#include "constantes.h"
#include "TimerInterrupt.h"

/*
Objetos y variables
*/

extern int maquinaEstados;
extern float rpmDerecha;
extern float rpmIzquierda;
extern volatile unsigned int pulsosDerecha;
extern volatile unsigned int pulsosIzquierda;
extern int rpmDerechaObjetivo;   
extern int rpmIzquierdaObjetivo; 

/*
Funciones
*/

// init de los encoders
void encoders_setup();

//Funcion IRS 0 - Motor derecho
void ISR_CountDerecha()

// Funcion IRS 1 - Motor izquierdo
void ISR_CountIzquierda()

// TimerOne ISR(Se llama cada segundo y recalcula RPMs) *
void ISR_timerone()

// Info de velocidades por puerto serial
void encoders_info();

/*
Funciones de TEST
*/

// 
void encoders_test01();

// 
void encoders_test02();

// 
void encoders_test03();

#endif