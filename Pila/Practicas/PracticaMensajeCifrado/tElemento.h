//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H
typedef char tElemento;

void asignarElemento(tElemento* destino, tElemento origen);
tElemento elementoVacio();
int esIgual(tElemento elemento1, tElemento elemento2);
void mostrarElemento(tElemento elemento);
int esVocal(tElemento elemento);
int esEspacio(tElemento elemento);
#endif //TELEMENTO_H
