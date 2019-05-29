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
   int codItem;
   int capMaxima;
   int capActual;
} Cajas;

/************************************************/

/*PRE: Que la caja existe

Post: Devuelve cantidad de item

*/

int getItem(Cajas &cajas);


#endif // __PARAMETROS_H__
