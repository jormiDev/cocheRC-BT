#ifndef __JORMAZ_CBASICOSENSORDIST_HPP__
#define __JORMAZ_CBASICOSENSORDIST_HPP__

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


/*
  distanciaSetup

  inicializa el sensor de HC-SR04
  inicializa motor SG90
*/
void distanciaSetup();

/*
	distanciaUpdate
	
	actualiza lectura distancias (frontal/todas)
*/
void distanciaUpdate();

/*
	distanciaMide
	
	mide distancia con la orientación del angulo pasado
*/
int distanciaMide(int ang);
	
/*	
	sensorOrienta(int ang)
	
	actualiza orientación del SG90
*/
void sensorOrienta(int ang);

/*	
	sensorAngulo()

	devuelve angulo del SG90
*/
int sensorAngulo();

#endif 