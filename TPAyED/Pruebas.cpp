#include "Pruebas.h"

void testLocomotoraRecolectarMondenas(){

           cout << "Test Colision locomotora o vagon con moneda" << endl;
        Terreno t;
        Locomotora l;
//ARMO LOCOMOTORA Y VAGON
        crearLocomotora(l);
        Posicion ploc;
        moverPosicion(ploc, 5,5);
        setPosicion(l,ploc);
        agregarVagon(l, 5);
        agregarVagon(l, 3);
        agregarVagon(l, 6);

        Lista monedas;
        crearLista(monedas,compararListaMonedas,eliminarMonedaDeLista);
        Moneda * m = new Moneda;
        crearMoneda(*m);
        setCantidad(*m, 2);
        moverPosicion(ploc, 5,5);
        setPosicion(*m,ploc); // LO SETEO EN LA POS DE LA LOCOMOTORA
        adicionarPrincipio(monedas, m);

        Moneda * m2 = new Moneda;
        crearMoneda(*m2);
        setCantidad(*m2, 10);
        moverPosicion(ploc, 5,5);
        setPosicion(*m2,ploc); // LO SETEO EN LA POS DE LA LOCOMOTORA
        adicionarPrincipio(monedas, m2);

    //Agrego locomotora y lista bandidos terrenos
        setLocomotora(t,l);
        setMonedas(t,monedas);

        cout <<"Locomotora " << "[" << t.locomotora.posicion.x << ";" <<  t.locomotora.posicion.x << "]";
        Lista vagones = getListaVagones(l);
        if (!listaVacia(vagones)){
            NodoLista * ptrNodo = primero(vagones);;
            while(!listaVacia(vagones) && ptrNodo != finLista()){
                Vagon * vagonActual = (Vagon*) ptrNodo->ptrDato;
                Posicion p = getPosicion(*vagonActual);
                int x = getX(p);
                int y = getY(p);
                cout << "[" << x << ";" <<  y << "]";
                ptrNodo = siguiente(vagones, ptrNodo);
            }
        }
        cout << endl;
        cout << "MONEDAS: " ;
        if (!listaVacia(monedas)){
            NodoLista * ptrNodo = primero(monedas);;
            while(!listaVacia(monedas) && ptrNodo != finLista()){
                Moneda * monedaActual = (Moneda*) ptrNodo->ptrDato;
                Posicion p = getPosicion(*monedaActual);
                int x = getX(p);
                int y = getY(p);
                cout << "[" << x << ";" <<  y << "]";
                ptrNodo = siguiente(monedas, ptrNodo);
            }
        }
        cout << endl << "TREN TIENE AFUERA ANTES DE RECOLET : " << t.locomotora.monedasAdquiridas << endl;

        locomotoraRecoletaMonedas(t);

        cout << endl << "TREN TIENE AFUERA DESPUES DE RECOLET : " << t.locomotora.monedasAdquiridas << endl;
        cout << "MONEDAS: " ;
        if (!listaVacia(t.monedas)){
        NodoLista * ptrNodo = primero(t.monedas);;
            while(!listaVacia(t.monedas) && ptrNodo != finLista()){
                Moneda * monedaActual = (Moneda*) ptrNodo->ptrDato;
                Posicion p = getPosicion(*monedaActual);
                int x = getX(p);
                int y = getY(p);
                cout << "[" << x << ";" <<  y << "]";
                ptrNodo = siguiente(t.monedas, ptrNodo);
            }
        }

}

void testColisionBandido(){
        cout << "Test Colision locomotora o vagon con bandido" << endl;
        Terreno t;
        Locomotora l;
//ARMO LOCOMOTORA Y VAGON
        crearLocomotora(l);
        Posicion ploc;
        moverPosicion(ploc, 5,5);
        setPosicion(l,ploc);
        agregarVagon(l, 5);
        agregarVagon(l, 3);
        agregarVagon(l, 6);

        Lista bandidos;
        crearLista(bandidos,compararListaBandidos,eliminarBandidoDeLista);
        Bandido * b = new Bandido;
        crearBandido(*b);
        moverPosicion(ploc, 6,5);
        setPosicion(*b,ploc); // LO SETEO EN LA POS DE LA LOCOMOTORA
        adicionarPrincipio(bandidos, b);

        Bandido * b2 = new Bandido;
        crearBandido(*b2);
        moverPosicion(ploc, 10,10);
        setPosicion(*b2,ploc); // LO SETEO EN LA POS DE LA LOCOMOTORA
        adicionarPrincipio(bandidos, b2);
    //Agrego locomotora y lista bandidos terrenos
        setLocomotora(t,l);
        setBandidos(t,bandidos);

        cout <<"Locomotora " << "[" << t.locomotora.posicion.x << ";" <<  t.locomotora.posicion.x << "]";
        Lista vagones = getListaVagones(l);
        if (!listaVacia(vagones)){
            NodoLista * ptrNodo = primero(vagones);;
            while(!listaVacia(vagones) && ptrNodo != finLista()){
                Vagon * vagonActual = (Vagon*) ptrNodo->ptrDato;
                Posicion p = getPosicion(*vagonActual);
                int x = getX(p);
                int y = getY(p);
                cout << "[" << x << ";" <<  y << "]";
                ptrNodo = siguiente(vagones, ptrNodo);
            }
        }
        cout << endl;
        cout << "BANDIDOS:" ;
        if (!listaVacia(bandidos)){
            NodoLista * ptrNodo = primero(bandidos);;
            while(!listaVacia(bandidos) && ptrNodo != finLista()){
                Bandido * bandidoActual = (Bandido*) ptrNodo->ptrDato;
                Posicion p = getPosicion(*bandidoActual);
                int x = getX(p);
                int y = getY(p);
                cout << "[" << x << ";" <<  y << "]";
                ptrNodo = siguiente(bandidos, ptrNodo);
            }
        }
        cout << endl;

        locomotoraEnRadarBandido(t);

        cout << "Despues de pelear lista Bandidos: " ;
        if (!listaVacia(t.bandidos)){
        NodoLista * ptrNodo = primero(t.bandidos);;
            while(!listaVacia(t.bandidos) && ptrNodo != finLista()){
                Bandido * b = (Bandido*) ptrNodo->ptrDato;
                Posicion p = getPosicion(*b);
                int x = getX(p);
                int y = getY(p);
                cout << "[" << x << ";" <<  y << "]";
                ptrNodo = siguiente(t.bandidos, ptrNodo);
            }
        }


}

void testAvanzarLocomotora(){
    cout << "Test de avanzar locomotora" << endl;
        Terreno t;

        Locomotora l;
        crearLocomotora(l);
        Posicion ploc;
        moverPosicion(ploc, 5,5);
        setPosicion(l,ploc);

        agregarVagon(l, 5);
        agregarVagon(l, 3);
        agregarVagon(l, 6);

        setLocomotora(t,l);
        cout <<"locomotora antes avanzar" << "[" << t.locomotora.posicion.x << ";" <<  t.locomotora.posicion.x << "]";
        Lista vagones = getListaVagones(l);
        if (!listaVacia(vagones)){
            NodoLista * ptrNodo = primero(vagones);;

            while(!listaVacia(vagones) && ptrNodo != finLista()){
                Vagon * vagonActual = (Vagon*) ptrNodo->ptrDato;
                Posicion p = getPosicion(*vagonActual);
                int x = getX(p);
                int y = getY(p);
                cout << "[" << x << ";" <<  y << "]";
                ptrNodo = siguiente(vagones, ptrNodo);
            }
        }
        //AVANZO LOCOMOTORA
        avanzarLocomotora(t, 3);

        cout <<"locomotora despues avanzar" << "[" << t.locomotora.posicion.x << ";" <<  t.locomotora.posicion.y << "]";
        vagones = getListaVagones(l);
        if (!listaVacia(vagones)){
            NodoLista * ptrNodo = primero(vagones);;

            while(!listaVacia(vagones) && ptrNodo != finLista()){
                Vagon * vagonActual = (Vagon*) ptrNodo->ptrDato;
                Posicion p = getPosicion(*vagonActual);
                int x = getX(p);
                int y = getY(p);
                cout << "[" << x << ";" <<  y << "]";
                ptrNodo = siguiente(vagones, ptrNodo);
            }
        }
        cout << endl;
        cout << endl;
        cout << endl;
}

void testCargaDeArchivos(){
    /* PRUEBA ARCHIVOS */
    cout << "lectura Comanda" << endl;
    Lector lectorComanda;
    crearLector(lectorComanda);
    abrirArchivo(lectorComanda, "comanda.txt");
    leerArchivoComandas(lectorComanda);
    eliminarLector(lectorComanda);

    cout << "lectura Parametros" << endl;
    Lector lector;
    crearLector(lector);
    abrirArchivo(lector, "parametros.txt");
    leerArchivoParametros(lector);
    eliminarLector(lector);

    cout << "lectura Minas" << endl;
    Lector lectorMinas;
    crearLector(lectorMinas);
    abrirArchivo(lectorMinas, "minas.txt");
    leerArchivoMinas(lectorMinas);
    eliminarLector(lectorMinas);

}

void testListaMinas(){
/* PRUEBA LISTA MINAS */
    cout << "***************** prueba de lista de minas -> " << endl;
    Lista listaMinas;
    //CREO LISTA
    crearLista(listaMinas, compararListaMinas, eliminarMinasDeLista);
    //agrego elemento a lista
    Mina* m = new Mina;
    crearMina((*m));
    adicionarPrincipio(listaMinas, m);
    adicionarPrincipio(listaMinas, m);
    adicionarPrincipio(listaMinas, m);
    adicionarPrincipio(listaMinas, m);
    imprimirListaMinas(listaMinas);
}

void testTerreno(){
    Terreno t;
    crearTerreno(t);
    imprimirMatriz(t);
}

