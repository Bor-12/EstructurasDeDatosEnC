//
// Created by borja on 01/05/2025.
//

#include <stdio.h>
#include <string.h>
#include "Persona.h"

void crearPersona(tPersona persona, const char *nombre) {
    strcpy(persona, nombre);
}

int sonIguales(tPersona p1, tPersona p2) {
    return strcmp(p1, p2) == 0;
}

void copiarPersona(tPersona destino, tPersona origen) {
    strcpy(destino, origen);
}

void mostrarPersona(tPersona persona) {
    printf("%s", persona);
}

