#include "tElemento.h"
#include <stdio.h>
void crearElemento(tElemento *PunteroElemento, char caracter) {
    PunteroElemento -> caracter = caracter;
}
void asignarElemento(tElemento *PunteroElemento, tElemento valor) {
    if (PunteroElemento != NULL) {
        PunteroElemento->caracter = valor.caracter;
    }
}

int esMenor(tElemento e1, tElemento e2) {
    return e1.caracter < e2.caracter;
}

int esIgual(tElemento e1, tElemento e2) {
    return e1.caracter == e2.caracter;
}

void mostrarElemento(tElemento e) {
    printf("Valor del elemento: %c\n", e.caracter);
}

tElemento elementoVacio() {
    tElemento e;
    e.caracter = '\0';  // Caracter nulo para representar "vacío"
    return e;
}
