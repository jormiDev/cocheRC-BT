#include <Arduino.h>

/*
 * Librerias propias
 */
#include <Jormi_Depura.h>

/* 
 * Variables globales e instancias de objetos 
 */
Jormi_Depura mensaje;


/*
 * *********************
 */
void setup() {
  Serial.begin(9600);
}

void loop() {

/*  
 *   Prueba de la lib_depura
 */
delay(2500);
mensaje.texto("Hola");

mensaje.salto();

int x = 19;
mensaje.xInt("x", x);

String cad = String ("Que tal?");
mensaje.xString("cad", cad);

bool bb = true;
mensaje.xBool("bb", bb);

float ff = 10.1415;
mensaje.xFloat("ff", ff);


}
