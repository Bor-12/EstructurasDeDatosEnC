#include <stdio.h>
#include "ArbolBinario.h"
#include "tElemento.h"

int main() {
    tArbol arbol;
    crearArbolVacio(&arbol);

    tElemento elem1 = {1};
    tElemento elem2 = {2};
    tElemento elem3 = {3};
    tElemento elem4 = {4};
    tElemento elem5 = {5};
    tElemento elem6 = {6};
    tElemento elem7 = {7};

    int pos1 = insertar(&arbol, elem1);
    int pos3 = insertar(&arbol, elem3);
    int pos5 = insertar(&arbol, elem5);
    int pos7 = insertar(&arbol, elem7);

    int pos2 = insertar(&arbol, elem2);
    arbol.almacen[pos2].izquierda = pos1;
    arbol.almacen[pos2].derecha = pos3;

    int pos6 = insertar(&arbol, elem6);
    arbol.almacen[pos6].izquierda = pos5;
    arbol.almacen[pos6].derecha = pos7;

    int pos4 = insertar(&arbol, elem4);
    arbol.almacen[pos4].izquierda = pos2;
    arbol.almacen[pos4].derecha = pos6;
    arbol.primeraPosicionOcupada = pos4;

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
    printf("El elemento %d %s en el árbol.\n", buscar.valor,
           pertenece(arbol, buscar) ? "está" : "no está");

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
