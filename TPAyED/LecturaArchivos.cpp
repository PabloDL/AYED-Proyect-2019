#include "LecturaArchivos.h"


void crearLector(Lector & lector){
}

void abrirArchivo(Lector & lector, string nombreArchivo){
    lector.ficheroEntrada.open(nombreArchivo, ios::in);
}

Parametros leerArchivoParametros(Lector & lector){
    Parametros parametros;
    string parametro;
    string dato;
    if (lector.ficheroEntrada.is_open()) {
        while (!lector.ficheroEntrada.eof()){
        getline(lector.ficheroEntrada,parametro, '=');
        getline(lector.ficheroEntrada,dato);
        cout << "Parametro: " << parametro << " dato : " << dato << endl;
        }
    }
    return parametros;
}
/*
PRE: Lector creado y archivo abierto  /// ACA TIENE Q DEVOLVER UNA LISTA
Post: se devuelve linea siguiente de archivo, o EOF en caso de fin de archivo
*/
Comanda leerArchivoComandas(Lector & lector){
    Comanda comanda;
    string codItem;
    string cantidad;

    if (lector.ficheroEntrada.is_open()) {
        while (!lector.ficheroEntrada.eof()){
            getline(lector.ficheroEntrada,codItem, ';');
            getline(lector.ficheroEntrada,cantidad);
            stringstream  issCod(codItem);
            issCod >> comanda.codItem;
            stringstream iss (cantidad);
            iss >> comanda.cantidad;
            cout << "coditem: " << codItem << " cantidad : " << cantidad << endl;
        }
    }
    return comanda;
}
/*
PRE: Lector creado y archivo abierto
Post: se devuelve linea siguiente de archivo, o EOF en caso de fin de archivo  /// ACA TIENE Q DEVOLVER UNA LISTA
*/
Mina leerArchivoMinas(Lector & lector){
    Mina mina;
    string posX,posY,codItem,IP,seq1,seq2,seq3,seq4,seq5;

    if (lector.ficheroEntrada.is_open()) {
        while (!lector.ficheroEntrada.eof()){
            getline(lector.ficheroEntrada,posX, ';');
            getline(lector.ficheroEntrada,posY, ';');
            getline(lector.ficheroEntrada,codItem, ';');
            getline(lector.ficheroEntrada,IP, ';');
            getline(lector.ficheroEntrada,seq1, ';');
            getline(lector.ficheroEntrada,seq2, ';');
            getline(lector.ficheroEntrada,seq3, ';');
            getline(lector.ficheroEntrada,seq4, ';');
            getline(lector.ficheroEntrada,seq5);
            stringstream  issPosX(posX); issPosX >> mina.posX;
            stringstream  issPosY(posY); issPosY >> mina.posY;
            stringstream  issCod(codItem); issCod >> mina.codItem;
            stringstream  issIP(IP); issIP >> mina.IP;
            stringstream  issSeq1(seq1); issSeq1 >> mina.seq1;
            stringstream  issSeq2(seq2); issSeq2 >> mina.seq2;
            stringstream  issSeq3(seq3); issSeq3 >> mina.seq3;
            stringstream  issSeq4(seq4); issSeq4 >> mina.seq4;
            stringstream  issSeq5(seq5); issSeq5 >> mina.seq5;

            cout << "PosX: " << mina.posX << "PosY: " << mina.posY <<"coditem: " << mina.codItem
                << "SEQ: " << mina.seq1 << ";" <<mina.seq2<<";"<<mina.seq3<<";"<<mina.seq3<<";" << mina.seq4 << ";" << mina.seq5<< endl;
        }
    }
    return mina;
}

/*
PRE: Lector creado y archivo abierto
Post: devuelve true si es fin o false caso contrario
*/
bool esFinDeArchivo(Lector &lector){
    bool fin = (lector.ficheroEntrada).eof();
    return fin;
}

/*
PRE: Lector existente
Post: se libera memoria para lector
*/
void eliminarLector(Lector & lector){
    lector.ficheroEntrada.close(); //EN REALIDAD VA EN LECTOR
}
