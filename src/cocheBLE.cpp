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
	// print the central's device
	Serial.println();
	Serial.println("loop  : Connected   BLE    (Device)");
	Serial.print("               MAC        : ");
	Serial.println(central.address());
	Serial.print("               name       : ");
	Serial.print(central.deviceName());
	Serial.println(central.localName());

	// Services
	Serial.println("          Servicio");
	Serial.print("               uuid       : ");
	Serial.println(unor4wifiService.uuid());

	// caracteristicas
	Serial.println("          Caracteristica");

	Serial.print("(unor4wifiCharacteristicMODO)            uuid       : ");
	Serial.println(unor4wifiCharacteristicMODO.uuid());
	Serial.print("	valueSize   : ");
	Serial.print(unor4wifiCharacteristicMODO.valueSize());
	Serial.print("	propierties : ");
	byte properties = unor4wifiCharacteristicMODO.properties();
	Serial.print(properties);
	if (properties & BLERead)  
		Serial.print("  Read  ");
	if (properties & (BLEWrite | BLEWriteWithoutResponse))
		Serial.print("  Write  ");
	if (properties & BLENotify)
		Serial.print("  Notify  ");
	Serial.println();
	Serial.print("	value       : ");
	Serial.println(unor4wifiCharacteristicMODO.value());

	Serial.print("(unor4wifiCharacteristicDIRECT)          uuid       : ");
	Serial.println(unor4wifiCharacteristicDIRECT.uuid());
	Serial.print("	valueSize   : ");
	Serial.print(unor4wifiCharacteristicDIRECT.valueSize());
	Serial.print("	propierties : ");
	properties = unor4wifiCharacteristicDIRECT.properties();
	Serial.print(properties);
	if (properties & BLERead)
		Serial.print("  Read  ");
	if (properties & (BLEWrite | BLEWriteWithoutResponse))
		Serial.print("  Write  ");
	if (properties & BLENotify)
		Serial.print("  Notify  ");
	Serial.println();
	Serial.print("	value       : ");
	Serial.println(unor4wifiCharacteristicDIRECT.value());

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