//
// Created by borja on 23/03/2025.
//


#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Cola.h"
#include "tElemento.h"
#include "tLista.h"

#define NUMERO_SALAS 5

typedef struct Hospital {
    tCola salaEspera[NUMERO_SALAS]; // 0: rojo, ..., 4: azul
    tLista listaEstadisticas;
} tHospital;

// Inicializa las 5 salas del hospital
void crearHospital(tHospital *h);

// Registra un paciente nuevo en la sala correspondiente según su prioridad
void registrarPaciente(tHospital *h, tElemento paciente);

// Muestra todos los pacientes en todas las salas (ordenados por prioridad)
void mostrarHospital(tHospital h);

/// Borra todos los pacientes registrados el último día del año (fecha == "31/12/aaaa")
void borrarPacientesUltimoDia(tHospital *h, const char* fechaUltima);

// Libera la memoria de todas las salas
void vaciarHospital(tHospital *h);

void mostrarEstadisticasEdad(tHospital h);

#endif // HOSPITAL_H