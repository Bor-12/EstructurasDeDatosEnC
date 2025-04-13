//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#define MAX_LONGITUD 50

typedef char tElemento[MAX_LONGITUD];

void crearElemento(tElemento *PunteroElemento, const char *cadena);
void asignarElemento(tElemento *PunteroElemento, tElemento valor);
int esIgual(tElemento e1, tElemento e2);
void mostrarElemento(tElemento e);


#endif // TELEMENTO_H
