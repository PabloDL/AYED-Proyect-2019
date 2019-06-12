#ifndef _LOCOMOTORA_H__
#define _LOCOMOTORA_H__

#ifndef velocidad
#define velocidad    5
#endif // velocidad

#include <sstream>

#include "Lista.h"
#include "Posicion.h"
#include "Vagon.h"
#include "Moneda.h"
#include "Funciones.h"

typedef struct Locomotora{
    int monedasAdquiridas;
    Posicion posicion;
    int velocidadL;
    Lista listaVagones;
}Locomotora;
/************************Axiomas******************/
//velocidad >= 0
//la locomotora empieza con 0 monedas
//la locomotora empieza con velocidad 0 es decir esta quieta

//******************gets y setters********************
void setMonedasAdquiridas(Locomotora& locomotora,int monedasAdquiridas);
int getMonedasAdquiridas(Locomotora& locomotora);

void setVelocidadL(Locomotora& locomotora, int velocidadL);
int getVelocidadL(Locomotora& locomotora);

void setPosicion(Locomotora& locomotora,Posicion posicion);
Posicion getPosicion(Locomotora& locomotora);

Lista getListaVagones(Locomotora& locomotora);
/***********************Primitivas**********************/
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
//post: se suma la moneda ontenida a la cantidad total de monedasAdquiridas
void obtenerMoneda(Locomotora& locomotora,Moneda moneda);

//pre:Locomotora creada
//post: si es posible realizar el pago se le resta cantMonedas al campo monedasAdquiridas de locomotora y
//      se actualiza con la nueva cnt de monedas adquiridas, luego retorna true ,si no se cumple con la cantMonedas a pagar retorna false
bool gastarMonedas(Locomotora& locomotora,int cantMonedas);

//pre:Locomotora creada
//post: se le agrega un nodo con un dato de tipo struct 'Vagon' a pilaVagones de la locomotora
void agregarVagon(Locomotora& locomotora,int capVagon);

//pre: locomotora creada y con uno o mas vagaones(nodos) agregados a la misma
//post: elimina el ultimo Vagon(nodo) de la locomotora(listaVagones)
//        devuelve true si cuando lo saca NO quedan vagones, sino false
bool sacarVagon(Locomotora& locomotora);

//pre: Locomotora creada y cargada con uno o mas vagones que CUMPLAN CON UNA de las siguentes condiciones:
//    (1) capacidad total disponible
//    (2)el tipoVagon tiene que ser el mismo que caja(item)  y tener suficiente capacidad para poder almacenarlo
//post: guarda una caja en la listaCajas de vagon , si no se cumple ni una de las 2 condiciones anteriores no hace nada
void almacenarCaja(Locomotora& locomotora,Cajas& caja);

//pre: locomotora creada y cargada con 1 o mas vagones
//post: devuelve la cantidad de lingotes de un unico tipo(ORO,PLATA,BRONCE,ETC)
int getCantLingotes(Locomotora& locomotora , string tipoItem);

//pre:  Locomotora creada , cargada con 1 o mas vagones y dichos vagones cargados con 1 o mas cajas para poder realizar la operacion
//post: empieza siempre con el ULTIMO VAGON ingresado y procede a identificar si ese vagon es del mismo tipo que el tipoItem, si es del mismo tipo empieza
//      a recorrer su lista de cajas sacando lingotes hasta que se cumpla la cantSolicitada ,
//      actualizando 'la cant de lingotes actuales de una caja' y 'la capacidad del vagon usada' ,
//      si ese vagon no logra cumplir con la cant de lingotes solicitados se pasa a recorrer el anterior de la listaVagones hasta cumplir con
//      la cantSolicitada de lingotes(recuerden que siempre empieza del ultimo vagon y va ir hasta el primero si es necesario)
//      finalmente devuelve 'la cant de lingotes solicitados si se cumple con la cantSolicitada' , si no es asi devuelve '0'
int pagarBandido(Locomotora& locomotora , int cantSolicitada , int tipoItem);


bool hayLugarParaCajaEnLocomotora(Locomotora& locomotora , int cantSolicitada , string tipoItem);

#endif // _locomotora_h_
