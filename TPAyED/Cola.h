#ifndef __COLA_H__
#define __COLA_H__

#ifndef NULL
#define NULL      0
#endif
/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/

/* Tipo de Informacion que esta contenida en los Nodos de la
   Cola, identificada como Dato. */
typedef void* PtrDato;

/* Tipo de Estructura de los Nodos de la Cola. */
struct NodoCola {
    PtrDato ptrDato; // dato almacenado
    NodoCola* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Cola, el cual se usa para recorrer
   la Cola y acceder a sus Datos. */
typedef NodoCola* PtrNodoCola;

typedef void (*PFDestructor)(PtrDato);

/* Tipo de Estructura de la Cola */
struct Cola{
    PtrNodoCola primero;      // puntero al primer nodo de la pila
    PtrNodoCola ultimo;       // puntero al ultimo nodo de la pila
    PFDestructor destruye; //PARA LLAMAR DESTRUCTOR
};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : la cola no debe haber sido creada.
  post: cola queda creada y preparada para ser usada.

  cola : estructura de datos a ser creado.
*/
void crearCola(Cola &cola, PFDestructor destructor);

/*----------------------------------------------------------------------------*/
/*
  pre : cola Creada con crearCola().
  post: devuelve la representacion de lo Siguiente al último Nodo de la cola,
        o sea el valor Null, que en esta implementacion representa el final de
        la cola.

  return: representación del fin de la cola.
*/
PtrNodoCola finCola();

/*----------------------------------------------------------------------------*/
/*
  pre : cola creada con crearCola().
  post: Devuelve true si cola esta vacia, sino devuelve false.

  cola: cola sobre la cual se invoca la primitiva.
*/
bool colaVacia(Cola &cola);

/*----------------------------------------------------------------------------*/
/*
  pre : cola creada con crearCola().
  post: devuelve el puntero al primer elemento de la cola, o devuelve fin() si
        esta vacia

  cola: cola sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoCola colaFrente(Cola &cola);

/*----------------------------------------------------------------------------*/
/*
  pre : cola creada con crearCola().
  post: devuelve el puntero al ultimo elemento de la cola, o devuelve fin() si
        esta vacia

  cola: cola sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoCola colaFin(Cola &cola);

/*----------------------------------------------------------------------------*/
/*
  pre : cola creada con crearCola().
  post: agrega un nodo nuevo al final de la cola con el dato proporcionado
        y devuelve un puntero a ese elemento.

  cola: cola sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al principio de la cola.
  return puntero al nodo adicionado.
*/
PtrNodoCola encolar(Cola &cola, PtrDato ptrDato);

/*----------------------------------------------------------------------------*/
/*
  pre : cola creada con crearCola().
  post: saca un nodo al frente de la cola con el dato proporcionado
        y devuelve un puntero a ese elemento.

  cola: cola sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al principio de la cola.
  return puntero al nodo adicionado.
*/
PtrDato desencolar(Cola &cola);

/*----------------------------------------------------------------------------*/
/*
  pre : cola creada con crearCola().
  post: elimina todos los Nodos de la cola quedando destruida e inhabilitada
        para su uso.

  cola: cola sobre la cual se invoca la primitiva.
*/
void eliminarCola(Cola &cola);



#endif
