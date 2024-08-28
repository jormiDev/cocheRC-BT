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

    // init shaft encoder
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_DCHA), ISR_CountDerecha, RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_IZQ), ISR_CountIzquierda, RISING);

    // init IRQ timer
    miTimer.setInterval(ISR_timerone, 5000);
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
TimerOne ISR (Se llama cada 5 segundo y recalcula RPMs)
*/
void ISR_timerone()
{
    miTimer.pause();                                            // Stop the timer
    rpmDerecha = (pulsosDerecha * 12) / HUECOS_ENCODER;         // calculate RPM
    pulsosDerecha = 0;                                          //  reset counter to zero
    rpmIzquierda = (pulsosIzquierda * 12) / HUECOS_ENCODER; 
    pulsosIzquierda = 0;                                  
    miTimer.restart();                                          // Enable the timer
}

/*
Info de velocidades por puerto serial
*/
void encoders_info(){
    Serial.print("Encoder \t\t DRCHA \t rpms ( ");
    Serial.print(rpmDerecha);
    Serial.print(" )\t\t");

    Serial.print("IZQDA \t rpms ( ");
    Serial.print(rpmIzquierda);
    Serial.println(" )");
}

/*
Test 01 Encoders
test shaft encoder DRCHA
*/
void encoders_test01()
{
    delay(250);
    //Serial.println("Test 01 : Encoders");

    Serial.print("rpm / counter          ");
    Serial.print(rpmDerecha,5);
    Serial.print("          ");
    Serial.println(pulsosDerecha, 5);
}

/*
Test 02 Encoders
test shaft encoder IZQDA
*/
void encoders_test02()
{
    delay(250);
    //Serial.println("Test 02 : Encoders");
    
    Serial.print("rpm / counter          ");
    Serial.print(rpmIzquierda, 5);
    Serial.print("          ");
    Serial.println(pulsosIzquierda, 5);
}

/*
Test 03 Encoders
test shaft encoder IZQDA + DRCHA
*/
void encoders_test03()
{
    delay(250);
    //Serial.println("Test 03 : Encoders");

    Serial.print("DRCHA - rpm / counter          ");
    Serial.print(rpmDerecha, 5);
    Serial.print("          ");
    Serial.print(pulsosDerecha, 5);
    Serial.print("       IZQDA         ");
    Serial.print(rpmIzquierda, 5);
    Serial.print("          ");
    Serial.println(pulsosIzquierda, 5);
}