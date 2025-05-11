//
// Created by borja on 27/02/2025.
//

#include "tElemento.h"
#include <stdio.h>

void asignarElemento(tElemento *PunteroElemento, tElemento valor) {
    if (PunteroElemento != NULL) {
        PunteroElemento->valor = valor.valor;
    }
}

int esMenor(tElemento e1, tElemento e2) {
    return e1.valor < e2.valor;
}

int esIgual(tElemento e1, tElemento e2) {
    return e1.valor == e2.valor;
}

void mostrarElemento(tElemento e) {
    printf("Valor del elemento: %d\n", e.valor);
}
tElemento elementoVacio() {
    tElemento e;
    e.valor = 0;
    return e;
}