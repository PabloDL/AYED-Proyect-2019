#ifndef __ESTACION_H__
#define __ESTACION_H__

#include <iostream>
#include "SDL_image.h"
#include "Posicion.h"

#define COFICIENTE_PESO_VAGON 5

using namespace std;

/*
    Definicion de tipo de dato Estacion para representar el lugar de compra de vagones
    Atributos:

    Axiomas
    * Entregara vagon segun formula Peso_máximo = 5kg*cantidad_monedas.
    * cantidad de vagones a entregar ilimitado
*/
/* Tipo de estructura de Estacion */
typedef struct Estacion{
    int id;
    Posicion posicion;

    SDL_Texture *textura;
    SDL_Rect rectImag;
}Estacion;

/************GETTERS AND SETTERS*********************/
/*PRE: Estacion creada
  POST: devuelve la posicion de la estacion
*/
Posicion getPosicion(Estacion &estacion);
/*PRE: Estacion creada
  POST: setea la posicion de la estacion
*/
void setPosicion(Estacion &estacion, Posicion posicion);
/***************************************************/
/*
PRE:
Post: inicializa parametros de estacion
*/
void crearEstacion(Estacion &estacion);
/*
PRE: Estacion creada
Post: libera recursos solicitados por estacion
*/
void eliminarEstacion(Estacion &estacion);
/*
PRE: Estacion creada
Post: calcula y devuelve peso que soporta vagon
*/
int entregarVagon(Estacion &estacion, int cantidadMonedas);
/*
PRE: Estacion existente
Post: Carga la textura a la Estacion y la relaciona al render
*/
void cargarTexturaEstacion(Estacion& estacion, SDL_Renderer * renderizador);
/*
PRE: Estacion existente
Post: agrega la Estacion al render
*/
void renderizarEstacion(Estacion& estacionActual, SDL_Renderer *renderizador);

#endif
