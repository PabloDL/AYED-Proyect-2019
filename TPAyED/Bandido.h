#ifndef __BANDIDO_H__
#define __BANDIDO_H__

#include <iostream>
#include "locomotora.h"

#define AREA_COBERTURA 2
#define MAXIMO_ROBO_BANDIDO 5

using namespace std;
/*
Definicion de tipo de dato Bandido para representar el rival del juego
    Atributos:
    * cantidad
    * posicion
    * tiempo Vida
    * intervalos que pasaran hasta aparicion

    Axiomas
    * cantidad < 100
    * posicion -> x e y > 0
    * tiempo vida > 0 [0..VB]
    * intervalos  > 0 [0..IB]
*/
/* Tipo de estructura de Bandido */
typedef struct Bandido{
    int id;
    int cantidad;
    Posicion posicion;
    int tiempoVida;
    int intervaloHastaAparicion;
    int areaCobertura;
    int codItem;

    SDL_Texture *textura;
    SDL_Rect rectImag;
}Bandido;

/************GETTERS AND SETTERS*********************/
int getId(Bandido &bandido);
int getCantidad(Bandido &bandido);
Posicion getPosicion(Bandido &bandido);
int getTiempoVida(Bandido &bandido);
int getIntervaloHastaAparicion(Bandido &bandido);
int getAreaCobertura(Bandido &bandido);
int getCodItem(Bandido &bandido);

void setId(Bandido &Bandido);
void setCantidad(Bandido &bandido, int cantidad);
void setPosicion(Bandido &bandido, Posicion posicion);
void setTiempoVida(Bandido &bandido, int tiempoVida);
void setIntervaloHastaAparicion(Bandido &bandido, int intervaloHastaAparicion);
void setAreaCobertura(Bandido &bandido, int areaCobertura);
void setCodItem(Bandido &bandido, int codItem);

/***************************************************/
/*
PRE:
Post: inicializa parametros de bandido, cantidad=0; posicion (0,0) tiempoVida y intervaloHastaAparicion random
*/
void crearBandido(Bandido &bandido);
/*
PRE: Bandido creado
Post: libera recursos solicitados por bandido
*/
void eliminarBandido(Bandido &bandido);
/*
PRE: Bandido existente y cargada
Post: Muestra por pantalla los atributos
*/
void toString(Bandido &bandido);

void cargarTexturaBandido(Bandido& bandido, SDL_Renderer * renderizador);
void renderizarBandido(Bandido& bandidoActual, SDL_Renderer *renderizador);

#endif

