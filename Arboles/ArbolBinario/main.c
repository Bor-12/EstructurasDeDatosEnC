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