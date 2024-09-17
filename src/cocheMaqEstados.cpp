#include "cocheMaqEstados.hpp"

/*
manual_STOP
modo manual/auto - app_STOP
*/
void manual_STOP(){
    motorDC_stop();
}

/*
manual_FWD
modo manual - app_FWD
*/
void manual_FWD(){
    motorDC_fwd(VELOCIDAD_MEDIA);
}

/*
manual_AFT
modo manual - app_AFT
*/
void manual_AFT(){
    motorDC_aft(VELOCIDAD_MEDIA);
}

/*
manual_IZQ
modo manual - app_IZQ
*/
void manual_IZQ(){
    motorDC_A_fwd(VELOCIDAD_MEDIA);
    motorDC_B_fwd(VELOCIDAD_BAJA);
}

/*
manual_DCHA
modo manual - app_DCHA
*/
void manual_DCHA(){
    motorDC_A_fwd(VELOCIDAD_BAJA);
    motorDC_B_fwd(VELOCIDAD_MEDIA);
}

/*
manual_90IZQ
modo manual - app_90IZQ
*/
void manual_90IZQ(){
    motorDC_90_IZQDA();
}

/*
manual_90DCHA
modo manual - app_90DCHA
*/
void manual_90DCHA(){
    motorC_90_DRCHA();
}

/*
manual_180
modo manual - app_180
*/
void manual_180(){
    motor_DC_180();
}


/*
maqEstados_INICIO
//  0
// estado inicial, desconecado ble + todo parado
*/
void maqEstados_INICIO(){
    maquinaEstados = ME_INICIO;
}

/*
maqEstados_CONECTADO_BLE
//  1
// INICIO + conectado a BLE
*/
void maqEstados_CONECTADO_BLE(){
    maquinaEstados = ME_DESCONECTADO_BLE;
}

/*
maqEstados_DESCONECTADO_BLE
//  2
// desconectado a BLE >> parar todo + estado buscar conexion
*/
void maqEstados_DESCONECTADO_BLE(){
    maquinaEstados = ME_DESCONECTADO_BLE;
}

/*
maqEstados_QUIT_APP
//  3
// >> parar todo + desconectar BLE
*/
void maqEstados_QUIT_APP(){
    maquinaEstados = ME_QUIT_APP;
}

/*
maqEstados_MODO_AUTO
//  4
// parar todo + analizar escenario + inicir conduccion automatica
*/
void maqEstados_MODO_AUTO(){
    maquinaEstados = ME_MODO_AUTO;
}

/*
maqEstados_MODO_MANUAL
//  5
// parar todo + esperar comnandos
*/
void maqEstados_MODO_MANUAL(){
    maquinaEstados = ME_MODO_MANUAL;
}
