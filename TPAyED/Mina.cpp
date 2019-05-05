#include "Mina.h"
/************GETTERS AND SETTERS*********************/
int getPosX(Mina &mina) {return mina.posX;};
int getPosY(Mina &mina) {return mina.posY;};
int getCodItem(Mina &mina) {return mina.codItem;};
int getIp(Mina &mina) {return mina.IP;};
int getSeq1(Mina &mina){return mina.seq1;};
int getSeq2(Mina &mina){return mina.seq2;};
int getSeq3(Mina &mina){return mina.seq3;};
int getSeq4(Mina &mina){return mina.seq4;};
int getSeq5(Mina &mina){return mina.seq5;};

void setPosX(Mina &mina, int posX){mina.posX = posX;}
void setPosY(Mina &mina, int posY){mina.posY = posY;}
void setCodItem(Mina &mina, int codItem){mina.codItem = codItem;}
void setIp(Mina &mina, int ip){mina.IP = ip;}
void setSeq1(Mina &mina, int seq1){mina.seq1 = seq1;}
void setSeq2(Mina &mina, int seq2){mina.seq2 = seq2;}
void setSeq3(Mina &mina, int seq3){mina.seq3 = seq3;}
void setSeq4(Mina &mina, int seq4){mina.seq4 = seq4;}
void setSeq5(Mina &mina, int seq5){mina.seq5 = seq5;}

/***************************************************/

void toString(Mina &mina){
    cout << mina.posX << "|" << mina.posY << "|"  << mina.codItem << "|" << mina.IP << "|" << mina.seq1 << "|"
        << mina.seq2 << "|" << mina.seq3 << "|" << mina.seq3 << "|" << mina.seq4 << "|"
        << mina.seq5 << endl;
}
