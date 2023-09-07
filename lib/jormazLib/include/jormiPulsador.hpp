/*
	jormiPulsador.h
	Librería de manejo de pulsadores
	v0.1	20200820
	v0.2	20200906
	
	Version Pull Up - PU
			Pulsado = 0v
			GND > Pulsador > pinDigital > resistencia > 5V
	Version Pull Down - PD		
			Pulsado = 5v
			Pulsado = 5v
			GND > resistencia > pinDigital > Pulsador > 5V
*/


#ifndef __jormiPulsador_HPP__
#define __jormiPulsador_HPP__

#include "Arduino.h"

class jormiPulsador
{

private:
	byte _pin;		//pin conectado al pulsador
	bool _estado;	//valor pulsador TRUE-FALSE
	bool _tipo;		//tipo de pulsador 
					//		PU = TRUE
					//		PD = FALSE
	
	
public:
/*	Constructor
	int pin
*/
jormiPulsador(byte pin, bool tipo);


/*
	Estado
	Lee estado del pulsador
	
	version PullUp (pulsado == LOW)
	return
		true, pulsado
		false, no pulsado
		
	version PullDown (pulsado == HIGH)
	return
		true, pulsado
		false, no pulsado
*/
bool estado();


/*
	Update
*/
void update();


/*
	Información
	Muestra en ventana de depuración info de las variables
*/
void informacion();



};

#endif //__jormiPulsador_HPP__
