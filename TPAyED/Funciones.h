#ifndef _FUNCIONES_H__
#define _FUNCIONES_H__

#include "Lista.h"
#include "Mina.h"

//COMPARADORES
ResultadoComparacion compararListaMinas(PtrDato ptrDato1, PtrDato ptrDato2);

//DESTRUCTORES
void eliminarMinasDeLista(PtrDato ptrDato);

//IMPRESION
void imprimirListaMinas(Lista &l);

#endif
