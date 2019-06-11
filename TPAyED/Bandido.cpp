#include "Bandido.h"


/************GETTERS AND SETTERS*********************/
int getCantidad(Bandido &bandido){}
Posicion getPosicion(Bandido &bandido){ return bandido.posicion;}
int getTiempoVida(Bandido &bandido){ return bandido.tiempoVida;}
int getIntervaloHastaAparicion(Bandido &bandido){ return bandido.intervaloHastaAparicion;}
int getAreaCobertura(Bandido &bandido){ return bandido.areaCobertura;}

void setCantidad(Bandido &bandido, int cantidad){bandido.cantidad=MAXIMO_ROBO_BANDIDO;}
void setPosicion(Bandido &bandido, Posicion posicion){bandido.posicion=posicion;}
void setTiempoVida(Bandido &bandido, int tiempoVida){bandido.tiempoVida=tiempoVida;}
void setIntervaloHastaAparicion(Bandido &bandido, int intervaloHastaAparicion){bandido.intervaloHastaAparicion=intervaloHastaAparicion;}
void setAreaCobertura(Bandido &bandido, int area){ bandido.areaCobertura=area;}

/***************************************************/

void crearBandido(Bandido &bandido){
    bandido.id = 0;
    bandido.cantidad= MAXIMO_ROBO_BANDIDO;
    bandido.tiempoVida= 0;
    bandido.intervaloHastaAparicion= 0;
    bandido.areaCobertura= AREA_COBERTURA;

}

void eliminarBandido(Bandido &bandido){}

void toString(Bandido &bandido){}

void robarItem(Bandido &bandido, Locomotora& locomotora){}

void destruirVagon(Bandido &bandido, Locomotora& locomotora){}

