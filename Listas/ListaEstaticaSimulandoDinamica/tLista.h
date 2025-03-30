//
// Created by borja on 28/02/2025.
//

#ifndef TLISTA_H
#define TLISTA_H
#include "tElemento.h"
#define DIMENSION 100
typedef struct NodoLista {
   tElemento elemento;
   int siguiente;
}tNodo;

typedef struct Lista {
   tNodo almacen[DIMENSION];
   int primeraOcupada;
   int primeraLibre;
}tLista;

void crearListaVacia(tLista *lista);
int esListaVacia(tLista lista);
int esListaLlena(tLista lista);
void insertarElementoInicio(tLista *lista, tElemento elemento);
void insertarElementoFinal(tLista *lista, tElemento elemento);
void eliminarElemento(tLista *lista, tElemento elemento);
tElemento obtenerPrimerElemento(tLista lista);
tElemento obtenerUltimoElemento(tLista lista);
int longitudLista(tLista lista);
void mostrarLista(tLista lista);
void vaciarLista(tLista *lista);

#endif //TLISTA_H
