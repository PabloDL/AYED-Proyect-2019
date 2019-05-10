#ifndef __MONEDA_H__
#define __MONEDA_H__

#include <iostream>

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
}Moneda;

/************GETTERS AND SETTERS*********************/
Posicion getPosicion(Moneda &moneda);
int getCantidad(Moneda &moneda);
int getAparicion(Moneda &moneda);
int getDuracion(Moneda &moneda);

void setPosicion(Moneda &moneda, Posicion &posicion);
void setAparicion(Moneda &moneda, int duracion);
void setDuracion(Moneda &moneda, int aparicion);
void setCantidad(Moneda &moneda, int cantidad);

/***************************************************/
/*
PRE:
Post: inicializa parametros de moneda, posicion=(0,0), duracion, aparicion,cantidad se calculan en forma random
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

#endif // __PARAMETROS_H__

