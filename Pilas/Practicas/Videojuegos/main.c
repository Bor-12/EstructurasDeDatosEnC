#include <stdio.h>
#include "Pila.h"

#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8);//para q salga bien los caracteres
    tPila pilaVideojuegos;
    crearPilaVacia(&pilaVideojuegos);

    int opcion;
    do {
        printf("\n=== MENÚ ===\n");
        printf("1. Registrar nuevo videojuego\n");
        printf("2. Mostrar todos los videojuegos registrados\n");
        printf("3. Mostrar videojuegos gratuitos (más recientes primero)\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                tElemento nuevo;
                leerElemento(&nuevo);
                apilar(&pilaVideojuegos, nuevo);
                printf("Videojuego registrado correctamente.\n");
                break;
            }

            case 2:
                printf("\nVideojuegos registrados:\n");
            mostrarPila(&pilaVideojuegos);
            break;

            case 3: {
                printf("\nVideojuegos gratuitos (últimos primero):\n");
                tNodo* aux = pilaVideojuegos.principio;
                while (aux != NULL) {
                    if (esGratis(aux->elemento)) {
                        mostrarElemento(aux->elemento);
                    }
                    aux = aux->siguiente;
                }
                break;
            }

            case 0:
                printf("Saliendo del programa.\n");
            break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}
