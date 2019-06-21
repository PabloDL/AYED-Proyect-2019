#include "Estacion.h"
/************GETTERS AND SETTERS*********************/
Posicion getPosicion(Estacion &estacion){
    return estacion.posicion;
}
void setPosicion(Estacion &estacion, Posicion posicion){
    moverPosicion(estacion.posicion, getX(posicion), getY(posicion));
}
/***************************************************/
void crearEstacion(Estacion &estacion){
    crearPosicion(estacion.posicion);
    moverPosicion(estacion.posicion, 0, 0);
    estacion.textura = NULL;
}

void eliminarEstacion(Estacion &estacion){
}

int entregarVagon(Estacion &estacion, int cantidadMonedas){
    return COFICIENTE_PESO_VAGON * cantidadMonedas;
}

void cargarTexturaEstacion(Estacion& estacion, SDL_Renderer * renderizador){
    if(estacion.textura == NULL){
        estacion.textura = IMG_LoadTexture(renderizador, "assets/img/estacion4.png");
    }
}

void renderizarEstacion(Estacion& estacionActual, SDL_Renderer *renderizador){
        Posicion p = getPosicion(estacionActual);
        estacionActual.rectImag.x = getX(p)*40;
        estacionActual.rectImag.y = getY(p)*40;
        estacionActual.rectImag.w = 40;
        estacionActual.rectImag.h = 40;
        SDL_RenderCopy(renderizador, estacionActual.textura, NULL, &estacionActual.rectImag);
}
