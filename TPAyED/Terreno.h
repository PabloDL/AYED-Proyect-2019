#ifndef Terreno_h
#define Terreno_h

#include <iostream>
#include "locomotora.h"
#include "Lista.h"
#include "vagon.h"
#include "Mina.h"
#include "Moneda.h"
#include "Estacion.h"

#include <SDL_image.h>


#define ANCHO_TERRENO 20
#define ALTO_TERRENO 20

using namespace std;

enum Estados{
    JUGABLE, GAMEOVER, LOCOMOTORADETENIDA
};

typedef struct Terreno{
    //int ancho;
    //int alto;
    Locomotora locomotora;
    Lista minas;
    Lista estaciones;
    Lista monedas;
    Lista bandidos;
    /* la matriz tiene:
    E=ESTACION, M=MINAS, L=LOCOMOTORA,B=BANDIDOS, m=MONEDAS,T=TERRENO VACIO  */
    char matrizJuego[ANCHO_TERRENO][ALTO_TERRENO];
    int intervaloActual; //cada vez entro a actualizarTerreno incremento intervalo actual
    Estados estadoJuego;
    SDL_Texture *texturas[10];
    SDL_Rect rectImag;
    int textureMap[ANCHO_TERRENO][ALTO_TERRENO];
}Terreno;
/*******************GETTERS Y SETTERS*******************/

//int getAncho(Terreno& terreno)
//void setAncho(Terreno& terreno)
//int getAlto(Terreno& terreno)
//void setAlto(Terreno& terreno)
void setLocomotora(Vagon& vagon,int pesoMaximo);

/***********************PRIMITIVAS*********************/
//pre:
//post: se inicializan los parametros de Terreno
void crearTerreno(Terreno& terreno);

//pre:Tiene que existir el terreno
//post:Se elimina el terreno en cascada con los atributos internos
//se usa al cerrar el juego
void eliminarTerreno(Terreno& terreno);

//pre:Terreno tiene que estar creado e inicializado
//post: se posiciona la locomotora en el terreno
void aparecerLocomotora(Terreno& terreno);

//pre: Terreno tiene que estar creado e inicializado
//post: se posiciona una mina en el terreno
void aparecerMina(Terreno& terreno);

//pre:Terreno tiene que estar creado e inicializado
//post:se posiciona una estacion en el terreno
void aparecerEstacion(Terreno& terreno);

//pre:Terreno tiene que estar creado e inicializado
//post:se posiciona una moneda checkeando si es posible en el terreno
void aparecerMoneda(Terreno& terreno);

//pre:Terreno tiene que estar creado e inicializado
//post: se posiciona una moneda checkeando si es posible en el terreno
void aparecerBandido(Terreno& terreno);

//pre:Terreno tiene que estar creado e inicializado
//post: se devuelve nueva produccion de mina
void nuevaProduccionMina(Terreno& terreno);
/*
PRIMERO SE ACTUALIZAN TODOS LOS COMPONENTES, SE ACTUALIZA JUEGO Y LUEGO SE AVANZA LOCOMOTORA PARA
CHEQUEAR SI CAMBIA ALGUN CONDICION DEL JUEGO Y SE MODIFICA SEGUN ESO
PRE: Terreno Creado y inicializado
POST: Terreno actualizado, con movimientos de locomotora yproducciones de minas, monedas  y bandidos
      SI ALGUNA DE LAS CONDICIONES DEL JUEGO CAMBIA MODIFICA VARIABLE ESTADO
*/
void actualizarTerreno(Terreno& terreno, int sentido);

//PRE: Terreno Creado y inicializado
//POST: Recore listas y redibuja si es necesario,
//      Matriz actualizada con nuevos movimientos, revisa colisiones y de ser necesario aplica cambios
void actualizarMatrizJuego(Terreno &terreno);

//PRE: Terreno Creado y inicializado
//POST: Avanza locomotora y sus vagones, verifica si algun vagon o la locomotora tienn una intercepciopn
//y en tal caso efectua accion
void avanzarLocomotora(Terreno &terreno, int sentido);

//PRE: Terreno Creado y inicializado, se debe llamar de actualizar terreno
//POST: verifica colisiones y actualiza estado matriz y actua en efecto
void chequearColisiones(Terreno& terreno);

void cargarTexturasTerreno(Terreno& terreno, SDL_Renderer& renderizador);

void renderizarTerreno(Terreno& terreno,SDL_Renderer &renderizador);

#endif // Terreno_h

