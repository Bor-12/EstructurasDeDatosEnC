//
// Created by borja on 17/03/2025.
//

#ifndef PILA_H
#define PILA_H
#define DIMENSION 100
#include "tElemento.h"

typedef struct Nodo {
    tElemento elemento;
    int siguiente;
    int anterior;
}tNodo;

typedef struct Pila {
    tNodo almacen[DIMENSION];
    int primeraLibre;
    int primeraOcupada;
}tPila;
void crearPilaVacia(tPila* pila);
void apilar(tPila* pila, tElemento elem); // push

void cima(tPila* pila, tElemento* elem);
void desapilar(tPila* pila);  // pop

int esPilaVacia(tPila* pila);
int esPilaLlena(tPila *pila);
void mostrarPila(tPila* pila);
#endif //PILA_H
