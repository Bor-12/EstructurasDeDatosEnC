//
// Created by borja on 17/03/2025.
//

#ifndef PILA_H
#define PILA_H
#include "tElemento.h"
typedef struct Nodo {
    struct Nodo *anterior;
    tElemento elemento;
}tNodoPila;
typedef tNodoPila *tPila;
void crearPilaVacia(tPila* pila);
void apilar(tPila* pila, tElemento elem); // push

void cima(tPila* pila, tElemento* elem);
void desapilar(tPila* pila);  // pop

int esPilaVacia(tPila* pila);

void mostrarPila(tPila* pila);
#endif //PILA_H
