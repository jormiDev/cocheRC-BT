#include <Arduino.h>
#include <Jormi_Pulsador.h>
#include <Jormi_Led.h>
#include <Jormi_Depura.h>


/*
 * Define objetos y variables necesarias
 */
Jormi_Pulsador botoncillo(10); //pulsador en pin 10
Jormi_Led miled(5);           //led en pin 5
Jormi_Depura mensaje;


/*
 * ***********************
 */
void setup() {
  miled.init();
  mensaje.init();
  botoncillo.init();

  mensaje.texto("Pull Up Botón");
    
}

void loop() {

  delay(300);
  bool estado = botoncillo.estadoPU();
  mensaje.xBool("Estado", estado);

  if( estado )
    miled.enciende();
  else
    miled.apaga();  

}