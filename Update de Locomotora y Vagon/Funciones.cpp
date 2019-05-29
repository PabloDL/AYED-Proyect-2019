#include "Funciones.h"

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

/***************************************CAJAS**************************************/
ResultadoComparacion compararListaCajas(PtrDato ptrDato1, PtrDato ptrDato2) {
    int dato1 = ((Cajas*) ptrDato1)->capMaxima;
    int dato2 = ((Cajas*) ptrDato2)->capMaxima;

    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}

void eliminarCajaDeLista(PtrDato ptrDato) {
    Cajas cajaAEliminar = *((Cajas*) ptrDato);
    //eliminarCaja(cajaAEliminar);
}

void imprimirListaCajas(Lista &l){
        /// Recorro la lista de Cajas
     if(!listaVacia(l)){
         int c = 0;
        PtrNodoLista nodo = primero(l);
        while(nodo != finLista()){
            Cajas caja = *((Cajas*)(nodo->ptrDato));
            cout<<"Caja "<< c << "-> ";
            cout<< "TipoCaja: "<<caja.codItem << " -> Capacidad: " << caja.capActual << "/" << caja.capMaxima << endl;
            nodo = siguiente(l, nodo);
            c++;
        }

    }
}

/*********************************************VAGONES******************************************/
ResultadoComparacion compararListaVagones(PtrDato ptrDato1 , PtrDato ptrDato2){
    int dato1 = ((Vagon*) ptrDato1)->capVagon;
    int dato2 = ((Vagon*) ptrDato2)->capVagon;

    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}

void eliminarVagonesDeLista(PtrDato ptrDato){
    Vagon vagonAEliminar = *((Vagon*) ptrDato);
    eliminarVagon(vagonAEliminar);
}

void imprimirListaVagones(Lista& l){
    if(!listaVacia(l)){
            int c = 0; //para saber en que vagon estoy, siempre empiezo de 0
            PtrNodoLista nodo = primero(l);
            while(nodo != finLista()){
                cout<< "********************************************\n";
                Vagon vagon = *((Vagon*)nodo->ptrDato);
                cout<<"Vagon "<< c <<" -> ";
                cout<< "Tipo Vagon: "<<vagon.tipoVagon << " -> Capacidad: " << vagon.capVagonUsada << "/"<< vagon.capVagon << endl;
                imprimirListaCajas( vagon.listaCajas );
                nodo = siguiente(l, nodo);
                cout<<"\n";
                c++;
            }
    }
}
