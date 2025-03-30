//
// Created by borja on 28/02/2025.
//


#include "tLista.h"
#include <stdlib.h>

//O(1)
void crearListaVacia(tLista *lista) {
    *lista = NULL;
}
//O(1)
int esListaVacia(tLista lista) {
    return lista == NULL;
}

// O(n)
void insertarOrdenadoInicio(tLista *lista, tElemento elemento) {
    tNodo *actual = *lista;
    tNodo *anterior = NULL;
    while (actual != NULL && !esMenor(actual -> elemento, elemento)){
        anterior = actual;
        actual = actual -> siguiente;
    }
    tNodo *nuevoNodo = (tNodo*) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo-> elemento, elemento);
    nuevoNodo -> siguiente = NULL;
    if (anterior == NULL) {
        nuevoNodo -> siguiente = *lista;
        *lista = nuevoNodo;
        return;
    }
    if (actual == NULL) {
        anterior -> siguiente = nuevoNodo;
    }else {
        anterior -> siguiente = nuevoNodo;
        nuevoNodo -> siguiente = actual;
    }
}

// O(n)
void insertarOrdenadoFinal(tLista *lista, tElemento elemento) {
    tNodo *actual = *lista;
    tNodo *anterior = NULL;
    while (actual != NULL && (!esMenor(actual->elemento, elemento) || esIgual(actual->elemento, elemento))){
        anterior = actual;
        actual = actual -> siguiente;
    }
    tNodo *nuevoNodo = (tNodo*) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo-> elemento, elemento);
    nuevoNodo -> siguiente = NULL;
    if (anterior == NULL) {
        nuevoNodo -> siguiente = *lista;
        *lista = nuevoNodo;
        return;
    }
    if (actual == NULL) {
        anterior -> siguiente = nuevoNodo;
    }else {
        anterior -> siguiente = nuevoNodo;
        nuevoNodo -> siguiente = actual;
    }
}
//O(n)
void eliminarElemento(tLista *lista, tElemento elemento) {
    if (*lista == NULL) return;

    tNodo *actual = *lista;
    tNodo *anterior = NULL;

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
//O(1)
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
//O(n)
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
//O(n)
void vaciarLista(tLista *lista) {
    tNodo *aux;
    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->siguiente;
        free(aux);
    }
}
