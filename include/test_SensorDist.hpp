#ifndef __JORMAZ_TEST_SENSORDIST_HPP__
#define __JORMAZ_TEST_SENSORDIST_HPP__

/*
    Ángulos
        distValores	[0] 	(00)		Izqda
                    [1]		(45)
                    [2]		(90)		Frontal
                    [3]		(135)
                    [4] 	(180)		Drcha
*/

#include "Arduino.h"
#include <HCSR04.h>
#include <Servo.h>

#include "jormazLib.h"
#include "constantes.h"

/*
 * 	Objetos y variables
 */

extern jormiDepura mensaje;
extern int maquinaEstados;

extern int distValores[5];
extern int velDeseadaIzquierda;
extern int velActualIzquierda;
extern HCSR04 distHCSR04;
extern Servo myservo;

/*
 * 	* * * * * Funciones * * * * *
 */


// Calculo de la distancia (medida simple)
void test_Ultrasonidos01();

// Calculo de la distancia (medida multiple)
void test_Ultrasonidos02();

// Mide todas las distancias (distanciaUpdate)
void test_Ultrasonidos03();


// Mueve el servo en las 5 posiones
void test_Servo01();

// Muestra el tiempo en ms para pasar de 0 a 180 - SERVO_DELAY_MS
void test_Servo02();

#endif