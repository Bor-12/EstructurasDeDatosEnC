//
// Created by borja on 30/03/2025.
//

#include "Conjunto.h"
#include <stdlib.h>
#include <time.h>
#include <complex.h>
//O(1)
void iniciarConjunto(tConjunto *conjunto) {
    conjunto -> cardinal = 0;
}
//O(cardinal)
int pertenece(tConjunto conjunto, tElemento elem) {
    if (conjunto.cardinal == 0) {
        return 0;
    }
    for (int i = 0; i < conjunto.cardinal; i++) {
        if ( esIgual(conjunto.almacen[i], elem)) {
            return 1;
        }
    }
    return 0;
}
//O(1)
int esConjuntoLleno(tConjunto conjunto) {
    return conjunto.cardinal == DIMENSION;
}
//O(cardinal)
void insertar(tConjunto *conjunto, tElemento elem) {
    if (!pertenece(*conjunto, elem) && !esConjuntoLleno(*conjunto)) {
        asignarElemento(&conjunto->almacen[conjunto->cardinal], elem);
        conjunto->cardinal++;
    }
}
//O(cardinal ^ 2)
void eliminar(tConjunto *conjunto, tElemento elem) {
    for (int i = 0; i < conjunto->cardinal; i++) {
        if (esIgual(conjunto->almacen[i], elem)) {
            // Desplazar todo a la izquierda desde la posición i
            for (int j = i; j < conjunto->cardinal - 1; j++) {
                asignarElemento(&conjunto->almacen[j], conjunto->almacen[j + 1]);
            }
            conjunto->cardinal--;
            break;
        }
    }
}
//O(1)
int esVacio(tConjunto conjunto) {
    return conjunto.cardinal == 0;
}
//O(cardinal)
void mostrarConjunto(tConjunto conjunto) {
    for (int i = 0; i < conjunto.cardinal; i++) {
        mostrarElemento(conjunto.almacen[i]);
    }
}
//O(cardinal)
void extraerElemento(tConjunto *conjunto, tElemento *elem) {
    if (conjunto->cardinal == 0) {
        *elem = elementoVacio();
        return;
    }

    static time_t ultimaSemilla = 0;
    time_t ahora = time(NULL);

    // Solo volver a llamar a srand si ha pasado al menos 1 segundo
    if (ahora != ultimaSemilla) {
        srand(ahora);
        ultimaSemilla = ahora;
    }

    int pos = rand() % conjunto->cardinal;
    asignarElemento(elem, conjunto->almacen[pos]);

    for (int i = pos; i < conjunto->cardinal - 1; i++) {
        conjunto->almacen[i] = conjunto->almacen[i + 1];
    }

    conjunto->cardinal--;
}

// Devuelve 1 si todos los elementos de conjunto1 están en conjunto2
//O(cardinal1 * cardinal2)
int esSubconjunto(tConjunto conjunto1, tConjunto conjunto2) {
    for (int i = 0; i < conjunto1.cardinal; i++) {//O(cardinal1)
        if (!pertenece(conjunto2, conjunto1.almacen[i])) {//O(cardinal2)
            return 0;
        }
    }
    return 1;
}

//O(cardinal1 * cardinal2)
int igualConjunto(tConjunto conjunto1, tConjunto conjunto2) {
    if (conjunto1.cardinal != conjunto2.cardinal) {
        return 0;
    }

    return esSubconjunto(conjunto1, conjunto2) && esSubconjunto(conjunto2, conjunto1);
}

//O(cardinal_original)
void asignarConjunto(tConjunto *copia, tConjunto original) {
    copia->cardinal = original.cardinal;
    for (int i = 0; i < original.cardinal; i++) {
        copia->almacen[i] = original.almacen[i];
    }
}
//O(1)
void destruirConjunto(tConjunto *conjunto) {
    conjunto->cardinal = 0;
}

// O((cardinalA + cardinalB)^2) en el peor caso

tConjunto unionConjuntos(tConjunto conjuntoA, tConjunto conjuntoB) {
    tConjunto resultado;
    iniciarConjunto(&resultado);

    // Añadir todos los de A
    for (int i = 0; i < conjuntoA.cardinal; i++) {
        insertar(&resultado, conjuntoA.almacen[i]);
    }

    // Añadir los de B si no están
    for (int i = 0; i < conjuntoB.cardinal; i++) {
        insertar(&resultado, conjuntoB.almacen[i]);
    }

    return resultado;
}
//O(cardinalA * cardinalB)
tConjunto interseccion(tConjunto conjuntoA, tConjunto conjuntoB) {
    tConjunto resultado;
    iniciarConjunto(&resultado);

    for (int i = 0; i < conjuntoA.cardinal; i++) {//O(cardinalA )
        if (pertenece(conjuntoB, conjuntoA.almacen[i])) {//O(cardinalB)
            insertar(&resultado, conjuntoA.almacen[i]);
        }
    }

    return resultado;
}
//O(cardinalA * cardinalB)
tConjunto diferencia(tConjunto conjuntoA, tConjunto conjuntoB) {
    tConjunto resultado;
    iniciarConjunto(&resultado);//O(1)

    for (int i = 0; i < conjuntoA.cardinal; i++) {//O(cardinalA)
        if (!pertenece(conjuntoB, conjuntoA.almacen[i])) {//O(cardinalB)
            insertar(&resultado, conjuntoA.almacen[i]);
        }
    }

    return resultado;
}
