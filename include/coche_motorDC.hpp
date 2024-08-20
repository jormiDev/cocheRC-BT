#ifndef __COCHE_MOTORDC__
#define __COCHE_MOTORDC__

#include "Arduino.h"
#include "constantes.h"

/*
{
Rotate the Motor A clockwise
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);

Rotates the Motor A counter-clockwise
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);

Stop Soft
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);

Stop Hard
digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
*/

/*
Objetos y variables
*/

extern int maquinaEstados;
extern byte motorA_ENA; // Velocidad motorA 0.255
extern byte motorB_ENB; // Velocidad motorB 0..255

/*
Funciones
*/

// init del L298N
void motorDC_setup();

// motorA - avance
void motorDC_A_fwd(byte _vel);

// motorA - atras
void motorDC_A_aft(byte _vel);

// motorA - stop
void motorDC_A_stop();

// motorA - avance
void motorDC_B_fwd(byte _vel);

// motorA - atras
void motorDC_B_aft(byte _vel);

// motorA - stop
void motorDC_B_stop();

// avance AMBOS motores
void motorDC_fwd(byte _vel);

// atras AMBOS motores
void motorDC_aft( byte _vel);

// stop AMBOS motores
void motorDC_stop();

// giro 90 derecha
void motorC_90_DRCHA();

// giro 90 izquierda
void motorDC_90_IZQDA();

// giro 180
void motor_DC_180();


/*
Funciones de TEST
*/

//
void motorDC_test01();

//
void motorDC_test02();

//
void motorDC_test03();

#endif