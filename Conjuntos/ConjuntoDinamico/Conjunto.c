//
// Created by borja on 30/03/2025.
//

#include "Conjunto.h"
#include <stdlib.h>
#include <time.h>
#include <complex.h>

void iniciarConjunto(tConjunto *conjunto) {
    *conjunto = NULL;
}

int pertenece(tConjunto conjunto, tElemento elem) {
    tNodo *aux = conjunto;
    while (aux != NULL) {
        if (esIgual(aux -> elemento, elem)) {
            return 1;
        }
        aux = aux -> siguiente;
    }
    return 0;
}

void insertar(tConjunto *conjunto, tElemento elem) {
    tNodo *nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&nuevoNodo -> elemento, elem);
    nuevoNodo -> siguiente = *conjunto;
    *conjunto = nuevoNodo;
}
void eliminar(tConjunto *conjunto, tElemento elem) {
    tNodo *actual = *conjunto;
    tNodo *anterior = NULL;
    while (actual != NULL && !esIgual(actual -> elemento, elem)) {
        anterior = actual;
        actual = actual -> siguiente;
    }
    if (actual == NULL) {
        return;
    }
    if (anterior == NULL) {
        *conjunto = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
}
int esVacio(tConjunto conjunto) {
    return conjunto == NULL;
}
void mostrarConjunto(tConjunto conjunto) {
    tNodo *aux = conjunto;
    while (aux != NULL) {
        mostrarElemento(aux -> elemento);
        aux = aux -> siguiente;
    }
}

int longitudConjunto(tConjunto conjunto) {
    int contador = 0;
    tNodo *aux = conjunto;
    while (aux != NULL) {
        contador++;
        aux = aux -> siguiente;
    }
    return contador;
}

void extraerElemento(tConjunto *conjunto, tElemento *elem) {
    if (*conjunto == NULL) {
        *elem = elementoVacio(); // o simplemente return si prefieres
        return;
    }

    // Semilla aleatoria segura
    static time_t ultimaSemilla = 0;
    time_t ahora = time(NULL);
    if (ahora != ultimaSemilla) {
        srand(ahora);
        ultimaSemilla = ahora;
    }

    int longitud = longitudConjunto(*conjunto);


    int posicion = rand() % longitud;


    tNodo *actual = *conjunto;
    tNodo *anterior = NULL;

    for (int i = 0; i < posicion; i++) {
        anterior = actual;
        actual = actual->siguiente;
    }


    asignarElemento(elem, actual -> elemento);


    if (anterior == NULL) {
        *conjunto = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
}
int esSubconjunto(tConjunto conjunto1, tConjunto conjunto2) {
    tNodo *aux = conjunto1;
    while (aux != NULL) {
        if (!pertenece(conjunto2, aux->elemento)) {
            return 0;
        }
        aux = aux->siguiente;
    }
    return 1;
}

int igualConjunto(tConjunto conjunto1, tConjunto conjunto2) {
    int len1 = longitudConjunto(conjunto1);
    int len2 = longitudConjunto(conjunto2);
    if (len1 != len2) return 0;
    return esSubconjunto(conjunto1, conjunto2) && esSubconjunto(conjunto2, conjunto1);
}

void asignarConjunto(tConjunto *copia, tConjunto original) {
    iniciarConjunto(copia);
    tNodo *aux = original;
    while (aux != NULL) {
        insertar(copia, aux->elemento);  // Inserta en orden inverso, pero sigue siendo válido para conjuntos
        aux = aux->siguiente;
    }
}

void destruirConjunto(tConjunto *conjunto) {
    tNodo *actual = *conjunto;
    while (actual != NULL) {
        tNodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    *conjunto = NULL;
}

tConjunto unionConjuntos(tConjunto conjuntoA, tConjunto conjuntoB) {
    tConjunto resultado;
    iniciarConjunto(&resultado);

    tNodo *aux = conjuntoA;
    while (aux != NULL) {
        insertar(&resultado, aux->elemento);
        aux = aux->siguiente;
    }

    aux = conjuntoB;
    while (aux != NULL) {
        if (!pertenece(resultado, aux->elemento)) {
            insertar(&resultado, aux->elemento);
        }
        aux = aux->siguiente;
    }

    return resultado;
}


tConjunto interseccion(tConjunto conjuntoA, tConjunto conjuntoB) {
    tConjunto resultado;
    iniciarConjunto(&resultado);

    tNodo *aux = conjuntoA;
    while (aux != NULL) {
        if (pertenece(conjuntoB, aux->elemento)) {
            insertar(&resultado, aux->elemento);
        }
        aux = aux->siguiente;
    }

    return resultado;
}

tConjunto diferencia(tConjunto conjuntoA, tConjunto conjuntoB) {
    tConjunto resultado;
    iniciarConjunto(&resultado);

    tNodo *aux = conjuntoA;
    while (aux != NULL) {
        if (!pertenece(conjuntoB, aux->elemento)) {
            insertar(&resultado, aux->elemento);
        }
        aux = aux->siguiente;
    }

    return resultado;
}

