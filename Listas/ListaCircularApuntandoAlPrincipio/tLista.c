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

// O(n)
void insertarElementoInicio(tLista *lista, tElemento elemento) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elemento);
    if(esListaVacia(*lista)){
        nuevoNodo -> siguiente = nuevoNodo;
    }else{

        tNodo *aux = *lista;
        while (aux -> siguiente != *lista) {
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevoNodo;
        nuevoNodo -> siguiente = *lista;
    }
    *lista = nuevoNodo;
}

// O(n)
void insertarElementoFinal(tLista *lista, tElemento elemento) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elemento);
    if(esListaVacia(*lista)){
        nuevoNodo -> siguiente = nuevoNodo;
        *lista = nuevoNodo;
    }else{
        tNodo *aux = *lista;
        while (aux -> siguiente != *lista) {
            aux = aux -> siguiente;
        }
        nuevoNodo -> siguiente = *lista;
        aux -> siguiente = nuevoNodo;

    }
}
//O(n) si solo tiene 1 elemento se recorre 1 vez y si se encuentra al final 1 vez en los dos casos O(n)
void eliminarElemento(tLista *lista, tElemento elemento) {
   if(!esListaVacia(*lista)){
       tNodo *actual = *lista;
       tNodo *anterior = NULL;
        int encontrado = 0;
         do {
             if (esIgual(actual->elemento, elemento)) {
                encontrado = 1;
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
         } while (actual != *lista && !encontrado);
         if(encontrado){
           if(actual == actual -> siguiente){
               *lista = NULL;

           }else{
                 if(actual == *lista){
                     *lista = actual -> siguiente;
                     // Buscar el anterior porq no lo tenemos
                     if (anterior == NULL) {
                         anterior = *lista;
                         while (anterior->siguiente != actual) {
                             anterior = anterior->siguiente;
                         }
                     }
                 }
                 anterior->siguiente = actual->siguiente;
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
    return lista -> elemento;
}
// O(n)
tElemento obtenerUltimoElemento(tLista lista) {
    tNodo *aux = lista;
    while (aux -> siguiente != lista) {
        aux = aux -> siguiente;
    }
    return aux -> elemento;
}
//O(n)
int longitudLista(tLista lista) {
    int contador = 0;
    if (!esListaVacia(lista)) {
        tNodo *actual = lista;
        do {
            contador++;
            actual = actual->siguiente;
        } while (actual != lista);
    }
    return contador;
}

// O(n)
void mostrarLista(tLista lista) {
    if (!esListaVacia(lista)) {
        tNodo *actual = lista;

        do {
            mostrarElemento(actual->elemento);
            actual = actual->siguiente;
        } while (actual != lista);
    }
}

//O(n)
void vaciarLista(tLista *lista) {
    if (!esListaVacia(*lista)) {
        tNodo *actual = *lista;
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
        tNodo *actual = origen;

        do {
            insertarElementoFinal(destino, actual->elemento);
            actual = actual->siguiente;
        } while (actual != origen);
    }
}

