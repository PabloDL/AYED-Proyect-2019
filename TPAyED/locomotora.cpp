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

Lista getListaVagones(Locomotora& locomotora){
    return locomotora.listaVagones;
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
        locomotora.monedasAdquiridas -= cantAPagar;
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
    crearVagon( *ptrVagon ); //se crea el vagon
    setCapVagon( *ptrVagon , capVagon ); //se le asigna la capacidad maxima de cajas que podra almacenar el vagon

    if( listaVacia(locomotora.listaVagones) ){
        Posicion posNuevo = getPosicion(locomotora);
        setX(posNuevo, getX(posNuevo)-1 );
        setPosicion(*ptrVagon, posNuevo);
        adicionarPrincipio( locomotora.listaVagones , ptrVagon );//se agrega a la lista de vagones
    }
    else{

        Posicion posNuevo = getPosicion(*(Vagon*)(ultimo(locomotora.listaVagones)->ptrDato));
        setX(posNuevo, getX(posNuevo)-1 );
        setPosicion(*ptrVagon, posNuevo);
        adicionarFinal( locomotora.listaVagones , ptrVagon  );
    }
}

int getCantLingotes(Locomotora& locomotora , string tipoItem){
    int cantLingotes = 0;
    PtrNodoLista cursor = primero(locomotora.listaVagones);

    while( cursor != finLista() ){

        if( !listaVacia( ((Vagon*)cursor->ptrDato)->listaCajas ) ){

            if( mismoTipo( *((Vagon*)cursor->ptrDato) , tipoItem ) ){
                cantLingotes += ((Vagon*)cursor->ptrDato)->capVagonUsada;
            }

        }
        cursor = siguiente( locomotora.listaVagones , cursor );
    }

    return cantLingotes;
}

//NOTA: NO FUNCIONA PORQUE ESTOY LLAMANDO A METODOS DE CAJA (getCapMax) (getCantItem) (getCodItem) que no esta agregados en el tda de CAJA
/*
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
*/

//NOTA: NO FUNCIONA PORQUE ESTOY LLAMANDO A METODOS DE CAJA (getCapMax) (getCantItem) (getCodItem) que no esta agregados en el tda de CAJA
/*
int pagarBandido(Locomotora& locomotora, int cantSolicitada, string tipoItem){
    bool pagado = false;//booleana para terminar el bucle de ListaVagones si es necesario

    if ( !listaVacia( locomotora.listaVagones ) ){//verifico que por lo menos la locomotora tenga 1 vagon
        if ( getCantLingotes(locomotora, tipoItem) >= cantSolicitada ){ //primero antes que nada verifico que la cant solicitada por el ladron sea posible cumplir

            PtrNodoLista cursor = ultimo( locomotora.listaVagones ); //nodo de listaVagones de locomotora , siempre empiezo tratando de pagar con los items del ultimo vagon ingresado
            int lingotesSacados = 0;//variable usada como contador de items de una caja
            int totalLingotesSacados = 0;//variable usada para identificar cuando se cumple con la cantidadSolicitada por el ladron sumando todos los lingotesSacados que sean necesarios

            //bucle de las listas de vagones de locomotora
            while( cursor != primero( locomotora.listaVagones ) && !pagado ){
                    Vagon *ptrVagonAUtilizar = &( *((Vagon*)cursor->ptrDato) );

                    if( !listaVacia( ptrVagonAUtilizar->listaCajas ) ){ //verifico que el vagon actual del cursor tenga por lo menos 1 caja
                        if( mismoTipo( *ptrVagonAUtilizar , tipoItem ) ){//verfico que el vagon sea del mismo tipo de lo que solicita el ladron
                            bool termino = false;//booleana para terminar el bucle de ListaCajas si es necesario
                            PtrNodoLista cursorCaja = ultimo( ptrVagonAUtilizar->listaCajas );//empiezo siempre con la ultima caja ingresada al vagon

                            //bucle de las listas de cajas de los vagones
                            while( cursorCaja != primero( ptrVagonAUtilizar->listaCajas ) && !termino ){
                                Cajas *ptrCajaAUtilizar = &( *((Cajas*)cursorCaja->ptrDato) );
                                lingotesSacados = 0;

                                while( lingotesSacados != getCapMax( *ptrCajaAUtilizar ) && totalLingotesSacados != cantSolicitada ) {
                                    lingotesSacados ++ ;
                                    totalLingotesSacados ++ ;
                                }

                                if( lingotesSacados == getCapMax( *ptrCajaAUtilizar ) ){//si la cant de lingotes sacados es igual a la capacidad maxima de la caja entonces elimino la caja de la lista
                                    eliminarCaja( *ptrCajaAUtilizar ); //llamo al destructor de caja y la elimina
                                    eliminarNodo( ptrVagonAUtilizar->listaCajas , cursorCaja );//elimino el nodo caja de la lista
                                }
                                else{
                                    ptrCajaAUtilizar->cantitem -= lingotesSacados;//resto la 'cant de lingotes de la caja' con 'lingotes sacados' para tener la nueva cant de actual de lingotes de una caja
                                }
                                ptrVagonAUtilizar->capVagonUsada -= lingotesSacados;//le resto a la 'cap vagon usada' los lingotes sacados con el fin de ACTUALIZAR la 'cap del vagon usada'


                                if( totalLingotesSacados == cantSolicitada  ){
                                    pagado = true; //asignos las booleanas en true para terminar los bucles
                                    termino = true;
                                }

                                cursorCaja =  anterior( ptrVagonAUtilizar->listaCajas , cursorCaja );//va a ir de la ultima caja de la lista hasta la primera del vagon actual
                            }
                            if( !termino ){ //esto quiere decir que al no entrar en el bucle de lista cajas, solo ahi una caja y es la primera de la lista
                                Cajas *ptrCajaAUtilizar = &( *((Cajas*)cursorCaja->ptrDato) );
                                lingotesSacados = 0;

                                while( lingotesSacados != getCapMax(*ptrCajaAUtilizar) && totalLingotesSacados != cantSolicitada ) {
                                    lingotesSacados ++ ;
                                    totalLingotesSacados ++ ;
                                }

                                if( lingotesSacados == getCapMax(*ptrCajaAUtilizar) ){//si la cant de lingotes sacados es igual a la capacidad maxima de la caja entonces elimino la caja de la lista
                                    eliminarCaja( *ptrCajaAUtilizar ); //llamo al destructor de caja y la elimina
                                    eliminarNodo( ptrVagonAUtilizar->listaCajas , cursorCaja );//elimino el nodo caja de la lista
                                }
                                else{
                                    ptrCajaAUtilizar->cantitem -= lingotesSacados;//resto la 'cant de lingotes de la caja' con 'lingotes sacados' para tener la nueva cant de items de una caja
                                }
                                ptrVagonAUtilizar->capVagonUsada -= lingotesSacados;//le resto a la 'cap vagon usada' los lingotes sacados con el fin de ACTUALIZAR la 'cap del vagon usada'


                                if( totalLingotesSacados == cantSolicitada  ){
                                    pagado = true; //asignos las booleanas en true para terminar los bucles
                                }

                            }
                        }

                    }
                    cursor = anterior( locomotora.listaVagones , cursor ); //va a ir del ultimo vagon hasta el primero de la lista si es necesario

            }
            if( cursor == primero(locomotora.listaVagones) ){//primer vagon de la locmotora
                Vagon *ptrVagonAUtilizar = &( *((Vagon*)cursor->ptrDato) );
                if( mismoTipo( *ptrVagonAUtilizar , tipoItem ) ){//verfico que el vagon sea del mismo tipo de lo que solicita el ladron
                        bool termino = false;
                        PtrNodoLista cursorCaja = ultimo( ptrVagonAUtilizar->listaCajas );//empiezo siempre con la ultima caja ingresada al vagon

                    while( cursorCaja != primero( ptrVagonAUtilizar->listaCajas ) && !termino ){//repito el bucle de caja para el primer vagon
                            Cajas *ptrCajaAUtilizar = &( *((Cajas*)cursorCaja->ptrDato) );
                            lingotesSacados = 0;

                            while( lingotesSacados != getCapMax( *ptrCajaAUtilizar ) && totalLingotesSacados != cantSolicitada ) {
                                lingotesSacados ++ ;
                                totalLingotesSacados ++ ;
                            }

                            if( lingotesSacados == getCapMax( *ptrCajaAUtilizar ) ){//si la cant de lingotes sacados es igual a la capacidad maxima de la caja entonces elimino la caja de la lista
                                eliminarCaja( *ptrCajaAUtilizar ); //llamo al destructor de caja y la elimina
                                eliminarNodo( ptrVagonAUtilizar->listaCajas , cursorCaja );//elimino el nodo caja de la lista
                            }
                            else{
                                ptrCajaAUtilizar->cantitem -= lingotesSacados;//resto la 'cant de lingotes de la caja' con 'lingotes sacados' para tener la nueva cant de items de una caja
                            }
                            ptrVagonAUtilizar->capVagonUsada -= lingotesSacados;//le resto a la 'cap vagon usada' los lingotes sacados con el fin de ACTUALIZAR la 'cap del vagon usada'


                            if( totalLingotesSacados == cantSolicitada  ){
                                pagado = true; //asignos las booleanas en true para terminar los bucles
                                termino = true;
                            }

                            cursorCaja =  anterior( ptrVagonAUtilizar->listaCajas , cursorCaja );//va a ir de la ultima caja de la lista hasta la primera
                    }
                    if( !termino ){//quiere decir que solo ahi una caja en el primer vagon de la locomotora
                        Cajas *ptrCajaAUtilizar = &( *((Cajas*)cursorCaja->ptrDato) );
                        lingotesSacados = 0;

                        while( lingotesSacados != getCapMax( *ptrCajaAUtilizar ) && totalLingotesSacados != cantSolicitada ) {
                            lingotesSacados ++ ;
                            totalLingotesSacados ++ ;
                        }

                        if( lingotesSacados == getCapMax( *ptrCajaAUtilizar ) ){//si la cant de lingotes sacados es igual a la capacidad maxima de la caja entonces elimino la caja de la lista
                            eliminarCaja( *ptrCajaAUtilizar ); //llamo al destructor de caja y la elimina
                            eliminarNodo( ptrVagonAUtilizar->listaCajas , cursorCaja );//elimino el nodo caja de la lista
                        }
                        else{
                            ptrCajaAUtilizar->cantitem -= lingotesSacados;//resto la 'cant de lingotes de la caja' con 'lingotes sacados' para tener la nueva cant de items de una caja
                        }
                        ptrVagonAUtilizar->capVagonUsada -= lingotesSacados;//le resto a la 'cap vagon usada' los lingotes sacados con el fin de ACTUALIZAR la 'cap del vagon usada'


                        if( totalLingotesSacados == cantSolicitada  ){
                            pagado = true; //asignos las booleanas en true para terminar los bucles
                        }

                    }
                }
            }
        }


    }
    return pagado;
}
*/

void sacarVagon(Locomotora& locomotora){
    PtrNodoLista nodo = ultimo(locomotora.listaVagones); //siempre se elimina el ultimo vagon de la lista
    Vagon * ptrVagon = &( *((Vagon*)nodo->ptrDato) );

    locomotora.listaVagones.destruye(ptrVagon); //llamo al destructor de listaVagones
    delete ptrVagon;
    eliminarNodo( locomotora.listaVagones , nodo );
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
