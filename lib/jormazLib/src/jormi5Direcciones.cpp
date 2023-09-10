
#ifndef __jormi5Direcciones_HPP__
#include "jormi5Direcciones.hpp"

#include "Arduino.h"

/*
	Constructor
*/
jormi5Direcciones::jormi5Direcciones(byte pinUP, byte pinDWN, byte pinLFT, byte pinRHT, byte pinMID, byte pinSET, byte pinRST)
{
	
	_pinUP = pinUP;
	_pinDWN = pinDWN;
	_pinLFT = pinLFT;
	_pinRHT = pinRHT;
	_pinMID = pinMID;
	_pinSET = pinSET;
	_pinRST = pinRST;

	_estado = 0b00000000;	//Con COM = GND con resistencia 10K como pull down
	
	pinMode( _pinUP, INPUT_PULLUP);
	pinMode( _pinDWN, INPUT_PULLUP);
	pinMode( _pinLFT, INPUT_PULLUP);
	pinMode( _pinRHT, INPUT_PULLUP);
	pinMode( _pinMID, INPUT_PULLUP);
	pinMode( _pinSET, INPUT_PULLUP);
	pinMode( _pinRST, INPUT_PULLUP);
}


/*
	Estado
	Devuelve el byte que contiene la lectura de pines
*/
byte jormi5Direcciones::estado()
{
	return _estado;
}


/*	
	Arriba
	True si pulsado UP
*/
bool jormi5Direcciones::arriba()
{
	if(bitRead(_estado, BUTTON_UP))
		return true;
	else 
		return false;
}


/*	
	Abajo
	True si pulsado DWN
*/
bool jormi5Direcciones::abajo()
{
	if(bitRead(_estado, BUTTON_DOWN))
		return true;
	else 
		return false;
}


/*	
	Izquierda
	True si pulsado LFT
*/
bool jormi5Direcciones::izquierda()
{
	if(bitRead(_estado, BUTTON_LEFT))
		return true;
	else 
		return false;
}


/*	
	Derecha
	True si pulsado RHT
*/
bool jormi5Direcciones::derecha()
{
	if(bitRead(_estado, BUTTON_RIGHT))
		return true;
	else 
		return false;
}


/*	
	Centro
	True si pulsado MID
*/
bool jormi5Direcciones::centro()
{
	if(bitRead(_estado, BUTTON_MID))
		return true;
	else 
		return false;
}


/*	
	Set
	True si pulsado SET
*/
bool jormi5Direcciones::set()
{
	if(bitRead(_estado, BUTTON_SET))
		return true;
	else 
		return false;
}


/*	
	Reset
	True si pulsado RST
*/
bool jormi5Direcciones::reset()
{
	if(bitRead(_estado, BUTTON_RESET))
		return true;
	else 
		return false;
}

	
/*
	Update
*/
void jormi5Direcciones::update()
{
	/*	COMENTADO PARA EVITAR ERRORES, PENDIENTE DE REVSION 2023
	
	
		byte leido;


		leido = digitalRead(_pinUP);
		if( leido != HIGH)
			_estado = bitSet(_estado, BUTTON_UP);
		else
			_estado = bitClear(_estado, BUTTON_UP);

		leido = digitalRead(_pinDWN);
		if( leido != HIGH)
			_estado = bitSet(_estado, BUTTON_DOWN);
		else
			_estado = bitClear(_estado, BUTTON_DOWN);

		leido = digitalRead(_pinLFT);
		if( leido != HIGH)
			_estado = bitSet(_estado, BUTTON_LEFT);
		else
			_estado = bitClear(_estado, BUTTON_LEFT);

		leido = digitalRead(_pinRHT);
		if( leido != HIGH)
			_estado = bitSet(_estado, BUTTON_RIGHT);
		else
			_estado = bitClear(_estado, BUTTON_RIGHT);

		leido = digitalRead(_pinMID);
		if( leido != HIGH)
			_estado = bitSet(_estado, BUTTON_MID);
		else
			_estado = bitClear(_estado, BUTTON_MID);

		leido = digitalRead(_pinSET);
		if( leido != HIGH)
			_estado = bitSet(_estado, BUTTON_SET);
		else
			_estado = bitClear(_estado, BUTTON_SET);

		leido = digitalRead(_pinRST);
		if( leido != HIGH)
			_estado = bitSet(_estado, BUTTON_RESET);
		else
			_estado = bitClear(_estado, BUTTON_RESET);

	*/
}


/*
	Información
	Muestra en ventana de depuración info de las variables y pines conectados
*/
void jormi5Direcciones::informacion()
{
//	Serial.println("Información del modulo 5 direcciones");
	
	// Serial.print("\t\t_pinUP\t = \t");
	// Serial.println(_pinUP);
	// Serial.print("(\t\t_pinDWN\t = \t");
	// Serial.println(_pinDWN);
	// Serial.print("(\t\t_pinLFT\t = \t");
	// Serial.println(_pinLFT);
	// Serial.print("\t\t_pinRHT\t = \t");
	// Serial.println(_pinRHT);
	// Serial.print("\t\t_pinMID\t = \t");
	// Serial.println(_pinMID);
	// Serial.print("\t\t_pinSET\t = \t");
	// Serial.println(_pinSET);
	// Serial.print("\t\t_pinRST\t = \t");
	// Serial.println(_pinRST);
	// Serial.println("\t\t_pinCOM\t = \tGND");	
	
	Serial.println("");
	Serial.print("\tEstado\t = \t");
	for (int b = 7; b >= 0; b--){
		Serial.print(bitRead(_estado, b));
		if( b == 4)
			Serial.print("  ");
	}
	Serial.println("\tCOM   RESET   SET   MID        RIGHT   LEFT   DOWN   UP");
	
}

#endif //__jormi5Direcciones_HPP__