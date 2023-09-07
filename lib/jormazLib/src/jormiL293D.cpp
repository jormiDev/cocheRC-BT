

#ifndef __jormiL293D_HPP__
#include "jormiL293D.hpp"

#include "Arduino.h"


/*
	Constructor 2 motores
 */
jormiL293D::jormiL293D(int IN1, int IN2, int IN3, int IN4)
{
  _IN1 = IN1;
  _IN2 = IN2;
  _IN3 = IN3;
  _IN4 = IN4;
  pinMode(_IN1, OUTPUT);  
  pinMode(_IN2, OUTPUT);
  pinMode(_IN3, OUTPUT);
  pinMode(_IN4, OUTPUT);
  
  this->stopA();
  this->stopB();
  this->enableA();
  this->enableB();
}


/*
	Constructor 1 motor
 */
jormiL293D::jormiL293D(int IN1, int IN2)
{
  _IN1 = IN1;
  _IN2 = IN2;
  _IN3 = -1;
  _IN4 = -1;  
  pinMode(_IN1, OUTPUT);  
  pinMode(_IN2, OUTPUT);
  
  this->stopA();
  this->enableA();
  this->disableB();

}


/*
	Mueve avante motorA
*/	
void jormiL293D::avanteA(int speed){
	if(_motorA){
		analogWrite(_IN1, speed);
		analogWrite(_IN2, LOW);
	}
}

void jormiL293D::avanteA(){
	if(_motorA){
	  analogWrite(_IN1, 255);
	  analogWrite(_IN2, LOW);
	}
}


/*
	Mueve avante motorB
*/	
void jormiL293D::avanteB(int speed){
	if(_motorB){
		analogWrite(_IN3, speed);
		analogWrite(_IN4, LOW);
	}	
}

void jormiL293D::avanteB(){
	if(_motorB){
		analogWrite(_IN3, 255);
		analogWrite(_IN4, LOW);  
	}
}


/*
	mueve atras motorA
*/
void jormiL293D::atrasA(int speed){
	if(_motorA){
	  analogWrite(_IN1, LOW);
	  analogWrite(_IN2, speed);
	}
}	

void jormiL293D::atrasA(){
	if(_motorA){
  analogWrite(_IN1, LOW);
  analogWrite(_IN2, 255);
	}
}	


/*
	mueve atras motorB
*/
void jormiL293D::atrasB(int speed){
	if(_motorB){
	  analogWrite(_IN3, LOW);
	  analogWrite(_IN4, speed); 
	}
}

void jormiL293D::atrasB(){
	if(_motorB){
	  analogWrite(_IN3, LOW);
	  analogWrite(_IN4, 255); 
	}
}


/*
	paro motorA
*/
void jormiL293D::stopA(){
	if(_motorA){
	  analogWrite(_IN1, LOW);
	  analogWrite(_IN2, LOW);
	}
}


/*
	paro motorB
*/
void jormiL293D::stopB(){
	if(_motorB){
	  analogWrite(_IN3, LOW);
	  analogWrite(_IN4, LOW); 
	}
}


/*
	activa motorA
*/
void jormiL293D::enableA(){
	_motorA = true;
}


/*
	desactiva motorA
*/
void jormiL293D::disableA(){
	_motorA = false;
}


/*
	activa motorB
*/
void jormiL293D::enableB(){
	_motorB = true;
}


/*
	desactiva motorB
*/
void jormiL293D::disableB(){
	_motorB = false;
}


/*
	Muestra información del objeto
*/
void jormiL293D::informacion(){
	Serial.print("L293D (pines)  \t");
	Serial.print(_IN1); Serial.print("\t");
	Serial.print(_IN1); Serial.print("\t");
	Serial.print(_IN3); Serial.print("\t");
	Serial.println(_IN4);
	Serial.println("      (motores)\tmotorA\t");
	Serial.print(_motorA); Serial.print("\t");
	Serial.println(_motorB);
}	


#endif