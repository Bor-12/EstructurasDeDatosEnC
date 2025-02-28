//
// Created by borja on 28/02/2025.
//

#include "tLista.h"

#include <stdio.h>

//O(1)
void crearListaVacia(tLista *lista) {
    lista -> ultimaPosicionOcupada = -1;
}
//O(1)
int esListaLlena(tLista lista) {
    return lista.ultimaPosicionOcupada == DIMENSION - 1;
}
//O(1)
int esListaVacia(tLista lista) {
    return lista.ultimaPosicionOcupada == -1;
}
//O(n)
void insertarElementoInicio(tLista *lista, tElemento elemento) {
    if (esListaLlena(*lista)) {
        return;
    }
    for (int i = lista->ultimaPosicionOcupada; i >= 0; i--) {
        lista->almacen[i + 1] = lista->almacen[i];
    }
    asignarElemento(&lista->almacen[0], elemento);
    lista->ultimaPosicionOcupada++;
}
//O(1)
void insertarElementoFinal(tLista *lista, tElemento elemento) {
    if (esListaLlena(*lista)) {
        return;
    }
    lista->ultimaPosicionOcupada++;
    asignarElemento(&lista->almacen[lista->ultimaPosicionOcupada], elemento);
}
//O(n^2)
void eliminarElemento(tLista *lista, tElemento elemento) {
    for (int i = 0; i <= lista -> ultimaPosicionOcupada; i++) {
        if (esIgual(lista -> almacen [i], elemento)) {
            for (int j = i; j < lista ->ultimaPosicionOcupada ; j++) {
                lista -> almacen[j] = lista -> almacen[j + 1];
            }
            lista -> ultimaPosicionOcupada--;
            i--; // Para revisar la misma posición en la siguiente iteración
        }
    }
}
// O(1)
tElemento obtenerPrimerElemento(tLista lista) {
    if (esListaVacia(lista)) {
        return elementoVacio();
    }
    return lista.almacen[0];
}
// O(1)
tElemento obtenerUltimoElemento(tLista lista) {
    if (esListaVacia(lista)) {
        return elementoVacio();
    }
    return lista.almacen[lista.ultimaPosicionOcupada];
}
// O(1)
int longitudLista(tLista lista) {
    return lista.ultimaPosicionOcupada + 1;
}

// O(n)
void mostrarLista(tLista lista) {
    if (esListaVacia(lista)) {
        printf("Lista vacía.\n");
    }else {
        for (int i = 0; i <= lista.ultimaPosicionOcupada; i++) {
            mostrarElemento(lista.almacen[i]);
        }
    }

}
// O(1)
void vaciarLista(tLista *lista) {
    lista -> ultimaPosicionOcupada = -1;
}