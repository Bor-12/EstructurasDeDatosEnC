#include <stdio.h>
#include "Pila.h"


int main() {
    tPila miPila;
    tElemento elemento1, elemento2, elemento3;

    crearPilaVacia(&miPila);

    if (esPilaVacia(&miPila)) {
        printf("La pila está vacía.\n");
    }

    elemento1.numero = 10;
    elemento2.numero = 20;
    elemento3.numero = 30;

    apilar(&miPila, elemento1);
    apilar(&miPila, elemento2);
    apilar(&miPila, elemento3);

    printf("Pila después de apilar elementos:\n");
    mostrarPila(&miPila);
    printf("\n");

    tElemento cimaElemento;
    cima(&miPila, &cimaElemento);
    printf("Elemento en la cima: %d\n", cimaElemento.numero);

    desapilar(&miPila);
    printf("\nPila después de desapilar un elemento:\n");
    mostrarPila(&miPila);
    printf("\n");

    if (esPilaVacia(&miPila)) {
        printf("La pila está vacía.\n");
    } else {
        printf("La pila aún tiene elementos.\n");
    }

    // Copiar pila
    tPila pilaCopia;
    copiar(miPila, &pilaCopia);

    printf("\nPila copiada:\n");
    mostrarPila(&pilaCopia);
    printf("\n");

    return 0;
}