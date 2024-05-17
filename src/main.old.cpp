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


//MAC  UNO r4 Wifi Pradera      F4:12:FA:76:20:A9
const int ledPin = LED_BUILTIN; // set ledPin to on-board LED

jormiDepura mensaje;
String(cadenaLeidaMITapp);

BLEService cocheService("19B10000-E8F2-537E-4F6C-D104768A1214");											// create service
BLEByteCharacteristic cocheCharacteristic("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);		// carcteriticas Read / Write

/*
 * ********   S E T U P   ***************
 */

void setup(){

mensaje.texto(" inicio setup");

// Serial init
Serial.begin(9600);
while (!Serial);

// BLE init
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

// led pasa conocer conexion
pinMode(ledPin, OUTPUT);                                    // ON conectado / OFF desconectado
  
// fin Setup
mensaje.texto(" inicio loop ");
delay(1000);


}//	setup



/*
 * ********   L O O P   ***************
 */

void loop(){
    BLEDevice central = BLE.central(); // listen for Bluetooth® Low Energy peripherals to connect:

    // if a central is connected to peripheral:
    if (central){

        mensaje.vble("Connected to central: ", central.address());          // print the central's MAC address:
        Serial.println("LED on");
        digitalWrite(ledPin, HIGH);


        // while the central is still connected to peripheral:
        while (BLE.connected())
        {
            /*// if the remote device wrote to the characteristic,
            // use the value to control the LED:
            if (switchCharacteristic.written())
            {
                if (switchCharacteristic.value())
                { // any value other than 0
                    Serial.println("LED on");
                    digitalWrite(ledPin, HIGH); // will turn the LED on
                }
                else
                { // a 0 value
                    Serial.println(F("LED off"));
                    digitalWrite(ledPin, LOW); // will turn the LED off
                }
            }*/
        }

    // when the central disconnects, print it out:
    }else{
            Serial.println("LED off");
            digitalWrite(ledPin, LOW);
            mensaje.vble("Disconnected from central: ", central.address());
    }

    } //	loop
