#ifndef __COCHE_ENCODERS__
#define __COCHE_ENCODERS__

#include "Arduino.h"
#include "Countimer.h"

#include "constantes.h"

/*
Objetos y variables
*/

extern int maquinaEstados;

extern Countimer miTimer;
extern float rpmDerecha;
extern float rpmIzquierda;
extern volatile unsigned int pulsosDerecha;
extern volatile unsigned int pulsosIzquierda;

/*
Funciones
*/

// init de los encoders
void encoders_setup();

//Funcion IRS 0 - Motor derecho
void ISR_CountDerecha();

// Funcion IRS 1 - Motor izquierdo
void ISR_CountIzquierda();

// TimerOne ISR(Se llama cada 5  segundo y recalcula RPMs) *
void ISR_timerone();

// Info de velocidades por puerto serial
void encoders_info();

/*
Funciones de TEST
*/

// test shaft encoder DRCHA
void encoders_test01();

// test shaft encoder IZQDA
void encoders_test02();

// test shaft encoder IZQDA + DRCHA
void encoders_test03();

#endif