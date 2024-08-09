
#include <Arduino.h>
#include <ArduinoBLE.h>



/*
 * Objetos y variables
 */


//MAC  UNO r4 Wifi Pradera      F4:12:FA:76:20:A9
/*
  0   null
  1   modo manual
  2   modo auto


*/

BLEService unor4wifiService("19B10000-E8F2-537E-4F6C-D104768A1214");                       // Bluetooth® Low Energy LED Service
BLEByteCharacteristic unor4wifiCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", 
          BLERead | BLEWrite);                                                             // BlLE Characteristic - custom 128-bit UUID, read and writable by central

const int ledPin = LED_BUILTIN;         // on  BLE conectado / off BLE desconectado




/*
 * ********   S E T U P   ***************
 */


void setup() {
  // Serial init
  Serial.begin(9600);
  while (!Serial);
  Serial.println("setup : init");

  // set LED pin to output mode           
  pinMode(ledPin, OUTPUT);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("setup : starting Bluetooth® Low Energy module failed!");
    while (1);
  }

  
  BLE.setLocalName("UNOr4Wifi_Pradera");                          // set advertised local name and service UUID:
  BLE.setAdvertisedService(unor4wifiService);
  unor4wifiService.addCharacteristic(unor4wifiCharacteristic);    // add the characteristic to the service
  BLE.addService(unor4wifiService);                               // add service
  unor4wifiCharacteristic.writeValue(0);                          // set the initial value for the characeristic:
  BLE.advertise();                                                // start advertising

  Serial.println("/nsetup : BLE init OK");

  Serial.println("setup : fin");
  delay(5000);
  Serial.println("/nloop  : init");
  
}

void loop() {
  
  BLEDevice central = BLE.central();                  // listen for Bluetooth® Low Energy peripherals to connect:

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("loop  : Connected   BLE     (MAC) ");
    Serial.println(central.address());                // print the central's MAC address:

    // while the central is still connected to peripheral:
    while (central.connected()) {
      digitalWrite(ledPin, HIGH);         // will turn the LED on

      //  //////////////////////  INICIO Conectado a BLE         //////////////////////  
      



      // if the remote device wrote to the characteristic,
      // use the value to control the LED:
      if (unor4wifiCharacteristic.written()) {
        if (unor4wifiCharacteristic.value()) {   // any value other than 0
          Serial.println("LED on");
          
        } else {                              // a 0 value
          Serial.println(F("LED off"));
          
        }
      }


    }  //  //////////////////////  FIN Conectado a BLE   //////////////////////  


    //  //////////////////////  INICIO Desconectado a BLE    //////////////////////  


    Serial.print("loop  : Disconnected BLE    (MAC) ");
    Serial.println(central.address());
    digitalWrite(ledPin, LOW);          // will turn the LED off



    //  //////////////////////  FIN Desconectado a BLE    //////////////////////  

  }
}
