

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "WiFiS3.h"
#include <Wire.h>
#include <SPI.h>
#include "HCSR04.h"
#include "Servo.h"
#include "Countimer.h"

#include <constantes.h>
#include "cocheBLE.hpp"
#include "coche_HC-SR04.hpp"
#include "coche_SG90.hpp"
#include "coche_Encoders.hpp"


// listen for Bluetooth® Low Energy peripherals to connect:
BLEDevice central;
// Bluetooth® Low Energy LED Service
BLEService unor4wifiService(BLE_SERVICE); 
// BlLE Characteristic
BLEStringCharacteristic unor4wifiCharacteristicMODO(BLE_CARACT_MODO, BLERead | BLEWrite | BLENotify, BLE_CARACT_MODO_LONG);
String ble_Modo = BLE_MODO_DEFAULT;
int ble_Modo_int = BLE_MODO_DEFAULT_INT;
BLEStringCharacteristic unor4wifiCharacteristicDIREC(BLE_CARACT_DIREC, BLERead | BLEWrite | BLENotify, BLE_CARACT_DIREC_LONG);
String ble_Direc = BLE_DIREC_DEFAULT;
int ble_Direc_int = BLE_MODO_DEFAULT_INT;

const int ledPin = LED_BUILTIN; // on  BLE conectado / off BLE desconectado

int maquinaEstados;                 

// coche_HC-RS04
HCSR04 distHCSR04(PIN_HCSR04_TRIGGER, PIN_HCSR04_ECHO);
float sensorDist;

// coche_SG90
Servo myservo; 
int posicionServo; // 0 .. 180

// coche_Encoders
Countimer miTimer;
volatile unsigned int pulsosDerecha;   // Contador pulsos lado derecho
volatile unsigned int pulsosIzquierda; // Contador pulsos lado izquierdo
float rpmDerecha;                      // RPM motor derecho
float rpmIzquierda;                    // RPM motor izquierdo
float rpmDerechaObjetivo;              // RPM motor derecho Deseadas
float rpmIzquierdaObjetivo;            // RPM motor izquierdo Deseadas

/*
 * ********   S E T U P   ***************
 */


void setup(){
    
    // Serial init
    Serial.begin(9600);
    while (!Serial)
        ;
    delay(5000);

    Serial.println("");
    Serial.println("UNO r4 WIFI");
    Serial.println("");
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
    Serial.println("setup : BLE            init OK");

    // Maquina de estados
    maquinaEstados = ME_INICIO;
    Serial.println("setup : maquina de estados  OK");

    // coche_HC-RS04
    ultrasonidos_setup();
    Serial.println("setup : HC-SR04        init OK");

    // coche_SG90
    servo_setup();
    Serial.println("setup : SG90           init OK");

    // coche_Encoders
    encoders_setup();
    Serial.println("setup : encoders       init OK");


    // fin setup
    Serial.println("setup : fin");
    delay(5000);
    Serial.println("");
    Serial.println("loop  : init");

}//	setup



/*
 * ********   L O O P   ***************
 */

void loop()
{
    // Arrancar IRQ Timer
    miTimer.run();
    miTimer.start();

    /*
    TEST
    */
    //ultrasonidos_test01();
    //ultrasonidos_test02();
    //servo_test01();
    //servo_test02();
    //servo_test03();
    //encoders_test01();
    //encoders_test02();

    /*
    maqEstados_INICIO();
    central = BLE.central();

    // if a central is connected to peripheral:
    if (central){

        conectadoBLE();                                 //  ejecuta una vez al conectar
        maqEstados_CONECTADO_BLE();

        // while the central is still connected to peripheral:
        while (central.connected())
        {

            loopConectado();                            //  loop cuando conectdo

            if( caracteristicaMODO() ){                 //  caracteristica MODO modificada
                switch (ble_Modo_int){
                case app_QUIT:
                    maqEstados_QUIT_APP();
                    break;
                case app_MANU:
                    maqEstados_MODO_MANUAL();
                    break;
                case app_AUTO:
                    maqEstados_MODO_AUTO();
                    break;
                default:
                    Serial.println("ble_Modo - valor deconocido");
                    break;
                }
            }

            if (caracteristicaDIREC()){                 //  caracteristica DIREC modificada
                switch (ble_Direc_int){
                case app_STOP:
                    manual_STOP();
                    break;
                case app_FWD:
                    manual_FWD();
                    break;
                case app_AFT:
                    manual_AFT();
                    break;
                case app_IZQ:
                    manual_IZQ();
                    break;
                case app_DCHA:
                    manual_DCHA();
                    break;
                case app_90IZQ:
                    manual_90IZQ();
                    break;
                case app_90DCHA:
                    manual_90DCHA();
                    break;
                case app_180:
                    manual_180();
                    break;
                default:
                    Serial.println("ble_Direc - valor deconocido");
                    break;
                }
            }
        }

        desconectadoBLE();                              //  ejecuta una vez al desconectar
        maqEstados_DESCONECTADO_BLE();
    }*/
}
