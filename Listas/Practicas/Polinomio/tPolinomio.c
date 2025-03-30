//
// Created by borja on 23/03/2025.
//

#include "tPolinomio.h"
#include "tPolinomio.h"
#include <stdio.h>
#include <math.h>

// Crea y devuelve un nuevo polinomio leído por teclado
tPolinomio leerPolinomio() {
    tPolinomio p;
    crearListaVacia(&p);
    int n;
    printf("Cuantos terminos tiene el polinomio? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        tElemento e;
        leerElemento(&e);
        insertarOrdenadoFinal(&p, e);
    }

    return p;
}
// Muestra el polinomio por pantalla
void mostrarPolinomio(tPolinomio p) {
    if (esListaVacia(p)) {
        printf("0\n");
        return;
    }
    mostrarLista(p);
    printf("\n");
}


// Calcula la derivada de un polinomio
void derivadaPolinomio(tPolinomio *pd, tPolinomio p) {
    crearListaVacia(pd);
    tLista aux = p;
    while (aux != NULL) {
        tElemento e = aux->elemento;
        if (getExponente(e) > 0) {
            tElemento der;
            derivada(&der, e);
            insertarOrdenadoFinal(pd, der);
        }
        aux = aux->siguiente;
    }
}

// Evalúa el valor del polinomio para un valor de x
float valorPolinomio(tPolinomio p, float x) {
    float resultado = 0.0f;
    tLista aux = p;
    while (aux != NULL) {
        tElemento e = aux->elemento;
        resultado += getCoeficiente(e) * powf(x, getExponente(e));
        aux = aux->siguiente;
    }
    return resultado;
}

// Suma dos polinomios y guarda el resultado en otro
void sumarPolinomios(tPolinomio *s, tPolinomio p1, tPolinomio p2) {
    crearListaVacia(s);

    // Copiar todos los elementos de p1 en s
    tLista aux1 = p1;
    while (aux1 != NULL) {
        insertarOrdenadoFinal(s, aux1->elemento);
        aux1 = aux1->siguiente;
    }

    // Recorrer p2 y sumar en s si exponente ya existe, o insertar si no
    tLista aux2 = p2;
    while (aux2 != NULL) {
        tElemento e2 = aux2->elemento;
        tLista temp = *s;
        int encontrado = 0;

        while (temp != NULL) {
            if (igualElemento(temp->elemento, e2)) {
                temp->elemento.coeficiente += e2.coeficiente;
                encontrado = 1;
                break;
            }
            temp = temp->siguiente;
        }

        if (!encontrado) {
            insertarOrdenadoFinal(s, e2);
        }

        aux2 = aux2->siguiente;
    }
}