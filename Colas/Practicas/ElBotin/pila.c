#include <stdlib.h>
#include <stdio.h>
#include "pila.h"

void crearPilaVacia(tPila* pila) {
    *pila = NULL;
}

void apilar(tPila* pila, tElementoPila elem) {
    tNodoPila* pnodo = (tNodoPila*)malloc(sizeof(tNodoPila));
    pnodo->elem = elem; // asignar
    pnodo->ant = *pila;
    *pila = pnodo;
}

void cima(tPila* pila, tElementoPila* elem) {
    if (!esPilaVacia(pila)) {
        *elem = (*pila)->elem; // asignar
    }
}

void desapilar(tPila* pila) {
    if (!esPilaVacia(pila)) {
        tNodoPila* pnodo = *pila;
        *pila = (*pila)->ant;
        free(pnodo);
    }
}

int esPilaVacia(tPila* pila) {
    return *pila == NULL;
}

void mostrarPila(tPila* pila) {
    printf("__\n");
    tNodoPila* pnodo = *pila;
    while (pnodo != NULL) {
        printf("%d\n", pnodo->elem); // mostrarElemento
        pnodo = pnodo->ant;
    }
    printf("__\n");
}
