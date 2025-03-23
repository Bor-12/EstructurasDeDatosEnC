//
// Created by borja on 21/03/2025.
//

#include "Cola.h"
#include "stdio.h"
#include "stdlib.h"
void crearColaVacia(tCola* cola) {
    cola -> final = NULL;
    cola -> principio = NULL;
    cola -> longitud = 0;
}
void encolar(tCola* cola, tElemento elem) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elem);
    nuevoNodo -> siguiente = NULL;
    nuevoNodo -> anterior = NULL;
    cola -> longitud++;

    if (esColaVacia(cola)) {
        cola -> principio = nuevoNodo;
        cola -> final = nuevoNodo;
    }else {
        tNodo *actual = cola -> principio;
        // cuanto mayor sea el elemento mayor prioridad tiene
        while (actual != NULL && (!esMenor(actual -> elemento, elem) || esIgual(actual -> elemento, elem))) {
            actual = actual -> siguiente;
        }
        if (actual == NULL) {
            nuevoNodo -> anterior = cola -> final;
            cola -> final -> siguiente = nuevoNodo;
            cola -> final  = nuevoNodo;
        }else {
            if (actual == cola -> principio) {
                nuevoNodo -> siguiente = cola -> principio;
                cola -> principio  -> anterior = nuevoNodo;
                cola -> principio = nuevoNodo;
            }else {
                nuevoNodo -> siguiente = actual;
                nuevoNodo -> anterior = actual -> anterior;
                actual -> anterior -> siguiente = nuevoNodo;
                actual -> anterior = nuevoNodo;
            }

        }
    }


}

void primeroCola(tCola* cola, tElemento* elem) {
    if (!esColaVacia(cola)) {
        asignarElemento(elem, cola->principio->elemento);
    }
}
void desencolar(tCola* cola) {
    if (!esColaVacia(cola)) {
        tNodo *aux = cola->principio;
        cola->principio = aux->siguiente;

        if (cola->principio != NULL) {
            cola->principio->anterior = NULL;
        } else {
            cola->final = NULL;  // la cola quedó vacía
        }

        free(aux);
        cola->longitud--;
    }
}

void eliminarElementoCola(tCola *cola, tElemento elem){
    tNodo *actual = cola -> principio;
    tNodo *anterior = NULL;
    while(actual != NULL && !esIgual(actual -> elemento, elem)){
        anterior = actual;
        actual = actual -> siguiente;
    }
    if (actual != NULL){
        tNodo *aux = actual;
        if(anterior == NULL){
            cola -> principio = actual -> siguiente;
            if(cola -> principio != NULL){
                cola -> principio -> anterior = NULL;
            }else{
                cola -> final = NULL;
            }

        }
        else{
            anterior->siguiente = actual->siguiente;
            if (actual->siguiente != NULL)
                actual->siguiente->anterior = anterior;
            else
                cola->final = anterior;
        }
        free(actual);
        cola->longitud--;
    }
}

int esColaVacia(tCola* cola) {
    return cola -> principio == NULL;
}
int longitudCola(tCola* cola) {
    return cola -> longitud;
}
void mostrarCola(tCola* cola) {
    tNodo *aux = cola -> principio;
    while (aux != NULL) {
        mostrarElemento(aux -> elemento);
        aux = aux -> siguiente;
    }
}