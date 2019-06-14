#include "Estacion.h"
/************GETTERS AND SETTERS*********************/
Posicion getPosicion(Estacion &estacion){
    return estacion.posicion;
}
void setPosicion(Estacion &estacion, Posicion posicion){
    moverPosicion(estacion.posicion, getX(posicion), getY(posicion));
}
/***************************************************/
void crearEstacion(Estacion &estacion){
    crearPosicion(estacion.posicion);
    moverPosicion(estacion.posicion, 0, 0);
}

void eliminarEstacion(Estacion &estacion){
}

int entregarVagon(Estacion &estacion, int cantidadMonedas){
    return COFICIENTE_PESO_VAGON * cantidadMonedas;
}
