//
// Created by borja on 30/03/2025.
//
#ifndef CONJUNTO_H
#define CONJUNTO_H


#include "tElemento.h"
typedef struct Nodo{
    tElemento elemento;
    struct Nodo* siguiente;
}tNodo;

typedef tNodo* tConjunto;



void iniciarConjunto(tConjunto *conjunto);
int pertenece(tConjunto conjunto, tElemento elem);
void insertar(tConjunto *conjunto, tElemento elem);
void eliminar(tConjunto *conjunto, tElemento elem);
int esVacio(tConjunto conjunto);
void mostrarConjunto(tConjunto conjunto);
int longitudConjunto(tConjunto conjunto);
void extraerElemento(tConjunto *conjunto, tElemento *elem);
int esSubconjunto(tConjunto conjunto1, tConjunto conjunto2);
int igualConjunto(tConjunto conjunto1, tConjunto conjunto2);
void asignarConjunto(tConjunto *copia, tConjunto original);
void destruirConjunto(tConjunto *conjunto);
tConjunto unionConjuntos(tConjunto conjuntoA, tConjunto conjuntoB);
tConjunto interseccion(tConjunto conjuntoA, tConjunto conjuntoB);
tConjunto diferencia(tConjunto conjuntoA, tConjunto conjuntoB);



#endif // CONJUNTO_H

