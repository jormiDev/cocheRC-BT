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
int ultrasonidos_decisionRumbo();               //PENDIENTE MODO AUTO

/*
Funciones de TEST
*/

// test de una medición
void ultrasonidos_test01();

// test de varias mediciones y la media de todas
void ultrasonidos_test02();

// test de mediciones moviemdo el servo en las posiciones -90, -45, 0, 45, 90
void ultrasonidos_test03();                     // PENDIENTE MODO AUTO

#endif