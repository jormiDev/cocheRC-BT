/*
	jormi5Direcciones.h
	Librería de manejo del modulo 5 direcciones + reset + set
	
	IMPORTANTE: COM puesto a GND con resistencia 10K como pull down
	Cuando el boton se pulsa se lee Vcc, sino esta pulsado lee GND
	
	v0.1	20210214	Multitask	
*/



#ifndef __jormi5Direcciones_HPP__
#define __jormi5Direcciones_HPP__

#include "Arduino.h"

#define BUTTON_UP		0
#define BUTTON_DOWN		1
#define BUTTON_LEFT		2
#define BUTTON_RIGHT	3
#define BUTTON_MID		4
#define BUTTON_SET		5
#define BUTTON_RESET	6


class jormi5Direcciones
{
	
private:
	byte _pinUP;		//Pines de conexión de módulo
	byte _pinDWN;		
	byte _pinLFT;		
	byte _pinRHT;		
	byte _pinMID;		
	byte _pinSET;		
	byte _pinRST;		

	byte _estado;		//8 bits que guardan es estado leido de cada pin
						//0		1		2		3		4		5		6		7		
						//UP	DWN		LFT		RGT		MID		SET		SRT		COM
						
	
public:


/*
	Constructor
*/
jormi5Direcciones(byte pinUP, byte pinDWN, byte pinLFT, byte pinRHT, byte pinMID, byte pinSET, byte pinRST);


/*
	Estado
	Devuelve el byte que contiene la lectura de pines
*/
byte estado();
	

/*	
	Arriba
	True si pulsado UP
*/
bool arriba();


/*	
	Abajo
	True si pulsado DWN
*/
bool abajo();


/*	
	Izquierda
	True si pulsado LFT
*/
bool izquierda();


/*	
	Derecha
	True si pulsado RHT
*/
bool derecha();


/*	
	Centro
	True si pulsado MID
*/
bool centro();


/*	
	Set
	True si pulsado SET
*/
bool set();


/*	
	Reset
	True si pulsado RST
*/
bool reset();


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


#endif //__jormi5Direcciones_HPP__
