//
// Created by borja on 28/02/2025.
//


#include "tLista.h"
#include <stdlib.h>

//O(1)
void crearListaVacia(tLista *lista) {
    lista -> principio = NULL;
    lista -> final = NULL;
}
//O(1)
int esListaVacia(tLista lista) {
    return lista.principio == NULL;
}

// O(1)
void insertarElementoInicio(tLista *lista, tElemento elemento) {
    tNodoLista *nuevoNodo = (tNodoLista *) malloc(sizeof(tNodoLista));
    if (nuevoNodo == NULL) return;
    asignarElemento(&nuevoNodo->elemento, elemento);
    nuevoNodo->siguiente = lista -> principio;
    nuevoNodo -> anterior = NULL;

    if(esListaVacia(*lista)){
        lista -> final =  nuevoNodo;
    }else{
        lista -> principio -> anterior = nuevoNodo;
    }
    lista -> principio = nuevoNodo;
}

// O(1)
void insertarElementoFinal(tLista *lista, tElemento elemento) {
    tNodoLista *nuevoNodo = (tNodoLista *) malloc(sizeof(tNodoLista));
    if (nuevoNodo == NULL) return;
    asignarElemento(&nuevoNodo->elemento, elemento);
    nuevoNodo->siguiente = NULL;
    nuevoNodo -> anterior = lista -> final;

    if(esListaVacia(*lista)){
        lista -> principio = nuevoNodo;
    }else{
        lista -> final -> siguiente = nuevoNodo;
    }

    lista -> final = nuevoNodo;
}
//O(n)
void eliminarElemento(tLista *lista, tElemento elemento) {
    if (esListaVacia(*lista)) return;

    tNodoLista *actual = lista -> principio;
    tNodoLista *anterior = NULL;

    while (actual != NULL && !esIgual(actual->elemento, elemento)) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if(actual == NULL){
        return;
    }
    if(anterior == NULL){
          lista -> principio = actual -> siguiente;
          lista -> principio -> anterior = NULL;
    }else{
          anterior -> siguiente = actual -> siguiente;
          actual -> siguiente -> anterior = anterior;
    }
    free(actual);
}
//O(1)
tElemento obtenerPrimerElemento(tLista lista) {
    if (esListaVacia(lista)) {
        return elementoVacio();
    }
    return  lista.principio -> elemento;
}
// O(1)
tElemento obtenerUltimoElemento(tLista lista) {
    if (esListaVacia(lista)) {
        return elementoVacio();
    }

    return lista.final ->elemento;
}
//O(n)
int longitudLista(tLista lista) {
    int contador = 0;
    tNodoLista *aux = lista.principio;
    while (aux != NULL) {
        aux  =  aux -> siguiente;
        contador++;
    }
    return contador;
}
// O(n)
void mostrarLista(tLista lista) {
    tNodoLista *aux = lista.principio;
    while (aux != NULL) {
        mostrarElemento(aux -> elemento);
        aux  =  aux -> siguiente;
    }

}
//O(n)
void vaciarLista(tLista *lista) {
    tNodoLista *aux;
    while (lista -> principio != NULL) {
        aux = lista -> principio;
        lista -> principio = lista -> principio ->siguiente;
        free(aux);
    }
}
tNodoLista * principioLista(tLista lista){
    return lista.principio;
}
