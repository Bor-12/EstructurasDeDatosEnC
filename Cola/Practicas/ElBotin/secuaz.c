//
// Created by Javier Vergara Igual on 7/3/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "secuaz.h"

void crearSecuaz(tSecuaz* secuaz, char* nombre) {
    strcpy(secuaz->nombre, nombre);
    secuaz->dineroCobrado = 0;
}

void asignar(tSecuaz* destino, tSecuaz origen) {
    strcpy(destino->nombre, origen.nombre);
    destino->dineroCobrado = origen.dineroCobrado;
}

int iguales(tSecuaz s1, tSecuaz s2) {
    return strcmp(s1.nombre, s2.nombre) == 0;
}

char* dameNombre(tSecuaz secuaz) {
    char *nombre = (char*)malloc(N * sizeof(char));
    strcpy(nombre, secuaz.nombre);
    return nombre;
}

int dameDineroCobrado(tSecuaz secuaz) {
    return secuaz.dineroCobrado;
}

void cobrar(tSecuaz* secuaz, int cantidad) {
    secuaz->dineroCobrado += cantidad;
}

void mostrarElemento(tSecuaz secuaz) {
    printf("Nombre: %s\n", secuaz.nombre);
    printf("Dinero cobrado: %d\n", secuaz.dineroCobrado);
}