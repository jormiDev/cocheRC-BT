#include "cocheBLE.hpp"


 /*
  * 	* * * * * Funciones * * * * * 
  */


 // Se ejecuta al contectarse al coche (una vez por conexcion)
 void conectadoBLE(){
	 Serial.print("loop  : Connected   BLE     (MAC) ");
	 Serial.println(central.address()); // print the central's MAC address:
	 digitalWrite(ledPin, HIGH);		// will turn the LED on
 }

 // Se ejecuta al desconectarse al coche (una sola vez)
 void desconectadoBLE(){
	 Serial.print("loop  : Disconnected BLE    (MAC) ");
	 Serial.println(central.address());
	 digitalWrite(ledPin, LOW); // will turn the LED off
 }

 // Se ejecuta al solicitar cerrar la app MIT
 void quitappBLE(){
 }

 // Codigo loop cuando conectado
 void loopConectado(){

	 // if the remote device wrote to the characteristic,
	 // use the value to control the LED:
	 if (unor4wifiCharacteristic.written())
	 {
		 if (unor4wifiCharacteristic.value())
		 { // any value other than 0
			 Serial.println("LED on");
		 }
		 else
		 { // a 0 value
			 Serial.println(F("LED off"));
		 }
	 }
 }

 // Codigo loop cuando DESconectado
 void loopDesconectado(){
 }