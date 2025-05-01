//
// Created by borja on 01/05/2025.
//

#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

void crearGrafoVacio(tGrafo *grafo) {
    *grafo = NULL;
}
void insertarVertice(tGrafo *grafo, tCiudad ciudad) {
    tNodoGrafo *nuevoNodo = (tNodoGrafo *) malloc(sizeof(tNodoGrafo));
    copiarCiudad(nuevoNodo -> ciudad, ciudad);
    nuevoNodo -> listaAdyacencias = NULL;
    nuevoNodo -> siguiente = *grafo;
    *grafo = nuevoNodo;
}
void insertarConexion(tGrafo *grafo, tCiudad origen, tCiudad destino) {
    tNodoGrafo *aux = *grafo;
    while (aux != NULL && !sonIguales(origen, aux -> ciudad)) {
        aux = aux -> siguiente;
    }
    if (aux != NULL) {
        tNodoAdyacencias *adyAux = aux -> listaAdyacencias;
        while (adyAux != NULL && !sonIguales(destino, adyAux -> ciudad)) {
            adyAux = adyAux -> siguiente;
        }
        if (adyAux == NULL) {
            tNodoAdyacencias *nuevoNodo = (tNodoAdyacencias*) malloc(sizeof(tNodoAdyacencias));
            copiarCiudad(nuevoNodo -> ciudad, destino);
            nuevoNodo -> siguiente = aux -> listaAdyacencias;
            aux -> listaAdyacencias = nuevoNodo;
        }
    }
}
void insertarArista(tGrafo *grafo, tCiudad origen, tCiudad destino) {
    insertarConexion(grafo, origen, destino);
    insertarConexion(grafo, destino, origen);
}
void mostrarGrafo(tGrafo grafo) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL) {
        printf("La ciudad: ");
        mostrarCiudad(aux->ciudad);
        printf(" esta conectada con:\n");

        tNodoAdyacencias *adyAux = aux->listaAdyacencias;
        while (adyAux != NULL) {
            printf("  - ");
            mostrarCiudad(adyAux->ciudad);
            printf("\n");
            adyAux = adyAux->siguiente;
        }
        printf("\n");
        aux = aux->siguiente;
    }
}
int numeroConexionesVertice(tGrafo grafo, tCiudad ciudad) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL && !sonIguales(ciudad, aux -> ciudad)) {
        aux = aux -> siguiente;
    }
    int contador = 0;
    if (aux != NULL) {
        tNodoAdyacencias *auxAdy = aux -> listaAdyacencias;
        while (auxAdy != NULL) {
            contador++;
            auxAdy = auxAdy -> siguiente;
        }
    }
    return contador;
}
void ciudadEnPosicion(tGrafo grafo,char *nombreCiudad, int posicion, tCiudad resultado) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL && !sonIguales(nombreCiudad, aux -> ciudad)) {
        aux = aux -> siguiente;
    }
    int contador = 0;
    if (aux != NULL) {
        tNodoAdyacencias *auxAdy = aux -> listaAdyacencias;
        while (auxAdy != NULL && contador < posicion) {
            contador++;
            auxAdy = auxAdy -> siguiente;
        }
        if (auxAdy != NULL) {
            copiarCiudad(resultado, auxAdy->ciudad);
        }
    }
}