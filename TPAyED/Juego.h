#ifndef Juego_h
#define Juego_h

#include <iostream>
#include "Terreno.h"
#include "SDL.h"

using namespace std;

typedef struct Juego{
    Terreno *terreno;
    bool estaCorriendo;
    SDL_Window *ventana;
    SDL_Renderer *renderizador;
    int counter;
}Juego;
/*GETTERS Y SETTERS*/

Terreno* getTerreno(Juego& juego);
/*
PRE: Juego no existe
Post:  se inicializan los atributos del juego
*/
void crearJuego(Juego &juego, const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

/*
PRE: el juego tiene que estar inicializado
Post: libera la memoria al destruir los tda
*/
void salirJuego(Juego &juego);

/*
PRE: Juego inicializado
Post:Se manejan los eventos (eventos de teclado,etc)del juego
*/
void manejarEventos(Juego &juego, SDL_Event & evento);

/*
PRE: Juego inicializado
Post:Se ejecutan las funciones de actualizacion de los estados (posicion, velocidad, acciones)de cada uno de los TDA que corresponda
*/
void actualizar(Juego &juego);

/*
PRE: Juego inicializado
Post: Se ejecutan las funciones de renderizado de cada uno de los TDA que correspondan
*/
void renderizar(Juego &juego, int renderIndex);


/*
PRE: Juego inicializado
Post: Se ejecutan las funciones de renderizado de cada uno de los TDA que correspondan
*/
void chequearEstado(Juego &juego);

/*
PRE: Juego inicializado
Post: Se ejecutan las funciones de renderizado de cada uno de los TDA que correspondan
*/
void renderizarMinas(Juego &juego);

/*
PRE: Juego inicializado
Post: Se ejecutan las funciones de renderizado de cada uno de los TDA que correspondan
*/
void renderizarMonedas(Juego &juego);

/*
PRE: Juego inicializado
Post: Se ejecutan las funciones de renderizado de cada uno de los TDA que correspondan
*/
void renderizarEstaciones(Juego &juego);

/*
PRE: Juego inicializado
Post: Se ejecutan las funciones de renderizado de cada uno de los TDA que correspondan
*/
void renderizarBandidos(Juego &juego);

/*
PRE: Juego inicializado
Post: Se ejecutan las funciones de renderizado de cada uno de los TDA que correspondan
*/
void renderizarvagones(Juego &juego, int counter, bool estaDetenida);

/*
PRE: Juego inicializado
Post: retorna el estado activo o no del juego
*/
bool corriendo(Juego &juego);


void cargarTexturas(Juego &juego);

void chequearEstado(Juego &juego);

#endif // Game_h
