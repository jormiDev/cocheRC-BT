#include "CBasicoRemoto.hpp"

//Parpadeo de led cada vez que se lee una pulsación
//El modulo HC-05 parpadea mientras no esta conectado

//pines
#define PIN_BT_RXD    4         //HC-05
#define PIN_BT_TXD    3
//Comandos BT remotos
#define	BT_MANUAL		'm'	
#define BT_AUTO			'a'
#define BT_STOP       	's'
#define BT_FWD        	'f'  
#define BT_AFT        	'r'
#define BT_IZQ        	'i'
#define BT_DER        	'd'
#define BT_GIR90_IZQ 	'z'
#define BT_GIR90_DER    'e'

//vbles
SoftwareSerial  brutus(PIN_BT_TXD, PIN_BT_RXD); //Pines puerto serie HC-06 (Tx, RX)
char            brutusData;						//Serial BT leido
char			brutusModo;						//Modo auto (A)/manual(M)




 /*
  * 	* * * * * Funciones * * * * *  
  */


/*
  Setup CBasicoRemoto
*/
void remotoSetup()
{
	brutus.begin(9600);
	brutusModo = 'm';
}

/*
  Leer buffer BT - AppInventor2
	Almacena comando en brutusData y devuelve:
		1 si hay comando leido
		O sino lee nada
*/
int remotoLeer()
{
	brutusData = ' ';
	
	if (brutus.available()) {  
		brutusData = brutus.read();

		mensaje.vble("BT AppInventor leido :\t",brutusData);          

		return 1;
	}else{
		return 0;
	}
}


