
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

    tElemento elem1 = {1};
    tElemento elem2 = {2};
    tElemento elem3 = {3};
    tElemento elem4 = {4};
    tElemento elem5 = {5};
    tElemento elem6 = {6};
    tElemento elem7 = {7};

    construir(&izqIzq, elem1);
    construir(&izqDer, elem3);
    construir(&izq, elem2);
    izq->izquierda = izqIzq;
    izq->derecha = izqDer;

    construir(&derIzq, elem5);
    construir(&derDer, elem7);
    construir(&der, elem6);
    der->izquierda = derIzq;
    der->derecha = derDer;

    construir(&arbol, elem4);
    arbol->izquierda = izq;
    arbol->derecha = der;

    printf("Recorrido inOrden: ");
    inOrden(arbol);
    printf("\n");

    printf("Recorrido preOrden: ");
    preOrden(arbol);
    printf("\n");

    printf("Recorrido postOrden: ");
    postOrden(arbol);
    printf("\n");

    printf("El árbol %s vacío.\n", esArbolVacio(arbol) ? "está" : "no está");

    tElemento buscar = {3};
    printf("El elemento %d %s en el árbol.\n", buscar.valor, pertenece(arbol, buscar) ? "está" : "no está");

    tElemento padre = {2};
    tElemento hijo = {1};
    printf("El nodo %d %s padre/madre de %d.\n", padre.valor,
           esPadreOMadre(arbol, padre, hijo) ? "es" : "no es", hijo.valor);

    printf("Número total de nodos: %d\n", contarNodos(arbol));
    printf("Número total de hojas: %d\n", contarHojas(arbol));
    printf("Profundidad del árbol: %d\n", profundidad(arbol));
    printf("El árbol %s equilibrado.\n", estaEquilibrado(arbol) ? "está" : "no está");

    tElemento elemNivel = {7};
    int nivel = nivelNodo(arbol, elemNivel, 0);
    if (nivel != -1)
        printf("El nodo %d está en el nivel %d\n", elemNivel.valor, nivel);
    else
        printf("El nodo %d no está en el árbol\n", elemNivel.valor);

    tArbol espejo;
    construirEspejo(arbol, &espejo);
    printf("InOrden del árbol espejo: ");
    inOrden(espejo);
    printf("\n");

    tElemento max;
    if (maximo(arbol, &max)) {
        printf("Máximo del árbol: ");
        mostrarElemento(max);
    } else {
        printf("El árbol está vacío, no hay máximo.\n");
    }

    tElemento min;
    if (minimo(arbol, &min)) {
        printf("Mínimo del árbol: ");
        mostrarElemento(min);
    } else {
        printf("El árbol está vacío, no hay mínimo.\n");
    }

    tElemento aEliminar = {6};
    printf("Eliminando el nodo con valor %d...\n", aEliminar.valor);
    eliminarElemento(&arbol, aEliminar);
    printf("Recorrido inOrden después de eliminar %d: ", aEliminar.valor);
    inOrden(arbol);
    printf("\n");

    destruirArbol(&arbol);
    destruirArbol(&espejo);

    if (esArbolVacio(arbol)) {
        printf("Árbol original destruido correctamente.\n");
    }
    if (esArbolVacio(espejo)) {
        printf("Árbol espejo destruido correctamente.\n");
    }

    return 0;
}
