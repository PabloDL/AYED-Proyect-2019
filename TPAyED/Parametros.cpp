#include "Parametros.h"
/************GETTERS AND SETTERS*********************/
int getS(Parametros &parametros) {return parametros.s;};
int getP(Parametros &parametros) {return parametros.p;};
int getA(Parametros &parametros) {return parametros.a;};
int getPosXE(Parametros &parametros) {return parametros.posXE;};
int getPosYE(Parametros &parametros){return parametros.posYE;};
int getIm(Parametros &parametros){return parametros.iM;};
int getVm(Parametros &parametros){return parametros.vM;};
int getIb(Parametros &parametros){return parametros.iB;};
int getVb(Parametros &parametros){return parametros.vB;};
int getIp(Parametros &parametros){return parametros.iP;};

void setS(Parametros &parametros, int s){parametros.s = s;}
void setP(Parametros &parametros, int p){parametros.p = p;}
void setA(Parametros &parametros, int a){parametros.a = a;}
void setPosXE(Parametros &parametros, int posXE){parametros.posXE = posXE;}
void setPosYE(Parametros &parametros, int posYE){parametros.posYE = posYE;}
void setIm(Parametros &parametros, int im){parametros.iM = im;}
void setVm(Parametros &parametros, int vm){parametros.vM = vm;}
void setIb(Parametros &parametros, int ib){parametros.iB = ib;}
void setIp(Parametros &parametros, int ip){parametros.iP = ip;}

/***************************************************/

void toString(Parametros &parametros){
    cout << parametros.s << "|" << parametros.p << "|"  << parametros.s << "|" << parametros.a << "|" << parametros.posXE << "|"
        << parametros.posYE << "|" << parametros.iM << "|" << parametros.vM << "|" << parametros.iB << "|"
        << parametros.vB << "|" << parametros.iP << endl;
}
