#include "Comanda.h"

/************GETTERS AND SETTERS*********************/
string getCodItem(Comanda &comanda){
    return comanda.codItem;
}

int getCantidad(Comanda &comanda){
    return comanda.cantidad;
}

void setCodItem(Comanda &comanda, string codItem){
    comanda.codItem = codItem;
}

void setCantidad(Comanda &comanda, int cantidad){
    comanda.cantidad = cantidad;
}

/***************************************************/

void toString(Comanda &comanda){
    cout << comanda.codItem << "|" << comanda.cantidad << endl;
}
