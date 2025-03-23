#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void crearColaVacia(tCola* cola) {
    *cola = NULL;
}

void encolar(tCola* cola, tElementoCola elem) {
    tNodoCola* pnodo = (tNodoCola*)malloc(sizeof(tNodoCola));
    asignar(&pnodo->elem, elem);
    if (esColaVacia(*cola)) {
        pnodo->sig = pnodo;
    } else {
        pnodo->sig = (*cola)->sig;
        (*cola)->sig = pnodo;
    }
    *cola = pnodo;
}

void primeroCola(tCola cola, tElementoCola* elem) {
    if (!esColaVacia(cola)) {
        asignar(elem, cola->sig->elem);
    }
}

void desencolar(tCola* cola) {
    if (!esColaVacia(*cola)) {
        tNodoCola* pnodo = (*cola)->sig;
        if (pnodo == *cola) {
            *cola = NULL;
        } else {
            (*cola)->sig = (*cola)->sig->sig;  // (*cola)->sig = pnodo->sig;
        }
        free(pnodo);
    }
}

int esColaVacia(tCola cola) {
    return cola == NULL;
}

void mostrarCola(tCola cola) {
    printf("[");
    if (!esColaVacia(cola)) {
        tNodoCola* pnodo = cola->sig;
        do {
            mostrarElemento(pnodo->elem);
            if (pnodo != cola) {
                printf(", ");
            }
            pnodo = pnodo->sig;
        } while (pnodo != cola->sig);
    }
    printf("]\n");
}
