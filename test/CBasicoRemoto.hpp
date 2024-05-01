#ifndef __JORMAZ_CBASICOREMOTO_HPP__
#define __JORMAZ_CBASICOREMOTO_HPP__ 


 #include "Arduino.h"
 #include <SoftwareSerial.h>
 
 #include "jormazLib.h"
 #include "constantes.h"


 /*
  * 	Objetos y variables 
  */

extern jormiDepura mensaje;

extern char comando;

/*
 * 	* * * * * Funciones * * * * *
 */


/*
  Setup remotoSetup
*/
void remotoSetup();

int remotoLeer();




#endif 