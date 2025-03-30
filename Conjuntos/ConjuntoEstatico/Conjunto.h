//
// Created by borja on 30/03/2025.
//
#ifndef CONJUNTO_H
#define CONJUNTO_H

#define DIMENSION 26 // El alfabeto tiene 26 letras (sin la ñ)
#include "tElemento.h"

typedef struct {
    tElemento almacen[DIMENSION];
    int cardinal; // Número de elementos dentro del conjunto
} tConjunto;


void iniciarConjunto(tConjunto *conjunto);
int pertenece(tConjunto conjunto, tElemento elem);
int esConjuntoLleno(tConjunto conjunto);
void insertar(tConjunto *conjunto, tElemento elem);
void eliminar(tConjunto *conjunto, tElemento elem);
int esVacio(tConjunto conjunto);
void mostrarConjunto(tConjunto conjunto);
void extraerElemento(tConjunto *conjunto, tElemento *elem);
int esSubconjunto(tConjunto conjunto1, tConjunto conjunto2);
int igualConjunto(tConjunto conjunto1, tConjunto conjunto2);
void asignarConjunto(tConjunto *copia, tConjunto original);
void destruirConjunto(tConjunto *conjunto);
tConjunto unionConjuntos(tConjunto conjuntoA, tConjunto conjuntoB);
tConjunto interseccion(tConjunto conjuntoA, tConjunto conjuntoB);
tConjunto diferencia(tConjunto conjuntoA, tConjunto conjuntoB);




#endif // CONJUNTO_H

