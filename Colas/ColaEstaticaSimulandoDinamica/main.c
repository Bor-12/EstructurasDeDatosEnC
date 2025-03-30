#include <stdio.h>
#include "Cola.h"
#include "tElemento.h"

int main() {
    tCola cola;
    tElemento e1, e2, e3, e4, primero;

    crearColaVacia(&cola);

    if (esColaVacia(&cola)) {
        printf("La cola está vacía.\n");
    }

    e1.numero = 10;
    e2.numero = 20;
    e3.numero = 30;

    printf("\nEncolando 10, 20, 30...\n");
    encolar(&cola, e1);
    encolar(&cola, e2);
    encolar(&cola, e3);

    printf("Contenido de la cola:\n");
    mostrarCola(&cola);

    primeroCola(&cola, &primero);
    printf("Primero en la cola: %d\n", primero.numero);

    printf("Desencolando un elemento...\n");
    desencolar(&cola);

    printf("Contenido tras desencolar:\n");
    mostrarCola(&cola);

    e4.numero = 40;
    printf("Encolando 40...\n");
    encolar(&cola, e4);

    printf("Cola actual:\n");
    mostrarCola(&cola);

    //printf("hacer bucle");
    //hacerBucleInfinito(&cola);
    printf("Vaciando la cola...\n");
    while (!esColaVacia(&cola)) {
        primeroCola(&cola, &primero);
        printf("Sacando: %d\n", primero.numero);
        desencolar(&cola);
    }

    if (esColaVacia(&cola)) {
        printf("Cola vacía al final.\n");
    }
    return 0;
}
