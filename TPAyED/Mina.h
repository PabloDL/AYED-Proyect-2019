#ifndef __MINA_H__
#define __MINA_H__

#include <iostream>

using namespace std;

typedef struct Mina{
    //posX;posY;codItem;IP;seq1;seq2;seq3;seq4;seq5
    int posX;
    int posY;
    int codItem;
    int IP;
    int seq1;
    int seq2;
    int seq3;
    int seq4;
    int seq5;
}Mina;

string toString(Mina &mina);

#endif // __PARAMETROS_H__
