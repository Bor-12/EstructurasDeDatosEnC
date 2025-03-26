//
// Created by borja on 21/03/2025.
//

#include "Cola.h"
#include "stdio.h"
#include "stdlib.h"

void crearColaVacia(tCola* cola) {
    *cola = NULL;
}
void encolar(tCola* cola, tElemento elem) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elem);
    if (!esColaVacia(cola)) {
        nuevoNodo->siguiente = (*cola)->siguiente;  // apunta al primero
        (*cola)->siguiente = nuevoNodo;
    }else{
        nuevoNodo -> siguiente = nuevoNodo;
    }
    *cola = nuevoNodo;
}

void primeroCola(tCola* cola, tElemento* elem) {
    if(!esColaVacia(cola)){
        asignarElemento(elem, (*cola) -> siguiente -> elemento);
    }
}
void desencolar(tCola* cola) {
    if (!esColaVacia(cola)) {
        tNodo* primero = (*cola)->siguiente;

        if (*cola == primero) {
            // Solo hay un nodo
            free(primero);
            *cola = NULL;
        } else {
            (*cola)->siguiente = primero->siguiente;
            free(primero);
        }
    }
}



int esColaVacia(tCola* cola) {
    return *cola == NULL;
}
int longitudCola(tCola* cola) {
    if (esColaVacia(cola)) return 0;

    int contador = 0;
    tNodo* aux = (*cola)->siguiente;
    do {
        contador++;
        aux = aux->siguiente;
    } while (aux != (*cola)->siguiente);

    return contador;
}

void mostrarCola(tCola* cola) {
    if (!esColaVacia(cola)) {
        tNodo* aux = (*cola)->siguiente;
        do {
            mostrarElemento(aux->elemento);
            aux = aux->siguiente;
        } while (aux != (*cola)->siguiente);
        printf("Circular \n");
    }
}
void hacerBucleInfinito(tCola *cola) {
    while (*cola != NULL) {
        mostrarElemento((*cola) -> elemento);
        *cola = (*cola) -> siguiente;
    }
}
