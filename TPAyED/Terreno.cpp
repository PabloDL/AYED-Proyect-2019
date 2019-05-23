#include "Terreno.h"

/************GETTERS AND SETTERS*********************/

//getters y setters
void setLocomotora(Vagon& vagon,int pesoMaximo){}

int getPesoMaximo(Vagon& vagon){}

void crearTerreno(Terreno& terreno){
    //INICIALIZO MATRIZ DE JUEGO
    for(int i=0; i++; i<800){
        for(int j=0; j++; j<800){
            terreno.matrizJuego[i][j] = 'T';
        }
    }
    //Aparcer minas
    //APARECERESTACION
    //aparecer locomotora, ultima por si hay algo en su posicion lo creo en +1
    //crear moneda -> no tienen q aparecer inmediatamente
    //CREAR bandido  -> no tienen q aparecer inmediatamente
    ////ACTUALIZAR EN MATRIZ POSICIONES DE ELEMENTOS
}

void eliminarTerreno(Terreno& terreno){}

void aparecerLocomotora(Terreno& terreno){}

void aparecerMina(Terreno& terreno){}

void aparecerEstacion(Terreno& terreno){}

void aparecerMoneda(Terreno& terreno){}

void aparecerBandido(Terreno& terreno){}

void nuevaProduccionMinas(Terreno& terreno){
    //Recorro las listas de minas y agrego un item a cada elemento
    NodoLista * ptrNodo = primero(terreno.minas);;
    Mina * minaActual = (Mina*) ptrNodo->ptrDato;
    while(! listaVacia(terreno.minas) && ptrNodo != finLista()){
        crearCaja(*minaActual); //Agrego caja a mina Actual
        ptrNodo = siguiente(terreno.minas, ptrNodo);
        Mina * minaActual = (Mina*) ptrNodo->ptrDato;
    }
}

void actualizarTerreno(Terreno& terreno, int sentido){
    //Actualizar minas
    //actualizar bandido //chequea si tiene q aparecer un bandido (el primero de lalista)
    //actualizar monedas //chequea si tiene q aparecer una moneda (el primero de lalista)
    ////ACTUALIZAR EN MATRIZ SI APARECIO BANDIDO O MONEDA
    //actualizarlocomotora(int sentido)
    //VER EN MATRIZ Q HAY EN POSICION
    //ACTUAR SI POSICION DE LOCOMOTORA O VAGONES ESTA EN ZONA DE CONFLICTO
    //ACTUALIZAR MATRIZ CON NUEVAS POSICION DE LOCOMOTORA -> TENER EN CUENTA EL TIPO POSICION
}
