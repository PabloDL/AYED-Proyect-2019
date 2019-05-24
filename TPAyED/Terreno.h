#ifndef Terreno_h
#define Terreno_h

#include <iostream>

using namespace std;

typedef struct Terreno{
    int ancho;
    int alto;
    Locomotora locomotora;
    Lista minas;
    Lista estaciones;
    Lista moneda;
    Lista bandidos;
}Terreno;
/*******************GETTERS Y SETTERS*******************/

int getAncho(Terreno& terreno)
void setAncho(Terreno& terreno)
int getAlto(Terreno& terreno)
void setAlto(Terreno& terreno)

/***********************PRIMITIVAS*********************/
//pre:
//post: se inicializan los parametros de Terreno
void crearTerreno(Terreno& terreno);

//pre:Tiene que existir el terreno
//post:Se elimina el terreno en cascada con los atributos internos
//se usa al cerrar el juego
void eliminarTerreno(Terreno& terreno)

//pre:Terreno tiene que estar creado e inicializado
//post: se posiciona la locomotora en el terreno
void aparecerLocomotora(Terreno& terreno);

//pre:Terreno tiene que estar creado e inicializado
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

#endif // Terreno_h
