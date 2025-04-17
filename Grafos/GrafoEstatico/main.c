#include <stdio.h>
#include "Grafo.h"

int main() {
    tGrafo grafo;
    tElemento vertices[VERTICES];

    for (int i = 0; i < VERTICES; i++) {
        vertices[i].valor = i + 1;
    }

    crearGrafoVacio(&grafo, vertices);

    insertarArista(&grafo, vertices[0], vertices[1]);
    insertarArista(&grafo, vertices[0], vertices[2]);
    insertarArista(&grafo, vertices[1], vertices[3]);
    insertarArista(&grafo, vertices[2], vertices[3]);
    insertarArista(&grafo, vertices[2], vertices[4]);
    insertarArista(&grafo, vertices[4], vertices[5]);
    insertarArista(&grafo, vertices[6], vertices[0]);
    insertarArista(&grafo, vertices[6], vertices[1]);
    insertarArista(&grafo, vertices[6], vertices[2]);
    insertarArista(&grafo, vertices[8], vertices[9]);

    printf("Vertices:\n");
    mostrarVertices(grafo);

    printf("\nConexiones del grafo:\n");
    mostrarConexionesGrafo(grafo);

    for (int i = 0; i < VERTICES; i++) {
        printf("Vertice %d -> Fuente: %d, Sumidero: %d\n",
               vertices[i].valor,
               esFuente(grafo, vertices[i]),
               esSumidero(grafo, vertices[i]));
    }

    printf("\nEstan conectados 1 y 2?: %d\n", estanConectados(grafo, vertices[0], vertices[1]));
    printf("Estan conectados 1 y 5?: %d\n", estanConectados(grafo, vertices[0], vertices[4]));
    printf("Estan conectados 9 y 6?: %d\n", estanConectados(grafo, vertices[8], vertices[5]));

    printf("\nCaminos de longitud 2 desde el vertice 1:\n");
    mostrarCaminosLongitudDos(grafo, vertices[0]);

    printf("\nCaminos de longitud 2 desde el vertice 7:\n");
    mostrarCaminosLongitudDos(grafo, vertices[6]);

    return 0;
}
