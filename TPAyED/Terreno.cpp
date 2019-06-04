#include "Terreno.h"

using namespace std;

/************GETTERS AND SETTERS*********************/

//getters y setters
void setLocomotora(Terreno & terreno, Locomotora & locomotora){
    terreno.locomotora = locomotora;
}

/*
crearTerreno(Terreno& terreno, int alto, int ancho){
    aparecerLocomotora(terreno);
    get
}
*/

Locomotora getLocomotora(Terreno & terreno){return terreno.locomotora;}

Lista getBandidos(Terreno & terreno){return terreno.bandidos;}

void setBandidos(Terreno & terreno, Lista& bandidos){terreno.bandidos=bandidos;}
/*********************************************************/
void crearTerreno(Terreno& terreno){
    //INICIALIZO MATRIZ DE JUEGO
    terreno.intervaloActual = 0;

    for(int i=0; i< ANCHO_TERRENO; i++){
        for(int j=0; j< ALTO_TERRENO; j++){
            terreno.matrizJuego[i][j] = 'T';
            terreno.textureMap[i][j]= rand() % 9 + 0;

            //necesito numeros aleatorios para poder cargar texturas distintas en el fondo
        }
    }

/*
    juego.locomotora.rectImag.y=juego.locomotora.f* 50;//coordenada de dibujo y
    juego.locomotora.rectImag.x= juego.locomotora.c* 50;//coordenada de dibujo x
    juego.locomotora.rectImag.w= 50;//ancho
    juego.locomotora.rectImag.h= 50;//alto
*/
    //Crea minas segun archivo Minas.h
    aparecerMina(terreno);
    //APARECERESTACION
    aparecerEstacion(terreno);
    //aparecer locomotora, ultima por si hay algo en su posicion lo creo en +1
    aparecerLocomotora(terreno);
    //crear moneda -> no tienen q aparecer inmediatamente
    aparecerMoneda(terreno);
    //CREAR bandido  -> no tienen q aparecer inmediatamente
    aparecerBandido(terreno);
    ////ACTUALIZAR EN MATRIZ POSICIONES DE ELEMENTOS
    actualizarMatrizJuego(terreno);
}

void actualizarMatrizJuego(Terreno &terreno){

}

void eliminarTerreno(Terreno& terreno){}

void aparecerLocomotora(Terreno& terreno){
    crearLocomotora(terreno.locomotora);
}

void aparecerMina(Terreno& terreno){}

void aparecerEstacion(Terreno& terreno){}

void aparecerMoneda(Terreno& terreno){
    //obtengo moneda si corresponde en intervalo, la agrego a la matriz e elimino
//    NodoLista * ptrNodo = primero(terreno.monedas);
//    bool eliminarNodoMoneda = false;
//     //Como la lista de monedas tiene orden en la aparicion la que aparecera va a ser la primera siempre
//     //PERO TENGO Q RECORRER PARA SABER CUANDO SE LLEGA AL FINAL DEL TIEMPO
//    while(!listaVacia(terreno.monedas) && ptrNodo != finLista()){
//        Moneda * ptrMonedaActual = (Moneda*) ptrNodo->ptrDato;
//        if ((getAparicion(*ptrMonedaActual)) == terreno.intervaloActual){
//            Posicion p = getPosicion(*ptrMonedaActual);
//            terreno.matrizJuego[getX(p)][getY(p)] = 'm';
//        }
//        if (getAparicion(*ptrMonedaActual) + getDuracion(*ptrMonedaActual) == terreno.intervaloActual){
//                //Llego al final del tiempo de vida
//                Posicion p = getPosicion(*ptrMonedaActual);
//               terreno.matrizJuego[getX(p)][getY(p)] = 'T';
//               eliminarNodoMoneda = true;
//        }
//        NodoLista * ptrNodoActual = ptrNodo;
//        ptrNodo = siguiente(terreno.monedas, ptrNodo);
//        if (eliminarNodoMoneda){
//            eliminarNodo(terreno.monedas, ptrNodoActual);
//            eliminarNodoMoneda = false;
//        }
//    }
}

void aparecerBandido(Terreno& terreno){}

void nuevaProduccionMinas(Terreno& terreno){
//    //Recorro las listas de minas y agrego un item a cada elemento
//    NodoLista * ptrNodo = primero(terreno.minas);;
//    Mina * minaActual = (Mina*) ptrNodo->ptrDato;
//    while(! listaVacia(terreno.minas) && ptrNodo != finLista()){
//        crearCaja(*minaActual); //Agrego caja a mina Actual
//        ptrNodo = siguiente(terreno.minas, ptrNodo);
//        Mina * minaActual = (Mina*) ptrNodo->ptrDato;
//    }
}

//YA esta todo cargado, hay q actualizar
void actualizarTerreno(Terreno& terreno, int sentido){
    //Actualizar minas
    nuevaProduccionMinas(terreno);
    //actualizar bandido //chequea si tiene q aparecer un bandido (el primero de lalista)
    aparecerBandido(terreno);
    //actualizar monedas //chequea si tiene q aparecer una moneda (el primero de lalista)
    aparecerMoneda(terreno);
    //avanzarLocomotora -> ACTUAR SI POSICION DE LOCOMOTORA O VAGONES ESTA EN ZONA DE CONFLI
    actualizarMatrizJuego(terreno);
    ////ACTUALIZAR EN MATRIZ SI APARECIO BANDIDO O MONEDA
    avanzarLocomotora(terreno, sentido);
    //REVISAR CAMBIOS
    chequearColisiones(terreno);
}

void avanzarLocomotora(Terreno &terreno, int sentido){
    //AVANZO LOCOMOTORA Y VAGONES
    Posicion nuevaPosicion;
    crearPosicion(nuevaPosicion);
    Locomotora locomotora = getLocomotora(terreno);
    Posicion pTemp = getPosicion(locomotora); //guardo posicion actual locomotora

    switch (sentido){   // IZQUIERDA,DERECHA,ARRIBA,ABAJO
        case 0: { //VA HACIA IZQUIERDA
            moverPosicion(nuevaPosicion,getX(pTemp)-1,getY(pTemp));
            break;
        }
        case 1: { //VA HACIA IZQUIERDA
            moverPosicion(nuevaPosicion,getX(pTemp)+1,getY(pTemp));
            break;
        }
        case 2: { //VA HACIA IZQUIERDA
            moverPosicion(nuevaPosicion,getX(pTemp),getY(pTemp)-1);
            break;
        }
        case 3: { //VA HACIA IZQUIERDA
            moverPosicion(nuevaPosicion,getX(pTemp),getY(pTemp)+1);
            break;
        }
    }
    setPosicion(locomotora, nuevaPosicion);  //SETEO NUEVA POSICION DE LOCOMOTORA
    setLocomotora(terreno,locomotora); //SETEO LOCOMOTORA actualizada en terreno (ira directamente?)
    Lista vagones = getListaVagones(locomotora);

    if (!listaVacia(vagones)){

        NodoLista * ptrNodo = primero(vagones);

        while(!listaVacia(vagones) && ptrNodo != finLista()){
            Vagon * vagonActual = (Vagon*) ptrNodo->ptrDato;
            Posicion posVagonAnterior = getPosicion(*vagonActual);
            moverPosicion(vagonActual->posicion, getX(pTemp),getY(pTemp));
            pTemp = posVagonAnterior;

            ptrNodo = siguiente(vagones, ptrNodo);

        }
    }

}

void chequearColisiones(Terreno & terreno){
    Posicion posLocomotora = getPosicion(terreno.locomotora);
    if (getX(posLocomotora) > ANCHO_TERRENO || getY(posLocomotora) > ALTO_TERRENO
                || (getX(posLocomotora) < 0) || getY(posLocomotora) < 0 ){
        terreno.estadoJuego = GAMEOVER; // SI SALGO DEL CUADRADO TERMINA JUEGO
    }
    else{
        //VERIFICO INTERSECCION
        //E=ESTACION, M=MINAS, L=LOCOMOTORA,B=BANDIDOS, m=MONEDAS,T=TERRENO VACIO
        if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'E'){
            terreno.estadoJuego = LOCOMOTORADETENIDA; // DETENGO LOCOMOTORA

            NodoLista * ptrNodo = primero(terreno.estaciones);
            while(! listaVacia(terreno.estaciones) && ptrNodo != finLista()){
                Estacion * estacionActual = (Estacion*) ptrNodo->ptrDato;
                Posicion posEstacion = getPosicion(*estacionActual);
                if (mismaPosicion(posEstacion, posLocomotora)){
            //SI ES MISMA ESTACION -> VENDO VAGON
                    int capacidadVagon = entregarVagon((*estacionActual), getMonedasAdquiridas(terreno.locomotora));
                    if (capacidadVagon > 0){
                    agregarVagon(terreno.locomotora, capacidadVagon);
                    }
                }
            ptrNodo = siguiente(terreno.estaciones, ptrNodo);
            }
        }
        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'M'){
            //obtengo minas si es posible o eliminoproduccion si no tengo capacidad
        }
        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'T'){
            //no tengoque hacer nada ya avanzo locomotora
            //PENSAR SI VA ACA O AFUERA -> TIene q ir afuera para que cuando en el juego
            //se toca la tecla para avanzar avance antes de verificar posicion
        }
        locomotoraEnRadarBandido(terreno);

        locomotoraRecoletaMonedas(terreno);
//        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'B'){
//            //Peleo contra bandido
//        }
//        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'm'){
//            //obtengo monedas
//        }

    }

}

void locomotoraEnRadarBandido(Terreno& terreno){
// if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'B'){
//           //Peleo contra bandido
//        }
    bool pelear = false;
    Lista bandidosAPelear;
    crearLista(bandidosAPelear, compararListaBandidos, eliminarBandidoDeLista);

    Locomotora l = getLocomotora(terreno);
    Posicion pLocomotora = getPosicion(l);
    Lista bandidos = getBandidos(terreno);
    if (!listaVacia(bandidos)){
            NodoLista * ptrNodoBandido = primero(bandidos);

            while(!listaVacia(bandidos) && ptrNodoBandido != finLista() && !pelear){
                Bandido * bandido = (Bandido*) ptrNodoBandido->ptrDato;
                Posicion pBandido = getPosicion(*bandido);
                //veo si hay algun tren o vagon esta en esa posicion
                pelear = enCercanias(pBandido, pLocomotora, getAreaCobertura(*bandido));
                if (!pelear){
                    Lista vagones = getListaVagones(terreno.locomotora);
                    NodoLista * ptrNodo = primero(vagones);
                    //LO BUSCO EN LOS VAGONES
                    while(!listaVacia(vagones) && ptrNodo != finLista() && !pelear){
                        Vagon * vagon = (Vagon*) ptrNodo->ptrDato;
                        Posicion pVagon = getPosicion(*vagon);
                        pelear = enCercanias(pBandido, pVagon, getAreaCobertura(*bandido));
                        ptrNodo = siguiente(vagones, ptrNodo);
                    }
                }
                if(pelear){
                    adicionarPrincipio(bandidosAPelear,bandido);  //ADICIONO TODOS LOS BANDIDOS Q ESTAN CERCA
                    pelear=false;
                }
                ptrNodoBandido = siguiente(bandidos, ptrNodoBandido);
            }
    }
    //RECORRO LISTA DE BANDIDOS A PELEAR PARA VER CONTRA QUIEN PELEO
    NodoLista * ptrNodo = primero(bandidosAPelear);
    while(!listaVacia(bandidosAPelear) && ptrNodo != finLista()){
        //PELEAR CON BANDIDO SE CUAL ES PORQUE LO DEJE EN EL prtNODO
        Posicion pB = getPosicion(*(Bandido*)ptrNodo->ptrDato);
        cout << "ROBO ITEM LOCOMOTORA, bandido pos [" << getX(pB)
                <<";" <<getY(pB) << "]" << endl;
        //ACA SEGUIR VER COMO PELEAR CON TREN Y BANDIDO
        ptrNodo = siguiente(bandidos, ptrNodo);
    }

    //VER COMO ELIMINAR BANDIDO UNA VEZ PASADO
    // USAR ?? void eliminarDato(Lista &lista, PtrDato ptrDato);
}

void locomotoraRecoletaMonedas(Terreno& terreno){}

void cargarTexturasTerreno(Terreno& terreno, SDL_Renderer * renderizador){
    terreno.texturas[0] = IMG_LoadTexture(renderizador, "assets/img/suelo_0.png");
    terreno.texturas[1] = IMG_LoadTexture(renderizador, "assets/img/suelo_1.png");
    terreno.texturas[2] = IMG_LoadTexture(renderizador, "assets/img/suelo_2.png");
    terreno.texturas[3] = IMG_LoadTexture(renderizador, "assets/img/suelo_3.png");
    terreno.texturas[4] = IMG_LoadTexture(renderizador, "assets/img/suelo_4.png");
    terreno.texturas[5] = IMG_LoadTexture(renderizador, "assets/img/suelo_5.png");
    terreno.texturas[6] = IMG_LoadTexture(renderizador, "assets/img/suelo_6.png");
    terreno.texturas[7] = IMG_LoadTexture(renderizador, "assets/img/suelo_7.png");
    terreno.texturas[8] = IMG_LoadTexture(renderizador, "assets/img/suelo_8.png");
    terreno.texturas[9] = IMG_LoadTexture(renderizador, "assets/img/suelo_9.png");

}


void renderizarTerreno(Terreno& terreno,SDL_Renderer *renderizador){
    for(int c=0;c<ANCHO_TERRENO;c++){
        for(int d=0;d<ALTO_TERRENO;d++){
            terreno.rectImag.x=c*50;
            terreno.rectImag.y=d*50;
            terreno.rectImag.w=50;
            terreno.rectImag.h=50;
            int texturaActual = terreno.textureMap[c][d];
            cout << "textura actual " << texturaActual << endl;
            SDL_RenderCopy(renderizador,terreno.texturas[texturaActual], NULL, &terreno.rectImag);
        }
    }
}
