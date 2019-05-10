#ifndef __BANDIDO_H__
#define __BANDIDO_H__

#include <iostream>

#include "locomotora.h"

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
    int cantidad;
    Posicion posicion;
    int tiempoVida;
    int intervaloHastaAparicion;
}Bandido;

/************GETTERS AND SETTERS*********************/
int getCantidad(Bandido &bandido);
int getPosicion(Bandido &bandido);
int getTiempoVida(Bandido &bandido);
int getIntervaloHastaAparicion(Bandido &bandido);

void setCantidad(Bandido &bandido, int cantidad);
void setCantidad(Bandido &bandido, Posicion posicion);
void setCantidad(Bandido &bandido, int tiempoVida);
void setCantidad(Bandido &bandido, int intervaloHastaAparicion);

/***************************************************/
/*
PRE:
Post: inicializa parametros de bandido, cantidad=0; posicion (0,0) tiempoVida y intervaloHastaAparicion random
*/
void crearBandido(Bandido &bandido);
/*
PRE: comada creada
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
Post: "roba" el item de la locomotora
*/
void robarItem(Bandido &bandido, Locomotora& locomotora);

/*
PRE: Bandido existente
Post: si la locomotora queda en 0, destruye el vagon
*/
void destruirVagon(Bandido &bandido, Locomotora& locomotora);

#endif // __PARAMETROS_H__

