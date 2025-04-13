//
// Created by borja on 13/04/2025.
//

#include "Arbol-N-ario.h"
#include <stdio.h>
#include <stdlib.h>



void crearArbolVacio(tArbol *arbol) {
    *arbol = NULL;
}

int esArbolVacio(tArbol arbol) {
    return arbol == NULL;
}

tNodoArbol* crearNodo(tElemento elemento) {
    tNodoArbol* nuevo = malloc(sizeof(tNodoArbol));
    if (nuevo == NULL) {
        fprintf(stderr, "Error al reservar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    asignarElemento(&nuevo->elemento, elemento);
    nuevo->hijos = NULL;
    return nuevo;
}

void insertarHijo(tArbol padre, tArbol hijo) {
    if (padre == NULL || hijo == NULL) return;

    tListaHijos* nuevoHijo = malloc(sizeof(tListaHijos));
    if (nuevoHijo == NULL) {
        fprintf(stderr, "Error al reservar memoria para el hijo\n");
        exit(EXIT_FAILURE);
    }

    nuevoHijo->hijo = hijo;
    nuevoHijo->siguiente = padre->hijos;
    padre->hijos = nuevoHijo;
}


void preOrden(tArbol arbol) {
    if (arbol == NULL) return;
    mostrarElemento(arbol->elemento);
    printf("\n");
    tListaHijos* hijo = arbol->hijos;
    while (hijo != NULL) {
        preOrden(hijo->hijo);
        hijo = hijo->siguiente;
    }
}

void postOrden(tArbol arbol) {
    if (arbol == NULL) return;
    tListaHijos* hijo = arbol->hijos;
    while (hijo != NULL) {
        postOrden(hijo->hijo);
        hijo = hijo->siguiente;
    }
    mostrarElemento(arbol->elemento);
    printf("\n");
}

void inOrden(tArbol arbol) {
    if (arbol == NULL) return;
    tListaHijos* hijo = arbol->hijos;
    if (hijo != NULL) {
        inOrden(hijo->hijo);
        hijo = hijo->siguiente;
    }
    mostrarElemento(arbol->elemento);
    printf("\n");
    while (hijo != NULL) {
        inOrden(hijo->hijo);
        hijo = hijo->siguiente;
    }
}

void destruirArbol(tArbol* arbol) {
    if (*arbol == NULL) return;
    tListaHijos* hijo = (*arbol)->hijos;
    while (hijo != NULL) {
        destruirArbol(&hijo->hijo);
        tListaHijos* aux = hijo;
        hijo = hijo->siguiente;
        free(aux);
    }
    free(*arbol);
    *arbol = NULL;
}

int pertenece(tArbol arbol, tElemento elemento) {
    if (arbol == NULL) return 0;
    if (esIgual(arbol->elemento, elemento)) return 1;
    tListaHijos* hijo = arbol->hijos;
    while (hijo != NULL) {
        if (pertenece(hijo->hijo, elemento)) return 1;
        hijo = hijo->siguiente;
    }
    return 0;
}

int esPadreOMadre(tArbol arbol, tElemento padre, tElemento hijo) {
    if (arbol == NULL) return 0;
    if (esIgual(arbol->elemento, padre)) {
        tListaHijos* h = arbol->hijos;
        while (h != NULL) {
            if (esIgual(h->hijo->elemento, hijo)) return 1;
            h = h->siguiente;
        }
    }
    tListaHijos* hijoActual = arbol->hijos;
    while (hijoActual != NULL) {
        if (esPadreOMadre(hijoActual->hijo, padre, hijo)) return 1;
        hijoActual = hijoActual->siguiente;
    }
    return 0;
}

int contarNodos(tArbol arbol) {
    if (arbol == NULL) return 0;
    int total = 1;
    tListaHijos* hijo = arbol->hijos;
    while (hijo != NULL) {
        total += contarNodos(hijo->hijo);
        hijo = hijo->siguiente;
    }
    return total;
}

int contarHojas(tArbol arbol) {
    if (arbol == NULL) return 0;
    if (arbol->hijos == NULL) return 1;
    int total = 0;
    tListaHijos* hijo = arbol->hijos;
    while (hijo != NULL) {
        total += contarHojas(hijo->hijo);
        hijo = hijo->siguiente;
    }
    return total;
}

int profundidad(tArbol arbol) {
    if (arbol == NULL) return 0;
    int maxProf = 0;
    tListaHijos* hijo = arbol->hijos;
    while (hijo != NULL) {
        int profHijo = profundidad(hijo->hijo);
        if (profHijo > maxProf) maxProf = profHijo;
        hijo = hijo->siguiente;
    }
    return 1 + maxProf;
}

int estaEquilibrado(tArbol arbol) {
    if (arbol == NULL) return 1;
    int minProf = 1000000, maxProf = 0;
    tListaHijos* hijo = arbol->hijos;
    while (hijo != NULL) {
        int p = profundidad(hijo->hijo);
        if (p < minProf) minProf = p;
        if (p > maxProf) maxProf = p;
        hijo = hijo->siguiente;
    }
    return (maxProf - minProf <= 1);
}

void construirEspejo(tArbol arbol, tArbol *espejo) {
    if (arbol == NULL) {
        *espejo = NULL;
        return;
    }

    *espejo = crearNodo(arbol->elemento);

    tListaHijos* hijos = arbol->hijos;
    tListaHijos* invertida = NULL;

    while (hijos != NULL) {
        tArbol hijoEspejo;
        construirEspejo(hijos->hijo, &hijoEspejo);

        tListaHijos* nuevo = malloc(sizeof(tListaHijos));
        nuevo->hijo = hijoEspejo;
        nuevo->siguiente = invertida;
        invertida = nuevo;

        hijos = hijos->siguiente;
    }

    (*espejo)->hijos = invertida;
}

int nivelNodo(tArbol arbol, tElemento e, int nivel) {
    if (arbol == NULL) return -1;
    if (esIgual(arbol->elemento, e)) return nivel;
    tListaHijos* hijo = arbol->hijos;
    while (hijo != NULL) {
        int n = nivelNodo(hijo->hijo, e, nivel + 1);
        if (n != -1) return n;
        hijo = hijo->siguiente;
    }
    return -1;
}





