//
// Created by borja on 21/03/2025.
//

#ifndef COLA_H
#define COLA_H
#include "tElemento.h"
typedef struct Nodo {
    struct Nodo *siguiente;
    tElemento elemento;
}tNodo;
typedef tNodo *tCola;
void crearColaVacia(tCola* cola);
void encolar(tCola* cola, tElemento elem);

void primeroCola(tCola* cola, tElemento* elem);
void desencolar(tCola* cola);

int esColaVacia(tCola* cola);
int longitudCola(tCola* cola);
void mostrarCola(tCola* cola);
#endif //COLA_H
