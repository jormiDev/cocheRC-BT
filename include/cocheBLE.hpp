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
extern BLEStringCharacteristic unor4wifiCharacteristicMODO;
extern BLEStringCharacteristic unor4wifiCharacteristicDIREC;
extern const int ledPin;
extern String ble_Modo;
extern int ble_Modo_int;
extern String ble_Direc;
extern int ble_Direc_int;
extern int maquinaEstados;

/*
 * 	* * * * * Funciones * * * * *
 */

// Se ejecuta al contectarse al coche (una vez por conexcion)
void conectadoBLE();

// Se ejecuta al desconectarse al coche (una sola vez)
//  Modo y dirección a default, parar motores
void desconectadoBLE();

//Se ejecuta al solicitar cerrar la app MIT
void quitappBLE();

// Codigo loop cuando conectado    
// se ejecuta mientras este conectado cada iteración
void loopConectado();

// Caracteristica MODO
// lee caracteristica BLE y actualiza : vble_Modo
// dev true(valor caracteristica modificada) / false (no modificada)
bool caracteristicaMODO();

// Caracteristica DIRECCION
// lee caracteristica BLE y actualiza : ble_Direc
// dev true(valor caracteristica modificada) / false (no modificada)
bool caracteristicaDIREC();


#endif 
