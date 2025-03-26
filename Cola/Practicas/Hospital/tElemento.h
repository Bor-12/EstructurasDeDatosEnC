//
// Created by borja on 27/02/2025.
//
#ifndef TELEMENTO_H
#define TELEMENTO_H

#define MAX_NOMBRE 50
#define MAX_MOTIVO 100
#define MAX_FECHA 11  // dd/mm/aaaa + '\0'

typedef struct {
    char nombre[MAX_NOMBRE];
    char apellidos[MAX_NOMBRE];
    int edad;
    char motivo[MAX_MOTIVO];
    char fecha[MAX_FECHA]; // en formato "dd/mm/aaaa"
    int prioridad;         // 1: rojo, 2: naranja, ..., 5: azul
} tElemento;

void asignarElemento(tElemento *PunteroElemento, tElemento valor);
tElemento crearPaciente(const char* nombre, const char* apellidos, int edad, const char* motivo, const char* fecha, int prioridad);
int esMenor(tElemento e1, tElemento e2);
int esIgual(tElemento e1, tElemento e2);
void mostrarElemento(tElemento e);
int obtenerRangoEdad(tElemento e);
tElemento elementoVacio();


#endif // TELEMENTO_H
