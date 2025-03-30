//
// Created by borja on 27/02/2025.
//
#include "tElemento.h"
#include <stdio.h>
#include <string.h>

void asignarElemento(tElemento *destino, tElemento origen) {
    if (destino != NULL) {
        strcpy(destino->titulo, origen.titulo);
        strcpy(destino->fecha, origen.fecha);
        strcpy(destino->fuente, origen.fuente);
        destino->visionados = origen.visionados;
    }
}

// Comparar por número de visionados
int esMenor(tElemento e1, tElemento e2) {
    return e1.visionados < e2.visionados;
}

// Comparar por título y fecha (podrías añadir más)
int esIgual(tElemento e1, tElemento e2) {
    return strcmp(e1.titulo, e2.titulo) == 0 && strcmp(e1.fecha, e2.fecha) == 0;
}

void mostrarElemento(tElemento e) {
    printf("Título: %s\n", e.titulo);
    printf("Fecha: %s\n", e.fecha);
    printf("Fuente: %s\n", e.fuente);
    printf("Visionados: %d\n", e.visionados);
}

tElemento elementoVacio() {
    tElemento e;
    e.titulo[0] = '\0';
    e.fecha[0] = '\0';
    e.fuente[0] = '\0';
    e.visionados = 0;
    return e;
}
void leerCadena(char *cadena, int max) {
    fgets(cadena, max, stdin);
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}
tElemento crearNoticia() {
    tElemento noticia;
    getchar(); // Limpiar el salto de línea anterior

    printf("Introduce el título: ");
    leerCadena(noticia.titulo, MAX_TEXTO);

    printf("Introduce la fecha de publicación: ");
    leerCadena(noticia.fecha, MAX_TEXTO);

    printf("Introduce el medio o fuente: ");
    leerCadena(noticia.fuente, MAX_TEXTO);

    printf("Introduce el número de visionados: ");
    scanf("%d", &noticia.visionados);

    return noticia;
}