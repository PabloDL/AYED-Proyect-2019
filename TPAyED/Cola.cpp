#include "Cola.h"


/******************************************************************************/
/* Funciones auxiliares */
/*------------------------------*/
PtrNodoCola crearNodoCola(PtrDato ptrDato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoCola ptrAux = new NodoCola;

  ptrAux->ptrDato = ptrDato;
  ptrAux->sgte = NULL;

  return ptrAux;
}

/*----------------------------------------------------------------------------*/

void eliminarNodoCola(Cola &cola) {

  PtrNodoCola ptrExPrimero;

  /* verifica que la cola no esté vacia y que nodo no sea fin*/
  if (! colaVacia(cola)) {

      ptrExPrimero = cola.primero;
      cola.primero = colaFrente(cola)->sgte;

    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrExPrimero;
  }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearCola(Cola &cola) {
  cola.primero = finCola();
  cola.ultimo = finCola();
}

/*----------------------------------------------------------------------------*/


PtrNodoCola finCola(){
   return NULL;
}

/*----------------------------------------------------------------------------*/

bool colaVacia(Cola &cola){
  return (cola.primero == finCola());
}

/*----------------------------------------------------------------------------*/

PtrNodoCola colaFrente(Cola &cola){
    return cola.primero;
}

/*----------------------------------------------------------------------------*/

PtrNodoCola colaFin(Cola &cola){
    return cola.ultimo;
}

PtrNodoCola encolar(Cola &cola, PtrDato ptrDato){

  /* crea el nodo */
  PtrNodoCola ptrNuevoNodo = crearNodoCola(ptrDato);

  /* lo incorpora al final de la cola */

  if (colaVacia(cola)){
     cola.primero = ptrNuevoNodo;
     cola.ultimo = ptrNuevoNodo;
  }
  else{
     cola.ultimo->sgte = ptrNuevoNodo;
     cola.ultimo = ptrNuevoNodo;
  }

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/

PtrDato desencolar(Cola &cola){

    PtrDato dato;
    dato = colaFrente(cola)->ptrDato;
    if ((! colaVacia(cola))){
        eliminarNodoCola(cola);
    }
    return dato;
}

/*----------------------------------------------------------------------------*/

void eliminarCola(Cola &cola){
    while((! colaVacia(cola))){
         eliminarNodoCola(cola);
     }
}
