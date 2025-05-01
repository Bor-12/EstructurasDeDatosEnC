//
// Created by borja on 17/03/2025.
//
#ifndef PILA_H
#define PILA_H

#include "Ciudad.h"

typedef struct Nodo {
    struct Nodo *anterior;
    tCiudad elemento;
} tNodo;

typedef tNodo *tPila;

void crearPilaVacia(tPila* pila);
void apilar(tPila* pila, tCiudad elem);       // push
void cima(tPila* pila, tCiudad* elem);        // top
void desapilar(tPila* pila);                  // pop
int esPilaVacia(tPila* pila);
void mostrarPila(tPila* pila);

#endif // PILA_H
