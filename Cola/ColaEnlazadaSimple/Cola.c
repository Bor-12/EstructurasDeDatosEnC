//
// Created by borja on 21/03/2025.
//

#include "Cola.h"
#include "stdio.h"
#include "stdlib.h"
void crearColaVacia(tCola* cola) {
    *cola = NULL;
}
void encolar(tCola* cola, tElemento elem) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elem);

    if(!esColaVacia(cola)){
        tNodo *aux = cola;
        while (aux -> siguiente != NULL){
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevoNodo;
    }else{
        *cola = nuevoNodo;
    }

    nuevoNodo -> siguiente = NULL;
}

void primeroCola(tCola* cola, tElemento* elem) {
    if (!esColaVacia(cola)) {
        asignarElemento(elem, (*cola)-> elemento);
    }
}
void desencolar(tCola* cola) {
    if(!esColaVacia(cola)){
        tNodo *aux = *cola;
        *cola = (*cola) -> siguiente;
        free(aux);
    }
}


int esColaVacia(tCola* cola) {
    return *cola == NULL;
}
int longitudCola(tCola* cola) {
    tNodo *aux = *cola;
    int contador = 0;
    while (aux != NULL){
        contador++;
        aux = aux -> siguiente;
    }
    return contador;
}
void mostrarCola(tCola* cola) {
    tNodo *aux = *cola;

    while (aux != NULL){
        mostrarElemento(aux -> elemento);
        aux = aux -> siguiente;
    }

}