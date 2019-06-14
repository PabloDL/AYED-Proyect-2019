#include "Cajas.h"

/***********GETTERS AND SETTERS ***************/
string getCodItem (Cajas &cajas) {return cajas.codItem;}
int getCapMaxima(Cajas &cajas) {return cajas.capActual;}
int getCapActual(Cajas &cajas) {return cajas.capMaxima;}

void setCantItem (Cajas &cajas, int cantitem) {cajas.cantitem = cantitem;}
void setCapMaxima(Cajas &cajas, int capActual) {cajas.capActual=capActual;};
void setCapActual(Cajas &cajas, int capMaxima) {cajas.capMaxima=capMaxima;};
void setCodItem(Cajas &cajas, string codItem) {cajas.codItem=codItem;};
/***********GETTERS AND SETTERS ***************/

void crearCajas(Cajas & cajas){
    cajas.cantitem=0;
    cajas.capActual=0;
    cajas.capMaxima=0;
    cajas.codItem="";
}

void eliminarCajas(Cajas & cajas){}
