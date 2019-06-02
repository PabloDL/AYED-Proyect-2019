#ifndef _VAGON_H_
#define _VAGON_H_

#include "Lista.h"
#include "Posicion.h"
#include "Cajas.h"
#include "Locomotora.h"

typedef struct Vagon{
    int capVagon; //capacidad del Vagon
    int capVagonUsada; //para poder saber cuanto se uso de la capacidadMaxima
    string tipoVagon; //podra ser ORO,PLATA,BRONCE,ETC
    Posicion posicion;
    int velocidadV;
    Lista listaCajas;//lista cajas
}Vagon;

/*********************Axiomas********************/
//capacidadVagon = 5kg * cantMonedas
//el vagon incia con tipoVagon 'SIN DEFINIR' hasta que se le agregue una CAJA
//el vagon solo puede almacenar CAJAS de su mismo tipo(item)
/***************getters y setters******************/
void setCapVagon(Vagon& vagon,int capVagon);
int getCapVagon(Vagon& vagon);

void setCapVagonUsada(Vagon& vagon,int capVagonUsada);
int getCapVagonUsada(Vagon& vagon);

void setVelocidadV(Vagon& vagon,int velocidadV);
int getVelocidadV(Vagon& vagon);

void setTipoVagon(Vagon& vagon,string tipoVagon);
string getTipoVagon(Vagon& vagon);

void setPosicion(Vagon& vagon,Posicion& posicion);
Posicion getPosicion(Vagon& vagon);
/***********************Primitivas*********************/
//pre:
//post: se inicializan los parametros de Vagon
void crearVagon(Vagon& vagon);

//pre:vagon creado
//post:se liberan los recursos usados en Vagon
void eliminarVagon(Vagon& vagon);

//pre:vagon creado
//post: devuelve true si el vagon esta vacio o false si no esta vacio
bool vagonVacio(Vagon& vagon);

//pre: vagon creado y asignado con 1 o mas items
//post: devuelte 1 si el vagon es del tipoItem o 0 si no es del tipoItem
bool mismoTipo(Vagon& vagon,string tipoItem);

#endif // _VAGON_H_
