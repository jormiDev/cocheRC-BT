#include "logicaRC.hpp"

/*
 * 	* * * * * Funciones * * * * *
 */


/*
   logicaBasica
*/
int logicaBasica()
{
    int next = 0;
    if (distValores[2] > DISTANCIA_100)
    { // Distancia segura, vel MAXIMA
        velDeseadaDerecha = VELOCIDAD_MAXIMA;
        velDeseadaIzquierda = VELOCIDAD_MAXIMA;
        next = 3;
    }
    else if (distValores[2] > DISTANCIA_66)
    { // Distancia segura, vel MEDIA
        velDeseadaDerecha = VELOCIDAD_MEDIA;
        velDeseadaIzquierda = VELOCIDAD_MEDIA;
        next = 3;
    }
    else if (distValores[2] > DISTANCIA_33)
    { // Distancia segura, vel BAJA
        velDeseadaDerecha = VELOCIDAD_BAJA;
        velDeseadaIzquierda = VELOCIDAD_BAJA;
        next = 3;
    }
    else
    { // Distancia NO segura
        velDeseadaDerecha = VELOCIDAD_STOP;
        velDeseadaIzquierda = VELOCIDAD_STOP;
        next = 4;
    }

    return next;
}

/*
    logicaGiro

    con todas las distancia calcula la nueva dirección

    return angulo de giro
        aplica el giro a la distancia mayor leida
        si ninguna en segura, aplica un giro de 180º
*/
int logicaGiro()
{
    bool seguro = false;
    int winRumb = 0;
    int winDist = distValores[0];

    if (distValores[0] > DISTANCIA_33)
    {
        seguro = true;
    }

    for (int i = 1; i < 5; i++)
    {
        if (distValores[i] > DISTANCIA_33)
        {
            seguro = true;
        }
        if (distValores[i] > winDist)
        {
            winDist = distValores[i];
            winRumb = i;
        }
    }

    if (!seguro)
    {
        // giro 180
        mensaje.texto("Distancia segura NO: GIRO 180");
        return 180;
    }
    else
        // es seguro,
        switch (winRumb)
        {
        case 0:
            winDist = -90;
            break;
        case 1:
            winDist = -45;
            break;
        case 2:
            winDist = 0;
            break;
        case 3:
            winDist = 45;
            break;
        case 4:
            winDist = 90;
            break;
        default:
            winDist = 180;
            break;
        }
    mensaje.vble("Distancia segura SI: GIRO ", winDist);
    return winDist;
}
