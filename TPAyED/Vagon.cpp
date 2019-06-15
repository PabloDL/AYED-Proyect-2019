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

void setDireccion(Vagon& vagon, int direccion){
    vagon.direccion = direccion;
}

int getDireccion(Vagon &vagon){
    return vagon.direccion;
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
    vagon.texturas[0] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/0.png");
    vagon.texturas[1] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/1.png");
    vagon.texturas[2] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/2.png");
    vagon.texturas[3] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/3.png");
    vagon.texturas[4] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/4.png");
    vagon.texturas[5] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/5.png");
    vagon.texturas[6] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/6.png");
    vagon.texturas[7] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/7.png");
    vagon.texturas[8] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/8.png");
    vagon.texturas[9] = IMG_LoadTexture(renderizador, "assets/img/c2/izq/9.png");

    vagon.texturas[10] = IMG_LoadTexture(renderizador, "assets/img/c2/der/0.png");
    vagon.texturas[11] = IMG_LoadTexture(renderizador, "assets/img/c2/der/1.png");
    vagon.texturas[12] = IMG_LoadTexture(renderizador, "assets/img/c2/der/2.png");
    vagon.texturas[13] = IMG_LoadTexture(renderizador, "assets/img/c2/der/3.png");
    vagon.texturas[14] = IMG_LoadTexture(renderizador, "assets/img/c2/der/4.png");
    vagon.texturas[15] = IMG_LoadTexture(renderizador, "assets/img/c2/der/5.png");
    vagon.texturas[16] = IMG_LoadTexture(renderizador, "assets/img/c2/der/6.png");
    vagon.texturas[17] = IMG_LoadTexture(renderizador, "assets/img/c2/der/7.png");
    vagon.texturas[18] = IMG_LoadTexture(renderizador, "assets/img/c2/der/8.png");
    vagon.texturas[19] = IMG_LoadTexture(renderizador, "assets/img/c2/der/9.png");

    vagon.texturas[20] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/0.png");
    vagon.texturas[21] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/1.png");
    vagon.texturas[22] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/2.png");
    vagon.texturas[23] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/3.png");
    vagon.texturas[24] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/4.png");
    vagon.texturas[25] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/5.png");
    vagon.texturas[26] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/6.png");
    vagon.texturas[27] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/7.png");
    vagon.texturas[28] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/8.png");
    vagon.texturas[29] = IMG_LoadTexture(renderizador, "assets/img/c2/arr/9.png");

    vagon.texturas[30] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/0.png");
    vagon.texturas[31] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/1.png");
    vagon.texturas[32] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/2.png");
    vagon.texturas[33] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/3.png");
    vagon.texturas[34] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/4.png");
    vagon.texturas[35] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/5.png");
    vagon.texturas[36] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/6.png");
    vagon.texturas[37] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/7.png");
    vagon.texturas[38] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/8.png");
    vagon.texturas[39] = IMG_LoadTexture(renderizador, "assets/img/c2/aba/9.png");
}

void renderizarVagon(Vagon& vagon, SDL_Renderer *renderizador, int counter){
    int index = counter%10;
    Posicion p = getPosicion(vagon);
    vagon.rectImag.x = getX(p)*40;
    vagon.rectImag.y = getY(p)*40;
    vagon.rectImag.w = 40;
    vagon.rectImag.h = 40;
    SDL_RenderCopy(renderizador, vagon.texturas[index+(vagon.direccion*10)], NULL, &vagon.rectImag);
}
