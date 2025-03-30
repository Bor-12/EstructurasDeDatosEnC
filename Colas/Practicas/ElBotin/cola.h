#ifndef COLA_H
#define COLA_H

#include "secuaz.h"

typedef tSecuaz tElementoCola;

typedef struct nodoCola {
    tElementoCola elem;
    struct nodoCola* sig;
} tNodoCola;
typedef tNodoCola* tCola;

void crearColaVacia(tCola* cola);
void encolar(tCola* cola, tElementoCola elem);

void primeroCola(tCola cola, tElementoCola* elem);
void desencolar(tCola* cola);

int esColaVacia(tCola cola);

void mostrarCola(tCola cola);
#endif
