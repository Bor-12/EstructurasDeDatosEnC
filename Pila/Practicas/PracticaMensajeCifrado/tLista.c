// Created by borja on 28/02/2025.

#include "tLista.h"
#include <stdlib.h>

// O(1)
void crearListaVacia(tLista *lista) {
    *lista = NULL;
}

// O(1)
int esListaVacia(tLista lista) {
    return lista == NULL;
}

// O(1)
void insertarElementoInicio(tLista *lista, tElemento elemento) {
    tNodoLista *nuevoNodo = (tNodoLista *) malloc(sizeof(tNodoLista));
    if (nuevoNodo == NULL) return;
    asignarElemento(&nuevoNodo->elemento, elemento);
    nuevoNodo->siguiente = *lista;
    *lista = nuevoNodo;
}

// O(n)
void insertarElementoFinal(tLista *lista, tElemento elemento) {
    tNodoLista *nuevoNodo = (tNodoLista *) malloc(sizeof(tNodoLista));
    if (nuevoNodo == NULL) return;
    asignarElemento(&nuevoNodo->elemento, elemento);
    nuevoNodo->siguiente = NULL;

    if (esListaVacia(*lista)) {
        *lista = nuevoNodo;
    } else {
        tNodoLista *aux = *lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
}

// O(n)
void eliminarElemento(tLista *lista, tElemento elemento) {
    if (*lista == NULL) return;

    tNodoLista *actual = *lista;
    tNodoLista *anterior = NULL;

    while (actual != NULL && !esIgual(actual->elemento, elemento)) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) return;

    if (anterior == NULL) {
        *lista = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
}

// O(1)
tElemento obtenerPrimerElemento(tLista lista) {
    if (esListaVacia(lista)) {
        return elementoVacio();
    }
    return lista->elemento;
}

// O(n)
tElemento obtenerUltimoElemento(tLista lista) {
    if (esListaVacia(lista)) {
        return elementoVacio();
    }
    while (lista->siguiente != NULL) {
        lista = lista->siguiente;
    }
    return lista->elemento;
}

// O(n)
int longitudLista(tLista lista) {
    int contador = 0;
    while (lista != NULL) {
        lista = lista->siguiente;
        contador++;
    }
    return contador;
}

// O(n)
void mostrarLista(tLista lista) {
    while (lista != NULL) {
        mostrarElemento(lista->elemento);
        lista = lista->siguiente;
    }
}

// O(n)
void vaciarLista(tLista *lista) {
    tNodoLista *aux;
    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->siguiente;
        free(aux);
    }
}
