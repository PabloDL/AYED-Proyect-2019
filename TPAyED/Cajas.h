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
} Cajas;

/************************************************/

/*PRE: Que la caja existe

Post: Devuelve cantidad de item

*/

int getItem(Cajas &cajas);

/*PRE: Que la caja existe

Post: Devuelve cantidad de item

*/

void setCantItem(Cajas &cajas);


#endif // __PARAMETROS_H__
