#include <math.h>
#include <stdio.h>
#include "Conjunto.h"
#include "tElemento.h"
#include "tLista.h"
int main() {
    tLista lista;
    crearListaVacia(&lista);

    int numeros[] = {5, 6, 7, 8, 9, 12, 14, 15, 26, 72, 75, 82, 90, 91, 92};
    int longitud = sizeof(numeros) / sizeof(numeros[0]); // tamaño del array en bytes / tamaño de un elemento del array

    for (int i = 0; i < longitud; i++) {
        tElemento elem;
        crearElemento(&elem, numeros[i]);  // Asumiendo que tElemento contiene un int
        insertarElementoFinal(&lista, elem);
    }

    printf("Lista de bolas introducidas:\n");
    mostrarLista(lista);

    tConjunto conjuntoRestas;
    iniciarConjunto(&conjuntoRestas);


    tLista aux1 = lista;

    while (aux1 != NULL) {
        tLista aux2 = aux1->siguiente;
        while (aux2 != NULL) {
            int v1 = obtenerValor(aux1->elemento);
            int v2 = obtenerValor(aux2->elemento);
            int diferencia = abs(v1 - v2);

            if (diferencia != 0) {
                tElemento nuevo;
                crearElemento(&nuevo, diferencia);
                insertar(&conjuntoRestas, nuevo);
            }

            aux2 = aux2->siguiente;
        }
        aux1 = aux1->siguiente;
    }

    printf("\n Se pudieron incluir en los cartones todos estos numeros: \n");
    mostrarConjunto(conjuntoRestas);
    printf("\nOrdenado:\n");
    ordenarConjunto(&conjuntoRestas);
    mostrarConjunto(conjuntoRestas);

    return 0;
}
