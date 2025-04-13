//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#define MAX_NOMBRE 100
#define MAX_CARGO 100

typedef struct {
    char nombre[MAX_NOMBRE];
    int sueldo;
    char cargo[MAX_CARGO];
} tElemento;

void asignarElemento(tElemento *destino, tElemento origen);
int esMenorSueldo(tElemento e, int sueldo);
int esMenor(tElemento e1, tElemento e2); // compara sueldos
int esIgual(tElemento e1, tElemento e2); // compara nombre y cargo
void mostrarElemento(tElemento e);
tElemento crearElemento(const char* nombre, int sueldo, const char* cargo);

#endif //TELEMENTO_H

