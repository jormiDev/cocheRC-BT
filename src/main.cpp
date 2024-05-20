

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>

#include <constantes.h>
#include "cocheBLE.hpp"

BLEService unor4wifiService("19B10000-E8F2-537E-4F6C-D104768A1214"); // Bluetooth® Low Energy LED Service
BLEByteCharacteristic unor4wifiCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214",
                                              BLERead | BLEWrite); // BlLE Characteristic - custom 128-bit UUID, read and writable by central

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

    BLE.setLocalName("UNOr4Wifi_Pradera"); // set advertised local name and service UUID:
    BLE.setAdvertisedService(unor4wifiService);
    unor4wifiService.addCharacteristic(unor4wifiCharacteristic); // add the characteristic to the service
    BLE.addService(unor4wifiService);                            // add service
    unor4wifiCharacteristic.writeValue(0);                       // set the initial value for the characeristic:
    BLE.advertise();                                             // start advertising

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
    if (central)
    {
        conectadoBLE();

        // while the central is still connected to peripheral:
        while (central.connected())
        {
            //  //////////////////////  INICIO Conectado a BLE         //////////////////////

            loopConectado();


        } //  //////////////////////  FIN Conectado a BLE   //////////////////////

        //  //////////////////////  INICIO Desconectado a BLE    //////////////////////

        desconectadoBLE();



        //  //////////////////////  FIN Desconectado a BLE    //////////////////////
    }
}
