//
// Created by borja on 28/02/2025.
//

#ifndef TLISTA_H
#define TLISTA_H
#include "tElemento.h"

typedef struct NodoLista {
    tElemento elemento;
    struct NodoLista *siguiente;
    struct NodoLista *anterior;

}tNodo;

typedef struct Lista {
    tNodo *principio;
    tNodo *final;
}tLista;

void crearListaVacia(tLista *lista);
int esListaVacia(tLista lista);
void insertarElementoInicio(tLista *lista, tElemento elemento);
void insertarElementoFinal(tLista *lista, tElemento elemento);
void eliminarElemento(tLista *lista, tElemento elemento);
tElemento obtenerPrimerElemento(tLista lista);
tElemento obtenerUltimoElemento(tLista lista);
int longitudLista(tLista lista);
void mostrarLista(tLista lista);
void vaciarLista(tLista *lista);
void copiarLista(tLista origen, tLista *destino);

#endif //TLISTA_H
