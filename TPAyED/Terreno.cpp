#include "Terreno.h"

using namespace std;

/************GETTERS AND SETTERS*********************/

//getters y setters
void setLocomotora(Vagon& vagon,int pesoMaximo){}

int getPesoMaximo(Vagon& vagon){}
/*

crearTerreno(Terreno& terreno, int alto, int ancho){
    aparecerLocomotora(terreno);
    get
}

*/

void crearTerreno(Terreno& terreno){
    //INICIALIZO MATRIZ DE JUEGO
    terreno.intervaloActual = 0;

    for(int i=0; i++; i< ANCHO_TERRENO){
        for(int j=0; j++; j< ALTO_TERRENO){
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

}

void eliminarTerreno(Terreno& terreno){}

void aparecerLocomotora(Terreno& terreno){}

void aparecerMina(Terreno& terreno){}

void aparecerEstacion(Terreno& terreno){}

void aparecerMoneda(Terreno& terreno){
    //obtengo moneda si corresponde en intervalo, la agrego a la matriz e elimino
    NodoLista * ptrNodo = primero(terreno.monedas);
    bool eliminarNodoMoneda = false;
     //Como la lista de monedas tiene orden en la aparicion la que aparecera va a ser la primera siempre
     //PERO TENGO Q RECORRER PARA SABER CUANDO SE LLEGA AL FINAL DEL TIEMPO
    while(!listaVacia(terreno.monedas) && ptrNodo != finLista()){
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
        ptrNodo = siguiente(terreno.monedas, ptrNodo);
        if (eliminarNodoMoneda){
            eliminarNodo(terreno.monedas, ptrNodoActual);
            eliminarNodoMoneda = false;
        }
    }
}

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

//YA esta todo cargado, hay q actualizar
void actualizarTerreno(Terreno& terreno, int sentido){
    //Actualizar minas
    nuevaProduccionMinas(terreno);
    //actualizar bandido //chequea si tiene q aparecer un bandido (el primero de lalista)
    aparecerBandido(terreno);
    //actualizar monedas //chequea si tiene q aparecer una moneda (el primero de lalista)
    aparecerMoneda(terreno);
    //avanzarLocomotora -> ACTUAR SI POSICION DE LOCOMOTORA O VAGONES ESTA EN ZONA DE CONFLI
    actualizarMatrizJuego(terreno);
    ////ACTUALIZAR EN MATRIZ SI APARECIO BANDIDO O MONEDA
    avanzarLocomotora(terreno, sentido);
    //REVISAR CAMBIOS
    chequearColisiones(terreno);
}

void avanzarLocomotora(Terreno &terreno, int sentido){
    // veo en posicon q avanza locomotora si tengo algo en matriz
    //

}

void chequearColisiones(Terreno & terreno){
    Posicion posLocomotora = getPosicion(terreno.locomotora);
    if (getX(posLocomotora) > ANCHO_TERRENO || getY(posLocomotora) > ALTO_TERRENO){
        terreno.estadoJuego = GAMEOVER; // SI SALGO DEL CUADRADO TERMINA JUEGO
    }
    else{
        //VERIFICO INTERSECCION
        //E=ESTACION, M=MINAS, L=LOCOMOTORA,B=BANDIDOS, m=MONEDAS,T=TERRENO VACIO
        if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'E'){
            NodoLista * ptrNodo = primero(terreno.estaciones);;
            Estacion * estacionActual = (Estacion*) ptrNodo->ptrDato;
            while(! listaVacia(terreno.estaciones) && ptrNodo != finLista()){
                Posicion posEstacion = getPosicion(*estacionActual);
                if (mismaPosicion(posEstacion, posLocomotora)){
            //SI ES MISMA ESTACION -> VENDO VAGON
                    int capacidadVagon = entregarVagon((*estacionActual), getMonedasAdquiridas(terreno.locomotora));
                    if (capacidadVagon > 0){
                    agregarVagon(terreno.locomotora, capacidadVagon);
                }
            }
            ptrNodo = siguiente(terreno.estaciones, ptrNodo);
            Estacion * estacionActual = (Estacion*) ptrNodo->ptrDato;
            terreno.estadoJuego = LOCOMOTORADETENIDA; // DETENGO LOCOMOTORA
        }

        }
        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'M'){
            //obtengo minas si es posible o eliminoproduccion si no tengo capacidad
        }
        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'B'){
            //Peleo contra bandido
        }
        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'm'){
            //obtengo monedas
        }
        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'T'){
            //no tengoque hacer nada ya avanzo locomotora
            //PENSAR SI VA ACA O AFUERA -> TIene q ir afuera para que cuando en el juego
            //se toca la tecla para avanzar avance antes de verificar posicion
        }
    }

}

