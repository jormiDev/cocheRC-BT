#include <Arduino.h>
#include <ArduinoBLE.h>
#include <Wire.h>
#include <SPI.h>
#include <WiFi.h>

#include <jormazLib.h>
#include <constantes.h>

 
/*
 * Objetos y variables
 */

jormiDepura mensaje;
String(cadenaLeidaMITapp);

BLEService cocheService("19B10000-E8F2-537E-4F6C-D104768A1214");											// create service
BLEByteCharacteristic cocheCharacteristic("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);		// carcteriticas Read / Write

/*
 * ********   S E T U P   ***************
 */

void setup(){

// Serial init
Serial.begin(9600);
while (!Serial);

//BLE init
if (!BLE.begin()){
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);
}
BLE.setLocalName("UNOr4WifiPradera");						// set the local name peripheral advertises
BLE.setAdvertisedService(cocheService);						// set the UUID for the service this peripheral advertises:
cocheService.addCharacteristic(cocheCharacteristic);		// add the characteristics to the service
BLE.addService(cocheService);								// add the service
cocheCharacteristic.writeValue(0);							// valor inicial caracteristica
BLE.advertise();											// start advertising
Serial.println("Bluetooth® device active, waiting for connections...");

// fin Setup
mensaje.texto(" inicio loop ");
delay(1000);


}//	setup



/*
 * ********   L O O P   ***************
 */

void loop(){

BLE.poll();			// poll for Bluetooth® Low Energy events

mensaje.vble("MIT app :      ", cocheCharacteristic.value());
  


delay(3000);

}//	loop
