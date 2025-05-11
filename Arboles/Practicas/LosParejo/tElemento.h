//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#define MAX_NOMBRE 100

typedef struct {
    char nombre[MAX_NOMBRE];
} tElemento;
tElemento crearElemento(const char* nombre);
void asignarElemento(tElemento *destino, tElemento origen);
int esMenor(tElemento e1, tElemento e2);
int esIgual(tElemento e1, tElemento e2);
void mostrarElemento(tElemento e);

#endif //TELEMENTO_H