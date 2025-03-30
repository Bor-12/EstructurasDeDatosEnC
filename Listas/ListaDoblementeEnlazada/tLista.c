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

// O(1)
void insertarElementoInicio(tLista *lista, tElemento elemento) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    if (nuevoNodo == NULL) return;
    asignarElemento(&nuevoNodo->elemento, elemento);
    nuevoNodo->siguiente = *lista;
    nuevoNodo -> anterior = NULL;
    if(!esListaVacia(*lista)){
        (*lista) -> anterior = nuevoNodo;
    }
    *lista = nuevoNodo;
}

// O(n)
void insertarElementoFinal(tLista *lista, tElemento elemento) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    if (nuevoNodo == NULL) return;
    asignarElemento(&nuevoNodo->elemento, elemento);
    nuevoNodo->siguiente = NULL;
    tNodo *ultimoNodo = *lista;
    if(!esListaVacia(*lista)){
        while(ultimoNodo -> siguiente != NULL){
            ultimoNodo = ultimoNodo -> siguiente;
        }
        ultimoNodo -> siguiente = nuevoNodo;
    }
    nuevoNodo -> anterior = ultimoNodo;
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
    if(actual == NULL)
         return;
    if(anterior == NULL){
      actual -> siguiente -> anterior = NULL;
      *lista = actual -> siguiente;
      free(actual);
    }else{
          anterior = actual -> siguiente;
          actual -> siguiente -> anterior = anterior;
    }

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
