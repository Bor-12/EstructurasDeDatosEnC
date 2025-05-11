//
// Created by borja on 17/04/2025.
//

#include "Grafo.h"

#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
void crearGrafoVacio(tGrafo *grafo) {
    *grafo = NULL;
}
void insertarVertice(tGrafo *grafo, tElemento vertice) {
    tNodoGrafo *nuevoVerticeGrafo = (tNodoGrafo *) malloc(sizeof(tNodoGrafo));
    asignarElemento(&nuevoVerticeGrafo -> vertice, vertice);
    nuevoVerticeGrafo -> adyacencias = NULL;
    nuevoVerticeGrafo -> siguiente = *grafo;
    *grafo = nuevoVerticeGrafo;
}
void insertarConexion(tGrafo *grafo, tElemento origen, tElemento destino, int ponderacion) {
    tNodoGrafo *auxVerticeOrigen = *grafo;
    while (auxVerticeOrigen != NULL && !esIgual(auxVerticeOrigen->vertice, origen)) {
        auxVerticeOrigen = auxVerticeOrigen->siguiente;
    }

    if (auxVerticeOrigen != NULL) {
        tNodoAdyacencias *auxVerticeAdyacencias = auxVerticeOrigen->adyacencias;
        while (auxVerticeAdyacencias != NULL && !esIgual(auxVerticeAdyacencias->vertice, destino)) {
            auxVerticeAdyacencias = auxVerticeAdyacencias->siguiente;
        }

        if (auxVerticeAdyacencias == NULL) {
            tNodoAdyacencias *nuevoNodo = (tNodoAdyacencias*) malloc(sizeof(tNodoAdyacencias));
            asignarElemento(&nuevoNodo->vertice, destino);
            nuevoNodo->ponderacion = ponderacion; //si es otro dato se utilizaria el set correspondiente como conocemos el tipo de dato simpolemente igualo
            nuevoNodo->siguiente = auxVerticeOrigen->adyacencias;
            auxVerticeOrigen->adyacencias = nuevoNodo;
        } else {
            printf("Ya existe una conexión de ");
            mostrarElemento(origen);
            printf(" hacia ");
            mostrarElemento(destino);
            printf("\n");
        }
    } else {
        printf("No se encontró el vértice de origen: ");
        mostrarElemento(origen);
        printf("\n");
    }
}


void insertarArista(tGrafo *grafo, tElemento origen, tElemento destino, int ponderacion) {
    insertarConexion(grafo, origen, destino, ponderacion);
    insertarConexion(grafo, destino, origen, ponderacion);
}


void mostrarVerticesGrafo(tGrafo grafo) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL) {
        mostrarElemento(aux -> vertice);
        printf(" ");
        aux = aux -> siguiente;
    }
    printf("\n");
}
void mostrarConexionesGrafo(tGrafo grafo) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL) {
        printf("Las conexiones de ");
        mostrarElemento(aux->vertice);
        printf(" son: ");
        tNodoAdyacencias *adyacencias = aux->adyacencias;
        while (adyacencias != NULL) {
            mostrarElemento(adyacencias->vertice);
            printf("(peso: %d) ", adyacencias->ponderacion);
            adyacencias = adyacencias->siguiente;
        }
        printf("\n");
        aux = aux->siguiente;
    }
}

tNodoGrafo* busquedaNodoGrafo(tGrafo grafo, tElemento vertice) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL && !esIgual(aux -> vertice, vertice)) {
        aux = aux -> siguiente;
    }
    return aux;
}
tNodoAdyacencias* busquedaAdyacenciasNodoGrafo(tNodoAdyacencias *nodo, tElemento vertice) {
    tNodoAdyacencias *aux = nodo;
    while (aux != NULL && !esIgual(aux -> vertice, vertice)) {
        aux = aux -> siguiente;
    }
    return aux;
}
int tieneAristasSalientes(tGrafo grafo, tElemento vertice) {
    tNodoGrafo *aux = busquedaNodoGrafo(grafo, vertice);
    if (aux == NULL) {
        return 0;
    }
    return  aux -> adyacencias != NULL;
}
int tieneAristasEntrantes(tGrafo grafo, tElemento vertice) {
    while (grafo != NULL) {
        if (busquedaAdyacenciasNodoGrafo(grafo->adyacencias, vertice) != NULL) {
            return 1;
        }
        grafo = grafo->siguiente;
    }
    return 0;
}

int esFuente(tGrafo grafo, tElemento vertice) {
    return !tieneAristasEntrantes(grafo, vertice) && tieneAristasSalientes(grafo, vertice);
}
int esSumidero(tGrafo grafo, tElemento vertice) {
    return tieneAristasEntrantes(grafo, vertice) && !tieneAristasSalientes(grafo, vertice);
}
void mostrarConexionesDeUnVertice(tGrafo grafo, tElemento vertice) {
    tNodoGrafo *aux = busquedaNodoGrafo(grafo, vertice);

    if (aux == NULL) {
        printf("No se encontró el vértice en el grafo: ");
        mostrarElemento(vertice);
        printf("\n");
        return;
    }

    printf("Conexiones de ");
    mostrarElemento(vertice);
    printf(": ");

    tNodoAdyacencias *ady = aux->adyacencias;
    while (ady != NULL) {
        mostrarElemento(ady->vertice);
        printf(" ");
        ady = ady->siguiente;
    }
    printf("\n");
}

void mostrarCamidosLongitud2(tGrafo grafo, tElemento vertice) {
    tNodoGrafo *nodoOrigen = busquedaNodoGrafo(grafo, vertice);
    if (nodoOrigen == NULL) {
        printf("No se encontró el vértice: ");
        mostrarElemento(vertice);
        printf("\n");
        return;
    }

    tNodoAdyacencias *nivel1 = nodoOrigen->adyacencias;
    while (nivel1 != NULL) {
        tNodoGrafo *nodoIntermedio = busquedaNodoGrafo(grafo, nivel1->vertice);
        if (nodoIntermedio != NULL) {
            tNodoAdyacencias *nivel2 = nodoIntermedio->adyacencias;
            while (nivel2 != NULL) {
                if (!esIgual(nivel2->vertice, vertice)) {
                    printf("Camino de longitud 2: ");
                    mostrarElemento(vertice);
                    printf(" -> ");
                    mostrarElemento(nivel1->vertice);
                    printf(" -> ");
                    mostrarElemento(nivel2->vertice);
                    printf("\n");
                }
                nivel2 = nivel2->siguiente;
            }
        }
        nivel1 = nivel1->siguiente;
    }
}


int estanConectadas(tGrafo grafo, tElemento origen, tElemento destino) {
    tNodoGrafo *nodoOrigen = busquedaNodoGrafo(grafo, origen);
    if (nodoOrigen == NULL) return 0;

    return busquedaAdyacenciasNodoGrafo(nodoOrigen->adyacencias, destino) != NULL;
}

