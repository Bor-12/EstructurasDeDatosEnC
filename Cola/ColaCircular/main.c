#include <stdio.h>
#include "Cola.h"

int main() {
    tCola cola;
    tElemento e1, e2, e3, primero;

    crearColaVacia(&cola);

    if (esColaVacia(&cola)) {
        printf("La cola está vacía.\n");
    }

    // Crear elementos
    e1.numero = 10;
    e2.numero = 20;
    e3.numero = 15;

    // Encolar elementos
    printf("\nEncolando elementos...\n");
    encolar(&cola, e1);
    encolar(&cola, e2);
    encolar(&cola, e3);

    // Mostrar cola
    printf("\nContenido de la cola:\n");
    mostrarCola(&cola);

    // Obtener primero
    primeroCola(&cola, &primero);
    printf("\nPrimero en la cola: %d\n", primero.numero);

    // Desencolar
    printf("\nDesencolando un elemento...\n");
    desencolar(&cola);

    // Mostrar cola después de desencolar
    printf("\nContenido de la cola tras desencolar:\n");
    mostrarCola(&cola);

    // Mostrar longitud
    printf("\nLongitud de la cola: %d\n", longitudCola(&cola));

    return 0;
}
