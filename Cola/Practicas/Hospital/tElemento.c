//
// Created by borja on 27/02/2025.
//

#include "tElemento.h"
#include <stdio.h>

#include <stdio.h>
#include <string.h>
#include "tElemento.h"

void asignarElemento(tElemento *PunteroElemento, tElemento valor) {
    *PunteroElemento = valor;
}
tElemento crearPaciente(const char* nombre, const char* apellidos, int edad, const char* motivo, const char* fecha, int prioridad) {
    tElemento e;
    strncpy(e.nombre, nombre, MAX_NOMBRE);
    strncpy(e.apellidos, apellidos, MAX_NOMBRE);
    e.edad = edad;
    strncpy(e.motivo, motivo, MAX_MOTIVO);
    strncpy(e.fecha, fecha, MAX_FECHA);
    e.prioridad = prioridad;
    return e;
}

int esMenor(tElemento e1, tElemento e2) {
    // Menor prioridad significa número de prioridad mayor (porque 1 = más urgente)
    return e1.prioridad > e2.prioridad;
}

int esIgual(tElemento e1, tElemento e2) {
    return e1.prioridad == e2.prioridad;
}
void mostrarElemento(tElemento e) {
    printf("Paciente: %s %s\n", e.nombre, e.apellidos);
    printf("Edad: %d\n", e.edad);
    printf("Motivo: %s\n", e.motivo);
    printf("Fecha: %s\n", e.fecha);
    printf("Prioridad: %d\n", e.prioridad);
    printf("----------------------------\n");
}
tElemento elementoVacio() {
    tElemento e;
    strcpy(e.nombre, "");
    strcpy(e.apellidos, "");
    strcpy(e.motivo, "");
    strcpy(e.fecha, "");
    e.edad = -1;
    e.prioridad = 6; // más baja que cualquier prioridad válida (1 a 5)
    return e;
}

int obtenerRangoEdad(tElemento e) {
    if (e.edad <= 15) return 0;
    else if (e.edad <= 30) return 1;
    else if (e.edad <= 50) return 2;
    else return 3;
}

