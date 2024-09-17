#include "coche_motorDC.hpp" 


/*
Init del L298N
*/
void motorDC_setup()
{
    myMotors.setSpeed(VELOCIDAD_STOP);
    myMotors.stop();
} 

/*
motor A - avance
*/
void motorDC_A_fwd(byte _vel){
    myMotors.setSpeedA(_vel);
    myMotors.forwardA();
    debugMensajeln("motor A - fwd");
}

/*
motor A - atras
*/
void motorDC_A_aft(byte _vel)
{
    myMotors.setSpeedA(_vel);
    myMotors.backwardA();
    debugMensajeln("motor A - aft");
}

/*
motor A - stop 
*/
void motorDC_A_stop()
{
    myMotors.setSpeedA(VELOCIDAD_STOP);
    myMotors.stopA();
    debugMensajeln("motor A - stop");
}

/*
motor B - avance
*/
void motorDC_B_fwd(byte _vel){
    myMotors.setSpeedB(_vel);
    myMotors.forwardB();
    debugMensajeln("motor    B - fwd");
}

/*
motor B - atras
*/
void motorDC_B_aft(byte _vel)
{
    myMotors.setSpeedB(_vel);
    myMotors.backwardB();
    debugMensajeln("motor    B - aft");
}

/*
motor B - stop 
*/
void motorDC_B_stop()
{
    myMotors.setSpeedB(VELOCIDAD_STOP);
    myMotors.stopB();
    debugMensajeln("motor    B - stop");
}

/*
avance AMBOS motores
*/
void motorDC_fwd(byte _vel){
    motorDC_A_fwd(_vel);
    motorDC_B_fwd(_vel);
    debugMensajeln("motores         - fwd");
}

/*
atras AMBOS motores
*/
void motorDC_aft(byte _vel){
    motorDC_A_aft(_vel);
    motorDC_B_aft(_vel);
    debugMensajeln("motores         - aft");
}

/*
stop AMBOS motores
*/
void motorDC_stop(){
    motorDC_A_stop();
    motorDC_B_stop();
    debugMensajeln("motores         - stop");
}

/*
giro 90 derecha
*/
void motorC_90_DRCHA(){
    debugMensaje("motores                     90 derecha");
    myMotors.setSpeedA(VELOCIDAD_BAJA);
    myMotors.setSpeedB(VELOCIDAD_MEDIA);
    myMotors.forwardForA(MOTOR_TIEMPO_90);
    myMotors.forwardForB(MOTOR_TIEMPO_90);
    debugMensajeln("   -  fin giro");
}

/*
giro 90 izquierda
*/
void motorDC_90_IZQDA()
{
    debugMensaje("motores                     90 izquierda");
    myMotors.setSpeedA(VELOCIDAD_MEDIA);
    myMotors.setSpeedB(VELOCIDAD_BAJA);
    myMotors.forwardForA(MOTOR_TIEMPO_90);
    myMotors.forwardForB(MOTOR_TIEMPO_90);
    debugMensajeln("   -  fin giro");
}

/*
giro 180
*/
void motor_DC_180()
{
    debugMensaje("motores                     giro 180");
    myMotors.setSpeedA(VELOCIDAD_INVERSA);
    myMotors.setSpeedB(VELOCIDAD_INVERSA);
    myMotors.forwardForA(MOTOR_TIEMPO_180);
    myMotors.backwardForB(MOTOR_TIEMPO_180);
    debugMensajeln("   -  fin giro");
}

/*
motorDC_info
*/
void motorDC_info(){
    Serial.println("motores info");
    Serial.print("\t\tMotor A is moving = ");
    Serial.print(myMotors.isMovingA() ? "YES" : "NO");
    Serial.print(" at speed = ");
    Serial.println(myMotors.getSpeedA());
    Serial.print("\t\tMotor B is moving = ");
    Serial.print(myMotors.isMovingB() ? "YES" : "NO");
    Serial.print(" at speed = ");
    Serial.println(myMotors.getSpeedB());
}


/*
TEST
*/


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