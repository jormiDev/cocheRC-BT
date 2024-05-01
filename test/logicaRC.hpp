#ifndef __JORMAZ_LOGICARC_HPP__
#define __JORMAZ_LOGICARC_HPP__

#include "Arduino.h"
#include <HCSR04.h>

#include "jormazLib.h"
#include "constantes.h"


/*
 * 	Objetos y variables
 */


extern jormiDepura mensaje;
extern int distValores[5];
extern int velDeseadaIzquierda;
extern int velDeseadaDerecha;


/*
 * 	* * * * * Funciones * * * * *
 */
    
/*
    logicaBasica

    manteniendo la dirección, calcula la nueva velocidad según la distancia por delante

    return siguiente estado de maquinaEstados
        3	mantener dirección
        4	parar y calculo de nueva dirección
*/
int logicaBasica();


/*
logicaGiro

    con todas las distancia calcula la nueva dirección

    return angulo de giro
        aplica el giro a la distancia mayor leida
        si ninguna en segura, aplica un giro de 180º
*/
int logicaGiro();

#endif