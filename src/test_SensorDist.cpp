#include "test_SensorDist.hpp"
#include "CBasicoSensorDist.hpp"


/*
Calculo de la distancia (medida simple)
*/
void test_Ultrasonidos01()
{
	delay(2500);
	mensaje.salto();
	mensaje.texto("* TestingHC-SR04 * \t Medida simple ");
	mensaje.salto();
	mensaje.vble("* Distancia medida (cms) = \t ", distHCSR04.dist());
}


/*
Calculo de la distancia (medida multiple)
*/
void test_Ultrasonidos02()
{
	delay(2500);
	mensaje.salto();
	mensaje.texto("* TestingHC-SR04 * \t Medida multiple ");
	mensaje.salto();

	unsigned long myTime, myDiff;
	myTime = millis();

	int dist;
	int distMedia = 0;
	mensaje.texto("* Distancias medidas (cms) y periodo (ms)");
	for (int i = 0; i < 10; i++)
	{
		dist = distHCSR04.dist();
		distMedia = distMedia + dist;
		// mensaje.vble("*", i);
		mensaje.vble("*cms = \t ", dist);
	}

	distMedia  = distMedia / 10;
	mensaje.vble("media medida (cms)= ", distMedia);

	myDiff = millis();
	myTime = (myDiff - myTime) / 10;
	mensaje.vble("tiempo (ms) = ", myTime);
	myTime = myDiff;
}


/*
Mide todas las distancias (distanciaUpdate)
*/
void test_Ultrasonidos03()
{
	mensaje.salto();
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
Mueve el servo en las 5 posiones
*/
void test_Servo01()
{
	mensaje.texto("* TestingSG90 * \t Posicionado SG90");
	mensaje.salto();
	delay(2500);
	int ang;

	sensorOrienta(45);
	delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(90);
	delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(0);
	delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(135);
	delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);

	sensorOrienta(180);
	delay(SERVO_DELAY_MS);
	ang = sensorAngulo();
	mensaje.vble("* Angulo ", ang);
}


/*
Muestra el tiempo en ms para pasar de 0 a 180 - SERVO_DELAY_MS
*/
void test_Servo02()
{
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

	myTime = myDiff - myTime;
	mensaje.vble("* ms = \t", myTime);
}
