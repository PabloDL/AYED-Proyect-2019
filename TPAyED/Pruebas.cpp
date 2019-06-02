#include "Pruebas.h"

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
    //HASTA ACA ESTAMOS OJOOOOOOO NO AVANZA LOCOMOTORA POSICION
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
