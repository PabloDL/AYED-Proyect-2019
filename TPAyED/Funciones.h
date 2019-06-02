#ifndef _FUNCIONES_H__
#define _FUNCIONES_H__

#include "Lista.h"
#include "Mina.h"

//COMPARADORES
ResultadoComparacion compararListaMinas(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararListaVagones(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararListaCajas( PtrDato ptrDato1 , PtrDato ptrDato2 );

//DESTRUCTORES
void eliminarMinasDeLista(PtrDato ptrDato);

void eliminarVagonesDeLista(PtrDato ptrDato);

void eliminarCajaDeLista(PtrDato ptrDato);

//IMPRESION
void imprimirListaMinas(Lista &l);

void imprimirListaVagones(Lista& l);

void imprimirListaCajas(Lista& l);
#endif
