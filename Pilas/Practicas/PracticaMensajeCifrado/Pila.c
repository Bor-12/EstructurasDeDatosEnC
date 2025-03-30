//
// Created by borja on 17/03/2025.
//
// Created by borja on 17/03/2025.

#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

void crearPilaVacia(tPila* pila) {
    *pila = NULL;
}

// push
// O(1)
void apilar(tPila* pila, tElemento elem) {
    tNodoPila *nuevoNodo = (tNodoPila *) malloc(sizeof(tNodoPila));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        return;
    }
    asignarElemento(&nuevoNodo->elemento, elem);
    nuevoNodo->anterior = *pila;
    *pila = nuevoNodo;
}

// cima
// O(1)
void cima(tPila* pila, tElemento* elem) {
    if (*pila == NULL) {
        printf("Error: Intento de acceder a la cima de una pila vacía.\n");
        return;
    }
    *elem = (*pila)->elemento;
}

// pop
// O(1)
void desapilar(tPila* pila) {
    if (*pila == NULL) {
        printf("Error: Intento de desapilar una pila vacía.\n");
        return;
    }
    tNodoPila *aux = *pila;
    *pila = aux->anterior;
    free(aux);
}

// comprobar si está vacía
// O(1)
int esPilaVacia(tPila* pila) {
    return *pila == NULL;
}

// mostrar pila
// O(n)
void mostrarPila(tPila* pila) {
    tNodoPila *aux = *pila;
    while (aux != NULL) {
        mostrarElemento(aux->elemento);
        aux = aux->anterior;
    }
}
