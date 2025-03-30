#ifndef PILA_H
#define PILA_H

typedef int tElementoPila; // Billete

typedef struct nodoPila {
    tElementoPila elem;
    struct nodoPila* ant;  // sig
} tNodoPila;
typedef tNodoPila* tPila;

void crearPilaVacia(tPila* pila);
void apilar(tPila* pila, tElementoPila elem); // push

void cima(tPila* pila, tElementoPila* elem);
void desapilar(tPila* pila);  // pop

int esPilaVacia(tPila* pila);

void mostrarPila(tPila* pila);
#endif
