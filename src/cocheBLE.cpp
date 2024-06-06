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
	Serial.print("               MAC  (name)      : ");
	Serial.print(central.address());
	Serial.print("  ( ");
	Serial.print(central.deviceName());
	Serial.print(central.localName());
	Serial.println("  ) ");

	// Services
	Serial.println("          Servicio");
	Serial.print("               uuid       : ");
	Serial.println(unor4wifiService.uuid());

	// caracteristicas
	Serial.println("          Caracteristicas");

	Serial.print("(unor4wifiCharacteristicMODO)            uuid       : ");
	Serial.println(unor4wifiCharacteristicMODO.uuid());
	Serial.print("	valueSize   : ");
	Serial.println(unor4wifiCharacteristicMODO.valueSize());
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

	Serial.print("(unor4wifiCharacteristicDIREC)          uuid       : ");
	Serial.println(unor4wifiCharacteristicDIREC.uuid());
	Serial.print("	valueSize   : ");
	Serial.println(unor4wifiCharacteristicDIREC.valueSize());
	Serial.print("	propierties : ");
	properties = unor4wifiCharacteristicDIREC.properties();
	Serial.print(properties);
	if (properties & BLERead)
		Serial.print("  Read  ");
	if (properties & (BLEWrite | BLEWriteWithoutResponse))
		Serial.print("  Write  ");
	if (properties & BLENotify)
		Serial.print("  Notify  ");
	Serial.println();
	Serial.print("	value       : ");
	Serial.println(unor4wifiCharacteristicDIREC.value());

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
 }


 // Codigo loop cuando DESconectado
 void loopDesconectado(){
 }


// Caracteristica MODO
bool caracteristicaMODO(){
	if (unor4wifiCharacteristicMODO.written())	{
		ble_Modo = unor4wifiCharacteristicMODO.value();
		Serial.print("loop  : MODO modificado      (lenght = ");
		Serial.print(unor4wifiCharacteristicMODO.valueSize());
		Serial.print(")    :  ");
		Serial.println(ble_Modo);
		return true;
	}else
		return false;
}
 

 
// Caracteristica DIRECCION
bool caracteristicaDIREC(){
	if (unor4wifiCharacteristicDIREC.written())	{
		ble_Direc = unor4wifiCharacteristicDIREC.value();
		Serial.print("loop  : DIRECION modificada     (lenght = ");
		Serial.print(unor4wifiCharacteristicDIREC.valueSize());
		Serial.print(")    :  ");
		Serial.println(ble_Direc);
		return true;
	}else
		return false;
}
 