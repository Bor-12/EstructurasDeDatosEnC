//
// Created by borja on 28/02/2025.
//

#ifndef TLISTA_H
#define TLISTA_H
#include "tElemento.h"
#define DIMENSION 100
typedef struct Lista{
    tElemento almacen[DIMENSION];
    int ultimaPosicionOcupada;
}tLista;

int esListaLlena(tLista lista);
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

#endif //TLISTA_H
