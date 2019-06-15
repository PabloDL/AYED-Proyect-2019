#include "Vagon.h"
#include "Funciones.h"

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
Posicion getPosicion(Vagon& vagon){
    return vagon.posicion;
}
/*******************Primitivas************************/
void crearVagon(Vagon& vagon){
    vagon.capVagon = 1; //por defecto la capacidad del vagon es 1
    vagon.capVagonUsada = 0; //logicamente el vagon va a estar vacio al crearse
    vagon.tipoVagon = "SIN DEFINIR"; //por defecto al crearse el vagon va a estar vacio y entonces su tipo esta indefinido
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

void cargarTexturaVagon(Vagon& vagon, SDL_Renderer * renderizador){
    vagon.textura = IMG_LoadTexture(renderizador, "assets/img/c2/arr/0.png");
}

void renderizarVagon(Vagon& vagon, SDL_Renderer *renderizador){
        Posicion p = getPosicion(vagon);
        vagon.rectImag.x = getX(p)*40;
        vagon.rectImag.y = getY(p)*40;
        vagon.rectImag.w = 40;
        vagon.rectImag.h = 40;
        SDL_RenderCopy(renderizador, vagon.textura, NULL, &vagon.rectImag);
}
