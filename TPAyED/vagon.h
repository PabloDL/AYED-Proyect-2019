#ifndef _vagon_h_
#define _vagon_h_

#include "posicion.h"
#include "Cajas.h"

enum item{//ITEMS
    ORO,PLATA,BRONCE,
    PLATINO,ROCA,CARBON,
    SIN_DEFINIR
};
typedef struct Vagon{
    int pesoMaximo;
    item tipoVagon;
    Posicion posicion;
    //Lista cajasAlmacenadas ?
}Vagon;
/*********************Axiomas********************/
//el vagon incia con tipoVagon SIN_DEFINIR
//el vagon inicia con un pesoMaximo definido por 5kg*cantMonedas
//el vagon solo puede almacenar items de su mismo tipo

/***********************Primitivas*********************/
//getters y setters
void setPesoMaximo(Vagon& vagon,int pesoMaximo);
int getPesoMaximo(Vagon& vagon);

void setTipoVagon(Vagon& vagon,item tipoVagon);
item getTipoVagon(Vagon& vagon);

void setPosicion(Vagon& vagon,Posicion posicion);
Posicion getPosicion(Vagon& vagon,Posicion posicion);

//pre:
//post: se inicializan los parametros de Vagon
void crearVagon(Vagon& vagon);

//pre:vagon creado
//post:se liberan los recursos usados en Vagon
void eliminarVagon(Vagon& vagon);

//pre:vagon creado
//post:el vagon se movera en base a los eventos que genera la locomotora
void avanzar(Vagon& vagon,Posicion& posicion);

//pre: vagon creado y con capMaxima total disponible o el (tipoVagon tiene que ser el mismo que caja
//     y tener suficiente capacidad para poder almacenarlo)
//post: guarda una caja en un vagon,si no se cumple ni una de las 2 condiciones anteriores no hace nada
void almacenarItem(Vagon& vagon,Cajas& caja);

//pre:Vagon creado
//post; devuelve '1' si el vagon esta vacio osea si no tiene ni un item o '0' si no esta vacio
bool vagonVacio(Vagon& vagon);

//pre: vagon creado y asignado con 1 o mas items
//post: devuelte 1 si el vagon es del tipoItem o 0 si no es del tipoItem
bool esVagonTipo(Vagon& vagon,item tipoItem);

#endif // _vagon_h_
