#include <stdio.h>
#include "Cola.h"


int main() {

    tCola cola;
    crearColaVacia(&cola);



    printf("=== COLA DESPUÉS DE ELIMINAR ===\n");
    mostrarCola(&cola);

    // Registrar acciones
    tElemento a1 = crearElemento("Francia", "Ha enviado tropas a la frontera", 4);
    tElemento a2 = crearElemento("Estados Unidos", "Ha sancionado económicamente a un país", 5);
    tElemento a3 = crearElemento("Rusia", "Prueba de misil balístico", 3);
    tElemento a4 = crearElemento("Alemania", "Convocatoria de emergencia diplomática", 5);

    encolar(&cola, a1);
    encolar(&cola, a2);
    encolar(&cola, a3);
    encolar(&cola, a4);

    printf("=== ACCIONES REGISTRADAS ===\n");
    mostrarCola(&cola);

    // Mostrar la siguiente acción a gestionar (el primero en la cola)
    printf("\n=== SIGUIENTE ACCIÓN A GESTIONAR ===\n");
    tElemento siguiente;
    primeroCola(&cola, &siguiente);
    mostrarElemento(siguiente);

    // Eliminar una acción concreta (por nivel de alerta)
    printf("\n=== ELIMINAR UNA ACCIÓN (Alemania) ===\n");
    eliminarElementoCola(&cola, a4);
    mostrarCola(&cola);

    // Liberar la memoria
    printf("\n=== VACIAR TODAS LAS ACCIONES ===\n");
    while (!esColaVacia(&cola)) {
        desencolar(&cola);
    }

    return 0;
}
