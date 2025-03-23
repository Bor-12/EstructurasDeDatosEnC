#include <stdio.h>

#include <stdio.h>
#include "tPolinomio.h"

int main() {
    printf("=== LECTURA DEL PRIMER POLINOMIO ===\n");
    tPolinomio p1 = leerPolinomio();

    printf("\n=== DERIVADA DEL PRIMER POLINOMIO ===\n");
    tPolinomio derivada;
    derivadaPolinomio(&derivada, p1);
    mostrarPolinomio(derivada);

    printf("\n=== EVALUAR POLINOMIO ===\n");
    float x;
    printf("Introduce el valor de x: ");
    scanf("%f", &x);
    float resultado = valorPolinomio(p1, x);
    printf("Resultado de evaluar el polinomio en x = %.2f: %.2f\n", x, resultado);

    printf("\n=== LECTURA DEL SEGUNDO POLINOMIO ===\n");
    tPolinomio p2 = leerPolinomio();

    printf("\n=== SUMA DE AMBOS POLINOMIOS ===\n");
    tPolinomio suma;
    sumarPolinomios(&suma, p1, p2);
    mostrarPolinomio(suma);

    return 0;
}