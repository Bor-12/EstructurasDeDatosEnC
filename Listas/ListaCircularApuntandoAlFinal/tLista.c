//
// Created by borja on 28/02/2025.
//


#include "tLista.h"
#include <stdlib.h>

//O(1)
void crearListaVacia(tLista *lista) {
    *lista = NULL;
}
//O(1)
int esListaVacia(tLista lista) {
    return lista == NULL;
}

// O(1)
void insertarElementoInicio(tLista *lista, tElemento elemento) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elemento);
    if(esListaVacia(*lista)){
        nuevoNodo -> siguiente = nuevoNodo;
        *lista = nuevoNodo;
    }else{
        nuevoNodo -> siguiente = (*lista) -> siguiente;
        (*lista) -> siguiente = nuevoNodo;
    }
}

// O(1)
void insertarElementoFinal(tLista *lista, tElemento elemento) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elemento);
    if(esListaVacia(*lista)){
        nuevoNodo -> siguiente = nuevoNodo;
    }else{
        nuevoNodo -> siguiente = (*lista) -> siguiente;
        (*lista) -> siguiente = nuevoNodo;
    }
    *lista = nuevoNodo;
}
//O(n)
void eliminarElemento(tLista *lista, tElemento elemento) {
    if (!esListaVacia(*lista)) {
        tNodo *actual = (*lista)->siguiente; // Empieza en el primero
        tNodo *anterior = *lista;
        int encontrado = 0;

        do {
            if (esIgual(actual->elemento, elemento)) {
                encontrado = 1;
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
        } while (!encontrado && actual != (*lista)->siguiente);

        if (encontrado) {
            if (actual == anterior) {
                // Solo hay un nodo
                *lista = NULL;
            } else {
                anterior->siguiente = actual->siguiente;
                if (actual == *lista) {
                    // Si eliminas el último, actualiza el puntero final
                    *lista = anterior;
                }

            }
            free(actual);
        }
    }
}

//O(1)
tElemento obtenerPrimerElemento(tLista lista) {
    if(esListaVacia(lista)){
        return elementoVacio();
    }
    return lista -> siguiente -> elemento;
}
// O(1)
tElemento obtenerUltimoElemento(tLista lista) {
    if(esListaVacia(lista)){
        return elementoVacio();
    }
    return lista -> elemento;
}
//O(n)
int longitudLista(tLista lista) {
    int contador = 0;
    if (!esListaVacia(lista)) {
        tNodo *actual = lista->siguiente;
        do {
            contador++;
            actual = actual->siguiente;
        } while (actual != lista->siguiente);
    }
    return contador;
}

// O(n)
void mostrarLista(tLista lista) {
    if (!esListaVacia(lista)) {
        tNodo *actual = lista->siguiente; // primer nodo

        do {
            mostrarElemento(actual->elemento);
            actual = actual->siguiente;
        } while (actual != lista->siguiente);
    }
}

//O(n)
void vaciarLista(tLista *lista) {
    if (!esListaVacia(*lista)) {
        tNodo *actual = (*lista)->siguiente; // Primer nodo
        tNodo *aux;

        while (actual != *lista) {
            aux = actual;
            actual = actual->siguiente;
            free(aux);
        }

        // Liberar el último nodo
        free(*lista);
        *lista = NULL;
    }
}

void copiarLista(tLista origen, tLista *destino) {
    crearListaVacia(destino);

    if (!esListaVacia(origen)) {
        tNodo *actual = origen->siguiente; // Primer nodo

        do {
            insertarElementoFinal(destino, actual->elemento);
            actual = actual->siguiente;
        } while (actual != origen->siguiente);
    }
}

