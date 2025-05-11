#include <stdio.h>
#include "ArbolBinario.h"
#include "tElemento.h"

int main() {
    tArbol arbol;
    inicializarArbol(&arbol);

    // Insertar elementos para forzar rebalanceo en AVL
    int valores[] = {30, 20, 40, 10, 25, 35, 50, 5, 15};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("Insertando elementos en el arbol AVL...\n");
    for (int i = 0; i < n; i++) {
        tElemento elem;
        elem.valor = valores[i];
        insertar(&arbol, elem);
    }
    printf("Verificacion manual de AVL: %s\n", verificarAVL(arbol) ? "Correcto" : "Incorrecto");

    printf("\nRecorrido inOrden (ordenado):\n");
    inOrden(arbol);

    printf("\n\nRecorrido preOrden:\n");
    preOrden(arbol);

    printf("\n\nRecorrido postOrden:\n");
    postOrden(arbol);

    printf("\n\nAltura del arbol: %d\n", obtenerAltura(arbol));
    printf("El arbol %s equilibrado.\n", estaEquilibrado(arbol) ? "esta" : "no esta");


    tElemento buscar = {25};
    printf("\nEl elemento %d %s en el arbol.\n", buscar.valor,
           pertenece(arbol, buscar) ? "esta" : "no esta");


    tElemento aEliminar = {20};
    printf("\nEliminando el nodo con valor %d...\n", aEliminar.valor);
    eliminarElemento(&arbol, aEliminar);

    printf("Recorrido inOrden despues de eliminar %d:\n", aEliminar.valor);
    inOrden(arbol);


    destruirArbol(&arbol);
    printf("\n\nArbol destruido. Esta vacio? %s\n", estaVacio(arbol) ? "Si" : "No");

    return 0;
}
