#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "LecturaArchivos.h"
#include "Lista.h"
#include "Funciones.h"
#include "Mina.h"


int main( int argc, char* argv[]){
    cout << "lectura Comanda" << endl;
    Lector lectorComanda;
    crearLector(lectorComanda);
    abrirArchivo(lectorComanda, "comanda.txt");
    leerArchivoComandas(lectorComanda);
    eliminarLector(lectorComanda);

    cout << "lectura Parametros" << endl;
    Lector lector;
    crearLector(lector);
    abrirArchivo(lector, "parametros.txt");
    leerArchivoParametros(lector);
    eliminarLector(lector);

    cout << "lectura Minas" << endl;
    Lector lectorMinas;
    crearLector(lectorMinas);
    abrirArchivo(lectorMinas, "minas.txt");
    leerArchivoMinas(lectorMinas);
    eliminarLector(lectorMinas);


    cout << "***************** prueba de lista de minas -> " << endl;
    Lista listaMinas;
    //CREO LISTA
    crearLista(listaMinas, compararListaMinas, eliminarMinasDeLista);
    //agrego elemento a lista
    Mina* m = new Mina;
    crearMina((*m));
    adicionarPrincipio(listaMinas, m);
    adicionarPrincipio(listaMinas, m);
    adicionarPrincipio(listaMinas, m);
    adicionarPrincipio(listaMinas, m);
    imprimirListaMinas(listaMinas);


    if(SDL_Init(SDL_INIT_EVERYTHING)>=0){
        SDL_ShowSimpleMessageBox(
        SDL_MESSAGEBOX_INFORMATION,
        "OK",
        "SDL esta ok",
        NULL);
    }



    return 0;
}
