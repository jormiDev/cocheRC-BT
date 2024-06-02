#include "cocheBLE.hpp"

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>


/*
 * 	* * * * * Funciones * * * * *
 */

// Se ejecuta al contectarse al coche (una vez por conexcion)
void conectadoBLE()
{
	// print the central's MAC address / name / uuid
	Serial.print("loop  : Connected   BLE      MAC         : ");
	Serial.println(central.address()); 
	Serial.print("                             Dispositivo : ");
	Serial.println(central.deviceName());
	Serial.print("        Servicio             uuid        : ");
	Serial.println(unor4wifiService.uuid());
	Serial.print("        Caracteristica       valueSize   : ");
	Serial.println(unor4wifiCharacteristic.valueSize());
	Serial.print("        Caracteristica       valueLength : ");
	Serial.println(unor4wifiCharacteristic.valueLength());
	Serial.println("");
		
	digitalWrite(ledPin, HIGH); // will turn the LED on
 }

 // Se ejecuta al desconectarse al coche (una sola vez)
 void desconectadoBLE(){
	 Serial.print("loop  : Disconnected BLE    (MAC) ");
	 Serial.println(central.address());
	 digitalWrite(ledPin, LOW); // will turn the LED off
 }

 // Se ejecuta al solicitar cerrar la app MIT
 void quitappBLE(){
 }

 // Codigo loop cuando conectado
 void loopConectado(){

	int value = 0;
	int largo = 0;

	/*	if (unor4wifiCharacteristic.written()){

			value = unor4wifiCharacteristic.readValue();
			largo = unor4wifiCharacteristic.valueLength();

						Serial.print("loop  : Recibido     (lenght = ");
			Serial.print(largo);
			Serial.print(")    :  ");
			Serial.println(value);
		}*/
 }

 // Codigo loop cuando DESconectado
 void loopDesconectado(){
 }