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

int pertenece(tArbol arbol, tElemento elemento) {
    if (esArbolVacio(arbol)) return 0;
    if (esIgual(arbol->elemento, elemento)) return 1;

    if (pertenece(arbol->izquierda, elemento)) return 1;
    if (pertenece(arbol->derecha, elemento)) return 1;

    return 0;
}
int esPadreOMadre(tArbol arbol, tElemento padre, tElemento hijo) {
    if (arbol == NULL) return 0;

    if (esIgual(arbol->elemento, padre)) {
        if ((arbol->izquierda != NULL && esIgual(arbol->izquierda->elemento, hijo)) ||
            (arbol->derecha != NULL && esIgual(arbol->derecha->elemento, hijo))) {
            return 1;
            }
    }

    return esPadreOMadre(arbol->izquierda, padre, hijo) || esPadreOMadre(arbol->derecha, padre, hijo);
}
int sonHermanos(tArbol arbol , tElemento hermano1, tElemento hermano2){
    if (arbol == NULL || arbol->izquierda == NULL || arbol->derecha == NULL)
        return 0;

    int izq = esIgual(arbol->izquierda->elemento, hermano1) && esIgual(arbol->derecha->elemento, hermano2);
    int der = esIgual(arbol->izquierda->elemento, hermano2) && esIgual(arbol->derecha->elemento, hermano1);

    if (izq || der)
        return 1;

    return sonHermanos(arbol->izquierda, hermano1, hermano2) ||
           sonHermanos(arbol->derecha, hermano1, hermano2);
}

int contarNodos(tArbol arbol) {
    int resultado = 0;
    if (arbol == NULL) {
        resultado = 0;
    }else{
        resultado =  1 + contarNodos(arbol->izquierda) + contarNodos(arbol->derecha);
    }

    return resultado;
}
int contarHojas(tArbol arbol) {
    int resultado = 0;
    if (arbol == NULL) {
        resultado = 0;
    }else if (arbol->izquierda == NULL && arbol->derecha == NULL) {
        resultado = 1;
    } else {
        resultado = contarHojas(arbol->izquierda) + contarHojas(arbol->derecha);
    }
    return resultado;
}

void construirEspejo(tArbol arbol, tArbol *espejo) {
    if (arbol == NULL) {
        *espejo = NULL;
    } else {
        *espejo = (tArbol) malloc(sizeof(tNodo));
        asignarElemento(&(*espejo)->elemento, arbol->elemento);

        construirEspejo(arbol->derecha, &(*espejo)->izquierda);
        construirEspejo(arbol->izquierda, &(*espejo)->derecha);
    }
}


int profundidad(tArbol arbol) {
    int resultado = 0;

    if (arbol != NULL) {
        int izqProfundidad = profundidad(arbol->izquierda);
        int derProfundidad = profundidad(arbol->derecha);

        if (izqProfundidad > derProfundidad) {
            resultado = 1 + izqProfundidad;
        } else {
            resultado = 1 + derProfundidad;
        }
    }

    return resultado;
}



int estaEquilibrado(tArbol arbol) {
    int resultado = 1;

    if (arbol != NULL) {
        int izqProfundidad = profundidad(arbol->izquierda);
        int derProfundidad = profundidad(arbol->derecha);

        if (abs(izqProfundidad - derProfundidad) > 1 ||
            !estaEquilibrado(arbol->izquierda) ||
            !estaEquilibrado(arbol->derecha)) {
            resultado = 0;
            }
    }

    return resultado;
}

int nivelNodo(tArbol arbol, tElemento e, int nivel) {
    int resultado = -1;

    if (arbol != NULL) {
        if (esIgual(arbol->elemento, e)) {
            resultado = nivel;
        } else {
            int izqNivel = nivelNodo(arbol->izquierda, e, nivel + 1);
            if (izqNivel != -1) {
                resultado = izqNivel;
            } else {
                resultado = nivelNodo(arbol->derecha, e, nivel + 1);
            }
        }
    }
    return resultado;
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


