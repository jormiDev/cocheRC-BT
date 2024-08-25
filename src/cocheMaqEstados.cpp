#include "cocheMaqEstados.hpp"

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>


/*
 * 	* * * * * Funciones * * * * *
 */

// modo manual/auto - app_STOP
void manual_STOP(){
    motorDC_stop();
}

// modo manual - app_FWD
void manual_FWD(){
    motorDC_fwd(VELOCIDAD_MEDIA);
}

// modo manual - app_AFT
void manual_AFT(){
    motorDC_aft(VELOCIDAD_MEDIA);
}

// modo manual - app_IZQ
void manual_IZQ(){
    motorDC_A_fwd(VELOCIDAD_MEDIA);
    motorDC_B_fwd(VELOCIDAD_BAJA);
}

// modo manual - app_DCHA
void manual_DCHA(){
    motorDC_A_fwd(VELOCIDAD_BAJA);
    motorDC_B_fwd(VELOCIDAD_MEDIA);
}

// modo manual - app_90IZQ
void manual_90IZQ(){
    motorDC_90_IZQDA();
}

// modo manual - app_90DCHA
void manual_90DCHA(){
    motorC_90_DRCHA();
}

// modo manual - app_180
void manual_180(){
    motor_DC_180();
}

//  0
// estado inicial, desconecado ble + todo parado
void maqEstados_INICIO(){
    maquinaEstados = ME_INICIO;
}

//  1
// INICIO + conectado a BLE
void maqEstados_CONECTADO_BLE(){
    maquinaEstados = ME_DESCONECTADO_BLE;
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
    maquinaEstados = ME_MODO_AUTO;
}

//  5
// parar todo + esperar comnandos
void maqEstados_MODO_MANUAL(){
    maquinaEstados = ME_MODO_MANUAL;
}
