//
// Created by borja on 27/02/2025.
//
#include "tElemento.h"
#include <stdio.h>

void asignarLetra(tElemento *PunteroElemento, char letra) {
    PunteroElemento->letra = letra;
}
void asignarElemento(tElemento *PunteroElemento, tElemento valor) {
    PunteroElemento->letra = valor.letra;
}

int esMenor(tElemento e1, tElemento e2) {
    return e1.letra < e2.letra;
}

int esIgual(tElemento e1, tElemento e2) {
    return e1.letra == e2.letra;
}

void mostrarElemento(tElemento e) {
    printf("%c", e.letra);
}