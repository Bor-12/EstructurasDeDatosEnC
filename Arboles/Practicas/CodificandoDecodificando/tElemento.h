//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

typedef struct {
    char letra;
} tElemento;
void asignarLetra(tElemento *PunteroElemento, char letra);
void asignarElemento(tElemento *PunteroElemento, tElemento valor);
int esMenor(tElemento e1, tElemento e2);
int esIgual(tElemento e1, tElemento e2);
void mostrarElemento(tElemento e);

#endif //TELEMENTO_H
