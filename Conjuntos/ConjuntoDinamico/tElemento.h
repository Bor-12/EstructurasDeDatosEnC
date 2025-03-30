//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

typedef struct {
    char caracter;
} tElemento;
void crearElemento(tElemento *PunteroElemento, char caracter);
void asignarElemento(tElemento *PunteroElemento, tElemento valor);
int esMenor(tElemento e1, tElemento e2);
int esIgual(tElemento e1, tElemento e2);
void mostrarElemento(tElemento e);
tElemento elementoVacio();

#endif // TELEMENTO_H
