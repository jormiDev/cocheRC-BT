/*
 *  Notas
*/

//https://www.teachmemicro.com/lm393-ir-module-motor-speed-sensor/
//Los shaft encoders (sensores de velocidad) emplean los pines de interrupción 2 y 3 en Uno y Nano

/*
BLE Bluethoot

app MIT (telefono)                      Central - the BLE device which initiates an outgoing connection request to an advertising peripheral device
Arduino (servicio + caracteristicas)    Peripheral - the BLE device which accepts an incoming connection request after advertising
*/

#ifndef __JORMAZ_CONSTANTES_H__
#define __JORMAZ_CONSTANTES_H__

/*
Pines conectados
*/
#define PIN_ENC_DCHA 			2 		// Wncoder rotación lado derecho
#define PIN_ENC_IZQ 			3		// Encoder rotación lado izquierdo

#define PIN_IN1           	    4       // L298n
#define PIN_IN2           	    5		
#define PIN_ENA 				6		// PWD				
#define PIN_IN3           	    7
#define PIN_IN4           	    8 
#define PIN_ENB 				9      	// PWD 

#define PIN_SERVO               10       // PWM      SG90

#define PIN_HCSR04_ECHO         12       // Pines HC-RS04
#define PIN_HCSR04_TRIGGER      13



/*
Constastes del programa
*/

#define MOTOR_TIEMPO_PARO           200     // Delay para paso de movimiento a stop (ms)
#define MOTOR_TIEMPO_90             350     // Delay tiempo de giro 90 grados
#define MOTOR_TIEMPO_180            350     // Delay tiempo de giro 180 grados

#define VELOCIDAD_STOP              0       // velocidad 0
#define VELOCIDAD_BAJA              50      // (MODO_MANU) velodidad para los giros
#define VELOCIDAD_MEDIA             100     // (MODO_MANU) velocodad estandar 
#define VELOCIDAD_INVERSA           50      // (MODO MANU) motor inverso giro 180
#define VELOCIDAD_MAX				255

#define HCSR04_DELAY_MS             30      // HC-SR04 - para evitar fallo en multiples lecturas

#define SERVO_DELAY_MS              1300    // SG90 - delay (maximo) para posicionar el SG90

#define HUECOS_ENCODER              20      // Huecos en el disco de los encoders
#define ENCODER_IRQ_TIMER			1000	// ms entre llamadas a la funcion IRQ

/*
App MIT inventor
	mensajes recibidos
	MAC  UNO r4 Wifi Pradera      F4:12:FA:76:20:A9
*/

#define BLE_LOCAL_NAME          "UNOr4Wifi_Pradera (Peripheral)"
#define BLE_DEVICE_NAME         "UNOr4Wifi_Pradera"
#define BLE_SERVICE             "2020"
#define BLE_CARACT_MODO         "2021"
#define BLE_CARACT_MODO_LONG    10
#define BLE_CARACT_DIREC        "2022"
#define BLE_CARACT_DIREC_LONG   10

/*
Caracteristicas MODO
*/

#define BLE_MODO_DEFAULT 		"-1"           
#define BLE_MODO_DEFAULT_INT 	-1

#define app_AUTO               1       // modo auto
#define app_MANU               2       // modo manual
#define app_QUIT               3       // quit app
#define app_DISC               4       // desconectar

/*
Características DIREC
*/

#define BLE_DIREC_DEFAULT 		"-2"
#define BLE_DIREC_DEFAULT_INT 	-2

#define app_STOP               3       // stop
#define app_FWD                4       // fwd
#define app_AFT                5       // aft
#define app_IZQ                6       // izqda
#define app_DCHA               7       // drcha
#define app_90IZQ              8       // giro 90 grados a izquierda
#define app_90DCHA             9       // giro 90 grados a derecha
#define app_180                10      // giro 180 grados

/*
Maquina de estados
*/

#define ME_INICIO               0       // estado inicial, desconecado ble + todo parado
#define ME_CONECTADO_BLE        1       // INICIO + conectado a BLE
#define ME_DESCONECTADO_BLE     2       // desconectado a BLE >> parar todo + estado buscar conexion
#define ME_QUIT_APP             3       // >> parar todo + desconectar BLE
#define ME_MODO_AUTO            4       // parar todo + analizar escenario + inicir conduccion automatica
#define ME_MODO_MANUAL          5       // parar todo + esperar comnandos

#endif	//__JORMAZ_CONSTANTES_H__


/*
//#define MOTOR_INVERSION		400			    //Delay paso inversión de marcha (ms)

//#define TIEMPO_PERIODO  	1000		    //tiempo en ms entre lecturas distancia
//#define DISTANCIA_33		25			    //Distancia segura, vel BAJA
//#define DISTANCIA_66		50			    //Distancia segura, vel MEDIA
//#define DISTANCIA_100		75			    //Distancia segura, vel MAXIMA

              // Velocidades 0..255

#define VELOCIDAD_MAXIMA    240
#define VELOCIDAD_GIRO      40


//#define GIRO_45             200             // Tiempo de maniobra
//#define GIRO_90             400
//#define GIRO_180            400
*/


