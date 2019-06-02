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

/*PRE: Que la caja existe

Post: Devuelve cantidad de item

*/

string getItem(Cajas &cajas);

/*PRE: Que la caja existe

Post: Devuelve cantidad de item

*/

void setCantItem(Cajas &cajas);


int getCapMaxima(Cajas &cajas);
int getCapActual(Cajas &cajas);

#endif // __PARAMETROS_H__
