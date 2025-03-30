//
// Created by borja on 23/03/2025.
//

#ifndef PILA_H
#define PILA_H
#include "tElemento.h"
typedef struct Nodo{
    struct Nodo *siguiente;
    struct Nodo *anterior;
    tElemento elemento;
}tNodo;
typedef struct Pila {
    tNodo *principio;
    tNodo *final;
}tPila;
void crearPilaVacia(tPila* pila);
void apilar(tPila* pila, tElemento elem); // push

void cima(tPila* pila, tElemento* elem);
void desapilar(tPila* pila);  // pop

int esPilaVacia(tPila* pila);

void mostrarPila(tPila* pila);
void copiar(tPila origen, tPila *destino);


#endif //PILA_H
