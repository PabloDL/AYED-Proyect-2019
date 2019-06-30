#ifndef __POSICION_H__
#define __POSICION_H__

#include <iostream>
#include <stdlib.h>

using namespace std;

/*
    Definicion de tipo de dato Posicion para referencias posicion X e Y de un elemento
    Se busca representar univocamente una posicion en el juego
    Atributos:
    * X -> posicion eje X
    * Y -> posicion eje Y

    Axiomas
    * X >= 0
    * Y >= 0
*/

/* Tipo de estructura de Comanda */

typedef struct Posicion{
    int x;
    int y;
}Posicion;

/************GETTERS AND SETTERS*********************/
int getX(Posicion &posicion);

int getY(Posicion &posicion);

void setX(Posicion &posicion, int x);

void setY(Posicion &posicion, int y);

/***************************************************/
/*
PRE:
Post: inicializa parametros de posicion, x=0, y=0
*/
void crearPosicion(Posicion &posicion);
/*
PRE: posicion creada
Post: libera recursos solicitados por posicion
*/
void eliminarPosicion(Posicion &posicion);
/*
PRE: posicion creada
Post: libera recursos solicitados por posicion
*/
void moverPosicion(Posicion &posicion, int x, int y);
/*
PRE: posicion creada
Post: verifica si la posicion es valida en el juego, es
    decir verifica que sea una posicion posible en el juego,
    devuelve false si esta fuera del rango del juego
*/
bool esValidaPosicion(Posicion &posicion);

bool mismaPosicion(Posicion &posA, Posicion &posB);

/*
PRE: posicion creada
Post: verifica si la posicion A esta respecto de B a una diferencia de "distancia"
*/
bool enCercanias(Posicion &posA, Posicion &posB, int distancia);

Posicion alejarPosicion(Posicion &posA,Posicion &posB, int distancia);

#endif // __PARAMETROS_H__
