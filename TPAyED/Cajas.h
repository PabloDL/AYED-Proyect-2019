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


/*PRE:

Post: inicializa parametros de la caja

*/

void crearCaja(Cajas &cajas);


/*PRE: Que la caja existe

Post: Devuelve cantidad de item

*/

void modificarCantItem(Cajas &cajas);


/*PRE: Estacion creada

Post: libera recursos solicitados por estacion

*/

void eliminarCaja(Cajas &cajas);




#endif // __PARAMETROS_H__
