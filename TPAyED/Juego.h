#ifndef Juego_h
#define Juego_h

#include "SDL.h"
#include <iostream>

using namespace std;

typedef struct Juego{
    bool estaCorriendo;
    SDL_Window *ventana;
    SDL_Renderer *renderizador;
    int counter;
}Juego;

/*
PRE: Juego no existe
Post:
*/
void crearJuego(Juego &juego);

/*
PRE: el juego tiene que estar inicializado
Post: libera la memoria al destruir los tda
*/
void salirJuego(Juego &juego);

/*
PRE: juego creado
Post: se inicializan los atributos del juego
*/
void inicializar(Juego &juego, const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

/*
PRE: Juego inicializado
Post:Se manejan los eventos (eventos de teclado,etc)del juego
*/
void manejarEventos(Juego &juego);

/*
PRE: Juego inicializado
Post:Se ejecutan las funciones de actualizacion de los estados (posicion, velocidad, acciones)de cada uno de los TDA que corresponda
*/
void actualizar(Juego &juego);

/*
PRE: Juego inicializado
Post: Se ejecutan las funciones de renderizado de cada uno de los TDA que correspondan
*/
void renderizar(Juego &juego);

/*
PRE: Juego inicializado
Post: retorna el estado activo o no del juego
*/
bool corriendo(Juego &juego);

#endif // Game_h
