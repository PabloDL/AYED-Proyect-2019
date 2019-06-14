#ifndef __COMANDA_H__
#define __COMANDA_H__

#include <iostream>

using namespace std;

/*
    Definicion de tipo de dato Comanda para cargar items de archivo
    Cada comanda va a representar un reto a vencer en el juego
    Atributos:
    * codItem
    * cantidad

    Axiomas
    * codItem > 0, existente
    * cantidad < 100
*/

/* Tipo de estructura de Comanda */

typedef struct Comanda{
    string codItem;
    int cantidad;
}Comanda;

/************GETTERS AND SETTERS*********************/
string getCodItem(Comanda &comanda);

int getCantidad(Comanda &comanda);

void setCodItem(Comanda &comanda, string codItem);

void setCantidad(Comanda &comanda, int cantidad);

/***************************************************/
/*
PRE:
Post: inicializa parametros de comanda, codIten="", cantidad=0
*/
void crearComanda(Comanda &comanda);
/*
PRE: comada creada
Post: libera recursos solicitados por comanda
*/
void eliminarComanda(Comanda &comanda);
/*
PRE: Comanda existente y cargada
Post: Muestra por pantalla los atributos
*/
void toString(Comanda &comanda);

#endif
