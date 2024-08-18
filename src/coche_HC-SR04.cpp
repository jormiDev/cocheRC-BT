#include "coche_HC-SR04.hpp" 




/*
Ultrasonidos_setup
*/
void ultrasonidos_setup()
{   
} 

/*
Ultrasonidos_mide
*/
float ultrasonidos_mide()
{
    float x = distHCSR04.dist();
    delay(HCSR04_DELAY_MS);
    return x;
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


/*
Test 01 Ultrasonidos - una medida
*/
void ultrasonidos_test01(){
    delay(5000);
    Serial.println("Test 01 : HC-SR04 medida simple");
    sensorDist = ultrasonidos_mide();
    Serial.print("               distancia  (cms)      : ");
    Serial.println(sensorDist);
}

/*
Test 02 Ultrasonidos - varias mediciones  + media de ellas
*/
void ultrasonidos_test02(){
    delay(5000);
    Serial.println("Test 02 : HC-SR04 medida multiple");

    int x = 10;     //numero de mediciones
    
    unsigned long myTime, myDiff;
    myTime = millis();
    float  distMedia = 0;

    for (int i = 0; i < x; i++){
        sensorDist = ultrasonidos_mide();
        distMedia += sensorDist;
        Serial.print("i = ");
        Serial.print(i);
        Serial.print("               cms = ");
        Serial.println(sensorDist);
    }

    Serial.print(" distancia media             (cm) = ");
    Serial.println(distMedia/x);

    myDiff = millis();
    myTime = (myDiff - myTime) / x;
    Serial.print(" media de tiempo             (ms) = ");
    Serial.println(myTime);    
}

/*
Test 03 Ultrasonidos - test de mediciones moviemdo el servo en las posiciones -90, -45, 0, 45, 90
*/
void ultrasonidos_test03()
{
                            // PENDIENTE MODO AUTO
}