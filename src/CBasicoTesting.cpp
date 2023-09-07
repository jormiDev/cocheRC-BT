#include "CBasicoTesting.hpp"

/*
 * 	* * * * * Funciones * * * * *
 */
 
 
 
 /*
  *	Testing Servomotor SG90 ******************************
  */
  
  
//Mueve el servo en las 5 posiones 
void TestingServo01 (){
	mensaje.texto("* TestingSG90 * \t Posicionado SG90");
	mensaje.salto();
	delay(2500);
	int ang;

	sensorOrienta(45); 		delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(90); 		delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(0); 		delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(135); 	delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(180);		delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);
}

//Muestra el tiempo en ms para pasar de 0 a 180 - SERVO_DELAY_MS
void TestingServo02 (){
	unsigned long myTime, myDiff;

	mensaje.salto();
	mensaje.texto("* TestingSG90 * \t SERVO_DELAY_MS    de 0 a 180");
	mensaje.salto();
	delay(2500);

	myservo.write(0);
	delay(SERVO_DELAY_MS);
	myTime = millis();

	myservo.write(180);		
	delay(SERVO_DELAY_MS);
	myDiff = millis();
	
	myTime = myDiff-myTime;
	mensaje.vble("* ms = \t", myTime);
 }



 /*
  *	Testing Ultrasonic sensor HC SR04 ******************************
  */
 
 
//Calculo de la distancia (medida simple)  
 void TestingUltrasonidos01(){
	delay(2500);
	mensaje.texto("* TestingHC-SR04 * \t Medida simple ");
	mensaje.salto();
	mensaje.vble("* Distancia medida (cms) = \t ", distHCSR04.dist());
 }	 


//Calculo de la distancia (medida multiple)  
 void TestingUltrasonidos02(){
	delay(2500);
	mensaje.texto("* TestingHC-SR04 * \t Medida multiple ");
	mensaje.salto();
	
	unsigned long myTime, myDiff;
	myTime = millis();
	
	int dist;
	mensaje.texto("* Distancias medidas (cms) y periodo (ms)");
	for (int i = 0; i < 10; i++) {
		dist = distHCSR04.dist();
		//mensaje.vble("*", i);
		mensaje.vble("*cms = \t ", dist);	 
	}

	myDiff = millis();
	myTime = (myDiff - myTime)/10;
	mensaje.vble("*ms  media = \t", myTime);
	myTime = myDiff;
 }


 // Mide todas las distancias (distanciaUpdate)
 void TestingUltrasonidos03(){
	mensaje.texto("* TestingHC-SR04 * \t Medida en todas las direcciones ");
	mensaje.salto();

	distValores[0] = distanciaMide(0);
	distValores[1] = distanciaMide(45);
	distValores[2] = distanciaMide(90);
	distValores[3] = distanciaMide(135);
	distValores[4] = distanciaMide(180);

	mensaje.vble("dist   0 -		", distValores[0]);
	mensaje.vble("dist  45 -		", distValores[1]);
	mensaje.vble("dist  90 -		", distValores[2]);
	mensaje.vble("dist 135 -		", distValores[3]);
	mensaje.vble("dist 180 -		", distValores[4]);
	delay(2500);
 }

 

/*
 *	Testing Motores ******************************
 */


// Test completo motor A
void TestingMotor01()
{
	mensaje.texto("* TestingMotor * \t  Motor A - Full speed");
	mensaje.salto();

	mensaje.texto("Fwd A");
	driverMotor.avanteA();		delay(2000);

	mensaje.texto("Stop A");
	driverMotor.stopA();		delay(2000);

	mensaje.texto("Aft A");
	driverMotor.atrasA();		delay(2000);

	mensaje.texto("Stop A");
	driverMotor.stopA();		delay(5000);

		/*
		mensaje.texto("* TestingMotor * \t  Motor A - Progresivo");
		mensaje.salto();		delay(2500);

		mensaje.texto("* Avante");
		for (int i = 50; i < 200; i += 5)
		{
			mensaje.vble("*\t", i);
			driverMotor.avanteA(i);
			delay(200);
		}

		mensaje.texto("Stop A");
		driverMotor.stopA();
		delay(5000);

		mensaje.texto("* Atras");
		for (int i = 50; i < 200; i += 5)
		{
			mensaje.vble("*\t", i);
			driverMotor.atrasA(i);
			delay(200);
		}
	*/

	mensaje.texto("Stop A");
	driverMotor.stopA();
	delay(5000);
	mensaje.salto();
}


// Test completo motor B
void TestingMotor02()
	{
		mensaje.texto("* TestingMotor * \t  Motor B - Full speed");
		mensaje.salto();
		delay(2500);

		mensaje.texto("Fwd B");
		driverMotor.avanteB();
		delay(2000);
		mensaje.texto("Stop B");
		driverMotor.stopB();
		delay(2000);
		mensaje.texto("Aft B");
		driverMotor.atrasB();
		delay(2000);
		mensaje.texto("Stop B");
		driverMotor.stopA();
		delay(5000);

		mensaje.texto("* TestingMotor * \t  Motor B - Progresivo");
		mensaje.salto();
		delay(2500);

		mensaje.texto("* Avante");
		for (int i = 50; i < 200; i += 5)
		{
			mensaje.vble("*\t", i);
			driverMotor.avanteB(i);
			delay(200);
		}

		mensaje.texto("Stop B");
		driverMotor.stopB();
		delay(5000);

		mensaje.texto("* Atras");
		for (int i = 50; i < 200; i += 5)
		{
			mensaje.vble("*\t", i);
			driverMotor.atrasB(i);
			delay(200);
		}

		mensaje.texto("Stop B");
		driverMotor.stopA();
		delay(5000);
	}
