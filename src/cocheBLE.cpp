#include "cocheBLE.hpp"


/*
conectadoBLE
Se ejecuta al contectarse al coche (una vez por conexcion)
 */
void conectadoBLE()
{
	// print the central's device
	Serial.println();
	Serial.println("loop  : Connected   BLE    (Device)");
	Serial.print("               MAC  (name)      : ");
	Serial.print(central.address());
	Serial.print("  ( ");
	Serial.print(central.deviceName());
	Serial.print(central.localName());
	Serial.println("  ) ");

	// Services
	Serial.println("          Servicio");
	Serial.print("               uuid       : ");
	Serial.println(unor4wifiService.uuid());

	// caracteristicas
	Serial.println("          Caracteristicas");

	Serial.print("(unor4wifiCharacteristicMODO)            uuid       : ");
	Serial.println(unor4wifiCharacteristicMODO.uuid());
	Serial.print("	valueSize   : ");
	Serial.println(unor4wifiCharacteristicMODO.valueSize());
	Serial.print("	propierties : ");
	byte properties = unor4wifiCharacteristicMODO.properties();
	Serial.print(properties);
	if (properties & BLERead)  
		Serial.print("  Read  ");
	if (properties & (BLEWrite | BLEWriteWithoutResponse))
		Serial.print("  Write  ");
	if (properties & BLENotify)
		Serial.print("  Notify  ");
	Serial.println();
	Serial.print("	value       : ");
	Serial.println(unor4wifiCharacteristicMODO.value());

	Serial.print("(unor4wifiCharacteristicDIREC)          uuid       : ");
	Serial.println(unor4wifiCharacteristicDIREC.uuid());
	Serial.print("	valueSize   : ");
	Serial.println(unor4wifiCharacteristicDIREC.valueSize());
	Serial.print("	propierties : ");
	properties = unor4wifiCharacteristicDIREC.properties();
	Serial.print(properties);
	if (properties & BLERead)
		Serial.print("  Read  ");
	if (properties & (BLEWrite | BLEWriteWithoutResponse))
		Serial.print("  Write  ");
	if (properties & BLENotify)
		Serial.print("  Notify  ");
	Serial.println();
	Serial.print("	value       : ");
	Serial.println(unor4wifiCharacteristicDIREC.value());

	digitalWrite(ledPin, HIGH); // will turn the LED on
}

/*
desconectadoBLE
Se ejecuta al desconectarse al coche (una sola vez)
*/
void desconectadoBLE()
{
	// mensaje desconexion BLE
	Serial.print("loop  : Disconnected BLE    (MAC) ");
	Serial.println(central.address());

	// modo y dirección a default
	ble_Modo = BLE_MODO_DEFAULT;
	unor4wifiCharacteristicMODO.writeValue(ble_Modo);
	ble_Direc = BLE_DIREC_DEFAULT;
	unor4wifiCharacteristicDIREC.writeValue(ble_Direc);

	// parar motores
	motorDC_stop();

	// apagar led indicador conexción
	digitalWrite(ledPin, LOW); // will turn the LED off	 
 }

 /*
 quitappBLE
 Se ejecuta al solicitar cerrar la app MIT
 */
 void quitappBLE(){
 }

/*
loopConectado
Codigo loop se ejecuta mientras este conectado cada iteración
*/
void loopConectado(){

	 //encoders_info();
 }

/*
caracteristica MODO
*/
bool caracteristicaMODO(){
	if (unor4wifiCharacteristicMODO.written())	{
		ble_Modo = unor4wifiCharacteristicMODO.value();
		Serial.print("loop  : MODO modificado      (lenght = ");
		Serial.print(unor4wifiCharacteristicMODO.valueSize());
		Serial.print(")    :  ");
		Serial.print(ble_Modo);

		if (ble_Modo == "app_AUTO")
			ble_Modo_int = app_AUTO;
		else if (ble_Modo == "app_MANU")
			ble_Modo_int = app_MANU;
		else if (ble_Modo == "app_QUIT")
			ble_Modo_int = app_QUIT;
		else if (ble_Modo == "app_DISC")
			ble_Modo_int = app_DISC;

		Serial.print("  -  ");
		Serial.println(ble_Modo_int);		

		return true;
	}else
		return false;
}
 
/*
Caracteristica DIRECCION
*/
bool caracteristicaDIREC(){
	if (unor4wifiCharacteristicDIREC.written())	{
		ble_Direc = unor4wifiCharacteristicDIREC.value();
		Serial.print("loop  : DIRECION modificada     (lenght = ");
		Serial.print(unor4wifiCharacteristicDIREC.valueSize());
		Serial.print(")    :  ");
		Serial.print(ble_Direc);

		if (ble_Direc == "app_STOP")
			ble_Direc_int = app_STOP;
		else if (ble_Direc == "app_FWD")
			ble_Direc_int = app_FWD;
		else if (ble_Direc == "app_AFT")
			ble_Direc_int = app_AFT;
		else if (ble_Direc == "app_IZQ")
			ble_Direc_int = app_IZQ;
		else if (ble_Direc == "app_DCHA")
			ble_Direc_int = app_DCHA;
		else if (ble_Direc == "app_90IZQ")
			ble_Direc_int = app_90IZQ;
		else if (ble_Direc == "app_90DCHA")
			ble_Direc_int = app_90DCHA;
		else if (ble_Direc == "app_180")
			ble_Direc_int = app_180;

		Serial.print("  -  ");
		Serial.println(ble_Direc_int);

		return true;
	}else
		return false;
}
 
