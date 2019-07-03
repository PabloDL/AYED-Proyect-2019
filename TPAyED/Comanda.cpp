#include "Comanda.h"

/************GETTERS AND SETTERS*********************/
string getCodItem(Comanda &comanda){return comanda.codItem;}
int getCantidad(Comanda &comanda){return comanda.cantidad;}
bool getCompletado(Comanda &comanda){return comanda.completado;}

void setCodItem(Comanda &comanda, string codItem){comanda.codItem = codItem;}
void setCantidad(Comanda &comanda, int cantidad){comanda.cantidad = cantidad;}
void setCompletado(Comanda &comanda, bool completado){comanda.completado=completado;}
/***************************************************/

void crearComanda(Comanda &comanda){}

void eliminarComanda(Comanda &comanda){}

void toString(Comanda &comanda){
    cout << comanda.codItem << "|" << comanda.cantidad << endl;
}
