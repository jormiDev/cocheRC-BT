/*
  Drive.h - Library for controlling Robot Car with L298x bridge series
  Created by Oladapo E. Ajala, November 13, 2018.
  Released into the public domain.
  Copy right InvenTech inc.
  
  jormiL293D_h
  Libreria manejo de motores DC via L293D
  v0.1		20210729		adaptación del original Drive
  v0.2		20211219		motores separados y revisión general
    
	
								Stop		Avance (horario)		Atras(antihorario)
	PIN1						LOW			HIGH/speed				LOW
	PIN2	PWD obligatorio		LOW			LOW						HIGH/speed
	PIN3
	PIN4	PWD obligatorio
	
	Inicio con motor parado
	
*/

#ifndef __jormiL293D_HPP__
#define __jormiL293D_HPP__

#include "Arduino.h"

class jormiL293D
{
  public:
  
	/*
		Constructor 2 motores
	*/
    jormiL293D(int IN1, int IN2, int IN3, int IN4);	
	
	/*
		Constructor 1 motor
	*/
    jormiL293D(int IN1, int IN2);
	
	/*
		Mueve avante
	*/		
    void avanteA(int speed);			// speed = 0 ..255
    void avanteA();						// full speed
    void avanteB(int speed);			// speed = 0 ..255
    void avanteB();						// full speed
		
	/*
		mueve atras
	*/
    void atrasA(int speed);				// speed = 0 ..255
    void atrasA();						// full speed
    void atrasB(int speed);				// speed = 0 ..255
    void atrasB();						// full speed
	
	/*
		paro
	*/
    void stopA();	
    void stopB();	
	
	/*
		activa / desactiva motores
	*/
	void enableA();
	void disableA();
	void enableB();
	void disableB();
	
	
	/*
		informacion
	*/
	void informacion();
	
	
  private:
	int _IN1;			//Pines conectados
	int	_IN2;
	int _IN3;
	int _IN4;
	bool _motorA;		//Motores enable(presente)
	bool _motorB;
};

#endif