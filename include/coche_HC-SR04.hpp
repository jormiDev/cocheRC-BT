#ifndef __COCHE_HC_SR04__
#define __COCHE_HC_SR04__

#include "Arduino.h"
#include "constantes.h"
#include <HCSR04.h>

/*
Objetos y variables
*/

extern int maquinaEstados;
extern float sensorDist;
extern HCSR04 distHCSR04;

/*
Funciones
*/

// init del sensor HR-SR04
void ultrasonidos_setup();

// mide la distancia en cms
float ultrasonidos_mide();

// mejor rumbo decidido automaticamente
int ultrasonidos_decisionRumbo();

#endif