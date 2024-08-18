#ifndef __COCHE_SG90__
#define __COCHE_SG90__

#include "Arduino.h"
#include "constantes.h"
#include "Servo.h"


/*
Conversion de posiciones

Servo               0 .. 180
Programa            -90 .. 90
*/




/*
Objetos y variables
*/

extern int maquinaEstados;
extern Servo myservo;
extern int posicionServo;      //0 .. 180

/*
Funciones
*/

// init del servo SG90
void servo_setup();

// mueve el servo a la posición
void servo_orienta(int angulo);

// devuelve el angulo del servo
int servo_posicion();


/*
Funciones de TEST
*/

// mueve el servo en las posiciones -90, -45, 0, 45, 90
void servo_test01();

// calcula el tiempo (en ms) para pasar de -90 a +90
void servo_test02();

// Paso lento de  -90 a +90c
void servo_test03();

#endif