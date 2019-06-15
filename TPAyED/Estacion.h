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
Posicion getPosicion(Estacion &estacion);
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


void cargarTexturaEstacion(Estacion& estacion, SDL_Renderer * renderizador);
void renderizarEstacion(Estacion& estacionActual, SDL_Renderer *renderizador);

#endif
