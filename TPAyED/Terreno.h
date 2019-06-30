#ifndef Terreno_h
#define Terreno_h

#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LecturaArchivos.h"
#include "locomotora.h"
#include "Lista.h"
#include "vagon.h"
#include "Mina.h"
#include "Moneda.h"
#include "Estacion.h"
#include "Bandido.h"
#include "Funciones.h"
#include "Parametros.h"

#define ANCHO_TERRENO 20
#define ALTO_TERRENO 15

using namespace std;
/*
Definicion de tipo de dato Terreno que contendra la logica de la aplicacion
    Axiomas
    * El juego tiene solo tres estados posibles (enum Estados)
    * Existen los archivos y estan adecuadamente en la carpeta donde se buscan
    * en la matriz solo pueden haber los elementos que se indican
*/
/* Tipo de estructura de Bandido */
enum Estados{
    JUGABLE, GAMEOVER, LOCOMOTORADETENIDA, GAMEOVER_FUERALIMITES, GAMEOVER_BANDIDO
};
typedef struct Terreno{
    Parametros parametros; //INICIALIZADO EN SET PARAMETROS
    Lista objetivoJuego;
    int intervalosAparicionProximaMoneda;
    int intervalosAparicionProximoBandido;
    Locomotora locomotora;
    Lista minas;
    Lista estaciones;
    Lista monedas;
    Lista bandidos;
    /* la matriz tiene:
    E=ESTACION, M=MINAS, L=LOCOMOTORA,B=BANDIDOS, m=MONEDAS,T=TERRENO VACIO  */
    char matrizJuego[ANCHO_TERRENO][ALTO_TERRENO];
    int intervaloActual;
    Estados estadoJuego;
    SDL_Texture *texturas[10];
    SDL_Rect rectImag;
    int textureMap[ANCHO_TERRENO][ALTO_TERRENO];

    TTF_Font* Sans ;
    SDL_Color White ;
    SDL_Surface* surfaceMessage ;
    SDL_Texture* Message;

}Terreno;
/*******************GETTERS Y SETTERS*******************/
void setLocomotora(Terreno & terreno, Locomotora & locomotora);
Locomotora getLocomotora(Terreno & terreno);
Lista* getBandidos(Terreno & terreno);
void setBandidos(Terreno & terreno, Lista& bandidos);
Lista* getMonedas(Terreno & terreno);
void setMonedas(Terreno & terreno, Lista& monedas);
Estados getEstado(Terreno & terreno);
/***********************PRIMITIVAS*********************/
//pre:
//post: se inicializan los parametros de Terreno, crea en forma random la primera aparicion de monedas y bandidos
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
PRE: Terreno Creado y inicializado
POST: Terreno actualizado, con movimientos de locomotora yproducciones de minas, monedas  y bandidos
      SI ALGUNA DE LAS CONDICIONES DEL JUEGO CAMBIA MODIFICA VARIABLE ESTADO
*/
void actualizarTerreno(Terreno& terreno);
//PRE: Terreno Creado y inicializado
//POST: Recore listas y redibuja si es necesario,
//      Matriz actualizada con nuevos movimientos, revisa colisiones y de ser necesario aplica cambios
void actualizarMatrizJuego(Terreno &terreno);
//PRE: Terreno Creado y inicializado
//POST: Avanza locomotora y sus vagones, verifica si algun vagon o la locomotora tienn una intercepciopn
//y en tal caso efectua accion
void avanzarLocomotora(Terreno &terreno);
//PRE: Terreno Creado y inicializado, se debe llamar de actualizar terreno
//POST: verifica colisiones y actualiza estado matriz y actua en efecto
void chequearColisiones(Terreno& terreno);
//PRE: Terreno Creado y inicializado, tiene que existir locomotora
//POST: verifica si hay algun bandido alrededor del tren (locomotora o vagon)
void locomotoraEnRadarBandido(Terreno& terreno);
//PRE: Terreno Creado y inicializado, tiene que existir locomotora
//POST: verifica si hay alguna moneda debajo del tren (locomotora o vagon)
void locomotoraRecoletaMonedas(Terreno& terreno);
//PRE: Terreno Creado y inicializado, solo se llama desde actualizarTerreno
//POST: Actualiza lista de monedas, verifica si debe crear una nueva (segun intervalos)
//      y elimina en caso de llegar al fin de vida de la moneda
void actualizarMonedas(Terreno& terreno);
//PRE: Terreno Creado y inicializado, solo se llama desde actualizarTerreno
//POST: Actualiza lista de Bandidos, verifica si debe crear uno nueva (segun intervalos)
//      y elimina en caso de llegar al fin de vida del bandido
void actualizarBandidos(Terreno& terreno);
//PRE: Terreno Creado y inicializado, Matriz inicializada
//POST: recorre matriz imprimiendo en forma de matriz los datos q tiene
void imprimirMatriz(Terreno &t);
//PRE: Terreno Creado y inicializado
//POST: verifica si al ingresar un nuevo vagon se alcanza la victoria, devuelve true si se cumplio objetivos
bool verificarComanda(Terreno &t);
//PRE: Terreno Creado y inicializado,
//POST: Carga las texturas
void cargarTexturasTerreno(Terreno& terreno, SDL_Renderer* renderizador);
//PRE: Terreno Creado y inicializado,
//POST: renderiza terreno
void renderizarTerreno(Terreno& terreno,SDL_Renderer *renderizador);
//PRE: Terreno Creado y inicializado, Archivo de parametros cargado
//POST: Devuelve el tiempo sobre el cual se deben refrescar los dibujos en pantalla
int getTiempoEntreIntervalos(Terreno& terreno);

void agregarMensajes(Terreno & terreno, SDL_Renderer *renderizador);
#endif // Terreno_h
