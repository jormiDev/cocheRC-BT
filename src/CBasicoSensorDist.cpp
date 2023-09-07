#include "CBasicoSensorDist.hpp"


/*
  Setup CBasicoSensorDist
*/
void distanciaSetup()
{
	mensaje.texto("setupDistancia INIT");
	//Setup HC-SR04
	distValores[0] = 0;
	distValores[1] = 0;
	distValores[2] = 0;
	distValores[3] = 0;
	distValores[4] = 0;
	mensaje.vble("\t enable HC-RS04 -    echo      pin = ", PIN_HCSR04_ECHO);
	mensaje.vble("\t enable HC-RS04 - trigger      pin = ", PIN_HCSR04_TRIGGER);

	// Init SG90
	myservo.attach(PIN_SERVO);
	mensaje.vble("\t enable SG90                   pin = ", PIN_SERVO);

	mensaje.texto("setupDistancia FIN");
}


/*
	distanciaUpdate
*/
void distanciaUpdate()
{
	if( maquinaEstados == 1 ){
		//Leer solo distancia frontal
		distValores[2] = distanciaMide(0);
	}
	
	else if( maquinaEstados == 4 ){
		//Leer TODAS las distancias
		distValores[0] = distanciaMide(0);
		distValores[1] = distanciaMide(45);
		distValores[2] = distanciaMide(90);
		distValores[3] = distanciaMide(135);
		distValores[4] = distanciaMide(180);
	}	
}


/*
	distanciaMide
*/
int distanciaMide(int ang)
{
	sensorOrienta(ang);

	int distCms = distHCSR04.dist();
	delay(HCSR04_DELAY_MS);

	return distCms;
}


/*
	sensorOrienta(int ang)
*/
void sensorOrienta(int ang)
{
	myservo.write(ang);
	delay(SERVO_DELAY_MS);
}


/*
	sensorAngulo()
	devuelve angulo del SG90
*/
int sensorAngulo(){
	return myservo.read();
}