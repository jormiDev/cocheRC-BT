#include "cocheMaqEstados.hpp"

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>


/*
 * 	* * * * * Funciones * * * * *
 */

// modo manual - app_STOP
void manual_STOP(){

}

// modo manual - app_FWD
void manual_FWD(){

}

// modo manual - app_AFT
void manual_AFT(){

}

// modo manual - app_IZQ
void manual_IZQ(){

}

// modo manual - app_DCHA
void manual_DCHA(){

}

// modo manual - app_90IZQ
void manual_90IZQ(){
    
}

// modo manual - app_90DCHA
void manual_90DCHA(){

}

// modo manual - app_180
void manual_180(){

}

//  0
// estado inicial, desconecado ble + todo parado
void maqEstados_INICIO(){
    maquinaEstados = ME_INICIO;
}

//  1
// INICIO + conectado a BLE
void maqEstados_CONECTADO_BLE(){
    maquinaEstados = ME_CONECTADO_BLE;
}

//  2
// desconectado a BLE >> parar todo + estado buscar conexion
void maqEstados_DESCONECTADO_BLE(){
    maquinaEstados = ME_DESCONECTADO_BLE;
}

//  3
// >> parar todo + desconectar BLE
void maqEstados_QUIT_APP(){
    maquinaEstados = ME_QUIT_APP;
}

//  4
// parar todo + analizar escenario + inicir conduccion automatica
void maqEstados_MODO_AUTO(){

}

//  5
// parar todo + esperar comnandos
void maqEstados_MODO_MANUAL(){

}
