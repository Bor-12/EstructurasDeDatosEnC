#include <stdio.h>
#include <string.h>
#include "arbolBinario.h"
#include "tElemento.h"

int main() {
    tArbol arbol;
    char palabra[] = "murcielago";
    char codificada[] = "megolaucir";

    printf("-------Codificando la palabra: %s -------\n", palabra);
    codificarPalabra(&arbol, palabra);
    preOrden(arbol);
    printf("\n");

    destruirArbol(&arbol);

    printf(" ------- Decodificando la palabra: %s -------\n", codificada);
    decodificarPalabra(&arbol, codificada);
    preOrden(arbol);
    printf("\n");
    destruirArbol(&arbol);

    return 0;
}

