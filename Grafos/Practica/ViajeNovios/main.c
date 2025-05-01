#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h"
int main(void) {
    tGrafo grafo;
    crearGrafoVacio(&grafo);

    const char *ciudades[] = {
        "Madrid", "Berlin", "Bruselas", "Paris", "Lisboa", "Dublin", "Londres", "Milan",
        "Atenas", "Moscu", "Sofia", "Praga", "Monaco", "Vienna"
    };
    int numCiudades = sizeof(ciudades) / sizeof(ciudades[0]);


    for (int i = 0; i < numCiudades; i++) {
        tCiudad c;
        crearCiudad(c, ciudades[i]);
        insertarVertice(&grafo, c);
    }


    const char *aristas[][2] = {
        {"Madrid", "Berlin"}, {"Madrid", "Bruselas"}, {"Madrid", "Paris"},
        {"Madrid", "Lisboa"}, {"Madrid", "Dublin"}, {"Madrid", "Atenas"},
        {"Berlin", "Bruselas"}, {"Berlin", "Lisboa"},
        {"Bruselas", "Vienna"}, {"Bruselas", "Moscu"},
        {"Paris", "Milan"}, {"Paris", "Londres"}, {"Paris", "Monaco"},
        {"Lisboa", "Milan"}, {"Lisboa", "Dublin"},
        {"Milan", "Monaco"}, {"Milan", "Londres"},
        {"Atenas", "Berlin"}, {"Atenas", "Moscu"}, {"Atenas", "Sofia"},
        {"Moscu", "Sofia"}, {"Moscu", "Praga"},
        {"Sofia", "Praga"}, {"Sofia", "Vienna"},
        {"Vienna", "Praga"}, {"Vienna", "Monaco"}
    };
    int numAristas = sizeof(aristas) / sizeof(aristas[0]);


    for (int i = 0; i < numAristas; i++) {
        tCiudad origen, destino;
        crearCiudad(origen, aristas[i][0]);
        crearCiudad(destino, aristas[i][1]);
        insertarArista(&grafo, origen, destino);
    }


    mostrarGrafo(grafo);
    srand(time(NULL));


    int totalConexionesDesdeMadrid = numeroConexionesVertice(grafo, "Madrid");
    int posAleatoria1 = rand() % totalConexionesDesdeMadrid;
    tCiudad primeraCiudad;
    ciudadEnPosicion(grafo, "Madrid", posAleatoria1, primeraCiudad);


    int totalConexionesDesdePrimera = numeroConexionesVertice(grafo, primeraCiudad);
    tCiudad segundaCiudad;
    int posAleatoria2;
    do {
        posAleatoria2 = rand() % totalConexionesDesdePrimera;
        ciudadEnPosicion(grafo, primeraCiudad, posAleatoria2, segundaCiudad);
    } while (sonIguales(segundaCiudad, "Madrid")); // no puede volver a Madrid

    printf("Primera ciudad: %s\n", primeraCiudad);
    printf("Segunda ciudad: %s\n", segundaCiudad);

    return 0;
}
