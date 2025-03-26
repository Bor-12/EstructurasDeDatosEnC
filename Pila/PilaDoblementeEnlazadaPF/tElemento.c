//
// Created by borja on 27/02/2025.
//

#include "tElemento.h"
#include <stdio.h>

void asignarElemento(tElemento *PunteroElemento, tElemento valor) {
    if (PunteroElemento != NULL) {
        PunteroElemento->numero = valor.numero;
    }
}

int esMenor(tElemento e1, tElemento e2) {
    return e1.numero < e2.numero;
}

int esIgual(tElemento e1, tElemento e2) {
    return e1.numero == e2.numero;
}

void mostrarElemento(tElemento e) {
    printf("Valor del elemento: %d\n", e.numero);
}
tElemento elementoVacio() {
    tElemento e;
    e.numero = 0;
    return e;
}