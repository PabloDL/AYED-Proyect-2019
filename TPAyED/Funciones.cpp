#include "Funciones.h"
#include "Mina.h"
#include "Terreno.h"

ResultadoComparacion compararListaMinas(PtrDato ptrDato1, PtrDato ptrDato2) {
    int dato1 = ((Mina*) ptrDato1)->codItem;
    int dato2 = ((Mina*) ptrDato2)->codItem;

    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}

void eliminarMinasDeLista(PtrDato ptrDato) {
    Mina minaAEliminar = *((Mina*) ptrDato);
    eliminarMina(minaAEliminar);
}

void imprimirListaMinas(Lista &l){
        /// Recorro la lista
     if(!listaVacia(l)){
        PtrNodoLista nodo = primero(l);
        while(nodo != finLista()){
            Mina mina = *((Mina*)(nodo->ptrDato));
            cout << mina.codItem << "|" << mina.IP << "|" << mina.posX << "|" << mina.posY << "|" << mina.seq1 << "|" << mina.seq1 << "|" << mina.seq2 << "|" << mina.seq3  << "|" << mina.seq4  << "|" << mina.seq5 << endl;
            nodo = siguiente(l, nodo);
        }

    }
}
//
//ResultadoComparacion compararListaEstaciones(PtrDato ptrDato1, PtrDato ptrDato2) {
//    int dato1 = ((Estacion*) ptrDato1)->id;
//    int dato2 = ((Estacion*) ptrDato2)->id;
//
//    if (dato1 < dato2) {
//        return MENOR;
//    }else if (dato1 > dato2) {
//        return MAYOR;
//    }else{
//        return IGUAL;
//    }
//}
//
//void eliminarEstacionDeLista(PtrDato ptrDato) {
//    Estacion estacionAEliminar = *((Estacion*) ptrDato);
//    eliminarEstacion(estacionAEliminar);
//}
//
//ResultadoComparacion compararListaMonedas(PtrDato ptrDato1, PtrDato ptrDato2) {
//    int dato1 = ((Moneda*) ptrDato1)->id;
//    int dato2 = ((Moneda*) ptrDato2)->id;
//
//    if (dato1 < dato2) {
//        return MENOR;
//    }else if (dato1 > dato2) {
//        return MAYOR;
//    }else{
//        return IGUAL;
//    }
//}
//
//void eliminarMonedaDeLista(PtrDato ptrDato) {
//    Moneda monedaAEliminar = *((Moneda*) ptrDato);
//    eliminarMoneda(monedaAEliminar);
//}
//
//
//ResultadoComparacion compararListaBandidos(PtrDato ptrDato1, PtrDato ptrDato2) {
//    int dato1 = ((Bandido*) ptrDato1)->id;
//    int dato2 = ((Bandido*) ptrDato2)->id;
//
//    if (dato1 < dato2) {
//        return MENOR;
//    }else if (dato1 > dato2) {
//        return MAYOR;
//    }else{
//        return IGUAL;
//    }
//}
//
//void eliminarBandidoDeLista(PtrDato ptrDato) {
//    Bandido bandidoAEliminar = *((Bandido*) ptrDato);
//    eliminarBandido(bandidoAEliminar);
//}

