#include "coche_HC-SR04.hpp" 




/*
Ultrasonidos_setup
*/
void ultrasonidos_setup()
{
   Serial.println("setup : HC-SR04 init OK");
} 

/*
Ultrasonidos_mide
*/
float ultrasonidos_mide()
{
    return distHCSR04.dist();
}

/*
Ultrasonidos_decisionRumbo

PENDIENTE para modo AUTO
1. leer las distancia de los angulos -90, -45, 0, 45, 90
2. ver la mayor distancia
3. devolver el rumbo de dicho opción
*/
int ultrasonidos_decisionRumbo()
{
    return 0;
}