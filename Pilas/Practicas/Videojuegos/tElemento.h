//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#define MAX_CADENA 100

typedef struct {
    char titulo[MAX_CADENA];
    char genero[MAX_CADENA];
    float puntuacion;
    float precio;
} tElemento;

void asignarElemento(tElemento *destino, tElemento origen);
int esMenor(tElemento e1, tElemento e2);     // Menor precio
int esIgual(tElemento e1, tElemento e2);     // Igual título
void mostrarElemento(tElemento e);
int esGratis(tElemento e);
void leerElemento(tElemento *e);

#endif // TELEMENTO_H

