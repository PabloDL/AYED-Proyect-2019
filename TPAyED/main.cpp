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
        Juego juego;
        crearJuego(juego);
        inicializar(juego,"Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

        while(corriendo(juego)){
            manejarEventos(juego);
            actualizar(juego);
            renderizar(juego);
        }



    //const char WindowTitle []= "Game";
        SDL_Init(SDL_INIT_EVERYTHING);

        SDL_Window *window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

        SDL_SetRenderDrawColor(renderer, 150, 100, 100, 255);

        SDL_RenderClear(renderer);

        SDL_Delay(5000);

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"OK","SDL esta ok",NULL);




    return 0;
}
