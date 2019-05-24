
#include "Juego.h"

void crearJuego(Juego &juego, const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    juego.counter = 0;
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        std::cout << "subsistemas inicializados..." << std::endl;
        juego.ventana = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(juego.ventana){
            std::cout << "Ventana creada..." << std::endl;
        }
        juego.renderizador = SDL_CreateRenderer(juego.ventana, -1, 0);
        if(juego.renderizador){
            SDL_SetRenderDrawColor(juego.renderizador, 101, 255, 100, 255);
            std::cout << "Renderizador creado..." << std::endl;
        }
        juego.estaCorriendo = true;
    }
    else{
        juego.estaCorriendo = false;
    }
}

void salirJuego(Juego &juego){
    SDL_DestroyWindow(juego.ventana);
    SDL_DestroyRenderer(juego.renderizador);
    SDL_Quit();
    std::cout << "Se salio del Juego" << std::endl;
}

void manejarEventos(Juego &juego){
    SDL_Event evento;
    SDL_PollEvent(&evento);
    switch (evento.type){
        case SDL_QUIT:
            juego.estaCorriendo = false;
            break;
        default:
            break;
    }
}

void actualizar(Juego &juego){
    juego.counter++;
    //AGREGAR FUNCIONES PARA ACTUALIZAR OBJETOS

    std::cout << juego.counter << std::endl;
}

void renderizar(Juego &juego){
    SDL_RenderClear(juego.renderizador);
    //AGREGAR FUNCIONES PARA RENDERIZAR OBJETOS
    SDL_RenderPresent(juego.renderizador);
}

bool corriendo(Juego &juego){
    return juego.estaCorriendo;
}
