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
void codificarPalabra(tArbol *arbol, char *palabra);
void construirCodificado(tArbol *arbol, char *palabra);
void decodificarPalabra(tArbol *arbol, char *palabra);
void construirDecodificado(tArbol *arbol, char *palabra);
void crearArbolVacio(tArbol *arbol);

int esArbolVacio(tArbol arbol);
void insertar(tArbol* arbol, tArbol derecho, tArbol izquierdo, tElemento elem);
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

#endif //ARBOLBINARIO_H
