#ifndef Terreno_h
#define Terreno_h

#include <iostream>
#include "locomotora.h"
#include "Lista.h"
#include "vagon.h"
#include "Mina.h"
#include "Moneda.h"

using namespace std;

typedef struct Terreno{
    //int ancho;
    //int alto;
    Locomotora locomotora;
    Lista minas;
    Lista estaciones;
    Lista moneda;
    Lista bandidos;
    /* la matriz tiene:
    E=ESTACION, M=MINAS, L=LOCOMOTORA,B=BANDIDOS, m=MONEDAS,T=TERRENO VACIO  */
    char matrizJuego[800][600];
    int intervaloActual; //cada vez entro a actualizarTerreno incremento intervalo actual
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

//PRE: Terreno Creado y inicializado
//POST: Terreno actualizado, con movimientos de locomotora yproducciones de minas, monedas  y bandidos
void actualizarTerreno(Terreno& terreno, int sentido);

//PRE: Terreno Creado y inicializado
//POST: Matriz actualizada con nuvos movimientos
void actualizarMatrizJuego(Terreno &terreno);

//PRE: Terreno Creado y inicializado
//POST: Avanza locomotora y sus vagones, verifica si algun vagon o la locomotora tienn una intercepciopn
//y en tal caso efectua accion
void avanzarLocomotora(Terreno &terreno, int sentido);

#endif // Terreno_h

