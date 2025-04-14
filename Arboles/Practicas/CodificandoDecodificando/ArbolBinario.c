//
// Created by borja on 26/03/2025.
//

#include "ArbolBinario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void codificarPalabra(tArbol *arbol, char *palabra) {
    tArbol original;

    construirCodificado(&original, palabra);  // Árbol original

    construirEspejo(original, arbol);         // El espejo se guarda directamente en *arbol

    destruirArbol(&original);                 // Ya no se necesita el árbol original
}


void construirCodificado(tArbol *arbol, char *palabra) {
    int len = strlen(palabra);
    crearArbolVacio(arbol);

    if (len == 0) return;

    tElemento raiz;
    asignarLetra(&raiz, palabra[0]);

    if (len == 1) {
        insertar(arbol, NULL, NULL, raiz);
        return;
    }

    char *resto = palabra + 1;//avanzar el puntero 1 bit para que no apunte a la primera letra sino que a la segunda
    int lenResto = len - 1;
    int mitad = lenResto / 2;

    // Si impar, la segunda parte tiene una letra más
    int lenIzq = mitad;
    int lenDer = lenResto - mitad;

    char izquierda[lenIzq + 1];
    char derecha[lenDer + 1];

    strncpy(izquierda, resto, lenIzq);
    izquierda[lenIzq] = '\0';

    strncpy(derecha, resto + lenIzq, lenDer);
    derecha[lenDer] = '\0';

    tArbol izq, der;
    construirCodificado(&izq, izquierda);
    construirCodificado(&der, derecha);

    insertar(arbol, der, izq, raiz);
}
void construirDecodificado(tArbol *arbol, char *palabra) {
    int len = strlen(palabra);
    crearArbolVacio(arbol);

    if (len == 0) return;

    tElemento raiz;
    asignarLetra(&raiz, palabra[0]);

    if (len == 1) {
        insertar(arbol, NULL, NULL, raiz);
        return;
    }

    char *resto = palabra + 1;
    int lenResto = len - 1;
    int mitad = (lenResto + 1) / 2;  // ahora la primera mitad es la más larga

    int lenIzq = mitad;
    int lenDer = lenResto - mitad;

    char izquierda[lenIzq + 1];
    char derecha[lenDer + 1];

    strncpy(izquierda, resto, lenIzq);
    izquierda[lenIzq] = '\0';

    strncpy(derecha, resto + lenIzq, lenDer);
    derecha[lenDer] = '\0';

    tArbol izq, der;
    construirDecodificado(&izq, izquierda);
    construirDecodificado(&der, derecha);

    insertar(arbol, der, izq, raiz);
}

void decodificarPalabra(tArbol *arbol, char *palabra) {
    tArbol arbolCodificado;
    crearArbolVacio(&arbolCodificado);

    construirDecodificado(&arbolCodificado, palabra);  // construye árbol desde palabra codificada

    construirEspejo(arbolCodificado, arbol);  // el espejo es el árbol original y lo guardamos en *arbol


    destruirArbol(&arbolCodificado);
}



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


