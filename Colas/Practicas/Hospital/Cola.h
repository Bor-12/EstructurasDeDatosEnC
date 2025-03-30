//
// Created by borja on 21/03/2025.
//

#ifndef COLA_H
#define COLA_H
#include "tElemento.h"
typedef struct NodoCola {
    struct NodoCola *siguiente;
    struct NodoCola *anterior;
    tElemento elemento;
}tNodo;
typedef struct Cola {
    tNodo *principio;
    tNodo *final;
    int longitud;
}tCola;
void crearColaVacia(tCola* cola);
void encolar(tCola* cola, tElemento elem);

void primeroCola(tCola* cola, tElemento* elem);
void desencolar(tCola* cola);

int esColaVacia(tCola* cola);
int longitudCola(tCola* cola);
void mostrarCola(tCola* cola);
#endif //COLA_H
