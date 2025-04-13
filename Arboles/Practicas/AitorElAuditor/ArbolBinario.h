//
// Created by borja on 26/03/2025.
//

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "tElemento.h"
#include "tLista.h"
typedef  struct Nodo{
    struct Nodo *izquierda;
    struct Nodo *derecha;
    tElemento elemento;
}tNodoArbol;
typedef tNodoArbol *tArbol;
void crearArbolVacio(tArbol *arbol);

int esArbolVacio(tArbol arbol);
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
void eliminarElementoArbol(tArbol* arbol, tElemento elemento);

tLista listarInferiores(tArbol arbol, int limite);


#endif //ARBOLBINARIO_H
