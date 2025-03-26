//
// Created by borja on 27/02/2025.
//

#include "tElemento.h"
#include <stdio.h>



void asignarElemento(tElemento* destino, tElemento origen) {
    *destino = origen;
}

int esIgual(tElemento elemento1, tElemento elemento2) {
    return elemento1 == elemento2;
}

void mostrarElemento(tElemento elemento) {
    printf("%c", elemento);
}

int esVocal(tElemento elemento) {
    return elemento == 'a' || elemento == 'e' || elemento == 'i' || elemento == 'o' || elemento == 'u' ||
           elemento == 'A' || elemento == 'E' || elemento == 'I' || elemento == 'O' || elemento == 'U';
}
tElemento elementoVacio(){
    tElemento e;
    asignarElemento(&e, "\0");
    return e;
}
int esEspacio(tElemento elemento) {
    return elemento == ' ';
}