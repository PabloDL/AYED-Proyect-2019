#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "LecturaArchivos.h"
#include "Juego.h"

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

//        if(SDL_Init(SDL_INIT_EVERYTHING)>=0){
//            SDL_ShowSimpleMessageBox(
//            SDL_MESSAGEBOX_INFORMATION,
//            "OK",
//            "SDL esta ok",
//            NULL);
//        }

    //-------------------------------------------------------------------------------------------
        const int FPS = 60;
        const int FrameDelay = 100/FPS;

        Juego juego;
        crearJuego(juego);
        inicializar(juego, "Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

        while(corriendo(juego)){
            manejarEventos(juego);
            actualizar(juego);
            renderizar(juego);
        }
        salirJuego(juego);
    return 0;
}
