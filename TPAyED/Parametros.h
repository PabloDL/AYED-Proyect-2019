#ifndef __PARAMETROS_H__
#define __PARAMETROS_H__

#include <iostream>

using namespace std;

typedef struct Parametros{
    string s;
    string p;
    string a;
    string posXE;
    string posYE;
    string iM;
    string vM;
    string iB;
    string vB;
    string iP;
}Parametros;

string toString(Parametros &parametros);

#endif // __PARAMETROS_H__
