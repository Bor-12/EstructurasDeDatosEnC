//
// Created by borja on 27/02/2025.
//

#include "tElemento.h"
#include <stdio.h>
#include <string.h>

void asignarElemento(tElemento *destino, tElemento origen) {
    strcpy(destino->titulo, origen.titulo);
    strcpy(destino->genero, origen.genero);
    destino->puntuacion = origen.puntuacion;
    destino->precio = origen.precio;
}

int esMenor(tElemento e1, tElemento e2) {
    return e1.precio < e2.precio;
}

int esIgual(tElemento e1, tElemento e2) {
    return strcmp(e1.titulo, e2.titulo) == 0;
}

void mostrarElemento(tElemento e) {
    if (e.precio == 0.0f) {
        printf("[GRATIS] %s | Género: %s | Puntuación: %.1f\n", e.titulo, e.genero, e.puntuacion);
    } else {
        printf("%s | Género: %s | Puntuación: %.1f | Precio: %.2f€\n", e.titulo, e.genero, e.puntuacion, e.precio);
    }
}



int esGratis(tElemento e) {
    return e.precio == 0.0f;
}
#include "tElemento.h"
#include <stdio.h>
#include <string.h>

void leerElemento(tElemento *e) {
    getchar();  // Limpia el buffer antes de leer cadenas

    printf("Introduce el título del juego: ");
    fgets(e->titulo, MAX_CADENA, stdin);
    e->titulo[strcspn(e->titulo, "\n")] = '\0';  // Elimina el salto de línea

    printf("Introduce el género: ");
    fgets(e->genero, MAX_CADENA, stdin);
    e->genero[strcspn(e->genero, "\n")] = '\0';

    printf("Introduce la puntuación del juego: ");
    scanf("%f", &e->puntuacion);

    printf("Introduce el precio: ");
    scanf("%f", &e->precio);
}

