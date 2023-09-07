
#ifndef __jormiPulsador_HPP__
#include "jormiPulsador.hpp"

#include "Arduino.h"

/*
	Constructor
	int pin			pin de entrada
*/
jormiPulsador::jormiPulsador(byte pin, bool tipo)
{
	_pin = pin;
	_estado = false;
	_tipo = tipo;
	pinMode(_pin, INPUT);
}


/*
	Estado
	Devuelve estado del pulsador	
	return
		true, pulsado
		false, no pulsado
*/
bool jormiPulsador::estado()
{
	return _estado;
}
	
	
/*
	Update
*/
void jormiPulsador::update()
{	
	bool x = digitalRead(_pin);
		
	if( _tipo ){
		//	Tipo PullUp
		if( x == LOW )
			_estado =  true;
		else
			_estado =  false;	
	}else{			
		//Tipo PullDown
		if( x == HIGH )
			_estado =  true;
		else
			_estado =  false;		
	}
}


/*
	Información
	Muestra en ventana de depuración info de las variables
*/
void jormiPulsador::informacion()
{
	Serial.print("jormiPulsador\t_pin\t\t\t = \t");
	Serial.println(_pin);						
	Serial.print("jormiPulsador\t_estado\t\t\t = \t");
	Serial.println(_estado);					
	Serial.print("jormiPulsador\t_tipo\t\t\t = \t");
	if( _tipo )
		Serial.println("Pull Up");	
	else
		Serial.println("Pull Down");	
}


#endif