#include <stdio.h>
#include "Grafo.h"
#include "tElemento.h"

int main() {
    tGrafo grafo;
    crearGrafoVacio(&grafo);

    tElemento v1 = {1}, v2 = {2}, v3 = {3}, v4 = {4}, v5 = {5};

    insertarVertice(&grafo, v1);
    insertarVertice(&grafo, v2);
    insertarVertice(&grafo, v3);
    insertarVertice(&grafo, v4);
    insertarVertice(&grafo, v5);

    insertarConexion(&grafo, v1, v2);
    insertarConexion(&grafo, v2, v3);
    insertarConexion(&grafo, v1, v4);
    insertarConexion(&grafo, v3, v5);

    printf("Vertices del grafo:\n");
    mostrarVerticesGrafo(grafo);

    printf("\nConexiones del grafo:\n");
    mostrarConexionesGrafo(grafo);

    printf("\nConexiones del vertice 1:\n");
    mostrarConexionesDeUnVertice(grafo, v1);

    printf("\nVerificacion de fuentes y sumideros:\n");
    for (int i = 1; i <= 5; i++) {
        tElemento v = {i};
        printf("Vertice %d -> Fuente: %d, Sumidero: %d\n", i, esFuente(grafo, v), esSumidero(grafo, v));
    }

    printf("\nVerificacion de conexiones directas:\n");
    printf("1 -> 2: %d\n", estanConectadas(grafo, v1, v2));
    printf("1 -> 3: %d\n", estanConectadas(grafo, v1, v3));
    printf("2 -> 3: %d\n", estanConectadas(grafo, v2, v3));
    printf("3 -> 5: %d\n", estanConectadas(grafo, v3, v5));
    printf("4 -> 1: %d\n", estanConectadas(grafo, v4, v1));

    printf("\nCaminos de longitud 2 desde vertice 1:\n");
    mostrarCamidosLongitud2(grafo, v1);

    printf("\nCaminos de longitud 2 desde vertice 2:\n");
    mostrarCamidosLongitud2(grafo, v2);

    return 0;
}
