#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cola.h"
#include "pila.h"

int main() {
    srand(time(NULL));

    tCola secuaces;
    crearColaVacia(&secuaces);
    tPila botin;
    crearPilaVacia(&botin);

    printf("Dime el número de secuaces de la banda:\n");
    int numSecuaces;
    scanf("%d", &numSecuaces);
    for (int i = 0; i < numSecuaces; i++) {
        tSecuaz secuaz; // tElementoCola
        printf("Nombre:\n");
        char nombre[N];
        scanf("%s", nombre);
        crearSecuaz(&secuaz, nombre);
        encolar(&secuaces, secuaz);
    }

    printf("\n");

    int billetes[] = {5, 10, 20, 50, 100, 200, 500};

    printf("Vamos a ver el botín\n");
    printf("Número de billetes:\n");
    int numBilletes;
    scanf("%d", &numBilletes);
    for (int i = 1; i <= numBilletes; i++) {
        int billete = billetes[rand() % 7]; // 7 es la longitud del vector
        printf("Billete %d: %d\n", i, billete);
        apilar(&botin, billete);
    }

    while (!esPilaVacia(&botin)) {
        tElementoPila billete;
        cima(&botin, &billete);
        desapilar(&botin);
        tSecuaz secuaz;
        primeroCola(secuaces, &secuaz);
        cobrar(&secuaz, billete);
        desencolar(&secuaces);
        encolar(&secuaces, secuaz);
        printf("Un billete de %d euros para...", billete);
        mostrarElemento(secuaz);
        printf("\n");
    }

    while (!esColaVacia(secuaces)) {
        tSecuaz secuaz;
        primeroCola(secuaces, &secuaz);
        desencolar(&secuaces);
        mostrarElemento(secuaz);
        printf("\n");
    }

    return 0;
}
