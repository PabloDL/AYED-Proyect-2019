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
/*PRE: bandido creado
  POST: devuelve el id del bandido
*/
int getId(Bandido &bandido);
/*PRE: bandido creado
  POST: devuelve  la cantidad que roba el bandido
*/
int getCantidad(Bandido &bandido);
/*PRE: bandido creado
  POST: devuelve la posicion del bandido
*/
Posicion getPosicion(Bandido &bandido);
/*PRE: bandido creado
  POST: devuelve el el tiempo de vida del bandido, es decir cuantos intervalos permanece en pantalla
*/
int getTiempoVida(Bandido &bandido);
/*PRE: bandido creado
  POST: devuelve el intevalo donde debera aparecer el bandido en pantalla
*/
int getIntervaloHastaAparicion(Bandido &bandido);
/*PRE: bandido creado
  POST: devuelve el area de cobertura del bandido
*/
int getAreaCobertura(Bandido &bandido);
/*PRE: bandido creado
  POST: devuelve el codigo del item que roba el bandido
*/
int getCodItem(Bandido &bandido);
/*PRE: terreno creado
  POST: setea id al bandido
*/
void setId(Bandido &Bandido);
/*PRE: terreno creado
  POST: setea id al bandido
*/
void setCantidad(Bandido &bandido, int cantidad);
/*PRE: terreno creado
  POST: setea cantidad al bandido
*/
void setPosicion(Bandido &bandido, Posicion posicion);
/*PRE: terreno creado
  POST: setea posicion al bandido
*/
void setTiempoVida(Bandido &bandido, int tiempoVida);
/*PRE: terreno creado
  POST: setea tiempo de vida al bandido
*/
void setIntervaloHastaAparicion(Bandido &bandido, int intervaloHastaAparicion);
/*PRE: terreno creado
  POST: setea el intervalo hasta aparicion al bandido
*/
void setAreaCobertura(Bandido &bandido, int areaCobertura);
/*PRE: terreno creado
  POST: setea area de cobertura a bandido
*/
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
/*
PRE: Bandido existente
Post: Carga la textura al bandido y la relaciona al render
*/
void cargarTexturaBandido(Bandido& bandido, SDL_Renderer * renderizador);
/*
PRE: Bandido existente
Post: agrega el bandido al render
*/
void renderizarBandido(Bandido& bandidoActual, SDL_Renderer *renderizador);

#endif

