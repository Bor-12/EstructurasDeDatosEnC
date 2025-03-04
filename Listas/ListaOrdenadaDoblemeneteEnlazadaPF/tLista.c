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

// O(n)
void insertarOrdenadoInicio(tLista *lista, tElemento elemento) {
    tNodo *pNuevo = (tNodo *)malloc(sizeof(tNodo));

    if (pNuevo != NULL) {
        asignarElemento(&pNuevo->elemento, elemento);
        pNuevo->siguiente = NULL;
        pNuevo->anterior = NULL;

        if (esListaVacia(*lista)) {
            lista->principio = pNuevo;
            lista->final = pNuevo;
        } else {
            tNodo *aux = lista->principio;

            while (aux != NULL && !esMenor(aux -> elemento, elemento)){
                aux = aux->siguiente;
            }

            if (aux == NULL) {
                // Insertar al final
                pNuevo->anterior = lista->final;
                lista->final->siguiente = pNuevo;
                lista->final = pNuevo;
            } else if (aux == lista->principio) {
                // Insertar al principio
                pNuevo->siguiente = lista->principio;
                lista->principio->anterior = pNuevo;
                lista->principio = pNuevo;
            } else {
                // Insertar en el medio
                pNuevo->siguiente = aux;
                pNuevo->anterior = aux->anterior;
                aux->anterior->siguiente = pNuevo;
                aux->anterior = pNuevo;
            }
        }
    }
}

// O(n)

void insertarOrdenadoFinal(tLista *lista, tElemento elemento) {
    tNodo *pNuevo = (tNodo *)malloc(sizeof(tNodo));

    if (pNuevo != NULL) {
        asignarElemento(&pNuevo->elemento, elemento);
        pNuevo->siguiente = NULL;
        pNuevo->anterior = NULL;

        if (esListaVacia(*lista)) {
            lista->principio = pNuevo;
            lista->final = pNuevo;
        } else {
            tNodo *aux = lista->principio;

            while (aux != NULL && (!esMenor(aux -> elemento, elemento) || esIgual(aux-> elemento, elemento))){
                aux = aux->siguiente;
            }

            if (aux == NULL) {
                // Insertar al final
                pNuevo->anterior = lista->final;
                lista->final->siguiente = pNuevo;
                lista->final = pNuevo;
            } else if (aux == lista->principio) {
                // Insertar al principio
                pNuevo->siguiente = lista->principio;
                lista->principio->anterior = pNuevo;
                lista->principio = pNuevo;
            } else {
                // Insertar en el medio
                pNuevo->siguiente = aux;
                pNuevo->anterior = aux->anterior;
                aux->anterior->siguiente = pNuevo;
                aux->anterior = pNuevo;
            }
        }
    }
}
//O(n)
void eliminarElemento(tLista *lista, tElemento elemento) {
    if (esListaVacia(*lista)) return;


    tNodo *actual = lista -> principio;
    tNodo *anterior = NULL;

    while (actual != NULL && !esIgual(actual->elemento, elemento)) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL) return;
    if (anterior == NULL) {
        actual -> siguiente -> anterior = NULL;
        lista-> principio = actual -> siguiente;
    }else {
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
    return lista.principio -> elemento;
}
// O(1)
tElemento obtenerUltimoElemento(tLista lista) {
    if (esListaVacia(lista)) {
        return elementoVacio();
    }
    return lista.final->elemento;
}
//O(n)
int longitudLista(tLista lista) {
    int contador = 0;
    while (lista.principio != NULL) {
        lista.principio = lista.principio -> siguiente;
        contador++;
    }
    return contador;
}
// O(n)
void mostrarLista(tLista lista) {
    while (lista.principio != NULL) {
        mostrarElemento(lista.principio -> elemento);
        lista.principio = lista.principio -> siguiente;

    }

}
//O(n)
void vaciarLista(tLista *lista) {
    tNodo *aux = lista -> principio;
    while (!esListaVacia(*lista)) {
        aux = lista -> principio;
        lista -> principio = lista -> principio -> siguiente;
        free(aux);
    }
}
