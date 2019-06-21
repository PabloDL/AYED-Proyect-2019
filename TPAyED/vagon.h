#ifndef _VAGON_H_
#define _VAGON_H_

#include "Lista.h"
#include "Posicion.h"
#include "Cajas.h"
#include "Locomotora.h"
#include "SDL_image.h"
/*********************Axiomas********************/
//capacidadVagon = 5kg * cantMonedas
//el vagon incia con tipoVagon 'SIN DEFINIR' hasta que se le agregue una CAJA
//el vagon solo puede almacenar CAJAS de su mismo tipo(item)
/***************getters y setters******************/
typedef struct Vagon{
    int capVagon; //capacidad del Vagon
    int capVagonUsada; //para poder saber cuanto se uso de la capacidadMaxima
    string tipoVagon; //podra ser ORO,PLATA,BRONCE,ETC
    Posicion posicion;
    int velocidadV;
    int direccion;
    Lista listaCajas;//lista cajas
    SDL_Texture *texturas [40];
    SDL_Rect rectImag;
}Vagon;
/**************GETTERS AND SETTERS *********************/
void setCapVagon(Vagon& vagon,int capVagon);
void setCapVagonUsada(Vagon& vagon,int capVagonUsada);
void setVelocidadV(Vagon& vagon,int velocidadV);
void setPosicion(Vagon& vagon,Posicion& posicion);
void setTipoVagon(Vagon& vagon,string tipoVagon);
void setDireccion(Vagon& vagon, int direccion);

int getCapVagon(Vagon& vagon);
int getCapVagonUsada(Vagon& vagon);
int getVelocidadV(Vagon& vagon);
string getTipoVagon(Vagon& vagon);
Posicion getPosicion(Vagon& vagon);
int getDireccion(Vagon &vagon);
/**************GETTERS AND SETTERS *********************/
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


void cargarTexturaVagon(Vagon& vagon, SDL_Renderer * renderizador);
void renderizarVagon(Vagon& vagon, SDL_Renderer *renderizador, int counter, bool estaDetenida);

#endif // _VAGON_H_
