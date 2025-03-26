//
// Created by borja on 23/03/2025.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hospital.h"
void crearHospital(tHospital *h) {
    for (int i = 0; i < NUMERO_SALAS; i++) {
        crearColaVacia(&h->salaEspera[i]);
    }
    crearListaVacia(&h->listaEstadisticas);
}

void registrarPaciente(tHospital *h, tElemento paciente) {
    int index = paciente.prioridad - 1;
    if (index >= 0 && index < NUMERO_SALAS) {
        encolar(&h->salaEspera[index], paciente);

        // Guardar en lista de estadísticas si es urgencia inmediata o prioridad alta
        if (paciente.prioridad == 1 || paciente.prioridad == 2) {
            insertarElementoFinal(&h->listaEstadisticas, paciente);
        }
    } else {
        printf("Prioridad fuera de rango: %d\n", paciente.prioridad);
    }
}

void mostrarHospital(tHospital h) {
    const char* colores[NUMERO_SALAS] = {"Rojo", "Naranja", "Amarillo", "Verde", "Azul"};
    for (int i = 0; i < NUMERO_SALAS; i++) {
        printf("---- Prioridad %s ----\n", colores[i]);
        mostrarCola(&h.salaEspera[i]);
    }
}

void borrarPacientesUltimoDia(tHospital *h, const char* fechaUltima) {
    for (int i = 0; i < NUMERO_SALAS; i++) {
        tCola* original = &h->salaEspera[i];
        tCola temporal;
        crearColaVacia(&temporal);

        while (!esColaVacia(original)) {
            tElemento e;
            primeroCola(original, &e);
            desencolar(original);

            if (strcmp(e.fecha, fechaUltima) != 0) {
                encolar(&temporal, e);
            }
        }
        *original = temporal;
    }

    // También limpiar de la lista de estadísticas
    tNodoLista* actual = principioLista(h ->listaEstadisticas);
    while (actual != NULL) {
        tNodoLista* siguiente = actual->siguiente;
        if (strcmp(actual->elemento.fecha, fechaUltima) == 0) {
            eliminarElemento(&h->listaEstadisticas, actual->elemento);
        }
        actual = siguiente;
    }
}

void vaciarHospital(tHospital *h) {
    for (int i = 0; i < NUMERO_SALAS; i++) {
        while (!esColaVacia(&h->salaEspera[i])) {
            desencolar(&h->salaEspera[i]);
        }
    }
    vaciarLista(&h->listaEstadisticas);
}

void mostrarEstadisticasEdad(tHospital h) {
    int urgencia[4] = {0};
    int alta[4] = {0};

    tNodoLista* actual = principioLista(h.listaEstadisticas);
    while (actual != NULL) {
        int rango = obtenerRangoEdad(actual->elemento);
        if (actual->elemento.prioridad == 1)
            urgencia[rango]++;
        else if (actual->elemento.prioridad == 2)
            alta[rango]++;
        actual = actual->siguiente;
    }

    const char* descripciones[4] = {"0-15", "16-30", "31-50", "51+"};
    printf("\nEstadísticas por edad (solo prioridad 1 y 2):\n");
    for (int i = 0; i < 4; i++) {
        printf("Rango %s -> Urgencia inmediata: %d, Prioridad alta: %d\n",
               descripciones[i], urgencia[i], alta[i]);
    }
}
