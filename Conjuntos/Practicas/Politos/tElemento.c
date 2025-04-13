#include "tElemento.h"
#include <stdio.h>
#include <string.h>

void crearElemento(tElemento *PunteroElemento, const char *cadena) {
    if (PunteroElemento != NULL) {
        strncpy(*PunteroElemento, cadena, MAX_LONGITUD - 1);
        (*PunteroElemento)[MAX_LONGITUD - 1] = '\0'; // Asegura terminación
    }
}

void asignarElemento(tElemento *PunteroElemento, tElemento valor) {
    if (PunteroElemento != NULL) {
        strncpy(*PunteroElemento, valor, MAX_LONGITUD - 1);
        (*PunteroElemento)[MAX_LONGITUD - 1] = '\0';
    }
}
int esIgual(tElemento e1, tElemento e2) {
    return strcmp(e1, e2) == 0;
}

void mostrarElemento(tElemento e) {
    printf("%s\n", e);
}



