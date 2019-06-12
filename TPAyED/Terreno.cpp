#include "Terreno.h"
#include "Mina.h"

using namespace std;

/************GETTERS AND SETTERS*********************/

//getters y setters
void setLocomotora(Terreno & terreno, Locomotora & locomotora){
    terreno.locomotora = locomotora;
}

Lista* getMonedas(Terreno & terreno){return &(terreno.monedas);}

void setMonedas(Terreno & terreno, Lista& monedas){terreno.monedas=monedas;}

/*
crearTerreno(Terreno& terreno, int alto, int ancho){
    aparecerLocomotora(terreno);
    get
}
*/

Locomotora getLocomotora(Terreno & terreno){return terreno.locomotora;}

Lista* getBandidos(Terreno & terreno){return &terreno.bandidos;}

void setBandidos(Terreno & terreno, Lista& bandidos){terreno.bandidos=bandidos;}
/*********************************************************/
void crearTerreno(Terreno& terreno){
    //INICIALIZO MATRIZ DE JUEGO
    terreno.intervaloActual = 0;
    //INICIALIZO LISTAS
    crearLista(terreno.bandidos, compararListaBandidos, eliminarBandidoDeLista);
    crearLista(terreno.estaciones, compararListaEstaciones, eliminarEstacionDeLista);
    crearLista(terreno.minas, compararListaMinas, eliminarMinasDeLista);
    crearLista(terreno.monedas, compararListaMonedas, eliminarMonedaDeLista);

    Lector lector;
    crearLector(lector);
    abrirArchivo(lector, "parametros.txt");
    terreno.parametros = leerArchivoParametros(lector);
    eliminarLector(lector);

    cout << "lectura Minas" << endl;
    Lector lectorMinas;
    crearLector(lectorMinas);
    abrirArchivo(lectorMinas, "minas.txt");
    terreno.minas = leerArchivoMinas(lectorMinas);
    eliminarLector(lectorMinas);

    for(int i=0; i< ANCHO_TERRENO; i++){
        for(int j=0; j< ALTO_TERRENO; j++){
            terreno.matrizJuego[i][j] = 'T';
            terreno.textureMap[i][j]= rand() % 9;

            //necesito numeros aleatorios para poder cargar texturas distintas en el fondo
        }
    }
    terreno.intervalosAparicionProximaMoneda = terreno.intervaloActual +rand()% (getIm(terreno.parametros)+terreno.intervaloActual);
    terreno.intervalosAparicionProximoBandido= terreno.intervaloActual +rand()% (getIb(terreno.parametros)+terreno.intervaloActual);
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
    actualizarMonedas(terreno);
    //CREAR bandido  -> no tienen q aparecer inmediatamente
    actualizarBandidos(terreno);
    ////ACTUALIZAR EN MATRIZ POSICIONES DE ELEMENTOS
    actualizarMatrizJuego(terreno);
}

void actualizarMatrizJuego(Terreno &terreno){

}

void eliminarTerreno(Terreno& terreno){}

void aparecerLocomotora(Terreno& terreno){
    crearLocomotora(terreno.locomotora);
}

void aparecerMina(Terreno& terreno){

    if (!listaVacia(terreno.minas )){
        NodoLista * ptrNodo = primero(terreno.minas);
        while (ptrNodo != finLista()){
            Mina * m = (Mina*) ptrNodo->ptrDato;
            terreno.matrizJuego[getPosX(*m)][getPosY(*m)] = 'M';
            ptrNodo = siguiente(terreno.minas, ptrNodo);
        }
    }
}

void aparecerEstacion(Terreno& terreno){
    Estacion * e = new Estacion;
    crearEstacion(*e);

    Posicion p;
    crearPosicion(p);
    moverPosicion(p, getPosXE(terreno.parametros), getPosYE(terreno.parametros));
    setPosicion(*e, p);

    adicionarPrincipio(terreno.estaciones, e);
    terreno.matrizJuego[getX(p)][getY(p)] = 'E';

}

void actualizarMonedas(Terreno& terreno){
    //obtengo moneda si corresponde en intervalo, la agrego a la matriz e elimino
    NodoLista * ptrNodo = primero(terreno.monedas);
    bool eliminarNodoMoneda = false;
     //RECORRO PARA SABER CUANDO SE LLEGA AL FINAL DEL TIEMPO
    while(!listaVacia(terreno.monedas) && ptrNodo != finLista()){
        Moneda * ptrMonedaActual = (Moneda*) ptrNodo->ptrDato;
        if (getAparicion(*ptrMonedaActual) + getDuracion(*ptrMonedaActual) == terreno.intervaloActual){
                //Llego al final del tiempo de vida
               Posicion p = getPosicion(*ptrMonedaActual);
               terreno.matrizJuego[getX(p)][getY(p)] = 'T';
               eliminarNodoMoneda = true;
        }
        NodoLista * ptrNodoActual = ptrNodo;
        ptrNodo = siguiente(terreno.monedas, ptrNodo);
        if (eliminarNodoMoneda){
            eliminarNodo(terreno.monedas, ptrNodoActual);
            eliminarNodoMoneda = false;
        }
    }
    //AGREGO SI CORRESPONDE UNA NUEVA MONEDA
    if (terreno.intervalosAparicionProximaMoneda == terreno.intervaloActual){
        aparecerMoneda(terreno);
        terreno.intervalosAparicionProximaMoneda = terreno.intervaloActual + 1 +rand()% (getIm(terreno.parametros)+terreno.intervaloActual);
    }
}

void actualizarBandidos(Terreno& terreno){
    //obtengo moneda si corresponde en intervalo, la agrego a la matriz e elimino
    NodoLista * ptrNodo = primero(terreno.bandidos);
    bool eliminarNodoBandido = false;
     //RECORRO PARA SABER CUANDO SE LLEGA AL FINAL DEL TIEMPO
    while(!listaVacia(terreno.bandidos) && ptrNodo != finLista()){
        Bandido * ptrBandidoActual = (Bandido*) ptrNodo->ptrDato;
        if (getIntervaloHastaAparicion(*ptrBandidoActual) + getTiempoVida(*ptrBandidoActual) == terreno.intervaloActual){
                //Llego al final del tiempo de vida
               Posicion p = getPosicion(*ptrBandidoActual);
               terreno.matrizJuego[getX(p)][getY(p)] = 'T';
               eliminarNodoBandido = true;
        }
        NodoLista * ptrNodoActual = ptrNodo;
        ptrNodo = siguiente(terreno.bandidos, ptrNodo);
        if (eliminarNodoBandido){
            eliminarNodo(terreno.bandidos, ptrNodoActual);
            eliminarNodoBandido = false;
        }
    }
    //AGREGO SI CORRESPONDE UNA NUEVO BANDIDO
    if (terreno.intervalosAparicionProximoBandido == terreno.intervaloActual){
        aparecerBandido(terreno);
        terreno.intervalosAparicionProximoBandido = terreno.intervaloActual + 1 +rand()% (getIb(terreno.parametros)+terreno.intervaloActual);
        cout << "proxima aparciacion bandido = " << terreno.intervalosAparicionProximoBandido << endl;
    }
}

void nuevaProduccionMinas(Terreno& terreno){
    //Recorro las listas de minas y agrego un item a cada elemento
    NodoLista * ptrNodo = primero(terreno.minas);;
    while(! listaVacia(terreno.minas) && ptrNodo != finLista()){
        Mina * minaActual = (Mina*) ptrNodo->ptrDato;
        crearCaja(*minaActual); //Agrego caja a mina Actual
        ptrNodo = siguiente(terreno.minas, ptrNodo);
    }
}

void aparecerMoneda(Terreno& terreno){
      //CREO RANDOM ENTRE IM (MAXIMO INTERVALO DE SEPARACION y EL INTERVALO ACTUAL)
      //que sera el tiempo de aparacicion de una nueva moneda
      int aparicion = terreno.intervaloActual;
      int duracion=1 + rand()% (getVm(terreno.parametros));
      int cantidad=1;
      int x = rand()% (ANCHO_TERRENO);
      int y = rand()% (ALTO_TERRENO);
      Posicion p;
      crearPosicion(p);
      moverPosicion(p,x,y);

      Moneda * nuevaMoneda = new Moneda;
      crearMoneda(*nuevaMoneda);
      setAparicion(*nuevaMoneda, aparicion);
      setDuracion(*nuevaMoneda, duracion);
      setCantidad(*nuevaMoneda, cantidad);
      setPosicion(*nuevaMoneda, p);

      //AGREGO A LISTA monedas Y A MATRIZ
      if(listaVacia(terreno.monedas)){
        adicionarPrincipio(terreno.monedas,nuevaMoneda);
      }
      else{
        adicionarFinal(terreno.monedas,nuevaMoneda);
      }
      terreno.matrizJuego[getX(p)][getY(p)] = 'm';
}

void aparecerBandido(Terreno& terreno){
      //CREO RANDOM ENTRE IM (MAXIMO INTERVALO DE SEPARACION y EL INTERVALO ACTUAL)
      //que sera el tiempo de aparacicion de una nueva moneda
      //int intervaloHastaAparicion; ??
      int aparicion=terreno.intervaloActual;
      int tiempoVida=1 + rand()% (getVb(terreno.parametros));
      int cantidad= 1 + rand()% (MAXIMO_ROBO_BANDIDO);
      int x = rand()% (ANCHO_TERRENO);
      int y = rand()% (ALTO_TERRENO);
      Posicion p;
      crearPosicion(p);
      moverPosicion(p,x,y);

      Bandido * nuevoBandido = new Bandido;
      crearBandido(*nuevoBandido);
      setIntervaloHastaAparicion(*nuevoBandido, aparicion);
      setTiempoVida(*nuevoBandido, tiempoVida);
      setCantidad(*nuevoBandido, cantidad);
      setPosicion(*nuevoBandido, p);
      //AGREGO A LISTA BANDIDOS Y A MATRIZ
      adicionarFinal(terreno.bandidos,nuevoBandido);
      terreno.matrizJuego[getX(p)][getY(p)] = 'B';

}

//YA esta todo cargado, hay q actualizar
void actualizarTerreno(Terreno& terreno, int sentido){
    terreno.intervaloActual++;
    //Actualizar minas
    nuevaProduccionMinas(terreno);
    //actualizar bandido //chequea si tiene q aparecer un bandido  o eliminar uno
    actualizarBandidos(terreno);
    //actualizar monedas //chequea si tiene q aparecer una moneda  o eliminar uno
    actualizarMonedas(terreno);
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
            terreno.estadoJuego = LOCOMOTORADETENIDA; // DETENGO LOCOMOTORA
            NodoLista * ptrNodo = primero(terreno.minas);
            while(! listaVacia(terreno.minas) && ptrNodo != finLista()){
                Mina * minaActual = (Mina*) ptrNodo->ptrDato;
                Posicion posMina;
                crearPosicion(posMina);
                moverPosicion(posMina,getPosX(*minaActual), getPosY(*minaActual));
                if (mismaPosicion(posMina, posLocomotora)){
            //SI ES MISMA ESTACION -> VENDO VAGON
                    Cajas * cajaARecibir = proximaCaja((*minaActual)); //DEVUELVE LA MINA TOP DE LA COLA
                    if (cajaARecibir != NULL){  //SI ES NULL NO HAY PRODCCION
                        if (hayLugarParaCajaEnLocomotora(terreno.locomotora, getCapMaxima(*cajaARecibir), getCodItem(*cajaARecibir))){
                            almacenarCaja(terreno.locomotora, *cajaARecibir);
                        }
                        else{ // SI NO HAY UGAR SE PENALIZA ELIMINANDO PRODUCCION
                                cout << "no hay lugar vacio produccion"<< endl;
                            eliminarProduccion(*minaActual);
                        }
                    }
                }
            ptrNodo = siguiente(terreno.minas, ptrNodo);
            }
        }
        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'T'){
            //no tengoque hacer nada ya avanzo locomotora
            //PENSAR SI VA ACA O AFUERA -> TIene q ir afuera para que cuando en el juego
            //se toca la tecla para avanzar avance antes de verificar posicion
        }
        //VEO COLISIONES CON BANDIDOS
        locomotoraEnRadarBandido(terreno);
        //VEO COLISIONES CON MONEDAS
        locomotoraRecoletaMonedas(terreno);

    }

}

void locomotoraEnRadarBandido(Terreno& terreno){
    bool pelear = false;

    Locomotora l = getLocomotora(terreno);
    Posicion pLocomotora = getPosicion(l);
    Lista* bandidos = getBandidos(terreno);
    if (!listaVacia(*bandidos)){
        NodoLista * ptrNodoBandido = primero(*bandidos);

        while(!listaVacia(*bandidos) && ptrNodoBandido != finLista() /*&& !pelear*/){
            Bandido * bandido = (Bandido*) ptrNodoBandido->ptrDato;
            Posicion pBandido = getPosicion(*bandido);
            NodoLista * ptrBandidoEliminar;
            //veo si hay algun tren o vagon esta en esa posicion
            cout << "bandido pos [" << getX(pBandido) <<";" <<getY(pBandido) << "]";
            cout << "VS [" << getX(pLocomotora) <<";" <<getY(pLocomotora) << "]";
            pelear = enCercanias(pBandido, pLocomotora, getAreaCobertura(*bandido));
            if (!pelear){
                Lista vagones = getListaVagones(terreno.locomotora);
                NodoLista * ptrNodo = primero(vagones);
                //LO BUSCO EN LOS VAGONES
                while(!listaVacia(vagones) && ptrNodo != finLista() && !pelear){

                    Vagon * vagon = (Vagon*) ptrNodo->ptrDato;
                    Posicion pVagon = getPosicion(*vagon);
                    pelear = enCercanias(pBandido, pVagon, getAreaCobertura(*bandido));
                    cout << "bandido pos [" << getX(pBandido) <<";" <<getY(pBandido) << "]";
                    cout << "VS [" << getX(pVagon) <<";" <<getY(pVagon) << "]";
                    ptrNodo = siguiente(vagones, ptrNodo);
                }
            }
            if(pelear){ //PELEO CON BANDIDO
                //adicionarPrincipio(bandidosAPelear,bandido);  //ADICIONO TODOS LOS BANDIDOS Q ESTAN CERCA
                cout << "ROBO ITEM LOCOMOTORA, bandido pos [" << getX(pBandido) <<";" <<getY(pBandido) << "]" << endl;
////FALTAAAAAAAAAAAAAAAA PELEAR CON BANDIDO
                //LOCOMOTORA.PELEARCONBANDIDO(LOCOMOTORA,BANDIDO);
                ptrBandidoEliminar = ptrNodoBandido;
                ptrNodoBandido = siguiente(*bandidos, ptrNodoBandido);
                //ACTUALIZO MATRIZ CON NUEVO VALOR
                terreno.matrizJuego[getX(pBandido)][getY(pBandido)] = 'T';
                eliminarNodo(*bandidos,ptrBandidoEliminar);
                pelear=false;
            }
            else{
                ptrNodoBandido = siguiente(*bandidos, ptrNodoBandido);
            }
        }
    }
}

void locomotoraRecoletaMonedas(Terreno& terreno){
    bool encontrado = false;
    Lista monedasABorrar;
    crearLista(monedasABorrar, compararListaMonedas, eliminarMonedaDeLista);

    Lista* monedas = getMonedas(terreno);
    Locomotora l = getLocomotora(terreno);
    Posicion pLocomotora = getPosicion(l);

    if (!listaVacia(*monedas)){
        NodoLista * ptrNodoMoneda = primero(*monedas);

        while(!listaVacia(*monedas) && ptrNodoMoneda != finLista()){
            Moneda * moneda = (Moneda*) ptrNodoMoneda->ptrDato;
            Posicion pMoneda = getPosicion(*moneda);
            //veo si hay algun tren o vagon esta en esa posicion
            encontrado = mismaPosicion(pMoneda,pLocomotora);
            NodoLista * ptrNodoEliminar;
            if (!encontrado){
                Lista vagones = getListaVagones(terreno.locomotora);
                NodoLista * ptrNodo = primero(vagones);
                //LO BUSCO EN LOS VAGONES
                while(!listaVacia(vagones) && ptrNodo != finLista() && !encontrado){
                    Vagon * vagon = (Vagon*) ptrNodo->ptrDato;
                    Posicion pVagon = getPosicion(*vagon);
                    encontrado = mismaPosicion(pMoneda,pVagon);
                    ptrNodo = siguiente(vagones, ptrNodo);
                }
            }
            if(encontrado){
//                    obtenerMoneda(l,*moneda);  //VERIFICAR SI FUNCIONA
                obtenerMoneda(terreno.locomotora, (*moneda));  //OJO ESTA MAL HAY Q USAR PUNTEROS
                encontrado=false;
                //ELIMINAR MONEDAAAAAAAAAAAAAAA
                ptrNodoEliminar = ptrNodoMoneda;
//                cout << "ENCONTRO MONEDA!! AHORA TIENE: -> " << terreno.locomotora.monedasAdquiridas;
                ptrNodoMoneda = siguiente(*monedas, ptrNodoMoneda);
                terreno.matrizJuego[getX(pMoneda)][getY(pMoneda)] = 'T';
                eliminarNodo(*monedas, ptrNodoEliminar); //SI ENCONTRE ELIMINO MONEDA
            }
            else{
                ptrNodoMoneda = siguiente(*monedas, ptrNodoMoneda); //SI NO CHOQUE SOLO AVANZO MONEDA
            }

        }
    }
}

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

void imprimirMatriz(Terreno &t){
    for(int i=0; i< ANCHO_TERRENO; i++){
        for(int j=0; j< ALTO_TERRENO; j++){
            cout << "[" << t.matrizJuego[j][i] <<"]" ;
        }
        cout << endl;
    }
}

