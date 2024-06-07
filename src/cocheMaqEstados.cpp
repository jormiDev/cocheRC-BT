#include "cocheMaqEstados.hpp"

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>


/*
 * 	* * * * * Funciones * * * * *
 */

//  0
// estado inicial, desconecado ble + todo parado
void maqEstados_INICIO(){

}

//  1
// INICIO + conectado a BLE
void maqEstados_CONECTADO_BLE(){

}

//  2
// desconectado a BLE >> parar todo + estado buscar conexion
void maqEstados_DESCONECTADO_BLE(){

}

//  3
// >> parar todo + desconectar BLE
void maqEstados_QUIT_APP(){

}

//  4
// parar todo + analizar escenario + inicir conduccion automatica
void maqEstados_MODO_AUTO(){

}

//  5
// parar todo + esperar comnandos
void maqEstados_MODO_MANUAL(){

}