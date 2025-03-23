//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H
#define MAX_TEXTO 100

typedef struct {
    char titulo[MAX_TEXTO];
    char fecha[MAX_TEXTO];
    char fuente[MAX_TEXTO];
    int visionados;
} tElemento;

void asignarElemento(tElemento *destino, tElemento origen);
int esMenor(tElemento e1, tElemento e2);      // Puedes comparar por visionados, por ejemplo
int esIgual(tElemento e1, tElemento e2);      // Puedes comparar por título y fecha
void mostrarElemento(tElemento e);
tElemento elementoVacio();
void leerCadena(char *cadena, int max);
tElemento crearNoticia();
#endif //TELEMENTO_H
