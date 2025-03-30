//
// Created by borja on 26/03/2025.
//

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "tElemento.h"

typedef  struct Nodo{
    struct Nodo *izquierda;
    struct Nodo *derecha;
    tElemento elemento;
}tNodo;
typedef tNodo *tArbol;
void crearArbolVacio(tArbol *arbol);

int esArbolVacio(tArbol arbol);
void insertar(tArbol* arbol, tArbol derecho, tArbol izquierdo, tElemento elem);
void destruirArbol(tArbol* arbol);
void inOrden(tArbol arbol);

void preOrden(tArbol arbol);

void postOrden(tArbol arbol);

#endif //ARBOLBINARIO_H
