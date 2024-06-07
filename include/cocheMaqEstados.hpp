#ifndef __coche_MAQ_ESTADOS_HPP__
#define __coche_MAQ_ESTADOS_HPP__

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>
#include "constantes.h"
#include "cocheBLE.hpp"

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

//  0
// estado inicial, desconecado ble + todo parado
void maqEstados_INICIO();

//  1
// INICIO + conectado a BLE
void maqEstados_CONECTADO_BLE();

//  2
// desconectado a BLE >> parar todo + estado buscar conexion
void maqEstados_DESCONECTADO_BLE();

//  3
// >> parar todo + desconectar BLE
void maqEstados_QUIT_APP();

//  4
// parar todo + analizar escenario + inicir conduccion automatica
void maqEstados_MODO_AUTO();

//  5
// parar todo + esperar comnandos
void maqEstados_MODO_MANUAL();


#endif 