//
// Created by borja on 23/03/2025.
//

#include "Pila.h"
#include "stdio.h"
#include "stdlib.h"
void crearPilaVacia(tPila* pila) {
    pila -> final = NULL;
    pila -> principio = NULL;
}
void apilar(tPila* pila, tElemento elem) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elem);
    nuevoNodo -> anterior = NULL;
    nuevoNodo -> siguiente = NULL;
    if (esPilaVacia(pila)) {
        pila -> final = nuevoNodo;
    }else {
        pila -> principio -> anterior = nuevoNodo;
        nuevoNodo -> siguiente = pila -> principio;
    }
    pila -> principio = nuevoNodo;
}
void cima(tPila* pila, tElemento* elem) {
    if (!esPilaVacia(pila)) {
        asignarElemento(elem, pila -> principio -> elemento);
    }
}
void desapilar(tPila* pila) {
    tNodo * aux = pila ->  principio;
    pila -> principio = pila -> principio -> siguiente;
    pila -> principio -> anterior = NULL;
    free(aux);
}

int esPilaVacia(tPila* pila) {
    return pila -> principio == NULL;
}

void mostrarPila(tPila* pila) {
    tNodo *aux = pila -> principio;
    while (aux != NULL){
        mostrarElemento(aux -> elemento);
        aux = aux -> siguiente;
    }
}