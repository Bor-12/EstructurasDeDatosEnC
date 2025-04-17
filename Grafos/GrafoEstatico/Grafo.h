//
// Created by borja on 17/04/2025.
//

#ifndef GRAFO_H
#define GRAFO_H
#define VERTICES 10
#include "tElemento.h"
typedef struct {
    int matrizAdyacencias[VERTICES][VERTICES];
    tElemento vertices[VERTICES];
    int numeroVertices;
} tGrafo;


void crearGrafoVacio(tGrafo *grafo, tElemento vertices[VERTICES]);
void insertarArista(tGrafo *grafo, tElemento origen, tElemento destino);
void mostrarVertices(tGrafo grafo);
void mostrarConexionesGrafo(tGrafo grafo);

int esFuente(tGrafo grafo, tElemento vertice);
int esSumidero(tGrafo grafo, tElemento vertice);
void mostrarConexionesDeUnVertice(tGrafo grafo, tElemento vertice);
void mostrarCamidosLongitudDos(tGrafo grafo, tElemento vertice);
int estanConectados(tGrafo grafo, tElemento origen, tElemento destino);

#endif //GRAFO_H
