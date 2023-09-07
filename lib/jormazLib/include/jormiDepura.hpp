
/*
	jormiDepura_h
	Librería para envio de mensajes de depuración
	v0.1	20200906
	v0.2	20210130
	v0.3	20210212	añadida sobrecarga y byte en binario

*/


#ifndef __jormiDepura_HPP__
#define __jormiDepura_HPP__

#include "Arduino.h"


class jormiDepura
{
private:	
		
public:
/*	
	Constructor
*/
jormiDepura();

/*
	texto
	Muestra una cadena de texto + \n
	Entrada: cadena de texto
*/
void texto(String cadena);

/*
	salto
	Inserta linea en blanco
*/
void salto();

/*
	xInt
	Muestra el valor de una variable int, String, bool, float, byte, uLong, long
*/
void vble(String v, int x);
void vble(String v, unsigned int x);
void vble(String v, String x);
void vble(String v, bool x);
void vble(String v, float x);
void vble(String v, byte x);
void vble(String v, unsigned long x);
void vble(String v, long x);

/*
	xBinario
	Muestra el valor de una variable byte en binario
*/
void binario(String v, byte x);
};

#endif	//__jormiDepura_HPP__