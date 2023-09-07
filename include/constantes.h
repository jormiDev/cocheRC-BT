/*
 *  Notas
*/
//https://www.teachmemicro.com/lm393-ir-module-motor-speed-sensor/
//Los shaft encoders (sensores de velocidad) emplean los pines de interrupción 2 y 3 en Uno y Nano


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

#define VELOCIDAD_BAJA		80			    //Velocidades 0..255
#define VELOCIDAD_MEDIA		150
#define VELOCIDAD_MAXIMA	255
#define VELOCIDAD_STOP    0
#define VELOCIDAD_GIRO		50			    //Velocidad maniobras de giro

#endif	//__JORMAZ_CONSTANTES_H__
