#include "coche_Encoders.hpp" 




/*
Encoders setup
*/
void encoders_setup()
{
    pulsosDerecha = 0;
    pulsosIzquierda = 0;
    rpmDerecha = 0;
    rpmIzquierda = 0;
    rpmDerechaObjetivo = 0;
    rpmIzquierdaObjetiv = 0;

    Timer1.initialize(1000000);                                                      // set timer for 1sec
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_IZQ), ISR_CountIzquierda, RISING); // Increase speed sensor pin goes High
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_DCHO), ISR_CountDerecha, RISING);  // Increase speed sensor pin goes High
    Timer1.attachInterrupt(ISR_timerone);                                            // Enable the timer
}

/*
Funcion IRS 0 - Motor derecho
*/
void ISR_CountDerecha()
{
    pulsosDerecha++;
}

/*
Funcion IRS 1 - Motor izquierdo
*/
void ISR_CountIzquierda()
{
    pulsosIzquierda++;
}

/*
TimerOne ISR (Se llama cada segundo y recalcula RPMs)
*/
void ISR_timerone()
{
    Timer1.detachInterrupt();                                   // Stop the timer
    rpmDerecha = (pulsosDerecha / HUECOS_ENCODER) * 60.00;      // calculate RPM
    pulsosDerecha = 0;                                          //  reset counter to zero
    rpmIzquierda = (pulsosIzquierda / HUECOS_ENCODER) * 60.00;  // calculate RPM
    pulsosIzquierda = 0;                                        //  reset counter to zero
    Timer1.attachInterrupt(ISR_timerone);                       // Enable the timer
}

/*
Info de velocidades por puerto serial
*/
void encoders_info(){
    Serial.print("Encoder Drcho \t rpms Actuales  ( ");
    Serial.print(rpmDerecha, 5);
    Serial.print(" ) \t rpms Objetivo ( ");
    Serial.print(rpmDerechaObjetivo);
    Serial.println(" )");

    Serial.print("Encoder Drcho \t rpms Actuales  ( ");
    Serial.print(rpmIzquierda, 5);
    Serial.print(" ) \t rpms Objetivo ( ");
    Serial.print(rpmIzquierdaObjetivo);
    Serial.println(" )");
}


/*
Test 01 Encoders

*/
void encoders_test01()
{
    delay(5000);
    Serial.println("Test 01 : Encoders");


}

/*
Test 02 Encoders

*/
void encoders_test02()
{
    delay(5000);
    Serial.println("Test 02 : Encoders");
}

/*
Test 03 Encoders

*/
void encoders_test03()
{
    delay(5000);
    Serial.println("Test 03 : Encoders");


}