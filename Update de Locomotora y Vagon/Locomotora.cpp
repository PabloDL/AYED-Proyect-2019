#include "Locomotora.h"
#include "Funciones.h"

/********************GETTERS Y SETTERS*************************/
void setMonedasAdquiridas(Locomotora& locomotora,int monedasAdquiridas){
    locomotora.monedasAdquiridas=monedasAdquiridas;
}
int getMonedasAdquiridas(Locomotora& locomotora){
    return locomotora.monedasAdquiridas;
}

void setPosicion(Locomotora& locomotora,Posicion posicion){
    moverPosicion( locomotora.posicion , getX(posicion) , getY(posicion) );
}
Posicion getPosicion(Locomotora& locomotora){
    return locomotora.posicion;
}

void setVelocidadL(Locomotora& locomotora,int velocidadL){
    locomotora.velocidadL=velocidadL;
}
int getVelocidadL(Locomotora& locomotora){
    return locomotora.velocidadL;
}

/*******************PRIMITIVAS**************************/
void crearLocomotora(Locomotora& locomotora){
   locomotora.monedasAdquiridas = 0;
   locomotora.velocidadL = 0;
   locomotora.posicion.x = 0;
   locomotora.posicion.y = 0;
   crearLista( locomotora.listaVagones, compararListaVagones , eliminarVagonesDeLista );
}

void obtenerMoneda(Locomotora& locomotora,Moneda moneda){
    locomotora.monedasAdquiridas += getCantidad(moneda);
}

bool gastarMonedas(Locomotora& locomotora,int cantAPagar){
    bool pagado = false;

    if( cantAPagar <= getMonedasAdquiridas(locomotora) ){ //si se tiene la cant necesaria de monedas entonces
        setMonedasAdquiridas(locomotora,locomotora.monedasAdquiridas - cantAPagar);
        pagado = true;
    }
    return pagado;
}

void frenarLocomotora(Locomotora& locomotora){
    setVelocidadL( locomotora , 0 );
}
void arrancarLocomotora(Locomotora& locomotora){
    setVelocidadL( locomotora, velocidad );
}

void agregarVagon(Locomotora& locomotora,int capVagon){
    Vagon * ptrVagon = new Vagon();
    crearVagon( *ptrVagon , capVagon ); //se crea el vagon con la capcidad Asignada

    if( listaVacia(locomotora.listaVagones) ){
        adicionarPrincipio( locomotora.listaVagones , ptrVagon );//se agrega a la lista de vagones
    }
    else{
        adicionarFinal( locomotora.listaVagones , ptrVagon  );
    }
}

void romperVagon(Locomotora& locomotora){
    PtrNodoLista nodo = ultimo(locomotora.listaVagones); //siempre se eliminar el ultimo vagon de la lista
    Vagon * ptrVagon = &( *((Vagon*)nodo->ptrDato) );

    locomotora.listaVagones.destruye(ptrVagon); //llamo al destructor de listaVagones
    delete ptrVagon;
    eliminarNodo( locomotora.listaVagones , nodo );
}

void almacenarCaja(Locomotora& locomotora, Cajas& caja){
    if( !listaVacia(locomotora.listaVagones) ){ //si la locomotora tiene almenos 1 vagon
        PtrNodoLista cursor = primero( locomotora.listaVagones );
        Cajas * ptrCaja = &caja;
        int total = 0;
        bool ubicado = false;

        while( cursor != finLista() && !ubicado ){
            total = getCapVagonUsada( *((Vagon*)cursor->ptrDato) ) + getCapMax( *ptrCaja ); //el total de capacidad que va a requerir el vagon , lo uso como un verificador

            if( total <= getCapVagon( *((Vagon*)cursor->ptrDato) ) && vagonVacio( *((Vagon*)cursor->ptrDato) ) ){//verifico que la sumaTotal sea menor o igual a la capacidadMaxima de dicho vagon y si el vagon esta vacio
                setTipoVagon( *((Vagon*)cursor->ptrDato) , getCodItem( *ptrCaja ) ); //al ser la primera caja del vagon, le asigno al vagon el tipo de item de la caja

                adicionarPrincipio( ((Vagon*)cursor->ptrDato)->listaCajas , ptrCaja); //lo agrego al principio de la lista ya que es la primera caja
                ((Vagon*)cursor->ptrDato)->capVagonUsada += getCapMax( *ptrCaja ); //acutalizo la capacidad usada del vagon con la cnt de items de la caja
                ubicado = true;
            }
            else if( total <= getCapVagon( *((Vagon*)cursor->ptrDato) ) && mismoTipo( *((Vagon*)cursor->ptrDato) , getCodItem(*ptrCaja)) ){ //verifico que la sumaTotal sea menor o igual a la capacidadMaxima de dicho vagon  y si el vagon es del mismo tipo que la caja (item)
                adicionarFinal( ((Vagon*)cursor->ptrDato)->listaCajas , ptrCaja );
                ((Vagon*)cursor->ptrDato)->capVagonUsada += getCapMax( *ptrCaja ); //acutalizo la capacidad usada del vagon con la cnt de items de la caja
                ubicado = true;
            }
            cursor = siguiente( locomotora.listaVagones , cursor );
        }
    }
}


bool sacarItem(Locomotora& locomotora, int cantItem, string tipoItem){
    //CODIGO...
}

void eliminarLocomotora(Locomotora& locomotora){
    PtrNodoLista cursor = primero(locomotora.listaVagones);
    PtrNodoLista previo = primero(locomotora.listaVagones);

    while( !listaVacia( locomotora.listaVagones ) ){
        Vagon  *ptrVagon = &( *((Vagon*)cursor->ptrDato) );
        eliminarVagon( *ptrVagon );

        locomotora.listaVagones.destruye( ptrVagon );
        delete ptrVagon;

        previo = cursor;
        cursor = siguiente( locomotora.listaVagones , cursor );
        eliminarNodo( locomotora.listaVagones , previo);
    }
}
