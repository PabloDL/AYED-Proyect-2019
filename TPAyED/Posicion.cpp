#include "Posicion.h"

/************GETTERS AND SETTERS*********************/
int getX(Posicion &posicion){
    return posicion.x;
}

int getY(Posicion &posicion){
    return posicion.y;
}

void setX(Posicion &posicion, int x){
    posicion.x = x;
}

void setY(Posicion &posicion, int y){
    posicion.y = y;
}
/***************************************************/

void crearPosicion(Posicion &posicion){
    posicion.x = 0;
    posicion.y = 0;
}
void eliminarPosicion(Posicion &posicion){

}
void moverPosicion(Posicion &posicion, int x, int y){
    posicion.x = x;
    posicion.y = y;
}
bool esValidaPosicion(Posicion &posicion){ // ES DE TERRENO AL PARECER
}

