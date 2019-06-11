#ifndef _FUNCIONES_H__
#define _FUNCIONES_H__

#include "Lista.h"
#include "Mina.h"

//COMPARADORES
ResultadoComparacion compararListaMinas(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararListaVagones(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararListaCajas( PtrDato ptrDato1 , PtrDato ptrDato2 );

ResultadoComparacion compararListaBandidos(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararListaMonedas(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion compararListaEstaciones(PtrDato ptrDato1, PtrDato ptrDato2);

void eliminarBandidoDeLista(PtrDato ptrDato);

//DESTRUCTORES
void eliminarMinasDeLista(PtrDato ptrDato);

void eliminarVagonesDeLista(PtrDato ptrDato);

void eliminarCajaDeLista(PtrDato ptrDato);

void eliminarMonedaDeLista(PtrDato ptrDato);

void eliminarEstacionDeLista(PtrDato ptrDato);
//IMPRESION
void imprimirListaMinas(Lista &l);

void imprimirListaVagones(Lista& l);

void imprimirListaCajas(Lista& l);
#endif
