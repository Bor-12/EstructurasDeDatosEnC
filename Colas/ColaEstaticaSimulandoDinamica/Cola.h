//
// Created by borja on 21/03/2025.
//

#ifndef COLA_H
#define COLA_Ha
#include "tElemento.h"
#define DIMENSION 100
typedef struct Nodo {
    struct Nodo *siguiente;
    struct Nodo *anterior;
    tElemento elemento;
}tNodo;
typedef struct Cola {
    int primeroOcupado;
    int primeroLibre;
    tNodo almacen[DIMENSION];
}tCola;
void crearColaVacia(tCola* cola);
void encolar(tCola* cola, tElemento elem);

void primeroCola(tCola* cola, tElemento* elem);
void desencolar(tCola* cola);

int esColaVacia(tCola* cola);
int esColaLlena(tCola *cola);
int longitudCola(tCola* cola);
void mostrarCola(tCola* cola);
void hacerBucleInfinito(tCola *cola);
#endif //COLA_H
