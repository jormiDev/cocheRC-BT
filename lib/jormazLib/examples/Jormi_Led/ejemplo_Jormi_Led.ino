#include <Jormi_Depura.h>
#include <Arduino.h>
#include <Jormi_Led.h>


Jormi_Led miled(2);
Jormi_Depura mensaje();

void setup() {
  Serial.begin(9600);
  delay (2000);
  miled.enciende();
  miled.informacion();  
  delay (2000);
  miled.apaga();
  miled.informacion();   

  miled.parpadeo(250); 
  miled.informacion();     
}

void loop() {
  
	miled.update();
	
}

/* 
	Codigo de la version 0.2 
*/
  // delay(3000);
  // mensaje.texto("enciende");
  // miled.enciende();
  // delay(3000);

  // mensaje.texto("apaga");
  // miled.apaga();
  // delay(3000);

  // int cual = miled.conectado();
  // mensaje.xInt("pin conectado", cual);
  // delay(3000);

  // mensaje.xInt("funcion valor", cual);
  // miled.valor(cual);
  // delay(3000);

  // cual = 0;
  // mensaje.xInt("funcion valor", cual);
  // miled.valor(cual);

  // mensaje.salto();
/* 
	FIN Codigo de la version 0.2 
*/

/*
 intlee = digitalRead(1);
 
 estado = botoncillo.estadoPD(); 
  String texto = String ("\nLectura:    pin = ");
  Serial.print(texto);
  Serial.print(_pin);
  texto = String (" valor = ");
  Serial.print(texto);
  Serial.print(_valor);*/