#include <stdio.h>
#include "tLista.h"
#include <windows.h>


int main(void) {
    SetConsoleOutputCP(CP_UTF8);//para q salga bien los caracteres
    int seguir = 1;
    tLista lista;
    crearListaVacia(&lista);

    while (seguir) {
        int decision;
        printf("\n--- MENÚ ---\n");
        printf("1. Insertar noticia\n");
        printf("2. Mostrar noticias\n");
        printf("3. Eliminar noticia\n");
        printf("4. Longitud de la lista\n");
        printf("0. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &decision);

        switch (decision) {
            case 1: {
                tElemento noticia = crearNoticia();
                insertarElementoFinal(&lista, noticia);
                break;
            }
            case 2:
                mostrarLista(lista);
            break;
            case 3: {
                tElemento noticia = crearNoticia();
                eliminarElemento(&lista, noticia);
                break;
            }
            case 4:
                printf("Longitud de la lista: %d\n", longitudLista(lista));
            break;
            case 0:
                seguir = 0;
            break;
            default:
                printf("Opción no válida.\n");
        }
    }

    vaciarLista(&lista);
    return 0;
}
