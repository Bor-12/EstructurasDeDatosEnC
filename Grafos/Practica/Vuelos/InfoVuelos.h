//
// Created by borja on 01/05/2025.
//
#ifndef TDATOSVUELO_H
#define TDATOSVUELO_H

typedef struct {
    char compania[50];
    int tiempo;
    float precio;
} tDatosVuelo;

void mostrarDatosVuelo(tDatosVuelo datos);
void asignarDatosVuelo(tDatosVuelo *destino, const char *compania, int tiempo, float precio);

#endif // TDATOSVUELO_H

