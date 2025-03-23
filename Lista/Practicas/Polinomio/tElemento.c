//
// Created by borja on 27/02/2025.
//

#include "tElemento.h"
#include <stdio.h>

#include "tElemento.h"
#include <stdio.h>

void asignarElemento(tElemento *e1, tElemento e2) {
    e1->coeficiente = e2.coeficiente;
    e1->exponente = e2.exponente;
}

void leerElemento(tElemento *e) {
    printf("Introduce coeficiente: ");
    scanf("%f", &e->coeficiente);
    printf("Introduce exponente: ");
    scanf("%d", &e->exponente);
}

int igualElemento(tElemento uno, tElemento dos) {
    return uno.exponente == dos.exponente;
}

int mayor(tElemento uno, tElemento dos) {
    return uno.exponente > dos.exponente;
}

void mostrarElemento(tElemento t) {
    printf("(%0.2f)x^%d ", t.coeficiente, t.exponente);
}

int getExponente(tElemento e) {
    return e.exponente;
}

float getCoeficiente(tElemento e) {
    return e.coeficiente;
}

void derivada(tElemento *ed, tElemento e) {
    ed->coeficiente = e.coeficiente * e.exponente;
    ed->exponente = e.exponente - 1;
}
tElemento elementoVacio() {
    tElemento e;
    e.coeficiente = -1;
    e.exponente = -1;
    return e;
}
