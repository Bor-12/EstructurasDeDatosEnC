//
// Created by borja on 26/03/2025.
//

#include "ArbolBinario.h"
#include <stdio.h>
#include <stdlib.h>
void crearArbolVacio(tArbol *arbol) {
    *arbol = NULL;
}

int esArbolVacio(tArbol arbol) {
    return arbol == NULL;
}
void insertar(tArbol* arbol, tArbol derecho, tArbol izquierdo, tElemento elem){
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elem);
    nuevoNodo -> derecha = derecho;
    nuevoNodo -> izquierda = izquierdo;
    *arbol = nuevoNodo;
}
void destruirArbol(tArbol* arbol) {
    if (*arbol != NULL) {
        destruirArbol(&(*arbol)->derecha);
        destruirArbol(&(*arbol)->izquierda);
        free(*arbol);
        *arbol = NULL;
    }
}


void inOrden(tArbol arbol) {
    if (arbol != NULL) {
        inOrden(arbol->izquierda);
        mostrarElemento(arbol->elemento);
        inOrden(arbol->derecha);
    }
}


void preOrden(tArbol arbol) {
    if (arbol != NULL) {
        mostrarElemento(arbol->elemento);
        preOrden(arbol->izquierda);
        preOrden(arbol->derecha);
    }
}

void postOrden(tArbol arbol) {
    if (arbol != NULL) {
        postOrden(arbol->izquierda);
        postOrden(arbol->derecha);
        mostrarElemento(arbol->elemento);
    }
}


