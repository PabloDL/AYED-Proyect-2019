#include "Terreno.h"

/************GETTERS AND SETTERS*********************/

//getters y setters
void setLocomotora(Vagon& vagon,int pesoMaximo){}

int getPesoMaximo(Vagon& vagon){}

void crearTerreno(Terreno& terreno){}

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

