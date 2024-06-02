

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>

#include <constantes.h>
#include "cocheBLE.hpp"

BLEService unor4wifiService(BLE_SERVICE); // Bluetooth® Low Energy LED Service
BLEIntCharacteristic unor4wifiCharacteristic(BLE_CARACTERISTICA,
                                             BLERead | BLEWrite | BLENotify); // BlLE Characteristic - custom 128-bit UUID, read and writable by central

const int ledPin = LED_BUILTIN;     // on  BLE conectado / off BLE desconectado

BLEDevice central;                  // listen for Bluetooth® Low Energy peripherals to connect:









/*
 * ********   S E T U P   ***************
 */


void setup(){
    
    // Serial init
    Serial.begin(9600);
    while (!Serial)
        ;
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
    unor4wifiService.addCharacteristic(unor4wifiCharacteristic); 

    // add the service
    BLE.addService(unor4wifiService);   

    // set the initial value for the characeristics
    unor4wifiCharacteristic.writeValue(0);                

    // start advertising       
    BLE.advertise();                                             

    Serial.println("/nsetup : BLE init OK");

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

        conectadoBLE();                 //  ejecuta una vez al conectar

        // while the central is still connected to peripheral:
        while (central.connected()){
           
            loopConectado();            //  loop cuando conectdo
        }   

        desconectadoBLE();              //  ejecuta una vez al desconectar
    }
}
