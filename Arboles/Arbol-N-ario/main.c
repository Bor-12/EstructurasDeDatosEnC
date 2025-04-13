#include <stdio.h>
#include <stdlib.h>
#include "Arbol-N-ario.h"
#include "tElemento.h"

int main() {
    // Árbol 1
    //        10
    //     /  |  |  \
    //   14  13 12  11

    // Árbol 2
    //              20
    //       /   /    \     \
    //     21   22    23     24
    //    /|\           \
    //  25 26 27         28
    //        |
    //       29

    // Árbol 3
    //        30
    //       / | \
    //     31 32 33
    //         |
    //         34
    //        / \
    //      35  36

    tArbol a1, a2, a3, espejo;
    crearArbolVacio(&a1);
    crearArbolVacio(&a2);
    crearArbolVacio(&a3);

    tElemento raiz1 = (tElemento){10};
    a1 = crearNodo(raiz1);
    insertarHijo(a1, crearNodo((tElemento){11}));
    insertarHijo(a1, crearNodo((tElemento){12}));
    insertarHijo(a1, crearNodo((tElemento){13}));
    insertarHijo(a1, crearNodo((tElemento){14}));

    a2 = crearNodo((tElemento){20});
    tArbol nodo21 = crearNodo((tElemento){21});
    tArbol nodo22 = crearNodo((tElemento){22});
    tArbol nodo23 = crearNodo((tElemento){23});
    tArbol nodo24 = crearNodo((tElemento){24});

    insertarHijo(nodo21, crearNodo((tElemento){25}));
    insertarHijo(nodo21, crearNodo((tElemento){26}));
    tArbol nodo27 = crearNodo((tElemento){27});
    tArbol nodo29 = crearNodo((tElemento){29});
    insertarHijo(nodo27, nodo29);
    insertarHijo(nodo21, nodo27);

    tArbol nodo28 = crearNodo((tElemento){28});
    insertarHijo(nodo23, nodo28);

    insertarHijo(a2, nodo21);
    insertarHijo(a2, nodo22);
    insertarHijo(a2, nodo23);
    insertarHijo(a2, nodo24);

    a3 = crearNodo((tElemento){30});
    tArbol nodo31 = crearNodo((tElemento){31});
    tArbol nodo32 = crearNodo((tElemento){32});
    tArbol nodo33 = crearNodo((tElemento){33});
    insertarHijo(a3, nodo31);
    insertarHijo(a3, nodo32);
    insertarHijo(a3, nodo33);

    tArbol nodo34 = crearNodo((tElemento){34});
    insertarHijo(nodo32, nodo34);

    insertarHijo(nodo34, crearNodo((tElemento){35}));
    insertarHijo(nodo34, crearNodo((tElemento){36}));

    printf("Árbol 1 (preorden):\n");
    preOrden(a1);
    printf("\n");

    printf("Árbol 2 (postorden):\n");
    postOrden(a2);
    printf("\n");

    printf("Árbol 3 (inorden):\n");
    inOrden(a3);
    printf("\n");

    printf("Contar nodos en Árbol 1: %d\n", contarNodos(a1));
    printf("Contar hojas en Árbol 2: %d\n", contarHojas(a2));
    printf("Profundidad de Árbol 2: %d\n", profundidad(a2));
    printf("¿Árbol 2 está equilibrado? %s\n", estaEquilibrado(a2) ? "Sí" : "No");

    tElemento buscar = (tElemento){29};
    printf("¿Pertenece 29 al Árbol 2? %s\n", pertenece(a2, buscar) ? "Sí" : "No");

    tElemento padre = (tElemento){27}, hijo = (tElemento){29};
    printf("¿Es 27 padre de 29 en Árbol 2? %s\n", esPadreOMadre(a2, padre, hijo) ? "Sí" : "No");

    printf("Nivel del nodo 29 en Árbol 2: %d\n", nivelNodo(a2, buscar, 0));

    construirEspejo(a2, &espejo);
    printf("\nÁrbol 2 (espejo, preorden):\n");
    preOrden(espejo);

    destruirArbol(&a1);
    destruirArbol(&a2);
    destruirArbol(&a3);
    destruirArbol(&espejo);

    return 0;
}
