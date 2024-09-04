#include "coche_SG90.hpp" 




/*
Servo SG90 setup
*/
void servo_setup()
{
    myservo.attach(PIN_SERVO);
    posicionServo = myservo.read();
    Serial.print("      Posición actual =  ");
    Serial.println(posicionServo);
} 

/*
Mueve el servo al angulo del parametro
*/
void servo_orienta(int angulo){
    //conversion +90 al parametro
    myservo.write(angulo + 90);
    delay(SERVO_DELAY_MS);
}

/*
Devuelve el angulo actual
*/
int servo_posicion(){
    //conversion -90 al resultado
    posicionServo = myservo.read();
    return posicionServo - 90;
}

/*
Test 01 SG90
mueve el servo en las posiciones -90, -45, 0, 45, 90
*/
void servo_test01()
{
    delay(5000);
    Serial.println("Test 01 : SG90 a las posiciones -90, -45, 0, 45, 90");

    Serial.print("      Posición actual =  ");
    Serial.println(servo_posicion());

        servo_orienta(-90);
    Serial.println("      ang  -90");
    servo_orienta(-45);
    Serial.println("      ang  -45");
    servo_orienta(0);
    Serial.println("      ang    0");
    servo_orienta(45);
    Serial.println("      ang   45");
    servo_orienta( 90);
    Serial.println("      ang   90");
}

/*
Test 02 SG90
calcula el tiempo (en ms) para pasar de -90 a +90
*/
void servo_test02()
{
    delay(5000);
    Serial.println("Test 02 : SG90 calcula el tiempo (en ms) para pasar de -90 a +90");
    
    unsigned long myTime, myDiff;

    servo_orienta(-90);
    delay(SERVO_DELAY_MS);
    myTime = millis();

    servo_orienta(90);
    myDiff = millis();

    myTime = myDiff - myTime;
    Serial.print(" media de tiempo             (ms) = ");
    Serial.println(myTime);
}

/*
Test 03 SG90
Paso lento de  -90 a +90
*/
void servo_test03()
{
    delay(5000);
    Serial.println("Test 03 : SG90 Paso lento de  -90 a +90");

    servo_orienta(-90);
    delay(SERVO_DELAY_MS);

    for (int pos = -90; pos <= 90; pos += 1)
    { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servo_orienta(pos); // tell servo to go to position in variable 'pos'
        delay(SERVO_DELAY_MS/5); // waits 15ms for the servo to reach the position
    }
    for (int pos = -90; pos >= 90; pos -= 1)
    {                       // goes from 180 degrees to 0 degrees
        servo_orienta(pos); // tell servo to go to position in variable 'pos'
        delay(SERVO_DELAY_MS/5); // waits 15ms for the servo to reach the position
    }
}