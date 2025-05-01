//
// Created by borja on 01/05/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define MAX_AMIGOS 10
void crearGrafoVacio(tGrafo *grafo) {
    *grafo = NULL;
}

void insertarVertice(tGrafo *grafo, tPersona persona) {
    tNodoGrafo *nuevoNodo = (tNodoGrafo *)malloc(sizeof(tNodoGrafo));
    copiarPersona(nuevoNodo->persona, persona);
    nuevoNodo->listaAdyacencias = NULL;
    nuevoNodo->siguiente = *grafo;
    *grafo = nuevoNodo;
}

void insertarConexion(tGrafo *grafo, tPersona origen, tPersona destino) {
    tNodoGrafo *aux = *grafo;
    while (aux != NULL && !sonIguales(aux->persona, origen)) {
        aux = aux->siguiente;
    }

    if (aux != NULL) {

        tNodoAdyacencias *ady = aux->listaAdyacencias;
        while (ady != NULL && !sonIguales(ady->persona, destino)) {
            ady = ady->siguiente;
        }


        if (ady == NULL) {
            tNodoAdyacencias *nuevoAdy = (tNodoAdyacencias *)malloc(sizeof(tNodoAdyacencias));
            copiarPersona(nuevoAdy->persona, destino);
            nuevoAdy->siguiente = aux->listaAdyacencias;
            aux->listaAdyacencias = nuevoAdy;
        }
    }
}

void insertarArista(tGrafo *grafo, tPersona origen, tPersona destino) {
    insertarConexion(grafo, origen, destino);
    insertarConexion(grafo, destino, origen);
}

void mostrarGrafo(tGrafo grafo) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL) {
        printf("Persona: ");
        mostrarPersona(aux->persona);
        printf(" esta conectada con:\n");

        tNodoAdyacencias *ady = aux->listaAdyacencias;
        while (ady != NULL) {
            printf("  - ");
            mostrarPersona(ady->persona);
            printf("\n");
            ady = ady->siguiente;
        }
        printf("\n");
        aux = aux->siguiente;
    }
}

void objetivoBirmania(tGrafo grafo, tPersona persona, tPersona *amigos, int *numAmigos) {
    *numAmigos = 0;

    tNodoGrafo *nodo = grafo;
    while (nodo != NULL && !sonIguales(nodo->persona, persona)) {
        nodo = nodo->siguiente;
    }

    if (nodo == NULL) return;

    tNodoAdyacencias *ady = nodo->listaAdyacencias;
    while (ady != NULL) {
        if (!estaEnLista(amigos, *numAmigos, ady->persona)) {
            copiarPersona(amigos[*numAmigos], ady->persona);
            (*numAmigos)++;
        }
        ady = ady->siguiente;
    }

    for (int i = 0; i < *numAmigos; i++) {
        tNodoGrafo *amigoNodo = grafo;
        while (amigoNodo != NULL && !sonIguales(amigoNodo->persona, amigos[i])) {
            amigoNodo = amigoNodo->siguiente;
        }

        if (amigoNodo != NULL) {
            tNodoAdyacencias *ady2 = amigoNodo->listaAdyacencias;
            while (ady2 != NULL) {
                if (!sonIguales(ady2->persona, persona) && !estaEnLista(amigos, *numAmigos, ady2->persona)) {
                    copiarPersona(amigos[*numAmigos], ady2->persona);
                    (*numAmigos)++;
                }
                ady2 = ady2->siguiente;
            }
        }
    }
}

int estaEnLista(tPersona *lista, int n, tPersona persona) {
    for (int i = 0; i < n; i++) {
        if (sonIguales(lista[i], persona)) {
            return 1;  // Está en la lista
        }
    }
    return 0;  // No está en la lista
}
