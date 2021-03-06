#include "Moneda.h"

Posicion getPosicion(Moneda &moneda){
    return moneda.posicion;
}

int getCantidad(Moneda &moneda){
    return moneda.cantidad;
}
int getAparicion(Moneda &moneda){
    return moneda.aparicion;
}
int getDuracion(Moneda &moneda){
    return moneda.duracion;
}

void setPosicion(Moneda &moneda, Posicion &posicion){
    moneda.posicion = posicion;
}
void setAparicion(Moneda &moneda, int duracion){
    moneda.duracion = duracion;
}
void setDuracion(Moneda &moneda, int aparicion){
    moneda.aparicion = aparicion;
}

void setCantidad(Moneda &moneda, int cantidad){
    moneda.cantidad = cantidad;
}

/***************************************************/

void crearMoneda(Moneda &moneda){
    moneda.aparicion = 0;
    moneda.cantidad = 0;
    moneda.duracion = 0;
    crearPosicion(moneda.posicion);
    moverPosicion(moneda.posicion, 0, 0);
}

void eliminarMoneda(Moneda &moneda){}

void toString(Moneda &moneda){}

