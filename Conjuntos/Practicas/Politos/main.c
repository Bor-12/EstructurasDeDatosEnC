#include <stdio.h>
#include <string.h>
#include "Conjunto.h"

int main() {
    int n;
    char linea[256];

    tConjunto siSet, noSet;
    iniciarConjunto(&siSet);
    iniciarConjunto(&noSet);

    scanf("%d", &n);
    getchar(); // Consumir salto de línea tras el número

    for (int i = 0; i < n; i++) {
        fgets(linea, 256, stdin);

        // Eliminar el salto de línea final si existe
        size_t len = strlen(linea);
        if (linea[len - 1] == '\n') {
            linea[len - 1] = '\0';
        }

        // Extraer el primer token (SI: o NO:)
        char *token = strtok(linea, " ");
        int esSI = (strcmp(token, "SI:") == 0);

        // Extraer los ingredientes
        token = strtok(NULL, " ");
        while (token != NULL) {
            tElemento ingrediente;
            crearElemento(&ingrediente, token);

            if (esSI) {
                if (!pertenece(siSet, ingrediente)) {
                    insertar(&siSet, ingrediente);
                }
            } else {
                if (!pertenece(noSet, ingrediente)) {
                    insertar(&noSet, ingrediente);
                }
            }

            token = strtok(NULL, " ");
        }
    }


    tConjunto resultado = diferencia(noSet, siSet);
    mostrarConjunto(resultado);


    destruirConjunto(&siSet);
    destruirConjunto(&noSet);
    destruirConjunto(&resultado);

    return 0;
}

