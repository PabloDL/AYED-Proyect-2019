#include "Mina.h"

/************GETTERS AND SETTERS*********************/
int getPosX(Mina &mina) {return mina.posX;};
int getPosY(Mina &mina) {return mina.posY;};
int getCodItem(Mina &mina) {return mina.codItem;};
int getIp(Mina &mina) {return mina.IP;};
int getSeq1(Mina &mina){return mina.seq1;};
int getSeq2(Mina &mina){return mina.seq2;};
int getSeq3(Mina &mina){return mina.seq3;};
int getSeq4(Mina &mina){return mina.seq4;};
int getSeq5(Mina &mina){return mina.seq5;};

void setPosX(Mina &mina, int posX){mina.posX = posX;}
void setPosY(Mina &mina, int posY){mina.posY = posY;}
void setCodItem(Mina &mina, int codItem){mina.codItem = codItem;}
void setIp(Mina &mina, int ip){mina.IP = ip;}
void setSeq1(Mina &mina, int seq1){mina.seq1 = seq1;}
void setSeq2(Mina &mina, int seq2){mina.seq2 = seq2;}
void setSeq3(Mina &mina, int seq3){mina.seq3 = seq3;}
void setSeq4(Mina &mina, int seq4){mina.seq4 = seq4;}
void setSeq5(Mina &mina, int seq5){mina.seq5 = seq5;}

/***************************************************/

void crearMina (Mina &mina){
    mina.codItem = 1;

    mina.IP = 1;
    mina.posX = 1;
    mina.posY = 1;
    mina.seq1 = 1;
    mina.seq2 = 1;
    mina.seq3 = 1;
    mina.seq4 = 1;
    mina.seq5 = 1;

    mina.seqActual=1;

    crearCola(mina.cajas, eliminarCajaDeLista);
}

void eliminarMina (Mina &mina){
// --->>    eliminarCola();
}

//TIENE Q DEVOLVER STRING ESTA CONCEPTUALMENTE MAL
void toString(Mina &mina){
    cout << mina.posX << "|" << mina.posY << "|"  << mina.codItem << "|" << mina.IP << "|" << mina.seq1 << "|"
        << mina.seq2 << "|" << mina.seq3 << "|" << mina.seq3 << "|" << mina.seq4 << "|"
        << mina.seq5 << endl;
}

void crearCaja (Mina &mina){
    //dependiendo de la seguencia actual agrego lo que corresponda

    switch (mina.seqActual){
        case 1:
            // ->> encolar (mina.colacaja, mina.seq1);
             mina.seqActual++;

            break;
        case 2:
            // ->>  encolar (mina.colacaja, mina.seq2);
             mina.seqActual++;

            break;
        case 3:
             // ->> encolar (mina.colacaja, mina.seq3);
             mina.seqActual++;

            break;
        case 4:
            // ->> encolar (mina.colacaja, mina.seq4);
             mina.seqActual++;

            break;
        case 5:
            // ->> encolar (mina.colacaja, mina.seq5);
             mina.seqActual = 1;

            break;
    }


}

Cajas* proximaCaja(Mina &mina){
    Cajas * c = NULL;
    if (!colaVacia(mina.cajas)){
        PtrNodoCola ptrNodoCola = colaFrente(mina.cajas);
        c =  (Cajas*)ptrNodoCola->ptrDato;
    }
    return c;
}

void eliminarProduccion(Mina &mina){
    mina.cajas;
    eliminarCola(mina.cajas);
}
