//
// Created by borja on 28/02/2025.
//

#ifndef TLISTA_H
#define TLISTA_H
#include "tElemento.h"

typedef struct Nodo {
    struct Nodo *siguiente;
    struct Nodo *anterior;
    tElemento elemento;
}tNodo;
typedef struct Lista {
    tNodo *principio;
    tNodo *final;
}tLista;

void crearListaVacia(tLista *lista);
int esListaVacia(tLista lista);
//la unica diferencia entre insertar ordenado inciio y final es si hay ya un elemento con la misma prioridad
//Cuanto mayor sea el elemento mas prioridad tiene
void insertarOrdenadoInicio(tLista *lista, tElemento elemento);
void insertarOrdenadoFinal(tLista *lista, tElemento elemento);

void eliminarElemento(tLista *lista, tElemento elemento);
tElemento obtenerPrimerElemento(tLista lista);
tElemento obtenerUltimoElemento(tLista lista);
int longitudLista(tLista lista);
void mostrarLista(tLista lista);
void vaciarLista(tLista *lista);

#endif //TLISTA_H
