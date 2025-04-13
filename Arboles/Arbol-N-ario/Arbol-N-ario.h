//
// Created by borja on 13/04/2025.
//

#ifndef ARBOL_N_ARIO_H
#define ARBOL_N_ARIO_H


#include "tElemento.h"
typedef struct tNodoArbol {
    tElemento elemento;
    struct tListaHijos* hijos;
} tNodoArbol;

typedef struct tListaHijos {
    struct tNodoArbol* hijo;
    struct tListaHijos* siguiente;
} tListaHijos;

typedef tNodoArbol* tArbol;


void crearArbolVacio(tArbol *arbol);
int esArbolVacio(tArbol arbol);
void insertarHijo(tArbol padre, tArbol hijo);
tNodoArbol* crearNodo(tElemento elemento);
void destruirArbol(tArbol* arbol);
int pertenece(tArbol arbol, tElemento elemento);
int esPadreOMadre(tArbol arbol, tElemento padre, tElemento hijo);
int contarNodos(tArbol arbol);
int contarHojas(tArbol arbol);
int estaEquilibrado(tArbol arbol);
void construirEspejo(tArbol arbol, tArbol *espejo);
int profundidad(tArbol arbol);
int nivelNodo(tArbol arbol, tElemento e, int nivel);
void inOrden(tArbol arbol);

void preOrden(tArbol arbol);

void postOrden(tArbol arbol);
#endif //ARBOL_N_ARIO_H
