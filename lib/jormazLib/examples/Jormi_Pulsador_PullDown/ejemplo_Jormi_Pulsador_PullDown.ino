#include <Arduino.h>
#include <Jormi_Pulsador.h>
#include <Jormi_Led.h>
#include <Jormi_Depura.h>


/*
 * Define objetos y variables necesarias
 */
Jormi_Pulsador botoncillo(11, false); //pulsador en pin 7 y tipo PD
Jormi_Led miled(10);           //led en pin 6
Jormi_Depura mensaje;


/*
 * ***********************
 */
void setup() {
  Serial.begin(9600);
  mensaje.texto("Pull Down Botón");
  botoncillo.informacion();
  
    
}

void loop() {

  botoncillo.update();
  miled.update();

  if( botoncillo.estado() )
    miled.enciende();
  else
    miled.apaga();



}


//Codigo v0.2
//  delay(300);
//  bool estado = botoncillo.estadoPD();
//  mensaje.xBool("Estado", estado);
//
//  if( estado )
//    miled.enciende();
//  else
//    miled.apaga();  
//Fin codigo