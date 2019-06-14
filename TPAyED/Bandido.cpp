#include "Bandido.h"


/************GETTERS AND SETTERS*********************/
int getCantidad(Bandido &bandido){}
Posicion getPosicion(Bandido &bandido){ return bandido.posicion;}
int getTiempoVida(Bandido &bandido){ return bandido.tiempoVida;}
int getIntervaloHastaAparicion(Bandido &bandido){ return bandido.intervaloHastaAparicion;}
int getAreaCobertura(Bandido &bandido){ return bandido.areaCobertura;}
int getCodItem(Bandido &bandido) {return bandido.codItem;}

void setCantidad(Bandido &bandido, int cantidad){bandido.cantidad=MAXIMO_ROBO_BANDIDO;}
void setPosicion(Bandido &bandido, Posicion posicion){bandido.posicion=posicion;}
void setTiempoVida(Bandido &bandido, int tiempoVida){bandido.tiempoVida=tiempoVida;}
void setIntervaloHastaAparicion(Bandido &bandido, int intervaloHastaAparicion){bandido.intervaloHastaAparicion=intervaloHastaAparicion;}
void setAreaCobertura(Bandido &bandido, int area){ bandido.areaCobertura=area;}
void setCodItem(Bandido &bandido, int cod){ bandido.codItem=cod;}

/***************************************************/

void crearBandido(Bandido &bandido){
    bandido.id = 0;
    bandido.cantidad= MAXIMO_ROBO_BANDIDO;
    bandido.tiempoVida= 0;
    bandido.intervaloHastaAparicion= 0;
    bandido.areaCobertura= AREA_COBERTURA;
    bandido.codItem = 1 + rand()% (5); //GENERO RANDOM EL CODIGO
}

void eliminarBandido(Bandido &bandido){}

void toString(Bandido &bandido){}
