#include "Juego.h"
#include "Terreno.h"
#include "locomotora.h"
/*GETTERS Y SETTERS*/

Terreno* getTerreno(Juego& juego){
   return juego.terreno;
}

/*-----------------------------*/
void crearJuego(Juego& juego, const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    juego.terreno = new Terreno;
    juego.counter = 0;
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        std::cout << "subsistemas inicializados..." << std::endl;
        juego.ventana = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(juego.ventana){
            std::cout << "Ventana creada..." << std::endl;
        }
        juego.renderizador = SDL_CreateRenderer(juego.ventana, -1, 0);
        if(juego.renderizador){
            SDL_SetRenderDrawColor(juego.renderizador, 101, 255, 100, 255);
            std::cout << "Renderizador creado..." << std::endl;
        }
        juego.estaCorriendo = true;

        crearTerreno(*juego.terreno);
    }
    else{
        juego.estaCorriendo = false;
    }
}

void salirJuego(Juego& juego){
    SDL_DestroyWindow(juego.ventana);
    SDL_DestroyRenderer(juego.renderizador);
    SDL_Quit();
    std::cout << "Se salio del Juego" << std::endl;
}

void manejarEventos(Juego& juego, SDL_Event & event){

//    SDL_Event evento;
//    SDL_PollEvent(&evento);
//cout << "evento: " << evento.type << endl;
//    switch (evento.type){
//        case SDL_QUIT:
//            juego.estaCorriendo = false;
//            system("pause");
//            break;
//        case SDL_KEYDOWN:
//            /* Check the SDLKey values and move change the coords */
//            switch( evento.key.keysym.sym ){
//                case SDLK_LEFT:
//                    juego.terreno->locomotora.direccion = 0;
//                    break;
//                case SDLK_RIGHT:
//                    juego.terreno->locomotora.direccion = 1;
//                    break;
//                case SDLK_UP:
//                    juego.terreno->locomotora.direccion = 2;
//                    break;
//                case SDLK_DOWN:
//                    system("pause");
//                    juego.terreno->locomotora.direccion = 3;
//                    break;
//                default:
//                    break;
//            }
//        default:
//            break;
//    }
while(SDL_PollEvent(&event)) {
    switch(event.type)
    {
    case SDL_WINDOWEVENT:
        switch(event.window.event)
        {
        case SDL_WINDOWEVENT_ENTER:
            cout << "entered" << endl;
            break;

        case SDL_WINDOWEVENT_LEAVE:
            cout << "left" << endl;
            break;
        }
        break;

    case SDL_KEYDOWN:
            switch( event.key.keysym.sym ){
                case SDLK_LEFT:
                    juego.terreno->locomotora.direccion = 0;
                    break;
                case SDLK_RIGHT:
                    juego.terreno->locomotora.direccion = 1;
                    break;
                case SDLK_UP:
                    juego.terreno->locomotora.direccion = 2;
                    break;
                case SDLK_DOWN:
                    juego.terreno->locomotora.direccion = 3;
                    break;
                default:
                    break;
            }
        break;
    }
}
}

void actualizar(Juego& juego){
    juego.counter++;
    //AGREGAR FUNCIONES PARA ACTUALIZAR OBJETOS
    actualizarTerreno(*juego.terreno);




    std::cout << juego.counter << std::endl;
}

void renderizar(Juego& juego){
    if(juego.counter == 1){
        cargarTexturas(juego);
    }
    cout << juego.counter << endl;
    SDL_RenderClear(juego.renderizador);

    renderizarTerreno(*(juego.terreno), juego.renderizador);
    renderizarLocomotora(juego.terreno->locomotora, juego.renderizador, juego.counter);
    //AGREGAR FUNCIONES PARA RENDERIZAR OBJETOS

    SDL_RenderPresent(juego.renderizador);
}

bool corriendo(Juego& juego){
    return juego.estaCorriendo;
}


void cargarTexturas(Juego& juego){
    cargarTexturasTerreno( *juego.terreno, juego.renderizador);
    cargarTexturasLocomotora( juego.terreno->locomotora , juego.renderizador);
}
