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
    bool completado; //PARA SABER SI SE COMPLETO LA COMANDA
}Comanda;

/************GETTERS AND SETTERS*********************/
/*
PRE:  Comanda creada y cargados valores
Post: devuelve valor de variable codItem de comanda
*/
string getCodItem(Comanda &comanda);
/*
PRE:  Comanda creada y cargados valores
Post: devuelve valor de variable cantidad de comanda
*/
int getCantidad(Comanda &comanda);
/*
PRE:  Comanda creada y cargados valores
Post: devuelve valor de variable completado de comanda
*/
bool getCompletado(Comanda &comanda);
/*
PRE:  Comanda creada y cargados valores
Post: setea valor de variable codItem de comanda segun parametro codItem
*/
void setCodItem(Comanda &comanda, string codItem);
/*
PRE:  Comanda creada y cargados valores
Post: setea valor de variable cantidad de comanda segun parametro cantidad
*/
void setCantidad(Comanda &comanda, int cantidad);
/*
PRE:  Comanda creada y cargados valores
Post: setea valor de variable completado de comanda segun parametro completado
*/
void setCompletado(Comanda &comanda, bool completado);
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
