//
// Created by borja on 28/02/2025.
//

#include "tLista.h"
#include <stdlib.h>
#include <stdio.h>
void crearListaVacia(tLista *lista) {
    lista -> principio = NULL;
    lista -> final = NULL;
}
int esListaVacia(tLista lista){
    return lista.principio == NULL;
}
void insertarElementoInicio(tLista *lista, tElemento elemento) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elemento);
    if (esListaVacia(*lista)) {
        lista -> final = nuevoNodo;
    }
    nuevoNodo -> siguiente = lista -> principio;
    lista -> principio = nuevoNodo;
}
void insertarElementoFinal(tLista *lista, tElemento elemento) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elemento);
    if (esListaVacia(*lista)) {
        lista -> principio = nuevoNodo;
    }else {
        lista -> final -> siguiente = nuevoNodo;
    }
    nuevoNodo -> siguiente = NULL;
    lista -> final = nuevoNodo;
}
void eliminarElemento(tLista *lista, tElemento elemento) {
    if (esListaVacia(*lista))
        return;
    tNodo *actual = lista -> principio;
    tNodo *anterior = NULL;
    while (actual != NULL &&  !esIgual(actual -> elemento, elemento)) {
        anterior = actual;
        actual = actual -> siguiente;
    }
    if (actual == NULL)
        return;

    //principio de la lista
    if (anterior == NULL) {
        lista -> principio = actual -> siguiente;

    }else {
        anterior -> siguiente = actual -> siguiente;
        if (actual == lista->final) {
            lista->final = anterior;
        }
    }
    free(actual);


}
tElemento obtenerPrimerElemento(tLista lista) {
    if (esListaVacia(lista))
        return elementoVacio();
    return lista.principio -> elemento;
}
tElemento obtenerUltimoElemento(tLista lista) {
    if (esListaVacia(lista))
        return elementoVacio();
    return lista.final -> elemento;
}
int longitudLista(tLista lista) {
    int contador = 0;
    tNodo *actual = lista.principio;
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void mostrarLista(tLista lista) {
    tNodo *actual = lista.principio;

    while (actual != NULL) {
        mostrarElemento(actual -> elemento);
        actual = actual->siguiente;
    }

}
void vaciarLista(tLista *lista) {
    tNodo *actual = lista -> principio;
    while (!esListaVacia(*lista)) {
        tNodo *aux = actual;
        actual = actual->siguiente;
        lista -> principio = actual;
    }

}