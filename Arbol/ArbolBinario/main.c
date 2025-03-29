#include <stdio.h>
#include "ArbolBinario.h"
#include "tElemento.h"

int main() {
    tArbol arbol, izq, der, izqIzq, izqDer, derIzq, derDer;


    crearArbolVacio(&arbol);
    crearArbolVacio(&izq);
    crearArbolVacio(&der);
    crearArbolVacio(&izqIzq);
    crearArbolVacio(&izqDer);
    crearArbolVacio(&derIzq);
    crearArbolVacio(&derDer);

    tElemento elem1 = {1};  // izquierda izquierda
    tElemento elem2 = {2};  // izquierda
    tElemento elem3 = {3};  // izquierda derecha
    tElemento elem4 = {4};  // raíz
    tElemento elem5 = {5};  // derecha izquierda
    tElemento elem6 = {6};  // derecha
    tElemento elem7 = {7};  // derecha derecha
    insertar(&izqIzq, NULL, NULL, elem1);
    insertar(&izqDer, NULL, NULL, elem3);
    insertar(&izq, izqDer, izqIzq, elem2);


    insertar(&derIzq, NULL, NULL, elem5);
    insertar(&derDer, NULL, NULL, elem7);
    insertar(&der, derDer, derIzq, elem6);


    insertar(&arbol, der, izq, elem4);


    printf("Recorrido inOrden: ");
    inOrden(arbol);
    printf("\n");

    printf("Recorrido preOrden: ");
    preOrden(arbol);
    printf("\n");

    printf("Recorrido postOrden: ");
    postOrden(arbol);
    printf("\n");


    if (!esArbolVacio(arbol)) {
        printf("Arbol no está vacío antes de destruirlo.\n");
    }


    destruirArbol(&arbol);


    if (esArbolVacio(arbol)) {
        printf("Arbol destruido correctamente.\n");
    } else {
        printf("Error al destruir el arbol.\n");
    }

    return 0;
}