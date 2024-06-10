/*
 *  Notas
*/

//https://www.teachmemicro.com/lm393-ir-module-motor-speed-sensor/
//Los shaft encoders (sensores de velocidad) emplean los pines de interrupción 2 y 3 en Uno y Nano

/*
    BLE Bluethoo

app MIT (telefono)                      Central - the BLE device which initiates an outgoing connection request to an advertising peripheral device
Arduino (servicio + caracteristicas)    Peripheral - the BLE device which accepts an incoming connection request after advertising
*/

#ifndef __JORMAZ_CONSTANTES_H__
#define __JORMAZ_CONSTANTES_H__


/*
 *  Pines conectados
 *
 *	#define PIN num_pin_conectado
 */

#define PIN_IN1           	    2       //Pines L298n		obligatorio PWD=IN2+IN4
#define PIN_IN2           	    3		//PWD	
#define PIN_IN3           	    4
#define PIN_IN4           	    5       //PWD 

#define PIN_SERVO               6       // PWM      SG90

#define PIN_HCSR04_ECHO         7       // Pines HC-RS04
#define PIN_HCSR04_TRIGGER      8

#define PIN_BT_RX               9       //Pines BT
#define PIN_BT_TX               10

#define PIN_ENC_DCHO     	    11     //Pin encoder rotación lado derecho
#define PIN_ENC_IZQ      	    12     //Pin encoder rotación lado izquierdo


/*
 *   Constastes del programa
 *
 *		const tipo_constante nombre_constante = valor_constante;
 *		const float pi = 3.14;
 */
  
const float diskslots = 20;  			    // Float for number of slots in encoder disk

#define HCSR04_DELAY_MS     30              //para evitar fallo en multiples lecturas

#define SERVO_DELAY_MS      1300             // delay (maximo) para posicionar el SG90

#define MOTOR_PARO			200			    //Delay paso movimiento a paro (ms)
#define MOTOR_INVERSION		400			    //Delay paso inversión de marcha (ms)

#define TIEMPO_PERIODO  	1000		    //tiempo en ms entre lecturas distancia
#define DISTANCIA_33		25			    //Distancia segura, vel BAJA
#define DISTANCIA_66		50			    //Distancia segura, vel MEDIA
#define DISTANCIA_100		75			    //Distancia segura, vel MAXIMA

#define VELOCIDAD_BAJA      80              // Velocidades 0..255
#define VELOCIDAD_MEDIA     160
#define VELOCIDAD_MAXIMA    240
#define VELOCIDAD_GIRO      40
#define VELOCIDAD_STOP      0

#define GIRO_45             200             // Tiempo de maniobra
#define GIRO_90             400
#define GIRO_180            400


/*
 *   App MIT inventor
 *
 *      mensajes recibidos
 *      MAC  UNO r4 Wifi Pradera      F4:12:FA:76:20:A9
 */

#define BLE_LOCAL_NAME          "UNOr4Wifi_Pradera (Peripheral)"
#define BLE_DEVICE_NAME         "UNOr4Wifi_Pradera"
#define BLE_SERVICE             "2020"
#define BLE_CARACT_MODO         "2021"
#define BLE_CARACT_MODO_LONG    10
#define BLE_CARACT_DIREC        "2022"
#define BLE_CARACT_DIREC_LONG   10

#define app_AUTO               1       // modo auto
#define app_MANU               2       // modo manual
#define app_QUIT               3       // quit app
#define app_DISC               4       // desconectar

#define app_STOP               3       // stop
#define app_FWD                4       // fwd
#define app_AFT                5       // aft
#define app_IZQ                6       // izqda
#define app_DCHA               7       // drcha


/*
 *  Maquina de estados
*/

#define ME_INICIO               0       // estado inicial, desconecado ble + todo parado
#define ME_CONECTADO_BLE        1       // INICIO + conectado a BLE
#define ME_DESCONECTADO_BLE     2       // desconectado a BLE >> parar todo + estado buscar conexion
#define ME_QUIT_APP             3       // >> parar todo + desconectar BLE
#define ME_MODO_AUTO            4       // parar todo + analizar escenario + inicir conduccion automatica
#define ME_MODO_MANUAL          5       // parar todo + esperar comnandos






#endif	//__JORMAZ_CONSTANTES_H__
