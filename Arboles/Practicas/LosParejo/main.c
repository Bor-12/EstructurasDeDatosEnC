#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArbolBinario.h"
#include "tElemento.h"

int main() {
    tArbol arbol;
    crearArbolVacio(&arbol);

    tArbol susana, alfonso, cesar, laura, pedro, teresa;

    insertar(&susana, NULL, NULL, crearElemento("Susana"));
    insertar(&alfonso, NULL, NULL, crearElemento("Alfonso"));
    insertar(&cesar, NULL, NULL, crearElemento("Cesar"));

    insertar(&laura, cesar, alfonso, crearElemento("Laura"));
    insertar(&pedro, laura, susana, crearElemento("Pedro"));
    insertar(&teresa, NULL, NULL, crearElemento("Teresa"));

    insertar(&arbol, teresa, pedro, crearElemento("Vanessa"));

    printf("Inorden:\n");
    inOrden(arbol);
    printf("\n");

    printf("Es Pedro padre de Laura? %s\n", esPadreOMadre(arbol, crearElemento("Pedro"), crearElemento("Laura")) ? "Si" : "No");
    printf("Es Cesar padre de Alfonso? %s\n", esPadreOMadre(arbol, crearElemento("Cesar"), crearElemento("Alfonso")) ? "Si" : "No");
    printf("Son Alfonso y Cesar hermanos? %s\n", sonHermanos(arbol, crearElemento("Alfonso"), crearElemento("Cesar")) ? "Si" : "No");
    printf("Son Susana y Laura hermanas? %s\n", sonHermanos(arbol, crearElemento("Susana"), crearElemento("Laura")) ? "Si" : "No");
    printf("Son Susana y Teresa hermanos? %s\n", sonHermanos(arbol, crearElemento("Susana"), crearElemento("Teresa")) ? "Si" : "No");

    destruirArbol(&arbol);
    return 0;
}
