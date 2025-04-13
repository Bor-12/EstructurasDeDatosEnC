//
// Created by borja on 26/03/2025.
//

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "tElemento.h"
#define DIMENSION 100
#define NULO -1
typedef  struct Nodo{
    int izquierda;
    int derecha;
    tElemento elemento;
}tNodo;
typedef struct {
    int primeraPosicionOcupada; //raiz
    int primeraPosicionLibre;
    tNodo almacen[DIMENSION];
}tArbol;
void crearArbolVacio(tArbol *arbol);

int esArbolVacio(tArbol arbol);
int insertar(tArbol* arbol, tElemento elem);
void destruirArbol(tArbol* arbol);
int pertenece(tArbol arbol, tElemento elemento);
int esPadreOMadre(tArbol arbol, tElemento padre, tElemento hijo);
int contarNodos(tArbol arbol);
int contarHojas(tArbol arbol);
int estaEquilibrado(tArbol arbol);
void construirEspejo(tArbol arbol, tArbol *espejo);
int buscarNivel(tArbol arbol, int pos, tElemento e, int nivel);
int profundidad(tArbol arbol);
int nivelNodo(tArbol arbol, tElemento e, int nivel);
void inOrden(tArbol arbol);

void preOrden(tArbol arbol);

void postOrden(tArbol arbol);
int contarNodosRec(tArbol arbol, int pos);
int contarHojasRec(tArbol arbol, int pos);
int profundidadRec(tArbol arbol, int pos);
int estaEquilibradoRec(tArbol arbol, int pos);
void inOrdenRec(tArbol arbol, int pos);
void preOrdenRec(tArbol arbol, int pos);
void postOrdenRec(tArbol arbol, int pos);
void copiarEspejo(tArbol* destino, tArbol origen, int origenPos, int* destinoPos);


#endif //ARBOLBINARIO_H
