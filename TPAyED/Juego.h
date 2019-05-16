#ifndef Juego_h
#define Juego_h

#include "SDL.h"
#include <iostream>

using namespace std;

typedef struct Juego{
    bool estaCorriendo;
    SDL_Window *ventana;
    SDL_Renderer *renderizador;
}Juego;

void crearJuego(Juego &juego);
void eliminarJuego(Juego &juego);
void inicializar(Juego &juego, const char* title, int xpos, int ypos, int width, int height);
void manejarEventos(Juego &juego);
void actualizar(Juego &juego);
void renderizar(Juego &juego);
void limpiar(Juego &juego);

bool corriendo(Juego &juego);



#endif // Game_h
