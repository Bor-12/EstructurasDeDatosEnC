//
// Created by borja on 23/03/2025.
//

#ifndef TPOLINOMIO_H
#define TPOLINOMIO_H
#include "tLista.h"


typedef tLista tPolinomio;

// Crea y devuelve un nuevo polinomio leído por teclado
tPolinomio leerPolinomio();

// Muestra el polinomio por pantalla
void mostrarPolinomio(tPolinomio p);

// Calcula la derivada de un polinomio
void derivadaPolinomio(tPolinomio *pd, tPolinomio p);

// Evalúa el valor del polinomio para un valor de x
float valorPolinomio(tPolinomio p, float x);

// Suma dos polinomios y guarda el resultado en otro
void sumarPolinomios(tPolinomio *s, tPolinomio p1, tPolinomio p2);
#endif //TPOLINOMIO_H
