//
// Created by borja on 17/03/2025.
//

#include "Pila.h"

#include <stdio.h>

#include "stdlib.h"
//O(DIM)
void crearPilaVacia(tPila* pila) {
    for (int i = 0; i < DIMENSION; i++){
        pila -> almacen[i].siguiente = i + 1;
    }
    for (int i = DIMENSION -1; i >= 0; i--){
        pila -> almacen[i].anterior = i -1;
    }
    pila -> almacen[0].anterior = -1;
    pila -> almacen[DIMENSION - 1].anterior = -1;
    pila -> primeraLibre = 0;
    pila -> primeraOcupada = -1;
}
// push
// O(1)
void apilar(tPila* pila, tElemento elem) {
    if (!esPilaLlena(pila)) {
        int nuevoNodo = pila -> primeraLibre;
        asignarElemento(&pila -> almacen[nuevoNodo].elemento, elem);
        pila -> primeraLibre = pila -> almacen[nuevoNodo].siguiente;

        pila -> almacen[nuevoNodo].siguiente = pila -> primeraOcupada;
        if (!esPilaVacia(pila)){
            pila->almacen[pila->primeraOcupada].anterior = nuevoNodo;
        }

        pila->almacen[nuevoNodo].anterior = -1;
        pila -> primeraOcupada = nuevoNodo;
    }
}
//O(1)
void cima(tPila* pila, tElemento* elem) {
    if (!esPilaVacia(pila)) {
        *elem = pila -> almacen[pila -> primeraOcupada].elemento;
    }
}

// pop
// O(1)
void desapilar(tPila* pila) {
    if (!esPilaVacia(pila)) {
        int nodoLiberado = pila->primeraOcupada;
        pila->primeraOcupada = pila->almacen[nodoLiberado].siguiente;

        pila->almacen[nodoLiberado].siguiente = pila->primeraLibre;
        pila->primeraLibre = nodoLiberado;
    }
}


//O(1)
int esPilaVacia(tPila* pila) {
    return pila -> primeraOcupada == -1;
}
int esPilaLlena(tPila *pila) {
    return pila -> primeraLibre == -1;
}
//O(n)
void mostrarPila(tPila* pila) {
    int actual = pila -> primeraOcupada;
    printf("Contenido de la pila:\n");
    while (actual != -1) {
        mostrarElemento(pila -> almacen[actual].elemento);
        actual = pila -> almacen[actual].siguiente;
    }
    printf("\n");
}
