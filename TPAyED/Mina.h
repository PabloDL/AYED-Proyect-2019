#ifndef __MINA_H__
#define __MINA_H__

#include <iostream>
#include <sstream>
#include "Cajas.h"
#include "Cola.h"
#include "Funciones.h"
#include "SDL_image.h"

using namespace std;
/*
Definicion de tipo de dato Mina para representar donde se producen las cajas de items
    AXIOMAS
    * Los item pueden ser: oro, plata, bronce, platino, roca y carbón.
    * La secuencia esta establecida por 5 numeros enteros del 1 al 5 inclusive

    * posX, posY, codItem, IP, seq enteros y > 0
*/
/* Tipo de estructura de Mina */

typedef struct Mina{
    int posX;
    int posY;
    int codItem;
    int IP;
    int seq1;
    int seq2;
    int seq3;
    int seq4;
    int seq5;
    Cola cajas;
    SDL_Texture* textura;
    SDL_Rect rectImag;
    int seqActual;
}Mina;
/***********GETTERS AND SETTERS*********************/
/*PRE: Mina creada
  POST: devuelve la Posicion X de la mina pasada por parametro
*/
int getPosX(Mina &mina);
/*PRE: Mina creada
  POST: devuelve la Posicion Y de la mina pasada por parametro
*/
int getPosY(Mina &mina);
/*PRE: Mina creada
  POST: devuelve codItem de la mina pasada por parametro
*/
int getCodItem(Mina &mina);
/*PRE: Mina creada
  POST: devuelve codItem de la mina pasada por parametro
*/
int getIp(Mina &mina);
/*PRE: Mina creada
  POST: devuelve Intervalo produccion de la mina pasada por parametro
*/
int getSeq1(Mina &mina);
/*PRE: Mina creada
  POST: devuelve produccion seq1 de la mina pasada por parametro
*/
int getSeq2(Mina &mina);
/*PRE: Mina creada
  POST: devuelve produccion seq2 de la mina pasada por parametro
*/
int getSeq3(Mina &mina);
/*PRE: Mina creada
  POST: devuelve produccion seq3 de la mina pasada por parametro
*/
int getSeq4(Mina &mina);
/*PRE: Mina creada
  POST: devuelve produccion seq5 de la mina pasada por parametro
*/
int getSeq5(Mina &mina);
/*PRE: Mina creada
  POST: setea PosX a la mina pasada por parametro
*/
void setPosX(Mina &mina, int posX);
/*PRE: Mina creada
  POST: setea PosY a la mina pasada por parametro
*/
void setPosY(Mina &mina, int posY);
/*PRE: Mina creada
  POST: setea codItem a la mina pasada por parametro
*/
void setCodItem(Mina &mina, int codItem);
/*PRE: Mina creada
  POST: setea IP a la mina pasada por parametro
*/
void setIp(Mina &mina, int ip);
/*PRE: Mina creada
  POST: setea Seq1 a la mina pasada por parametro
*/
void setSeq1(Mina &mina, int seq1);
/*PRE: Mina creada
  POST: setea Seq2 a la mina pasada por parametro
*/
void setSeq2(Mina &mina, int seq2);
/*PRE: Mina creada
  POST: setea Seq3 a la mina pasada por parametro
*/
void setSeq3(Mina &mina, int seq3);
/*PRE: Mina creada
  POST: setea Seq4 a la mina pasada por parametro
*/
void setSeq4(Mina &mina, int seq4);
/*PRE: Mina creada
  POST: setea Seq5 a la mina pasada por parametro
*/
void setSeq5(Mina &mina, int seq5);
/***************************************************/

/*
PRE:
POST: Inicializar los parametros de la mina, seqActual=1
*/
void crearMina (Mina &mina);

/*
PRE: Mina creada
POST: Eliminar recursos solicitados por la mina
*/
void eliminarMina (Mina &mina);

/*
PRE: Mina creada
POST: agrega caja a mina, segun corresponda sequencia actual (SeqActual = 1;)
*/
void crearCaja (Mina &mina);

/*
PRE: Caja creada
Post: libera recursos solicitados por para caja
*/

void eliminarCaja(Cajas &cajas);

/*
PRE: Mina existente y cargada
Post: Muestra por pantalla los atributos
*/
void toString(Mina &mina);

/*
PRE: Mina existente y cargada
Post: Devuelve la proxima caja de la cola sin sacarla de la cola
*/
Cajas* proximaCaja(Mina &mina);

void eliminarProduccion(Mina &mina);

//pre: debe existir una locomotora, y por tanto un terreno
//post: se cargan las texturas en el rect de locomotora
void cargarTexturaMina(Mina& mina, SDL_Renderer * renderizador);

//pre debe existir una locomotora y tener cargadas las texturas
//post: añade al renderizador las texturas de la locomotora en su posicion relativa
void renderizarMina(Mina& minaActual, SDL_Renderer *renderizador);

#endif
