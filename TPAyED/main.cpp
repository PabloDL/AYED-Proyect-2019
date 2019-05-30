#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>

#include "LecturaArchivos.h"
#include "Juego.h"
#include "Lista.h"
#include "Funciones.h"
#include "Mina.h"

int main( int argc, char* argv[]){
    srand(time(NULL));

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

    const int FPS = 60;
    const int FrameDelay = 100/FPS;
    Uint32 frameStart;
    int frameTime;




    Juego juego;
    crearJuego(juego, "Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(corriendo(juego)){
        frameStart = SDL_GetTicks();

        manejarEventos(juego);
        actualizar(juego);
        renderizar(juego);

        frameTime = SDL_GetTicks() - frameStart;
        if(FrameDelay > frameTime){
            SDL_Delay(FrameDelay - frameTime);
        }
    }
    salirJuego(juego);

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



//>>>>>>> master
    return 0;
}
