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
    tNodo* aux = pila->principio;
    pila->principio = pila->principio->siguiente;

    if (pila->principio == NULL) {
        pila->final = NULL;
    } else {
        pila->principio->anterior = NULL;
    }
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
void copiar(tPila origen, tPila *destino) {
    crearPilaVacia(destino); // Asegurarse de que destino esté vacía

    if (!esPilaVacia(&origen)) {
        tNodo *nodoOrigen = origen.principio;

        // Crear primer nodo
        tNodo *nodoNuevo = (tNodo *)malloc(sizeof(tNodo));
        asignarElemento(&nodoNuevo->elemento, nodoOrigen->elemento);
        nodoNuevo->anterior = NULL;
        nodoNuevo->siguiente = NULL;

        destino->principio = nodoNuevo;
        destino->final = nodoNuevo;

        nodoOrigen = nodoOrigen->siguiente;

        // Copiar el resto de nodos
        while (nodoOrigen != NULL) {
            tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
            asignarElemento(&nuevo->elemento, nodoOrigen->elemento);
            nuevo->anterior = destino->final;
            nuevo->siguiente = NULL;

            destino->final->siguiente = nuevo;
            destino->final = nuevo;

            nodoOrigen = nodoOrigen->siguiente;
        }
    }
}
