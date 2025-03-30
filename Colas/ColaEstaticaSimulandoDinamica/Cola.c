//
// Created by borja on 21/03/2025.
//

#include "Cola.h"
#include "stdio.h"
#include "stdlib.h"

// O(DIM)
void crearColaVacia(tCola* cola) {
    cola->primeroLibre = 0;
    cola->primeroOcupado = -1;

    for (int i = 0; i < DIMENSION - 1; i++) {
        cola->almacen[i].siguiente = i + 1;
    }
    cola->almacen[DIMENSION - 1].siguiente = -1;

    for (int i = 0; i < DIMENSION; i++) {
        cola->almacen[i].anterior = -1;
    }
}

int esColaLlena(tCola* cola) {
    return cola->primeroLibre == -1;
}

int esColaVacia(tCola* cola) {
    return cola->primeroOcupado == -1;
}

void encolar(tCola* cola, tElemento elem) {
    if (esColaLlena(cola)) {
        printf("Cola llena\n");
        return;
    }

    int nuevoNodo = cola->primeroLibre;
    cola->primeroLibre = cola->almacen[nuevoNodo].siguiente;

    asignarElemento(&cola->almacen[nuevoNodo].elemento, elem);
    cola->almacen[nuevoNodo].siguiente = -1;

    if (cola->primeroOcupado == -1) {
        // La cola está vacía
        cola->primeroOcupado = nuevoNodo;
        cola->almacen[nuevoNodo].anterior = -1;
    } else {
        // Buscar el último nodo ocupado
        int actual = cola->primeroOcupado;
        while (cola->almacen[actual].siguiente != -1) {
            actual = cola->almacen[actual].siguiente;
        }

        cola->almacen[actual].siguiente = nuevoNodo;
        cola->almacen[nuevoNodo].anterior = actual;
    }
}

void primeroCola(tCola* cola, tElemento* elem) {
    if (esColaVacia(cola)) {
        printf("Cola vacía\n");
        return;
    }
    asignarElemento(elem, cola->almacen[cola->primeroOcupado].elemento);
}

void desencolar(tCola* cola) {
    if (esColaVacia(cola)) {
        printf("Cola vacía\n");
        return;
    }

    int nodoEliminado = cola->primeroOcupado;
    cola->primeroOcupado = cola->almacen[nodoEliminado].siguiente;

    if (cola->primeroOcupado != -1) {
        cola->almacen[cola->primeroOcupado].anterior = -1;
    }

    // Devolver nodo a la lista libre
    cola->almacen[nodoEliminado].siguiente = cola->primeroLibre;
    cola->primeroLibre = nodoEliminado;
}

int longitudCola(tCola* cola) {
    int contador = 0;
    int actual = cola->primeroOcupado;
    while (actual != -1) {
        contador++;
        actual = cola->almacen[actual].siguiente;
    }
    return contador;
}

void mostrarCola(tCola* cola) {
    if (esColaVacia(cola)) {
        printf("Cola vacía\n");
        return;
    }

    int actual = cola->primeroOcupado;
    printf("Cola: ");
    while (actual != -1) {
        mostrarElemento(cola->almacen[actual].elemento);
        actual = cola->almacen[actual].siguiente;
    }
    printf("\n");
}


void hacerBucleInfinito(tCola* cola) {
    if (esColaVacia(cola)) return;

    // Unir el último con el primero para formar un bucle
    int actual = cola->primeroOcupado;
    while (cola->almacen[actual].siguiente != -1) {
        actual = cola->almacen[actual].siguiente;
    }
    cola->almacen[actual].siguiente = cola->primeroOcupado;
}

