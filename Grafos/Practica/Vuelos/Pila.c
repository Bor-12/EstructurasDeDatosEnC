//
// Created by borja on 17/03/2025.
//
#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

void crearPilaVacia(tPila* pila) {
    *pila = NULL;
}

void apilar(tPila* pila, tCiudad elem) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        return;
    }
    copiarCiudad(nuevoNodo->elemento, elem);
    nuevoNodo->anterior = *pila;
    *pila = nuevoNodo;
}

void cima(tPila* pila, tCiudad* elem) {
    if (*pila == NULL) {
        printf("Error: Intento de acceder a la cima de una pila vacía.\n");
        return;
    }
    copiarCiudad(*elem, (*pila)->elemento);
}

void desapilar(tPila* pila) {
    if (*pila == NULL) {
        printf("Error: Intento de desapilar una pila vacía.\n");
        return;
    }
    tNodo *aux = *pila;
    *pila = aux->anterior;
    free(aux);
}

int esPilaVacia(tPila* pila) {
    return *pila == NULL;
}

void mostrarPila(tPila* pila) {
    tNodo *aux = *pila;
    while (aux != NULL){
        mostrarCiudad(aux->elemento);
        printf("\n");
        aux = aux->anterior;
    }
}
