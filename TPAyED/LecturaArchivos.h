#ifndef __LECTURAARCHIVOS_H__
#define __LECTURAARCHIVOS_H__

#include<iostream>
#include <fstream>
#include <sstream>

#include "Parametros.h"
#include "Comanda.h"
#include "Mina.h"

using namespace std;
/*
    Definicicion de tipo de dato Lector para manejo de Archivos en proyecto
    Atributos:
    * fichero

    Axiomas
    * Existen tres tipos de archivos Paramatros.txt,Comanda.txt, Minas.txt
    * Los archivos estan creados con las estructuras correctas, no hay datos erroneos
*/

/* Tipo de estructura del Lector */
typedef struct Lector{
    fstream ficheroEntrada;
}Lector;

/*
PRE: Lector no existente
Post:
*/
void crearLector(Lector & lector);
/*
PRE: Lector creado
Post: si Archivo abierto y asignado a lector, devuelve true
      si error al abrir devuelve false
*/
bool abrirArchivo(Lector & lector, string nombreArchivo);
/*
PRE: Lector creado y archivo abierto
Post: Cierra archivo
*/
void cerrarArchivo(Lector & lector);
/*
PRE: Lector creado y archivo abierto sin errores, SE ESTA LEYENDO UN ARCHIVO DE PARAMETROS
Post: se devuelve instancia de Parametros con valores cargados
*/
Parametros leerArchivoParametros(Lector & lector);
/*
PRE: Lector creado y archivo abierto  SE ESTA LEYENDO UN ARCHIVO DE COMANDAS /// ACA TIENE Q DEVOLVER UNA LISTA
Post: se devuelve lista con instancias de Comandas con valores cargados
*/
Comanda leerArchivoComandas(Lector & lector);
/*
PRE: Lector creado y archivo abierto  SE ESTA LEYENDO UN ARCHIVO DE MINAS /// ACA TIENE Q DEVOLVER UNA LISTA
Post: se devuelve lista con instancias de Comandas con valores cargados
*/
Lista leerArchivoMinas(Lector & lector);
/*
PRE: Lector creado y archivo abierto
Post: devuelve true si es fin o false caso contrario
*/
bool esFinDeArchivo(Lector & lector);
/*
PRE: Lector existente
Post:
*/
void eliminarLector(Lector & lector);

#endif // __LECTURAARCHIVOS_H__
