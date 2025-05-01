#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafo.h"

int main() {
    FILE *f = fopen("../vuelos.txt", "r");
    if (!f) return 1;

    tGrafo grafo;
    crearGrafoVacio(&grafo);

    char origen[50], destino[50], compania[50];
    int tiempo;
    float precio;

    while (fgets(origen, sizeof(origen), f)) {
        fgets(destino, sizeof(destino), f);
        fgets(compania, sizeof(compania), f);
        fscanf(f, "%d\n", &tiempo);
        fscanf(f, "%f\n", &precio);

        origen[strcspn(origen, "\n")] = '\0';
        destino[strcspn(destino, "\n")] = '\0';
        compania[strcspn(compania, "\n")] = '\0';

        tCiudad cOrigen, cDestino;
        tDatosVuelo vuelo;

        strcpy(cOrigen, origen);
        strcpy(cDestino, destino);
        asignarDatosVuelo(&vuelo, compania, tiempo, precio);

        if (!ciudadExiste(grafo, cOrigen)) insertarVertice(&grafo, cOrigen);
        if (!ciudadExiste(grafo, cDestino)) insertarVertice(&grafo, cDestino);

        insertarConexion(&grafo, cOrigen, cDestino, vuelo);
    }

    fclose(f);

    // 1. Mostrar destinos desde una ciudad
    mostrarConexionesDeUnVertice(grafo, "Berlin");

    // 2. Verificar si el grafo es conexo
    if (esGrafoConexo(grafo)) {
        printf("\nEl grafo es conexo.\n");
    } else {
        printf("\nEl grafo NO es conexo.\n");
    }

    // 3. Mostrar ciudades a las que se puede ir con una escala
    printf("\nCiudades alcanzables desde Paris con UNA escala:\n");
    mostrarCaminosLongitud2(grafo, "Paris");

    // 4. Verificar si hay conexión directa
    if (estanConectadas(grafo, "Madrid", "Roma")) {
        printf("\nHay conexión directa de Madrid a Roma.\n");
    } else {
        printf("\nNO hay conexión directa de Madrid a Roma.\n");
    }

    // 5. Mostrar ciudades fuente y sumidero
    printf("\nFuentes y sumideros del grafo:\n");
    mostrarFuentesYSumideros(grafo);


    // 6. Trayecto con mayor número de compañías
    // trayectoConMasCompanias(grafo);

    // 7. Trayecto más caro y más barato
    // mostrarTrayectoMasCaroYBarato(grafo);

    // 8. Trayecto más lento y más rápido
    // mostrarTrayectoMasLentoYMasRapido(grafo);

    return 0;
}
