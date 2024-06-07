

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>

#include <constantes.h>
#include "cocheBLE.hpp"

// listen for Bluetooth® Low Energy peripherals to connect:
BLEDevice central;
// Bluetooth® Low Energy LED Service
BLEService unor4wifiService(BLE_SERVICE); 
// BlLE Characteristic 
BLEIntCharacteristic unor4wifiCharacteristicMODO(BLE_CARACT_MODO, BLERead | BLEWrite | BLENotify);
int ble_Modo = -1;
BLEIntCharacteristic unor4wifiCharacteristicDIREC(BLE_CARACT_DIREC, BLERead | BLEWrite | BLENotify);
int ble_Direc = -2;

const int ledPin = LED_BUILTIN;     // on  BLE conectado / off BLE desconectado

int maquinaEstados;                 

/*
 * ********   S E T U P   ***************
 */


void setup(){
    
    // Serial init
    Serial.begin(9600);
    while (!Serial)
        ;
    Serial.println();
    Serial.println("setup : init");

    // set LED pin to output mode
    pinMode(ledPin, OUTPUT);

    // begin initialization
    if (!BLE.begin())
    {
        Serial.println("setup : starting Bluetooth® Low Energy module failed!");
        while (1)
            ;
    }

    // set advertised local name and service UUID:
    BLE.setLocalName(BLE_LOCAL_NAME);                           
    BLE.setDeviceName(BLE_DEVICE_NAME);
    BLE.setAdvertisedService(unor4wifiService);
    // add the characteristic
    unor4wifiService.addCharacteristic(unor4wifiCharacteristicMODO);
    unor4wifiService.addCharacteristic(unor4wifiCharacteristicDIREC);
    // add the service
    BLE.addService(unor4wifiService);   
    // set the initial value for the characeristics
    unor4wifiCharacteristicMODO.writeValue(ble_Modo);
    unor4wifiCharacteristicDIREC.writeValue(ble_Direc);
    // start advertising
    BLE.advertise();
    Serial.println("/nsetup : BLE init OK");

    maquinaEstados = ME_INICIO;

    Serial.println("setup : fin");
    delay(5000);
    Serial.println("/nloop  : init");

}//	setup



/*
 * ********   L O O P   ***************
 */

void loop()
{
    central = BLE.central();

    // if a central is connected to peripheral:
    if (central){

        conectadoBLE();                                 //  ejecuta una vez al conectar

        // while the central is still connected to peripheral:
        while (central.connected()){
           
            loopConectado();                            //  loop cuando conectdo

            if( caracteristicaMODO() ){                 //  caracteristica MODO modificada
                
            }

            if (caracteristicaDIREC()){                 //  caracteristica DIREC modificada
                
            }
        }   

        desconectadoBLE();                              //  ejecuta una vez al desconectar
    }
}
