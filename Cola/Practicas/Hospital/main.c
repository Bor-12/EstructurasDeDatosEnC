#include <stdio.h>
#include <string.h>
#include "hospital.h"



int main() {
    tHospital h;
    crearHospital(&h);

    // Crear y registrar pacientes
    tElemento p1 = crearPaciente("Laura", "Martínez", 12, "Fiebre alta", "30/12/2024", 1); // urgencia inmediata
    tElemento p2 = crearPaciente("Pedro", "Gómez", 25, "Dolor abdominal", "30/12/2024", 2); // prioridad alta
    tElemento p3 = crearPaciente("Ana", "López", 35, "Dolor cabeza", "31/12/2024", 3); // prioridad moderada
    tElemento p4 = crearPaciente("Luis", "Pérez", 55, "Fractura", "31/12/2024", 1); // urgencia inmediata
    tElemento p5 = crearPaciente("Sofía", "Ruiz", 16, "Dolor de garganta", "30/12/2024", 2); // prioridad alta

    registrarPaciente(&h, p1);
    registrarPaciente(&h, p2);
    registrarPaciente(&h, p3);
    registrarPaciente(&h, p4);
    registrarPaciente(&h, p5);

    // Mostrar todos los pacientes registrados
    printf("=== Hospital antes de borrar el 31/12/2024 ===\n");
    mostrarHospital(h);

    // Mostrar estadísticas por edad
    mostrarEstadisticasEdad(h);

    // Borrar los pacientes del último día del año
    borrarPacientesUltimoDia(&h, "31/12/2024");

    // Mostrar pacientes después de borrar
    printf("\n=== Hospital después de borrar el 31/12/2024 ===\n");
    mostrarHospital(h);

    // Mostrar estadísticas otra vez
    mostrarEstadisticasEdad(h);

    // Liberar memoria
    vaciarHospital(&h);

    return 0;
}
