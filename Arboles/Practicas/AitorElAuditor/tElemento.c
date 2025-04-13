#include <stdio.h>
#include <string.h>
#include "tElemento.h"

void asignarElemento(tElemento *destino, tElemento origen) {
    strcpy(destino->nombre, origen.nombre);
    destino->sueldo = origen.sueldo;
    strcpy(destino->cargo, origen.cargo);
}
int esMenorSueldo(tElemento e, int sueldo){
    return e.sueldo < sueldo;
}
int esMenor(tElemento e1, tElemento e2) {
    return e1.sueldo < e2.sueldo;
}

int esIgual(tElemento e1, tElemento e2) {
    return strcmp(e1.nombre, e2.nombre) == 0 && strcmp(e1.cargo, e2.cargo) == 0;
}

void mostrarElemento(tElemento e) {
    printf("Nombre: %s | Cargo: %s | Sueldo: %d\n", e.nombre, e.cargo, e.sueldo);
}

tElemento crearElemento(const char* nombre, int sueldo, const char* cargo) {
    tElemento e;
    strncpy(e.nombre, nombre, MAX_NOMBRE);
    strncpy(e.cargo, cargo, MAX_CARGO);
    e.nombre[MAX_NOMBRE - 1] = '\0';
    e.cargo[MAX_CARGO - 1] = '\0';
    e.sueldo = sueldo;
    return e;
}
