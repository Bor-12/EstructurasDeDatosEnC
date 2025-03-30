#include <stdio.h>
#include "Conjunto.h"
#include "tElemento.h"

int main() {
    tConjunto conjuntoA, conjuntoB;

    iniciarConjunto(&conjuntoA);
    iniciarConjunto(&conjuntoB);

    tElemento a, b, c, d, e;
    crearElemento(&a, 'a');
    crearElemento(&b, 'b');
    crearElemento(&c, 'c');
    crearElemento(&d, 'd');
    crearElemento(&e, 'e');

    insertar(&conjuntoA, a);
    insertar(&conjuntoA, b);
    insertar(&conjuntoA, c);

    insertar(&conjuntoB, b);
    insertar(&conjuntoB, c);
    insertar(&conjuntoB, d);
    insertar(&conjuntoB, e);

    printf("Conjunto A:\n");
    mostrarConjunto(conjuntoA);

    printf("Conjunto B:\n");
    mostrarConjunto(conjuntoB);

    tConjunto unionAB = unionConjuntos(conjuntoA, conjuntoB);
    printf("\nUnion de A y B:\n");
    mostrarConjunto(unionAB);

    tConjunto interseccionAB = interseccion(conjuntoA, conjuntoB);
    printf("\nInterseccion de A y B:\n");
    mostrarConjunto(interseccionAB);

    tConjunto diferenciaAB = diferencia(conjuntoA, conjuntoB);
    printf("\nDiferencia A - B:\n");
    mostrarConjunto(diferenciaAB);

    printf("\nEliminando 'b' de conjunto A:\n");
    eliminar(&conjuntoA, b);
    mostrarConjunto(conjuntoA);

    printf("\n'a' pertenece a conjunto A? %s\n", pertenece(conjuntoA, a) ? "Si" : "No");
    printf("'b' pertenece a conjunto A? %s\n", pertenece(conjuntoA, b) ? "Si" : "No");


    tElemento extraido;
    extraerElemento(&conjuntoB, &extraido);
    printf("\nElemento extraido aleatoriamente de conjunto B:\n");
    mostrarElemento(extraido);

    printf("\nConjunto B tras la extraccion:\n");
    mostrarConjunto(conjuntoB);

    tConjunto copiaA;
    asignarConjunto(&copiaA, conjuntoA);
    printf("\nCopia del conjunto A:\n");
    mostrarConjunto(copiaA);


    printf("\nResultado de comprobar si copiaA es subconjunto de conjuntoA: %s\n",
           esSubconjunto(copiaA, conjuntoA) ? "Si" : "No");

    printf("Resultado de comprobar si conjuntoA es subconjunto de unionAB: %s\n",
           esSubconjunto(conjuntoA, unionAB) ? "Si" : "No");


    printf("\nComparacion entre conjuntoA y copiaA (igualdad): %s\n",
           igualConjunto(conjuntoA, copiaA) ? "Si" : "No");

    printf("Comparacion entre conjuntoA y conjuntoB (igualdad): %s\n",
           igualConjunto(conjuntoA, conjuntoB) ? "Si" : "No");

    destruirConjunto(&copiaA);
    printf("\nContenido de copiaA despues de destruirConjunto:\n");
    mostrarConjunto(copiaA);



    return 0;
}
