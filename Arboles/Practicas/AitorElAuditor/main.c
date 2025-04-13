#include <stdio.h>
#include "ArbolBinario.h"
#include "tElemento.h"
#include "tLista.h"

int main() {
    tArbol empresa;
    crearArbolVacio(&empresa);

    construir(&empresa, crearElemento("Vanessa", 20, "Ordenanza"));
    construir(&empresa, crearElemento("Pedro", 60, "Gerente"));
    construir(&empresa, crearElemento("Laura", 70, "Secretaria"));
    construir(&empresa, crearElemento("Cesar", 50, "Director General"));
    construir(&empresa, crearElemento("Teresa", 150, "Gestora"));
    construir(&empresa, crearElemento("Reyes", 200, "Directora IT"));
    construir(&empresa, crearElemento("Miguel", 250, "Resp. Sistemas"));
    construir(&empresa, crearElemento("Ramon", 240, "Resp. Proyectos"));
    construir(&empresa, crearElemento("German", 260, "Resp. Redes"));
    construir(&empresa, crearElemento("Alfonso", 100, "CEO"));

    printf("inOrden del arbol: \n");
    inOrden(empresa);
    int limite;
    printf("\nIntroduce el sueldo limite: \n");
    scanf("%d", &limite);

    tLista resultado = listarInferiores(empresa, limite);

    printf("\nEmpleados con sueldo menor a %d:\n", limite);
    mostrarLista(resultado);

    vaciarLista(&resultado);
    destruirArbol(&empresa);

    return 0;
}
