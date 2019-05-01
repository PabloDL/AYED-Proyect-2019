#ifndef __COMANDA_H__
#define __COMANDA_H__

#include <iostream>

using namespace std;

typedef struct Comanda{
    string codItem;
    int cantidad;
}Comanda;

string toString(Comanda &comanda);

#endif // __PARAMETROS_H__
