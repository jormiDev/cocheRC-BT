#include "main_debug.hpp"

/*
Serial.print : String
*/
void debugMensaje(String msg){
    if (DEBUG_0)
    {
        Serial.print(msg);
    }
}

/*
Serial.println : String
*/
void debugMensajeln(String msg)
{
    if (DEBUG_0)
    {
        Serial.println(msg);
    }
}

/*
Serial.print : String + int
*/
void debugMensaje(String msg, int vble){
    if (DEBUG_0){
        Serial.print(msg);
        Serial.print(vble);
    }
}

/*
Serial.println : String + int
*/
void debugMensajeln(String msg, int vble){
    if (DEBUG_0){
        Serial.print(msg);
        Serial.println(vble);
    }
}

