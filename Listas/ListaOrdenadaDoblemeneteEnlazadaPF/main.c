//
// Created by borja on 27/02/2025.
//
#include <stdio.h>
#include "tLista.h"

int main() {
    tLista lista;
    tElemento elemento1, elemento2, elemento3, elemento4, elemento5, elemento6;

    crearListaVacia(&lista);

    if (esListaVacia(lista)) {
        printf("La lista está vacía al inicio.\n");
    }

    elemento1.numero = 10;
    elemento2.numero = 20;
    elemento3.numero = 30;
    elemento4.numero = 40;
    elemento5.numero = 25;
    elemento6.numero = 5;

    insertarOrdenadoInicio(&lista, elemento1);
    printf("\nLista después de insertar un solo elemento (10):\n");
    mostrarLista(lista);
    printf("\n");

    insertarOrdenadoInicio(&lista, elemento2);
    insertarOrdenadoFinal(&lista, elemento3);
    insertarOrdenadoFinal(&lista, elemento4);
    insertarOrdenadoFinal(&lista, elemento5);
    insertarOrdenadoInicio(&lista, elemento6);

    printf("\nLista después de insertar múltiples elementos:\n");
    mostrarLista(lista);
    printf("\n");

    printf("Primer elemento: %d\n", obtenerPrimerElemento(lista).numero);
    printf("Último elemento: %d\n", obtenerUltimoElemento(lista).numero);
    printf("Longitud de la lista: %d\n", longitudLista(lista));

    eliminarElemento(&lista, elemento6);
    printf("\nLista después de eliminar el primer elemento (5):\n");
    mostrarLista(lista);
    printf("\n");

    eliminarElemento(&lista, elemento5);
    printf("\nLista después de eliminar el elemento 25:\n");
    mostrarLista(lista);
    printf("\n");

    eliminarElemento(&lista, elemento4);
    printf("\nLista después de eliminar el último elemento (40):\n");
    mostrarLista(lista);
    printf("\n");

    tElemento elementoNoExistente;
    elementoNoExistente.numero = 99;
    eliminarElemento(&lista, elementoNoExistente);
    printf("\nIntento de eliminar un elemento inexistente (99), la lista debe mantenerse igual:\n");
    mostrarLista(lista);
    printf("\n");

    vaciarLista(&lista);
    if (esListaVacia(lista)) {
        printf("La lista ha sido vaciada correctamente.\n");
    } else {
        printf("Error: la lista no se vació correctamente.\n");
    }

    return 0;
}
