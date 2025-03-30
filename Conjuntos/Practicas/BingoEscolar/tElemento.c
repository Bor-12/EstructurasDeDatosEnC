#include "tElemento.h"
#include <stdio.h>
void crearElemento(tElemento *PunteroElemento, int numero) {
    PunteroElemento -> numero = numero;
}
void asignarElemento(tElemento *PunteroElemento, tElemento valor) {
    if (PunteroElemento != NULL) {
        PunteroElemento->numero = valor.numero;
    }
}

int esMenor(tElemento e1, tElemento e2) {
    return e1.numero < e2.numero;
}

int esIgual(tElemento e1, tElemento e2) {
    return e1.numero == e2.numero;
}

void mostrarElemento(tElemento e) {
    printf("%d ", e.numero);
}
int obtenerValor(tElemento e){
  return e.numero;
}
tElemento elementoVacio() {
    tElemento e;
    e.numero = -1;
    return e;
}
