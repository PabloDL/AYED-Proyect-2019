#include "Vagon.h"

/**************Getters y Setters******************/
void setCapVagon(Vagon& vagon,int capVagon){
    vagon.capVagon = capVagon;
}
int getCapVagon(Vagon& vagon){
    return vagon.capVagon;
}

void setCapVagonUsada(Vagon& vagon,int capVagonUsada){
    vagon.capVagonUsada = capVagonUsada;
}
int getCapVagonUsada(Vagon& vagon){
    return vagon.capVagonUsada;
}

void setTipoVagon(Vagon& vagon,string tipoVagon){
    vagon.tipoVagon = tipoVagon;
}
string getTipoVagon(Vagon& vagon){
    return vagon.tipoVagon;
}

void setPosicion(Vagon& vagon,Posicion& posicion){
    moverPosicion( vagon.posicion, getX(posicion), getY(posicion) );
}
Posicion getPosicion(Vagon& vagon,Posicion& posicion){
    return vagon.posicion;
}
/*******************Primitivas************************/
void crearVagon(Vagon& vagon,int capVagon){
    vagon.capVagon = capVagon;
    vagon.capVagonUsada = 0; //logicamente el vagon va a estar vacio al crearse
    vagon.tipoVagon = "";
    vagon.velocidadV = velocidad;
    crearLista( vagon.listaCajas , compararListaCajas , eliminarCajaDeLista); //la lista de caja empieza valiendo null
}

bool vagonVacio(Vagon& vagon){
    return vagon.capVagonUsada == 0;
}

bool mismoTipo(Vagon& vagon , string item){
    return vagon.tipoVagon == item;
}

void eliminarVagon(Vagon& vagon){
    PtrNodoLista cursor = primero( vagon.listaCajas );
    PtrNodoLista previo = primero( vagon.listaCajas );

    while( !listaVacia(vagon.listaCajas) ){
        Cajas * ptrCaja = &( *((Cajas*)cursor->ptrDato) );
        vagon.listaCajas.destruye( ptrCaja );
        delete ptrCaja;

        previo = cursor;
        cursor = siguiente( vagon.listaCajas , cursor );
        eliminarNodo( vagon.listaCajas , previo);
    }
}
