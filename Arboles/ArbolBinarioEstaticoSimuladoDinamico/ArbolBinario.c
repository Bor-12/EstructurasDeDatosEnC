#include "ArbolBinario.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void crearArbolVacio(tArbol *arbol) {
    arbol->primeraPosicionOcupada = NULO;
    arbol->primeraPosicionLibre = 0;
    for (int i = 0; i < DIMENSION; i++) {
        arbol->almacen[i].izquierda = NULO;
        arbol->almacen[i].derecha = NULO;
    }
}

int esArbolVacio(tArbol arbol) {
    return arbol.primeraPosicionOcupada == NULO;
}

int insertar(tArbol* arbol, tElemento elem) {
    if (arbol->primeraPosicionLibre >= DIMENSION)
        return -1;

    int pos = arbol->primeraPosicionLibre++;
    arbol->almacen[pos].elemento = elem;
    arbol->almacen[pos].izquierda = NULO;
    arbol->almacen[pos].derecha = NULO;

    if (esArbolVacio(*arbol)) {
        arbol->primeraPosicionOcupada = pos;
    }

    return pos;
}

void destruirArbol(tArbol* arbol) {
    arbol->primeraPosicionLibre = 0;
    arbol->primeraPosicionOcupada = NULO;
}

int pertenece(tArbol arbol, tElemento elemento) {
    for (int i = 0; i < arbol.primeraPosicionLibre; i++) {
        if (esIgual(arbol.almacen[i].elemento, elemento)) return 1;
    }
    return 0;
}

int esPadreOMadre(tArbol arbol, tElemento padre, tElemento hijo) {
    for (int i = 0; i < arbol.primeraPosicionLibre; i++) {
        if (esIgual(arbol.almacen[i].elemento, padre)) {
            int izq = arbol.almacen[i].izquierda;
            int der = arbol.almacen[i].derecha;
            if ((izq != NULO && esIgual(arbol.almacen[izq].elemento, hijo)) ||
                (der != NULO && esIgual(arbol.almacen[der].elemento, hijo))) {
                return 1;
            }
        }
    }
    return 0;
}

int contarNodosRec(tArbol arbol, int pos) {
    if (pos == NULO) return 0;
    return 1 + contarNodosRec(arbol, arbol.almacen[pos].izquierda) +
               contarNodosRec(arbol, arbol.almacen[pos].derecha);
}

int contarNodos(tArbol arbol) {
    return contarNodosRec(arbol, arbol.primeraPosicionOcupada);
}

int contarHojasRec(tArbol arbol, int pos) {
    if (pos == NULO) return 0;
    if (arbol.almacen[pos].izquierda == NULO && arbol.almacen[pos].derecha == NULO) return 1;
    return contarHojasRec(arbol, arbol.almacen[pos].izquierda) +
           contarHojasRec(arbol, arbol.almacen[pos].derecha);
}

int contarHojas(tArbol arbol) {
    return contarHojasRec(arbol, arbol.primeraPosicionOcupada);
}

int profundidadRec(tArbol arbol, int pos) {
    if (pos == NULO) return 0;
    int izq = profundidadRec(arbol, arbol.almacen[pos].izquierda);
    int der = profundidadRec(arbol, arbol.almacen[pos].derecha);
    return 1 + (izq > der ? izq : der);
}

int profundidad(tArbol arbol) {
    return profundidadRec(arbol, arbol.primeraPosicionOcupada);
}

int estaEquilibradoRec(tArbol arbol, int pos) {
    if (pos == NULO) return 1;

    int izq = arbol.almacen[pos].izquierda;
    int der = arbol.almacen[pos].derecha;

    int profIzq = profundidadRec(arbol, izq);
    int profDer = profundidadRec(arbol, der);

    if (abs(profIzq - profDer) > 1) return 0;

    return estaEquilibradoRec(arbol, izq) && estaEquilibradoRec(arbol, der);
}

int estaEquilibrado(tArbol arbol) {
    return estaEquilibradoRec(arbol, arbol.primeraPosicionOcupada);
}

int buscarNivel(tArbol arbol, int pos, tElemento e, int nivel) {
    if (pos == NULO) return -1;
    if (esIgual(arbol.almacen[pos].elemento, e)) return nivel;

    int izq = buscarNivel(arbol, arbol.almacen[pos].izquierda, e, nivel + 1);
    if (izq != -1) return izq;

    return buscarNivel(arbol, arbol.almacen[pos].derecha, e, nivel + 1);
}

int nivelNodo(tArbol arbol, tElemento e, int nivel) {
    return buscarNivel(arbol, arbol.primeraPosicionOcupada, e, nivel);
}

void inOrdenRec(tArbol arbol, int pos) {
    if (pos == NULO) return;
    inOrdenRec(arbol, arbol.almacen[pos].izquierda);
    mostrarElemento(arbol.almacen[pos].elemento);
    inOrdenRec(arbol, arbol.almacen[pos].derecha);
}

void inOrden(tArbol arbol) {
    inOrdenRec(arbol, arbol.primeraPosicionOcupada);
}

void preOrdenRec(tArbol arbol, int pos) {
    if (pos == NULO) return;
    mostrarElemento(arbol.almacen[pos].elemento);
    preOrdenRec(arbol, arbol.almacen[pos].izquierda);
    preOrdenRec(arbol, arbol.almacen[pos].derecha);
}

void preOrden(tArbol arbol) {
    preOrdenRec(arbol, arbol.primeraPosicionOcupada);
}

void postOrdenRec(tArbol arbol, int pos) {
    if (pos == NULO) return;
    postOrdenRec(arbol, arbol.almacen[pos].izquierda);
    postOrdenRec(arbol, arbol.almacen[pos].derecha);
    mostrarElemento(arbol.almacen[pos].elemento);
}

void postOrden(tArbol arbol) {
    postOrdenRec(arbol, arbol.primeraPosicionOcupada);
}

void copiarEspejo(tArbol* destino, tArbol origen, int origenPos, int* destinoPos) {
    if (origenPos == NULO) return;

    int pos = (*destinoPos)++;
    destino->almacen[pos].elemento = origen.almacen[origenPos].elemento;

    int hijoIzq = NULO;
    int hijoDer = NULO;

    if (origen.almacen[origenPos].derecha != NULO) {
        hijoIzq = *destinoPos;
        copiarEspejo(destino, origen, origen.almacen[origenPos].derecha, destinoPos);
    }
    if (origen.almacen[origenPos].izquierda != NULO) {
        hijoDer = *destinoPos;
        copiarEspejo(destino, origen, origen.almacen[origenPos].izquierda, destinoPos);
    }

    destino->almacen[pos].izquierda = hijoIzq;
    destino->almacen[pos].derecha = hijoDer;
}

void construirEspejo(tArbol arbol, tArbol *espejo) {
    crearArbolVacio(espejo);
    if (arbol.primeraPosicionOcupada != NULO) {
        espejo->primeraPosicionOcupada = 0;
        int destinoPos = 0;
        copiarEspejo(espejo, arbol, arbol.primeraPosicionOcupada, &destinoPos);
        espejo->primeraPosicionLibre = destinoPos;
    }
}
