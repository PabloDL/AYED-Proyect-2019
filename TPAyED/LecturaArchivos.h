#ifndef __LECTURAARCHIVOS_H__
#define __LECTURAARCHIVOS_H__

#include<iostream>
#include <fstream>
#include <sstream>

#include "Parametros.h"
#include "Comanda.h"
#include "Mina.h"

using namespace std;

typedef struct Lector{
    fstream ficheroEntrada;
}Lector;

/*
PRE: Lector no existente
Post: se reserva memoria para lector
*/
void crearLector(Lector & lector);

/*
PRE: Lector creado
Post: Archivo abierto y asignado a lector, devuelvo 0 si no puede abrir archivo
*/
void abrirArchivo(Lector & lector, string nombreArchivo);

/*
PRE: Lector creado y archivo abierto
Post: se devuelve linea siguiente de archivo, o EOF en caso de fin de archivo
*/
Parametros leerArchivoParametros(Lector & lector);
/*
PRE: Lector creado y archivo abierto  /// ACA TIENE Q DEVOLVER UNA LISTA
Post: se devuelve linea siguiente de archivo, o EOF en caso de fin de archivo
*/
Comanda leerArchivoComandas(Lector & lector);
/*
PRE: Lector creado y archivo abierto
Post: se devuelve linea siguiente de archivo, o EOF en caso de fin de archivo  /// ACA TIENE Q DEVOLVER UNA LISTA
*/
Mina leerArchivoMinas(Lector & lector);

/*
PRE: Lector creado y archivo abierto
Post: devuelve true si es fin o false caso contrario
*/
bool esFinDeArchivo(Lector & lector);

/*
PRE: Lector existente
Post: se libera memoria para lector
*/
void eliminarLector(Lector & lector);

#endif // __LECTURAARCHIVOS_H__
