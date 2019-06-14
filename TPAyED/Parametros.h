#ifndef __PARAMETROS_H__
#define __PARAMETROS_H__

#include <iostream>

using namespace std;
/*
    Definicicion de tipo de dato Parametro para cargar items de archivo
    Atributos:
    s, p, a, PosXE, posYE,iM, vM, iB, vB, iP

    Axiomas
    * codItem > 0, existente
    * cantidad < 100
*/
/* Tipo de estructura de Comanda */
typedef struct Parametros{
    int s;
    int p;
    int a;
    int posXE;
    int posYE;
    int iM;
    int vM;
    int iB;
    int vB;
    int iP;
}Parametros;
/************GETTERS AND SETTERS*********************/
int getS(Parametros &parametros);
int getP(Parametros &parametros);
int getA(Parametros &parametros);
int getPosXE(Parametros &parametros);
int getPosYE(Parametros &parametros);
int getIm(Parametros &parametros);
int getVm(Parametros &parametros);
int getIb(Parametros &parametros);
int getVb(Parametros &parametros);
int getIp(Parametros &parametros);

void setS(Parametros &parametros, int s);
void setP(Parametros &parametros, int p);
void setA(Parametros &parametros, int a);
void setPosXE(Parametros &parametros, int posYE);
void setPOSYE(Parametros &parametros, int posXE);
void setIm(Parametros &parametros, int im);
void setVm(Parametros &parametros, int vm);
void setIb(Parametros &parametros, int ib);
void setIp(Parametros &parametros, int ip);

/***************************************************/
/*
PRE:
Post: inicializa parametros de TDA Parametros en 0
*/
void crearParametros(Parametros & parametros);
/*
PRE: Parametros creado
Post: libera recursos solicitados por parametros
*/
void eliminarParametros(Parametros & parametros);
/*
PRE: Mina existente y cargada
Post: Muestra por pantalla los atributos
*/
void toString(Parametros &parametros);

#endif
