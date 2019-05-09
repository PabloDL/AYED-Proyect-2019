#include "posicion.h"
//#include "pila.h" para cuando se agreguen los vagones a la locomotora

#define velocidad      5//macro
enum sentido{//para definir los eventos del teclado
    IZQUIERDA,DERECHA,ARRIBA,ABAJO
};
typedef struct Locomotora{
    int monedasAdquiridas;
    Posicion posicion;
    sentido movimientoL;
    int velocidadL;
    //Pila vagones; ?
}Locomotora;

/************************Axiomas******************/
//velocidad >= 0
//la locomotora empieza con 0 monedas
//la locomotora empieza con velocidad 0 es decir esta quieta

/***********************Primitivas**********************/
//******************gets y setters********************
void setMonedasAdquiridas(Locomotora& locomotora,int monedasAdquiridas);
int getMonedasAdquiridas(Locomotora& locomotora);

void setMovimientoL(Locomotora& locomotora,sentido movimientoL);
sentido getMovimientoL(Locomotora& locomotora);

void setPosicion(Locomotora& locomotora,Posicion posicion);
Posicion getPosicion(Locomotora& locomotora);

void setVelocidadL(Locomotora& locomotora,int velocidadL);
int getVeclodiadL(Locomotora& locomotora);

//pre:
//post:se inicializan los parametros de locomotora;
void crearLocomotora(Locomotora& locomotora);

//pre:locomotora creada
//post:se liberan los recursos utilizados por la locomotora
void eliminarLocomotora(Locomotora& locomotora);

//pre: locomotora creada
//post:se le asigna '0' al campo velocidadL de la locomotora
void frenarLocomotora(Locomotora& locomotora);

//pre: locomotora creada
//post: se le asigna el 'macro velocidad' al campo velocidadL de la locomotora
void arrancarLocomotora(Locomotora& locomotora);

//pre:Locomotora creada
//post:se le suma o resta el 'macro velocidad' a el campo 'x' de posicion
//     dependiendo del evento del teclado
void avanzar(Locomotora& locomotora,Posicion& posicion);

//pre:Locomotora creada
//post: se le suma o resta el 'macro velocidad'  a el campo 'y'  de posicion
//      dependiendo del evento del teclado
void girar(Locomotora& locomotora,Posicion& posicion);

//pre:Locomotora creada
//post: se suma la moneda ontenida a la cantidad total de monedasAdquiridas
void obtenerMoneda(Locomotora& locomotora);

//pre:Locomotora creada
//post: se le resta cantMonedas al campo monedasAdquiridas de locomotora y devuelve el nuevo total de monedasAdquiridas disponibles
//      si no se cumple con la cantMonedas a pagar retorna 0
int gastarMonedas(Locomotora& locomotora,int cantMonedas);
#endif // _locomotora_h_
