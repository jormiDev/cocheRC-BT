#include "CBasicoMotor.hpp"

/*
 *  Notas
*/

/*
https://www.teachmemicro.com/lm393-ir-module-motor-speed-sensor/
Los shaft encoders (sensores de velocidad) emplean los pines de interrupción 2 y 3 en Uno y Nano


				Stop		Avance (horario)		Atras(antihorario)
	PIN1		LOW			HIGH/speed				LOW
	PIN2(PWD) 	LOW			LOW						HIGH/speed
*/


 /*
  * 	* * * * * Funciones * * * * * 
  */

/*
  Setup CBasicoMotor
*/
void motorSetup()
{
	mensaje.texto("setupMotor INIT");

	// Init motores
	driverMotor.enableA();
	driverMotor.enableB();
	velDeseadaDerecha = 0;
	velDeseadaIzquierda = 0;

	mensaje.texto("\t enableMotor A");
	mensaje.vble("\t enable PIN_IN1       pin = ", PIN_IN1);
	mensaje.vble("\t enable PIN_IN2       pin = ", PIN_IN2);
	mensaje.texto("\t enableMotor B");
	mensaje.vble("\t enable PIN_IN3       pin = ", PIN_IN3);
	mensaje.vble("\t enable PIN_IN4       pin = ", PIN_IN4);

	// // Init contador de pulsos y rpm
	pulsosDerecha = 0;
	pulsosIzquierda = 0;
	rpmDerecha = 0;
	rpmIzquierda = 0;

	// // Declarar funcion interrupciones
	Timer1.initialize(1000000);														 // set timer for 1sec
	attachInterrupt(digitalPinToInterrupt(PIN_ENC_IZQ), ISR_CountIzquierda, RISING); // Increase speed sensor pin goes High
	attachInterrupt(digitalPinToInterrupt(PIN_ENC_DCHO), ISR_CountDerecha, RISING);	 // Increase speed sensor pin goes High
	Timer1.attachInterrupt(ISR_timerone);											 // Enable the timer

	mensaje.texto("\t Encoders");
	mensaje.vble("\t enable Derecho         pin = ", PIN_ENC_DCHO);
	mensaje.vble("\t enable Izquierdo       pin = ", PIN_ENC_IZQ);

	mensaje.texto("setupMotor FIN");
}


/*
  Funcion IRS 0 - Motor derecho 
*/
void ISR_CountDerecha()  
{
  pulsosDerecha++;  
} 
 

/*
  Funcion IRS 1 - Motor izquierdo
*/
void ISR_CountIzquierda()  
{
  pulsosIzquierda++;  
} 
 

/*
   TimerOne ISR
   Se llama cada segundo y recalcula RPMs
*/
void ISR_timerone()
{
  Timer1.detachInterrupt();  // Stop the timer
  rpmDerecha = (pulsosDerecha / diskslots) * 60.00;  // calculate RPM 
  pulsosDerecha = 0;  //  reset counter to zero
  rpmIzquierda = (pulsosIzquierda / diskslots) * 60.00;  // calculate RPM 
  pulsosIzquierda = 0;  //  reset counter to zero
  Timer1.attachInterrupt( ISR_timerone );  // Enable the timer
}


/*
  Serial motorSerial
*/
void motorSerial()
{
  	Serial.print("Derecho \t actualRPMs(");
	Serial.print(rpmDerecha,5);
	Serial.print(") \t actualVel(");
	Serial.print(velActualDerecha,5);
	Serial.print(") \t setVel(");
	Serial.print(velDeseadaDerecha,5);
	Serial.println(")");

  	Serial.print("Izquierdo \t actualRPMs(");
	Serial.print(rpmIzquierda,5);
	Serial.print(") \t actualVel(");
	Serial.print(velActualIzquierda,5);
	Serial.print(") \t setVel(");
	Serial.print(velDeseadaIzquierda,5);
	Serial.println(")");
}


/*
	motorUpdate
*/
void motorUpdate()
{
	//Motor Derecho == A
	if( velActualDerecha == 0 )
	{
		if(velDeseadaDerecha == 0) {
			// 0 >> 0
		}else if(velDeseadaDerecha < 0) {
			// 0 >> --
			velActualDerecha = velDeseadaDerecha;
			driverMotor.atrasA(abs(velDeseadaDerecha));
		}else{
			// 0 >> ++
			velActualDerecha = velDeseadaDerecha;
			driverMotor.avanteA(velDeseadaDerecha);	
		}
	}else if( velActualDerecha < 0 )
	{
		if(velDeseadaDerecha == 0) {
			// -- >> 0
			driverMotor.stopA();
			velActualDerecha = velDeseadaDerecha;
			delay(MOTOR_PARO);
		}else if(velDeseadaDerecha < 0) {
			// -- >> --
			velActualDerecha = velDeseadaDerecha;
			driverMotor.atrasA(abs(velDeseadaDerecha));
		}else{
			// -- >> ++
			velActualDerecha = velDeseadaDerecha;
			driverMotor.stopA();
			delay(MOTOR_INVERSION);
			driverMotor.avanteA(velDeseadaDerecha);	
		}
	}else{
		if(velDeseadaDerecha == 0) {
			// ++ >> 0
			driverMotor.stopA();
			velActualDerecha = velDeseadaDerecha;
			delay(MOTOR_PARO);
		}else if(velDeseadaDerecha < 0) {
			// ++ >> --
			velActualDerecha = velDeseadaDerecha;
			driverMotor.stopA();
			delay(MOTOR_INVERSION);
			driverMotor.atrasA(abs(velDeseadaDerecha));	
		}else{
			// ++ >> ++
			velActualDerecha = velDeseadaDerecha;
			driverMotor.avanteA(velDeseadaDerecha);
		}		
	}
	
	//Motor Izquierdo == B
	if( velActualIzquierda == 0 )
	{
		if(velDeseadaIzquierda == 0) {
			// 0 >> 0
		}else if(velDeseadaIzquierda < 0) {
			// 0 >> --
			velActualIzquierda = velDeseadaIzquierda;
			driverMotor.atrasA(abs(velDeseadaIzquierda));
		}else{
			// 0 >> ++
			velActualIzquierda = velDeseadaIzquierda;
			driverMotor.avanteA(velDeseadaIzquierda);	
		}
	}else if( velActualIzquierda < 0 )
	{
		if(velDeseadaIzquierda == 0) {
			// -- >> 0
			driverMotor.stopA();
			velActualIzquierda = velDeseadaIzquierda;
			delay(MOTOR_PARO);
		}else if(velDeseadaIzquierda < 0) {
			// -- >> --
			velActualIzquierda = velDeseadaIzquierda;
			driverMotor.atrasA(abs(velDeseadaIzquierda));
		}else{
			// -- >> ++
			velActualIzquierda = velDeseadaIzquierda;
			driverMotor.stopA();
			delay(MOTOR_INVERSION);
			driverMotor.avanteA(velDeseadaIzquierda);	
		}
	}else{
		if(velDeseadaIzquierda == 0) {
			// ++ >> 0
			driverMotor.stopA();
			velActualIzquierda = velDeseadaIzquierda;
			delay(MOTOR_PARO);
		}else if(velDeseadaIzquierda < 0) {
			// ++ >> --
			velActualIzquierda = velDeseadaIzquierda;
			driverMotor.stopA();
			delay(MOTOR_INVERSION);
			driverMotor.atrasA(abs(velDeseadaIzquierda));	
		}else{
			// ++ >> ++
			velActualIzquierda = velDeseadaIzquierda;
			driverMotor.avanteA(velDeseadaIzquierda);
		}
	}
}



/*
	motorGiro
*/
void motorGiro(int _ang){
	/*
	switch (_ang) {
	case 180:
	
	break;

	case -90:
	
	break;

	case -45:
	
	break;

	case 90:
	
	break;

	case 45:
	
	break;

	default:
		mensaje.vble("motorGiro() \t valor ángulo giro ilegal = ", _ang);
	break;

	}  
	*/
}





