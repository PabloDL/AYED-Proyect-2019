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

Estados getEstado(Terreno & terreno){return terreno.estadoJuego;}

Locomotora getLocomotora(Terreno & terreno){return terreno.locomotora;}

Lista* getBandidos(Terreno & terreno){return &terreno.bandidos;}

void setBandidos(Terreno & terreno, Lista& bandidos){terreno.bandidos=bandidos;}
/*********************************************************/
void crearTerreno(Terreno& terreno){
    //INICIALIZO MATRIZ DE JUEGO
    terreno.intervaloActual = 0;
    //INICIALIZO JUEGO EN JUGABLE PARA QUE SE EMPIEZE A RENDERIZAR
    terreno.estadoJuego = JUGABLE;
    //INICIALIZO LISTAS
    crearLista(terreno.bandidos, compararListaBandidos, eliminarBandidoDeLista);
    crearLista(terreno.estaciones, compararListaEstaciones, eliminarEstacionDeLista);
    crearLista(terreno.minas, compararListaMinas, eliminarMinasDeLista);
    crearLista(terreno.monedas, compararListaMonedas, eliminarMonedaDeLista);
    //LECTURA DE ARCHIVOS
    cout << "Lectura Parametros" << endl;
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

    cout << "lectura Comanda" << endl;
    Lector lectorComanda;
    crearLector(lectorComanda);
    abrirArchivo(lectorComanda, "comanda.txt");
    terreno.objetivoJuego = leerArchivoComandas(lectorComanda);
    eliminarLector(lectorComanda);

    //INICIALIZO MATRICES QUE SE USARAN PARA VERIFICAR COLISIONES Y TEXTURAS
    for(int i=0; i< ANCHO_TERRENO; i++){
        for(int j=0; j< ALTO_TERRENO; j++){
            terreno.matrizJuego[i][j] = 'T';
            terreno.textureMap[i][j]= rand() % 9 + 0;
            //necesito numeros aleatorios para poder cargar texturas distintas en el fondo
        }
    }
    //FIJO LOS VALORES DE INTERVALOS EN LOS QUE APARECERAN LA PRIMERA MONEDAS Y EL PRIMER BANDIDO
    //SEGUN LOS PARAMETROS LEIDOS
    terreno.intervalosAparicionProximaMoneda = 1 + terreno.intervaloActual +rand()% (getIm(terreno.parametros)+terreno.intervaloActual);
    terreno.intervalosAparicionProximoBandido= 1 + terreno.intervaloActual +rand()% (getIb(terreno.parametros)+terreno.intervaloActual);

    //SEGUN LOS ARCHIVOS CARGADOS CREO LAS MINAS Y LA ESTACION
    aparecerMina(terreno);
    aparecerEstacion(terreno);
    //APAREZCO LOCOMOTORA EN JUEGO
    aparecerLocomotora(terreno);
    //EN CASO DE QUE EL INTERVALO DE APARICION LO REQUIERA APAREZCO MONEDA EN TIEMPO 0
    actualizarMonedas(terreno);
}

void eliminarTerreno(Terreno& terreno){
    //ELIMINO TEXTURAS DE TERRENO
     for (int i=0 ; i < 10;i++){
        SDL_DestroyTexture(terreno.texturas[i]);
    }
    //ELIMINO LAS LISTAS CREADAS, CADA LISTA ELIMINA SU CONTENIDO LLAMANDO AL DESTRUCTOR
    eliminarLista(terreno.minas);
    eliminarLista(terreno.estaciones);
    eliminarLista(terreno.monedas);
    eliminarLista(terreno.bandidos);

}

void aparecerLocomotora(Terreno& terreno){
    //CREO LOCOMOTORA
    crearLocomotora(terreno.locomotora);
}

void aparecerMina(Terreno& terreno){
    if (!listaVacia(terreno.minas )){
        NodoLista * ptrNodo = primero(terreno.minas);
        while (ptrNodo != finLista()){
            Mina * m = (Mina*) ptrNodo->ptrDato;
            //ACTUALIZO EN MATRIZ LA POSICION DE LA MINA
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
    //ACTUALIZO EN MATRIZ LA POSICION DE ESTACION
    terreno.matrizJuego[getX(p)][getY(p)] = 'E';

}

void actualizarMonedas(Terreno& terreno){
    NodoLista * ptrNodo = primero(terreno.monedas);
    bool eliminarNodoMoneda = false;
     //RECORRO PARA SABER CUANDO SE LLEGA AL FINAL DEL TIEMPO POR CADA MONEDA
    while(!listaVacia(terreno.monedas) && ptrNodo != finLista()){
        Moneda * ptrMonedaActual = (Moneda*) ptrNodo->ptrDato;
        if (getAparicion(*ptrMonedaActual) + getDuracion(*ptrMonedaActual) == terreno.intervaloActual){
               //LA MONEDA LLEGO AL TIEMPO DE SU VIDA ENTONCES DEBE SER QUITADA DEL JUEGO
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
    //AGREGO SI CORRESPONDE SEGUN INTERVALO APARICION UNA NUEVA MONEDA
    if (terreno.intervalosAparicionProximaMoneda == terreno.intervaloActual){
        aparecerMoneda(terreno);
        //SI AGREGUE MONEDA FIJO NUEVO TIEMPO DE APARICION
        terreno.intervalosAparicionProximaMoneda = terreno.intervaloActual + 1 +rand()% (getIm(terreno.parametros));
    }
}

void actualizarBandidos(Terreno& terreno){
    NodoLista * ptrNodo = primero(terreno.bandidos);
    bool eliminarNodoBandido = false;
     //RECORRO PARA SABER CUANDO SE LLEGA AL FINAL DEL TIEMPO
    while(!listaVacia(terreno.bandidos) && ptrNodo != finLista()){
        Bandido * ptrBandidoActual = (Bandido*) ptrNodo->ptrDato;
        if (getIntervaloHastaAparicion(*ptrBandidoActual) + getTiempoVida(*ptrBandidoActual) == terreno.intervaloActual){
               //EL BANDIDO LLEGO AL TIEMPO DE SU VIDA ENTONCES DEBE SER QUITADO DEL JUEGO
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
        //SI AGREGUE BANDIDO FIJO NUEVO TIEMPO DE APARICION
        terreno.intervalosAparicionProximoBandido = terreno.intervaloActual + 1 +rand()% (getIb(terreno.parametros));
    }
}

void nuevaProduccionMinas(Terreno& terreno){
    //POR CADA INTERVALO AGREGO UNA PRODUCCION DE MINAS
    NodoLista * ptrNodo = primero(terreno.minas);;
    while(! listaVacia(terreno.minas) && ptrNodo != finLista()){
        Mina * minaActual = (Mina*) ptrNodo->ptrDato;
        crearCaja(*minaActual);
        ptrNodo = siguiente(terreno.minas, ptrNodo);
    }
}

void aparecerMoneda(Terreno& terreno){
      //CREO RANDOM ENTRE IM (MAXIMO INTERVALO DE SEPARACION y EL INTERVALO ACTUAL)
      Moneda * nuevaMoneda = new Moneda;
      int aparicion = terreno.intervaloActual;
      int duracion= 1 + rand()% (getVm(terreno.parametros));
      int cantidad=1;
      int x = rand()% (ANCHO_TERRENO);
      int y = rand()% (ALTO_TERRENO);
      Posicion p;
      crearPosicion(p);
      moverPosicion(p,x,y);
      crearMoneda(*nuevaMoneda);
      setAparicion(*nuevaMoneda, aparicion);
      setDuracion(*nuevaMoneda, duracion);
      setCantidad(*nuevaMoneda, cantidad);
      setPosicion(*nuevaMoneda, p);

      //AGREGO A LISTA MONEDAS Y A MATRIZ
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

      Posicion posLocomotora = getPosicion(terreno.locomotora);

      if (enCercanias(posLocomotora, p, getAreaCobertura(*nuevoBandido))){
        //SI LA LOCOMOTORA ESTA EN POSICION CREO EL BANDIDO CERCANO PERO NO EN LA MISMA POSICION
        //PARA QUE NO CAIGA EN EL MISMO LUGAR
        p = alejarPosicion(posLocomotora,p, getAreaCobertura(*nuevoBandido));
        cout << "Bandido creado en misma posicion que locomotora -> nueva posicion [" << getX(p)
        << ";" <<getY(p) << "]" << endl;
      }
      setPosicion(*nuevoBandido, p);
      //AGREGO A LISTA BANDIDOS Y A MATRIZ
      adicionarFinal(terreno.bandidos,nuevoBandido);
      terreno.matrizJuego[getX(p)][getY(p)] = 'B';

}

void actualizarTerreno(Terreno& terreno){
    //si es una iteracion de render solo va a actualizar la posicion de los objetos que se mueven
    //no se chequea ninguna logica del juego durante iteraciones de render;
    terreno.intervaloActual++;

    nuevaProduccionMinas(terreno);
    actualizarBandidos(terreno);
    actualizarMonedas(terreno);

    if (terreno.estadoJuego == JUGABLE)
        avanzarLocomotora(terreno);
    //REVISAR CAMBIOS
    chequearColisiones(terreno);

}

void avanzarLocomotora(Terreno &terreno){
    //AVANZO LOCOMOTORA Y VAGONES
    Posicion nuevaPosicion;
    crearPosicion(nuevaPosicion);
    Locomotora locomotora = getLocomotora(terreno);
    Posicion pTemp = getPosicion(locomotora); //guardo posicion actual locomotora
    int dTemp = getDireccion(locomotora); //guardo direccion actual locomotora
    switch (terreno.locomotora.direccion){
        case 0: { //VA HACIA IZQUIERDA
            moverPosicion(nuevaPosicion,getX(pTemp)-1,getY(pTemp));
            break;
        }
        case 1: { //VA HACIA DERECHA
            moverPosicion(nuevaPosicion,getX(pTemp)+1,getY(pTemp));
            break;
        }
        case 2: { //VA HACIA ARRIBA
            moverPosicion(nuevaPosicion,getX(pTemp),getY(pTemp)-1);
            break;
        }
        case 3: { //VA HACIA ABAJO
            moverPosicion(nuevaPosicion,getX(pTemp),getY(pTemp)+1);
            break;
        }
        default:
            moverPosicion(nuevaPosicion,getX(pTemp),getY(pTemp));
            break;
    }
    setPosicion(locomotora, nuevaPosicion);  //SETEO NUEVA POSICION DE LOCOMOTORA
    setLocomotora(terreno,locomotora); //SETEO LOCOMOTORA actualizada en terreno (ira directamente?)
    Lista vagones = getListaVagones(locomotora);

    if (!listaVacia(vagones)){

        NodoLista * ptrNodo = primero(vagones);

        while(!listaVacia(vagones) && ptrNodo != finLista()){
            Vagon * vagonActual = (Vagon*) ptrNodo->ptrDato;
            Posicion posVagonAnterior = getPosicion(*vagonActual);
            int dirVagonAnterior = getDireccion(*vagonActual);
            moverPosicion(vagonActual->posicion, getX(pTemp),getY(pTemp));
            setDireccion(*vagonActual, dTemp);
            pTemp = posVagonAnterior;
            dTemp = dirVagonAnterior;
            ptrNodo = siguiente(vagones, ptrNodo);
        }
    }
}

void chequearColisiones(Terreno & terreno){
    Posicion posLocomotora = getPosicion(terreno.locomotora);
    if (getX(posLocomotora) > ANCHO_TERRENO || getY(posLocomotora) > ALTO_TERRENO
                || (getX(posLocomotora) < 0) || getY(posLocomotora) < 0 ){
        terreno.estadoJuego = GAMEOVER_FUERALIMITES; // SI SALGO DEL CUADRADO TERMINA JUEGO
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
                        setMonedasAdquiridas(terreno.locomotora, 0);
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
                            cout << "Almaceno caja en Locomotora, recibo -> " << cajaARecibir->cantitem << " de"
                            << cajaARecibir->codItem<< endl;
                        }
                        else{ // SI NO HAY UGAR SE PENALIZA ELIMINANDO PRODUCCION
                            cout << "Locomotora sin lugar -> Vacio produccion"<< endl;
                            eliminarProduccion(*minaActual);
                        }
                    }
                }
            ptrNodo = siguiente(terreno.minas, ptrNodo);
            }
        }
        else if ( terreno.matrizJuego[getX(posLocomotora)][getY(posLocomotora)] == 'T'){
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
            //VERIFICA SI LOCOMOTORA O SUS VAGONES ESTAN EN CERCANIAS DEL RADAR
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
            if(pelear){ //PELEO CON BANDIDO
                cout << "Colision con bandido, pos [" << getX(pBandido) <<";" <<getY(pBandido) << "]"
                     << "Solicita: " << getCantidad(*bandido) << "de " << getCodItem(*bandido)   << endl;
                int alcanza = pagarBandido(terreno.locomotora, getCantidad(*bandido), getCodItem(*bandido));
                if (alcanza==0){
                    bool locomotoraVacia = sacarVagon(terreno.locomotora);
                    if (locomotoraVacia){ // EN ESTE CASO EL BANDIDO NO PUDO SACAR VAGONES ENTONCES SE PIERDE
                        terreno.estadoJuego = GAMEOVER_BANDIDO;
                    }
                }
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
            //VERIFICA SI TREN O VAGON ESTA EN ESA POSICION
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
                cout << "Locomotora recolecta moneda de -> " << getCantidad(*moneda) << endl;
                obtenerMoneda(terreno.locomotora, (*moneda));  //OJO ESTA MAL HAY Q USAR PUNTEROS
                encontrado=false;
                //ELIMINAR MONEDAAAAAAAAAAAAAAA
                ptrNodoEliminar = ptrNodoMoneda;
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

void renderizarTerreno(Terreno& terreno, SDL_Renderer *renderizador){
    for(int index_y=0;index_y<ALTO_TERRENO;index_y++){
        for(int index_x=0;index_x<ANCHO_TERRENO;index_x++){
            terreno.rectImag.x=index_x*40;
            terreno.rectImag.y=index_y*40;
            terreno.rectImag.w=40;
            terreno.rectImag.h=40;
            int texturaActual = terreno.textureMap[index_x][index_y];
            SDL_RenderCopy(renderizador,terreno.texturas[texturaActual], NULL, &terreno.rectImag);
        }
    }
}

void imprimirMatriz(Terreno &t){
    for(int i=0; i< ALTO_TERRENO; i++){
        for(int j=0; j<ANCHO_TERRENO ; j++){
            cout << "[" << t.matrizJuego[j][i] <<"]" ;
        }
        cout << endl;
    }
}

bool verificarComanda(Terreno &t){
    bool comandaCompletada = true;
    Locomotora l;
    l = getLocomotora(t);
     //ITEMS -> oro=0, plata=1, bronce=2, platino=3, roca=4,
    //recorro lista vagones para ver si se completa objetivo Juego
    if (!listaVacia(t.objetivoJuego)){
        NodoLista * ptrNodoObjetivos = primero(t.objetivoJuego);
        while(ptrNodoObjetivos != finLista() && comandaCompletada){
            int sumaItem = 0;
            Comanda * comandaActual = (Comanda*) ptrNodoObjetivos->ptrDato;
            Lista vagones = getListaVagones(l);
            NodoLista * ptrNodoVagon = primero(vagones);
            while(ptrNodoVagon != finLista()){
                Vagon * vagonActual = (Vagon*) ptrNodoVagon->ptrDato;
                if (getTipoVagon(*vagonActual) == getCodItem(*comandaActual)){
                    sumaItem=sumaItem + getCapVagonUsada(*vagonActual);
                }
                ptrNodoVagon = siguiente(vagones, ptrNodoVagon);
            }
            if (sumaItem < getCantidad(*comandaActual)){
            //NO TENGO La CANTIDAD DE ITEMS Q NECESITO PARA EL ITEM
                comandaCompletada = false;
            }
            ptrNodoObjetivos = siguiente(t.objetivoJuego, ptrNodoObjetivos);
        }
    }
    return comandaCompletada;
}

int getTiempoEntreIntervalos(Terreno& terreno){
    return getS(terreno.parametros);
}

void agregarMensajes(Terreno & terreno, SDL_Renderer *renderizador){

    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    terreno.Sans = TTF_OpenFont("assets/fonts/CFFarWest-Regular.ttf", 8); //this opens a font style and sets a size
    if(!terreno.Sans ) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }

    terreno.White = {0,0,0,0};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
    terreno.surfaceMessage = TTF_RenderText_Solid(terreno.Sans, "COMANDA ES", terreno.White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
    terreno.Message = SDL_CreateTextureFromSurface(renderizador, terreno.surfaceMessage); //now you can convert it into a texture

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = ANCHO_TERRENO*40;  //controls the rect's x coordinate
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 20; // controls the height of the rect

    //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

    //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

    SDL_RenderCopy(renderizador, terreno.Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
    //Don't forget too free your surface and texture
}

