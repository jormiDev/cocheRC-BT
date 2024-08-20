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
}

/*
motor A - atras
*/
void motorDC_A_aft(byte _vel)
{
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
    analogWrite(PIN_ENA, _vel);
}

/*
motor A - stop 
*/
void motorDC_A_stop()
{
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
    analogWrite(PIN_ENA, 0);
}

/*
motor B - avance
*/
void motorDC_B_fwd(byte _vel){
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
    analogWrite(PIN_ENB, _vel);
}

/*
motor B - atras
*/
void motorDC_B_aft(byte _vel)
{
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, HIGH);
    analogWrite(PIN_ENB, _vel);
}

/*
motor B - stop 
*/
void motorDC_B_stop()
{
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, LOW);
    analogWrite(PIN_ENB, 0);
}

/*
avance AMBOS motores
*/
void motorDC_fwd(byte _vel){
    motorDC_A_fwd(_vel);
    motorDC_B_fwd(_vel);
}

/*
atras AMBOS motores
*/
void motorDC_aft(byte _vel){
    motorDC_A_aft(_vel);
    motorDC_B_aft(_vel);
}

/*
stop AMBOS motores
*/
void motorDC_stop(){
    motorDC_A_stop();
    motorDC_B_stop();
}

/*
giro 90 derecha
*/
void motorC_90_DRCHA(){
                                    // PENDIENTE


}

/*
giro 90 izquierda
*/
void motorDC_90_IZQDA()
{
                                   // PENDIENTE


}

/*
giro 180
*/
void motor_DC_180()
{
                                   // PENDIENTE


}

/*
Test 01 

*/
void motorDC_test01()
{
    delay(5000);
    Serial.println("Test 01");


}

/*
Test 02 
*/
void motorDC_test02()
{
    delay(5000);
    Serial.println("Test 02");
    
}

/*
Test 03 
*/
void motorDC_test03()
{
    delay(5000);
    Serial.println("Test 03 :");

}