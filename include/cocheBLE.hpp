#ifndef __coche_BLE_HPP__
#define __coche_BLE_HPP__

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>
#include "constantes.h"
#include "cocheMaqEstados.hpp"

/*
 * 	Objetos y variables
 */

extern BLEDevice central;
extern BLEService unor4wifiService;
extern BLEIntCharacteristic unor4wifiCharacteristicMODO;
extern BLEIntCharacteristic unor4wifiCharacteristicDIREC;
extern const int ledPin;
extern int ble_Modo;
extern int ble_Direc;
extern int maquinaEstados;

/*
 * 	* * * * * Funciones * * * * *
 */

// Se ejecuta al contectarse al coche (una vez por conexcion)
void conectadoBLE();

// Se ejecuta al desconectarse al coche (una sola vez)
void desconectadoBLE();

//Se ejecuta al solicitar cerrar la app MIT
void quitappBLE();

//Codigo loop cuando conectado
void loopConectado();

// Codigo loop cuando DESconectado
void loopDesconectado();

// Caracteristica MODO
// dev true(valor caracteristica modificada) / false (no modificada)
bool caracteristicaMODO(); 

// Caracteristica DIRECCION
// dev true(valor caracteristica modificada) / false (no modificada)
bool caracteristicaDIREC();

#endif 