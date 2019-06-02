#include "Cajas.h"

string getItem (Cajas &cajas) {return cajas.codItem;}

void setCantItem (Cajas &cajas,int cantitem) {cajas.cantitem = cantitem;}

int getCapMaxima(Cajas &cajas) {return cajas.capActual;}
int getCapActual(Cajas &cajas) {return cajas.capMaxima;}

void getCapMaxima(Cajas &cajas, int capActual) {cajas.capActual=capActual;};
void getCapActual(Cajas &cajas, int capMaxima) {cajas.capMaxima=capMaxima;};
