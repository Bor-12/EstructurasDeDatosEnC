#include <stdio.h>

#include "grafo.h"
#include "Persona.h"
#define MAX_AMIGOS 10
int main(void) {
    tGrafo grafo;
    crearGrafoVacio(&grafo);

    const char *personas[] = {
        "Cathy", "Dave", "Bill", "Audrey", "Jeff",
        "Ilana", "Gayle", "Emily", "Frank", "Harry"
    };
    int numPersonas = sizeof(personas) / sizeof(personas[0]);

    for (int i = 0; i < numPersonas; i++) {
        tPersona p;
        crearPersona(p, personas[i]);
        insertarVertice(&grafo, p);
    }

    const char *amistades[][2] = {
        {"Cathy", "Bill"}, {"Cathy", "Dave"},
        {"Bill", "Audrey"}, {"Bill", "Jeff"},
        {"Jeff", "Audrey"}, {"Jeff", "Ilana"}, {"Jeff", "Dave"},
        {"Dave", "Gayle"},
        {"Gayle", "Emily"}, {"Gayle", "Harry"},
        {"Emily", "Frank"}
    };
    int numAmistades = sizeof(amistades) / sizeof(amistades[0]);

    for (int i = 0; i < numAmistades; i++) {
        tPersona p1, p2;
        crearPersona(p1, amistades[i][0]);
        crearPersona(p2, amistades[i][1]);
        insertarArista(&grafo, p1, p2);
    }

    printf("GRAFO COMPLETO:\n");
    mostrarGrafo(grafo);

    // Aplicar la función objetivoBirmania
    tPersona resultado[MAX_AMIGOS];
    int numResultado;
    tPersona origen;
    crearPersona(origen, "Cathy");

    objetivoBirmania(grafo, origen, resultado, &numResultado);

    printf("\nObjetivoBirmania (Cathy):\n");
    for (int i = 0; i < numResultado; i++) {
        printf(" - ");
        mostrarPersona(resultado[i]);
        printf("\n");
    }

    return 0;
}
