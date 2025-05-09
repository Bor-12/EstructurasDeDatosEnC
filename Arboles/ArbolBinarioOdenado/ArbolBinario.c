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
void construir(tArbol *arbol, tElemento e) {
    if (*arbol == NULL) {
        tNodo* nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
        asignarElemento(&nuevoNodo -> elemento, e);
        nuevoNodo-> derecha = NULL;
        nuevoNodo -> izquierda = NULL;
        *arbol = nuevoNodo;
    } else {
        tElemento r;
        asignarElemento(&r, (*arbol) -> elemento);
        if (esMenor(r, e)) {
            construir(&(*arbol)->derecha, e);
        } else {
            construir(&(*arbol)->izquierda, e);
        }
    }
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



//LA FUNCION DE PERTENECE SE PUEDE MERJORAR RESPECTO DE UN ARBOL NO ORDENADO
//Siempre que se busque un elemento se comprobara si es mayor o menor para saber por que parte del arbol buscar
int pertenece(tArbol arbol, tElemento elemento){
    int resultado = 0;

    if (arbol != NULL) {
        if (esIgual(arbol->elemento, elemento)) {
            resultado = 1;
        } else if (esMenor(arbol->elemento, elemento)) {
            resultado = pertenece(arbol->derecha, elemento);
        } else {
            resultado = pertenece(arbol->izquierda, elemento);
        }
    }
    return resultado;
}
int esPadreOMadre(tArbol arbol, tElemento padre, tElemento hijo) {
    if (arbol == NULL) return 0;

    if (esIgual(arbol->elemento, padre) &&
        ((arbol->izquierda != NULL && esIgual(arbol->izquierda->elemento, hijo)) ||
         (arbol->derecha != NULL && esIgual(arbol->derecha->elemento, hijo)))) {
        return 1;
         }

    if (esMenor(padre, arbol->elemento)) {
        return esPadreOMadre(arbol->izquierda, padre, hijo);
    } else {
        return esPadreOMadre(arbol->derecha, padre, hijo);
    }
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

int maximo(tArbol arbol, tElemento* elemento) {
    int resultado = 0;

    if (arbol != NULL) {

        while (arbol->derecha != NULL) {
            arbol = arbol->derecha;
        }

        asignarElemento(elemento, arbol -> elemento);
        resultado = 1;
    }
    return resultado;
}int minimo(tArbol arbol, tElemento* elemento) {
    int resultado = 0;

    if (arbol != NULL) {

        while (arbol->izquierda != NULL) {
            arbol = arbol->izquierda;
        }

        asignarElemento(elemento, arbol -> elemento);
        resultado = 1;
    }
    return resultado;
}
void eliminarElemento(tArbol* arbol, tElemento elemento) {
    tNodo *aux;
    if (*arbol != NULL) {

        if (esIgual((*arbol)->elemento, elemento)) {

            aux = *arbol;

            if ((*arbol)->izquierda == NULL) {
                // Caso 1: El nodo actual no tiene hijo izquierdo
                *arbol = (*arbol)->derecha;
                free(aux);
            } else if ((*arbol)->derecha == NULL) {
                // Caso 2: El nodo actual no tiene hijo derecho
                *arbol = (*arbol)->izquierda;
                free(aux);
            } else {
                // Caso 3: El nodo tiene ambos hijos
                tElemento min;
                minimo((*arbol)->derecha, &min);
                asignarElemento(&(*arbol)->elemento, min);
                eliminarElemento(&(*arbol)->derecha, min);
            }

        } else if (!esMenor(elemento, (*arbol)->elemento)) {
            eliminarElemento(&(*arbol)->derecha, elemento);
        } else {
            eliminarElemento(&(*arbol)->izquierda, elemento);
        }
    }
}

