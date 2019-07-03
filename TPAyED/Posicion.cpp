#include "Posicion.h"
#include "Terreno.h"

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

bool mismaPosicion(Posicion &posA, Posicion &posB){
    bool igual = false;
    if (posA.x == posB.x && posA.y == posB.y)
        igual = true;

    return igual;
}

bool enCercanias(Posicion &posA, Posicion &posB, int distancia){
    bool cercano = false;
    if ( (abs(getX(posA) - getX(posB)) <= distancia) &&  (abs(getY(posA) - getY(posB)) <= distancia)){
        cercano = true;
    }
    return cercano;
}

Posicion alejarPosicion(Posicion &posA,Posicion &posB, int distancia){
    Posicion pNueva;
    if ((abs(getX(posA) - getX(posB)) <= distancia+1)){
        if (getX(posA)+distancia < ANCHO_TERRENO){ //SI LA POS EN X TIENE LUGAR LO CORRO A LA DERECHA
            setX(pNueva,getX(posA)+distancia+2);
        }
        else
            setX(pNueva,getX(posA)-distancia-2);
    }
    else
        setX(pNueva, getX(posB));

    if ((abs(getY(posA) - getY(posB)) <= distancia+1)){
        if (getY(posA)+distancia < ALTO_TERRENO){ //SI LA POS EN X TIENE LUGAR LO CORRO A LA DERECHA
            setY(pNueva,getY(posA)+distancia+2);
        }
        else
            setY(pNueva,getX(posA)-distancia-2);
    }
    else
        setY(pNueva, getY(posB));

    return pNueva;
}
