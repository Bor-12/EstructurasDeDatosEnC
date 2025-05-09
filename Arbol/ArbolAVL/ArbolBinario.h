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
    int altura;
}tNodo;
typedef tNodo *tArbol;
void inicializarArbol(tArbol *arbol);
int estaVacio(tArbol arbol);
void insertar(tArbol *arbol, tElemento elemento);

int obtenerAltura(tArbol nodo);
void recalcularAltura(tArbol nodo);
int obtenerFactorBalance(tArbol nodo);
int verificarAVL(tArbol arbol);

tArbol rotacionSimpleIzquierda(tArbol nodo);
tArbol rotacionSimpleDerecha(tArbol nodo);

void construir(tArbol *arbol, tElemento e);
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
int maximo(tArbol arbol, tElemento* elemento);
int minimo(tArbol arbol, tElemento* elemento);
void eliminarElemento(tArbol* arbol, tElemento elemento);

#endif //ARBOLBINARIO_H
