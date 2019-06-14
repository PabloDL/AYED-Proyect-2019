#ifndef __CAJAS_H__
#define __CAJAS_H__

#include <iostream>

using namespace std;
/*
    Axiomas
    No puede contener mas de 5 item.
*/
/* Tipo de estructura de Cajas */

typedef struct Cajas{
   int cantitem;
   string codItem;
   int capMaxima;
   int capActual;
} Cajas;

/************************************************/
/*
PRE:
Post: inicializa parametros de Caja en 0
*/
void crearCajas(Cajas & cajas);
/*
PRE: Cajas creada
Post: libera recursos solicitados por Cajas
*/
void eliminarCajas(Cajas & cajas);
/*
PRE: Que la caja existe
Post: Devuelve cantidad de item
*/
string getCodItem(Cajas &cajas);
/*
PRE: Que la caja existe
Post: Devuelve cantidad de item
*/
void setCantItem(Cajas &cajas, int cantitem);
/*
PRE: Que la caja existe
Post: Devuelve capacidad maxima
*/
int getCapMaxima(Cajas &cajas);
/*
PRE: Que la caja existe
Post: Devuelve capacidad actual
*/
int getCapActual(Cajas &cajas);
/*
PRE: Que la caja existe
Post: Devuelve tipo de item
*/
void setCodItem(Cajas &cajas, string codItem);
/*
PRE: Que la caja existe
Post: Devuelve capacidad maxima de vagon
*/
void setCapMaxima(Cajas &cajas, int capActual);
/*
PRE: Que la caja existe
Post: Devuelve capacidad actual de vagon
*/
void setCapActual(Cajas &cajas, int capMaxima);

#endif
