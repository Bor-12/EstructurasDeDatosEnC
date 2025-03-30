//
// Created by borja on 28/02/2025.
//


#include "tLista.h"

#include <stdio.h>
#include <stdlib.h>

//O(DIMENSION)
void crearListaVacia(tLista *lista) {
    lista -> primeraLibre = 0;
    lista -> primeraOcupada = -1;
    for (int i = 0; i < DIMENSION; i++){
      lista -> almacen[i].siguiente = i + 1;
    }
    lista -> almacen[DIMENSION - 1].siguiente = -1;
}
//O(1)
int esListaVacia(tLista lista) {
    return lista.primeraOcupada == -1;
}
//O(1)
int esListaLlena(tLista lista) {
    return lista.primeraLibre == -1;
}
// O(1)
void insertarElementoInicio(tLista *lista, tElemento elemento) {
    if (!esListaLlena(*lista)) {
        int nuevoNodo = lista->primeraLibre;  // Guardamos el índice del nodo libre
        asignarElemento(&lista->almacen[nuevoNodo].elemento, elemento);

        lista->primeraLibre = lista->almacen[nuevoNodo].siguiente;  // Avanzamos primeraLibre
        lista->almacen[nuevoNodo].siguiente = lista->primeraOcupada; // Enlazamos el nuevo nodo al inicio de la lista ocupada
        lista->primeraOcupada = nuevoNodo;  // Actualizamos primeraOcupada
    }
}

// O(n)
void insertarElementoFinal(tLista *lista, tElemento elemento) {
    if (!esListaLlena(*lista)) {
        int nuevoNodo = lista->primeraLibre;
        asignarElemento(&lista->almacen[nuevoNodo].elemento, elemento);

        lista->primeraLibre = lista->almacen[nuevoNodo].siguiente;
        lista->almacen[nuevoNodo].siguiente = -1; // Nuevo último nodo apunta a NULL (-1)

        if (esListaVacia(*lista)) {
            lista->primeraOcupada = nuevoNodo;
        } else {
            int actual = lista->primeraOcupada;
            while (lista->almacen[actual].siguiente != -1) {
                actual = lista->almacen[actual].siguiente;
            }
            lista->almacen[actual].siguiente = nuevoNodo; // Conectamos el último nodo al nuevo nodo
        }
    }
}

// O(n)
void eliminarElemento(tLista *lista, tElemento elemento) {
    int anterior = -1, actual = lista->primeraOcupada;

    while (actual != -1 && !esIgual(lista->almacen[actual].elemento, elemento)) {
        anterior = actual;
        actual = lista->almacen[actual].siguiente;
    }

    if (actual != -1) { // Elemento encontrado
        if (anterior == -1) { // El elemento a borrar es el primero
            lista->primeraOcupada = lista->almacen[actual].siguiente;
        } else {
            lista->almacen[anterior].siguiente = lista->almacen[actual].siguiente;
        }

        // Devolvemos el nodo eliminado a la lista de libres
        lista->almacen[actual].siguiente = lista->primeraLibre;
        lista->primeraLibre = actual;
    }
}

// O(1)
tElemento obtenerPrimerElemento(tLista lista) {
    return lista.almacen[lista.primeraOcupada].elemento;
}

// O(n)
tElemento obtenerUltimoElemento(tLista lista) {
    int actual = lista.primeraOcupada;
    while (lista.almacen[actual].siguiente != -1) {
        actual = lista.almacen[actual].siguiente;
    }
    return lista.almacen[actual].elemento;
}

// O(n)
int longitudLista(tLista lista) {
    int contador = 0, actual = lista.primeraOcupada;
    while (actual != -1) {
        contador++;
        actual = lista.almacen[actual].siguiente;
    }
    return contador;
}

// O(n)
void mostrarLista(tLista lista) {
    int actual = lista.primeraOcupada;
    printf("[");
    while (actual != -1) {
        mostrarElemento(lista.almacen[actual].elemento);
        if (lista.almacen[actual].siguiente != -1) {
            printf(", ");
        }
        actual = lista.almacen[actual].siguiente;
    }
    printf("]\n");
}

// O(n)
void vaciarLista(tLista *lista) {
    crearListaVacia(lista);
}