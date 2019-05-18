#include "Funciones.h"
#include "Mina.h"

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
