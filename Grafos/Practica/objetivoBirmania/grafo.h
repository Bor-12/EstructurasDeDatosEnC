//
// Created by borja on 01/05/2025.
//

#ifndef GRAFO_H
#define GRAFO_H

#include "Persona.h"


typedef struct NodoAdyacencias {
    struct NodoAdyacencias *siguiente;
    tPersona persona;
} tNodoAdyacencias;

typedef tNodoAdyacencias *tListaAdyacencias;


typedef struct NodoGrafo {
    struct NodoGrafo *siguiente;
    tPersona persona;
    tListaAdyacencias listaAdyacencias;
} tNodoGrafo;

typedef tNodoGrafo *tGrafo;


void crearGrafoVacio(tGrafo *grafo);
void insertarVertice(tGrafo *grafo, tPersona persona);
void insertarConexion(tGrafo *grafo, tPersona origen, tPersona destino);
void insertarArista(tGrafo *grafo, tPersona origen, tPersona destino);
void mostrarGrafo(tGrafo grafo);

void objetivoBirmania(tGrafo grafo, tPersona persona, tPersona *amigos, int *numAmigos) ;
int estaEnLista(tPersona *lista, int n, tPersona persona);
#endif // GRAFO_H

