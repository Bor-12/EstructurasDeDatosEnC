//
// Created by borja on 27/02/2025.
//

#include <stdio.h>
#include "tLista.h"

int main() {
    tLista lista;
    tElemento elemento1, elemento2, elemento3, elemento4;

    crearListaVacia(&lista);

    if (esListaVacia(lista)) {
        printf("La lista está vacía.\n");
    }

    elemento1.numero = 10;
    elemento2.numero = 20;
    elemento3.numero = 30;
    elemento4.numero = 40;

    insertarOrdenadoInicio(&lista, elemento1);
    insertarOrdenadoInicio(&lista, elemento2);
    insertarOrdenadoFinal(&lista, elemento3);
    insertarOrdenadoFinal(&lista, elemento4);

    printf("Lista después de insertar elementos:\n");
    mostrarLista(lista);
    printf("\n");

    printf("Primer elemento: %d\n", obtenerPrimerElemento(lista).numero);
    printf("Último elemento: %d\n", obtenerUltimoElemento(lista).numero);
    printf("Longitud de la lista: %d\n", longitudLista(lista));

    eliminarElemento(&lista, elemento2);
    printf("\nLista después de eliminar el elemento con valor 20:\n");
    mostrarLista(lista);
    printf("\n");

    vaciarLista(&lista);
    if (esListaVacia(lista)) {
        printf("La lista ha sido vaciada correctamente.\n");
    }

    return 0;
}

