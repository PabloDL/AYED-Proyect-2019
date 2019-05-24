#include "Terreno.h"

/************GETTERS AND SETTERS*********************/

//getters y setters
void setLocomotora(Vagon& vagon,int pesoMaximo){}

int getPesoMaximo(Vagon& vagon){}

void crearTerreno(Terreno& terreno){
    //INICIALIZO MATRIZ DE JUEGO
    terreno.intervaloActual = 0;

    for(int i=0; i++; i<800){
        for(int j=0; j++; j<800){
            terreno.matrizJuego[i][j] = 'T';
        }
    }
    //Crea minas segun archivo Minas.h
    aparecerMina(terreno);
    //APARECERESTACION
    aparecerEstacion(terreno);
    //aparecer locomotora, ultima por si hay algo en su posicion lo creo en +1
    aparecerLocomotora(terreno);
    //crear moneda -> no tienen q aparecer inmediatamente
    aparecerMoneda(terreno);
    //CREAR bandido  -> no tienen q aparecer inmediatamente
    aparecerBandido(terreno);
    ////ACTUALIZAR EN MATRIZ POSICIONES DE ELEMENTOS
    actualizarMatrizJuego(terreno);
}

void actualizarMatrizJuego(Terreno &terreno){
    //obtengo moneda si corresponde en intervalo, la agrego a la matriz e elimino
    NodoLista * ptrNodo = primero(terreno.moneda);
    bool eliminarNodoMoneda = false;
     //Como la lista de monedas tiene orden en la aparicion la que aparecera va a ser la primera siempre
     //PERO TENGO Q RECORRER PARA SABER CUANDO SE LLEGA AL FINAL DEL TIEMPO
    while(!listaVacia(terreno.moneda) && ptrNodo != finLista()){
        Moneda * ptrMonedaActual = (Moneda*) ptrNodo->ptrDato;
        if ((getAparicion(*ptrMonedaActual)) == terreno.intervaloActual){
            Posicion p = getPosicion(*ptrMonedaActual);
            terreno.matrizJuego[getX(p)][getY(p)] = 'm';
        }
        if (getAparicion(*ptrMonedaActual) + getDuracion(*ptrMonedaActual) == terreno.intervaloActual){
                //Llego al final del tiempo de vida
                Posicion p = getPosicion(*ptrMonedaActual);
               terreno.matrizJuego[getX(p)][getY(p)] = 'T';
               eliminarNodoMoneda = true;
        }
        NodoLista * ptrNodoActual = ptrNodo;
        ptrNodo = siguiente(terreno.moneda, ptrNodo);
        if (eliminarNodoMoneda){
            eliminarNodo(terreno.moneda, ptrNodoActual);
            eliminarNodoMoneda = false;
        }
    }
    //HACER LO MISMO PARA BANDIDO
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
    //avanzarLocomotora -> ACTUAR SI POSICION DE LOCOMOTORA O VAGONES ESTA EN ZONA DE CONFLICTO
    //VER EN MATRIZ Q HAY EN POSICION
    //ACTUALIZAR MATRIZ CON NUEVAS POSICION DE LOCOMOTORA -> TENER EN CUENTA EL TIPO POSICION
}

void avanzarLocomotora(Terreno &terreno, int sentido){
    // veo en posicon q avanza locomotora si tengo algo en matriz
    //

}
