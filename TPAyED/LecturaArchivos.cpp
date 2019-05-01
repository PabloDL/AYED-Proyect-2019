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
