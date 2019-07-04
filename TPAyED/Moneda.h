#ifndef __MONEDA_H__
#define __MONEDA_H__

#include <iostream>
#include "SDL_image.h"
#include "Posicion.h"

using namespace std;
/*
    Definicion de tipo de dato Moneda
    Las monedas son el elemento que debera recolectar el tren para comprar vagones
    Atributos:
    * cantidad
    * posicion
    * Tiempo aparicion
    * Tiempo duracion

    Axiomas
    * codItem > 0, existente
    * cantidad < 100
    * tiempo aparicion [0..IM]
    * tiempo vida [0..IV]
*/
/* Tipo de estructura de Moneda*/
typedef struct Moneda{
    int cantidad;
    Posicion posicion;
    int aparicion;
    int duracion;

    SDL_Texture * textura;
    SDL_Rect rectImag;
}Moneda;

/************GETTERS AND SETTERS*********************/
/*PRE: Moneda creada
  POST: devuelve la posicion de la moneda pasado por parametro
*/
Posicion getPosicion(Moneda &moneda);
/*PRE: Moneda creada
  POST: devuelve la cantidad de la moneda pasado por parametro
*/
int getCantidad(Moneda &moneda);
/*PRE: Moneda creada
  POST: devuelve la aparicion de la moneda pasado por parametro
*/
int getAparicion(Moneda &moneda);
/*PRE: Moneda creada
  POST: devuelve la duracion de la moneda pasado por parametro
*/
int getDuracion(Moneda &moneda);
/*PRE: moneda creada
  POST: setea posicion a la moneda
*/
void setPosicion(Moneda &moneda, Posicion &posicion);
/*PRE: moneda creada
  POST: setea aparicion a la moneda
*/
void setAparicion(Moneda &moneda, int duracion);
/*PRE: moneda creada
  POST: setea duracion a la moneda
*/
void setDuracion(Moneda &moneda, int aparicion);
/*PRE: moneda creada
  POST: setea Cantidad a la moneda
*/
void setCantidad(Moneda &moneda, int cantidad);
/***************************************************/
/*
PRE:
Post: inicializa parametros de moneda, posicion=(0,0), aparicion = 0, duracion=0, cantidad =0;
*/
void crearMoneda(Moneda &moneda);
/*
PRE: Moneda creada
Post: libera recursos solicitados por comanda
*/
void eliminarMoneda(Moneda &moneda);
/*
PRE: Moneda existente y cargada
Post: Muestra por pantalla los atributos
*/
void toString(Moneda &moneda);
/*
PRE: Moneda existente
Post: Carga la textura a la moneda y la relaciona al render
*/
void cargarTexturaMoneda(Moneda& moneda, SDL_Renderer * renderizador);
/*
PRE: Moneda existente
Post: agrega moneda al render
*/
void renderizarMoneda(Moneda& monedaActual, SDL_Renderer *renderizador);

#endif
