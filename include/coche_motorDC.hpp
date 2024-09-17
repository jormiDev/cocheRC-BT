#ifndef __COCHE_MOTORDC__
#define __COCHE_MOTORDC__

#include "Arduino.h"
#include "constantes.h"
#include "coche_Encoders.hpp"
#include "main_debug.hpp"
#include "L298NX2.h"

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
extern L298NX2 myMotors;

    /*
    Funciones
    */

    // init del L298N
    void
    motorDC_setup();

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

// info
void motorDC_info();


/*
Funciones de TEST
*/

// test motor DRCHA (stop  -fwd BAJA - stop - aft - stop - fwd MEDIA - stop)
void motorDC_test01();

// motor IZQDA (stop  -fwd BAJA - stop - aft - stop - fwd MEDIA - stop)
void motorDC_test02();

// ambos motores (stop  -fwd BAJA - stop - aft - stop - fwd MEDIA - stop)
void motorDC_test03();

// calculo de RPM para todas las velocidades
void motorDC_test4();


#endif