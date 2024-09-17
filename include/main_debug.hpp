#ifndef __MAIN_DEBUG__
#define __MAIN_DEBUG__

#include "Arduino.h"
#include "constantes.h"


/*
Objetos y variables
*/



/*
Funciones
*/

void debugMensaje(String msg);
void debugMensajeln(String msg);

void debugMensaje(String msg, int vble);
void debugMensajeln(String msg, int vble);

#endif