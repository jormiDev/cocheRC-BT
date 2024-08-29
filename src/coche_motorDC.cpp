#include "coche_motorDC.hpp" 

/*
Init del L298N
*/
void motorDC_setup()
{
    // init motor A + stop soft
    pinMode(PIN_ENA, OUTPUT);       //PWD  
    pinMode(PIN_IN1, OUTPUT);
    pinMode(PIN_IN2, OUTPUT);

    motorA_ENA = 0;
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
    analogWrite(PIN_ENA, 0);

    //intn motor B + stop soft
    pinMode(PIN_ENB, OUTPUT);       //PWD
    pinMode(PIN_IN3, OUTPUT);
    pinMode(PIN_IN4, OUTPUT);

    motorB_ENB = 0;
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN2, LOW);
    analogWrite(PIN_IN4, 0);
} 

/*
motor A - avance
*/
void motorDC_A_fwd(byte _vel){
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
    analogWrite(PIN_ENA, _vel);
    Serial.println("motor A - fwd");
}

/*
motor A - atras
*/
void motorDC_A_aft(byte _vel)
{
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
    analogWrite(PIN_ENA, _vel);
    Serial.println("motor A - aft");
}

/*
motor A - stop 
*/
void motorDC_A_stop()
{
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
    analogWrite(PIN_ENA, 0);
    Serial.println("motor A - stop");
}

/*
motor B - avance
*/
void motorDC_B_fwd(byte _vel){
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
    analogWrite(PIN_ENB, _vel);
    Serial.println("motor    B - fwd");
}

/*
motor B - atras
*/
void motorDC_B_aft(byte _vel)
{
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, HIGH);
    analogWrite(PIN_ENB, _vel);
    Serial.println("motor    B - aft");
}

/*
motor B - stop 
*/
void motorDC_B_stop()
{
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, LOW);
    analogWrite(PIN_ENB, 0);
    Serial.println("motor    B - stop");
}

/*
avance AMBOS motores
*/
void motorDC_fwd(byte _vel){
    motorDC_A_fwd(_vel);
    motorDC_B_fwd(_vel);
    Serial.println("motores         - fwd");
}

/*
atras AMBOS motores
*/
void motorDC_aft(byte _vel){
    motorDC_A_aft(_vel);
    motorDC_B_aft(_vel);
    Serial.println("motores         - aft");
}

/*
stop AMBOS motores
*/
void motorDC_stop(){
    motorDC_A_stop();
    motorDC_B_stop();
    Serial.println("motores         - stop");
}

/*
giro 90 derecha
*/
void motorC_90_DRCHA(){
                                    // PENDIENTE

Serial.println("motores                     90 derecha");
}

/*
giro 90 izquierda
*/
void motorDC_90_IZQDA()
{
                                   // PENDIENTE

Serial.println("motores                     90 izquierda");
}

/*
giro 180
*/
void motor_DC_180()
{
                                   // PENDIENTE
Serial.println("motores                     180");
}

/*
Test 01
motor DRCHA (stop  -fwd BAJA - stop - aft - stop - fwd MEDIA - stop)
*/
void motorDC_test01()
{
    delay(5000);
    Serial.println("Test 01 : motor DRCHA");

    Serial.println("stop    VELOCIDAD_STOP");       
    delay(1000);
    motorDC_A_stop();                               
    delay(5000);

    Serial.println("fwd     VELOCIDAD_BAJA");       
    delay(1000);
    motorDC_A_fwd(VELOCIDAD_BAJA);                  
    delay(5000);

    Serial.println("stop    VELOCIDAD_STOP");       
    delay(1000);
    motorDC_A_stop();                               
    delay(5000);

    Serial.println("aft     VELOCIDAD_INVERSA");
    delay(1000);
    motorDC_A_aft(VELOCIDAD_INVERSA);
    delay(5000);

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_A_stop();
    delay(5000);

    Serial.println("fwd     VELOCIDAD_MEDIA");
    delay(1000);
    motorDC_A_fwd(VELOCIDAD_MEDIA);
    delay(5000);

    Serial.println("stop    VELOCIDAD_STOP");       
    delay(1000);
    motorDC_A_stop();                               
    delay(5000);
}

/*
Test 02
motor IZQDA (stop  -fwd BAJA - stop - aft - stop - fwd MEDIA - stop)
*/
void motorDC_test02()
{
    delay(5000);
    Serial.println("Test 02 : motor IZQDA");

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_B_stop();
    delay(5000);

    Serial.println("fwd     VELOCIDAD_BAJA");
    delay(1000);
    motorDC_B_fwd(VELOCIDAD_BAJA);
    delay(5000);

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_B_stop();
    delay(5000);

    Serial.println("aft     VELOCIDAD_INVERSA");
    delay(1000);
    motorDC_B_aft(VELOCIDAD_INVERSA);
    delay(5000);

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_B_stop();
    delay(5000);

    Serial.println("fwd     VELOCIDAD_MEDIA");
    delay(1000);
    motorDC_B_fwd(VELOCIDAD_MEDIA);
    delay(5000);

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_B_stop();
    delay(5000);
}

/*
Test 03
ambos motores (stop  -fwd BAJA - stop - aft - stop - fwd MEDIA - stop)
*/
void motorDC_test03()
{
    delay(5000);
    Serial.println("Test 03 : ambos motores");

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_stop();
    delay(5000);

    Serial.println("fwd     VELOCIDAD_BAJA");
    delay(1000);
    motorDC_fwd(VELOCIDAD_BAJA);
    delay(5000);

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_stop();
    delay(5000);

    Serial.println("aft     VELOCIDAD_INVERSA");
    delay(1000);
    motorDC_aft(VELOCIDAD_INVERSA);
    delay(5000);

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_stop();
    delay(5000);

    Serial.println("fwd     VELOCIDAD_MEDIA");
    delay(1000);
    motorDC_fwd(VELOCIDAD_MEDIA);
    delay(5000);

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_stop();
    delay(5000);
}

/*
Test 04
calculo de RPM para todas las velocidades
*/
void motorDC_test04()
{
    delay(5000);
    Serial.println("Test 04 : RPMs");

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_stop();
    delay(5000);
    encoders_info();

    Serial.println("fwd     VELOCIDAD_BAJA");
    delay(1000);
    motorDC_fwd(VELOCIDAD_BAJA);
    delay(5000);
    encoders_info();

    Serial.println("fwd     VELOCIDAD_MEDIA");
    delay(1000);
    motorDC_fwd(VELOCIDAD_MEDIA);
    delay(5000);
    encoders_info();

    Serial.println("fwd     VELOCIDAD_MAX");
    delay(1000);
    motorDC_fwd(VELOCIDAD_MAX);
    delay(5000);
    encoders_info();

    Serial.println("stop    VELOCIDAD_STOP");
    delay(1000);
    motorDC_stop();
    delay(5000);
    encoders_info();

    Serial.println("aft     VELOCIDAD_INVERSA");
    delay(1000);
    motorDC_aft(VELOCIDAD_INVERSA);
    delay(5000);
    encoders_info();
}