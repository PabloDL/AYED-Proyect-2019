#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>

#include "LecturaArchivos.h"
#include "Juego.h"
#include "Lista.h"
#include "Funciones.h"
#include "Mina.h"
#include "Pruebas.h"

int main( int argc, char* argv[]){
    srand(time(NULL));

    /*PRUEBA AVANCE LOCOMOTORA*/
    //testAvanzarLocomotora();
    /*PRUEBA ARCHIVOS*/
    //testCargaDeArchivos();
    /*PRUEBA LISTA MINAS RECORRER*/
    //testListaMinas();
    /*PRUEBA COLISION CON BANDIDO*/
    testColisionBandido();

 //MAIN PRINCIPAL JUEGO
    /*
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

    return 0;
    */
}
