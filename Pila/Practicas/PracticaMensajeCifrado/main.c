#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tLista.h"
#include "Pila.h"
#include "tElemento.h"

int main() {
    char* mensajeCifrado = "BnodJo s, dBneam";
    printf("Mensaje cifrado: %s\n", mensajeCifrado);

    // X'' a X'
    tLista lista;
    crearListaVacia(&lista);
    int porElFinal = 1;

    for (int i = strlen(mensajeCifrado) - 1; i >= 0; i--) {
        tElemento elem = mensajeCifrado[i];
        if (porElFinal) {
            insertarElementoFinal(&lista, elem);
            porElFinal = 0;
        } else {
            insertarElementoInicio(&lista, elem);
            porElFinal = 1;
        }
    }

    // X' a X
    char* mensajeDescifrado = (char*)malloc((strlen(mensajeCifrado) + 1) * sizeof(char));
    int i = 0;
    tPila pila;
    crearPilaVacia(&pila);

    while (!esListaVacia(lista)) {
        tElemento elem = obtenerPrimerElemento(lista);
        eliminarElemento(&lista, elem); // para avanzar

        if (!esVocal(elem)) {
            apilar(&pila, elem);
        } else {
            while (!esPilaVacia(&pila)) {
                tElemento elemAux;
                cima(&pila, &elemAux);
                desapilar(&pila);
                mensajeDescifrado[i++] = elemAux;
            }
            mensajeDescifrado[i++] = elem;
        }
    }

    // Vaciamos pila al final si quedan consonantes
    while (!esPilaVacia(&pila)) {
        tElemento elemAux;
        cima(&pila, &elemAux);
        desapilar(&pila);
        mensajeDescifrado[i++] = elemAux;
    }

    mensajeDescifrado[i] = '\0';
    printf("Mensaje descifrado: %s\n", mensajeDescifrado);

    free(mensajeDescifrado);
    return 0;
}
