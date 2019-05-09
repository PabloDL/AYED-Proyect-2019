#ifndef __MINA_H__
#define __MINA_H__

#include <iostream>

#include "Cajas.h"

using namespace std;

/*
Definicion de tipo de dato mina para representar estructura en donde se crean las cajas de item
*/

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
}Mina;

/*
AXIOMAS
Los item pueden ser: oro, plata, bronce, platino, roca y carbón.
La secuencia esta establecida por 5 numeros enteros del 1 al 5 inclusive

/************GETTERS AND SETTERS*********************/
int getPosX(Mina &mina);
int getPosY(Mina &mina);
int getCodItem(Mina &mina);
int getIp(Mina &mina);
int getSeq1(Mina &mina);
int getSeq2(Mina &mina);
int getSeq3(Mina &mina);
int getSeq4(Mina &mina);
int getSeq5(Mina &mina);

void setPosX(Mina &mina, int posX);
void setPosY(Mina &mina, int posY);
void setCodItem(Mina &mina, int codItem);
void setIp(Mina &mina, int ip);
void setSeq1(Mina &mina, int seq1);
void setSeq2(Mina &mina, int seq2);
void setSeq3(Mina &mina, int seq3);
void setSeq4(Mina &mina, int seq4);
void setSeq5(Mina &mina, int seq5);

/***************************************************/

/*
PRE:
POST: Inicializar los parametros de la mina
*/
void crearMina (Mina &mina);

/*
PRE: Mina creada
POST: Eliminar recursos solicitados por la mina 
*/
void eliminarMina (Mina &mina);

/*
PRE: Mina creada
POST: Devuelve cola de cajas
*/
void crearcaja (Mina &mina, Cajas &cajas);

/*
PRE: Mina existente y cargada
Post: Muestra por pantalla los atributos
*/
void toString(Mina &mina);

#endif // __PARAMETROS_H__
