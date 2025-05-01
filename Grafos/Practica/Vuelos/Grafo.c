#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pila.h"
void crearGrafoVacio(tGrafo *grafo) {
    *grafo = NULL;
}

void insertarVertice(tGrafo *grafo, tCiudad ciudad) {
    tNodoGrafo *nuevoVerticeGrafo = (tNodoGrafo *) malloc(sizeof(tNodoGrafo));
    copiarCiudad(nuevoVerticeGrafo->vertice, ciudad);
    nuevoVerticeGrafo->adyacencias = NULL;
    nuevoVerticeGrafo->siguiente = *grafo;
    *grafo = nuevoVerticeGrafo;
}
void insertarConexion(tGrafo *grafo, tCiudad origen, tCiudad destino, tDatosVuelo datos) {
    tNodoGrafo *auxVerticeOrigen = *grafo;
    while (auxVerticeOrigen != NULL && !sonIguales(auxVerticeOrigen->vertice, origen)) {
        auxVerticeOrigen = auxVerticeOrigen->siguiente;
    }

    if (auxVerticeOrigen != NULL) {
        // Comprobamos si ya hay una conexión con misma ciudad Y misma compañía
        tNodoAdyacencias *actual = auxVerticeOrigen->adyacencias;
        while (actual != NULL) {
            if (sonIguales(actual->vertice, destino) &&
                strcmp(actual->datosVuelo.compania, datos.compania) == 0 &&
                actual->datosVuelo.tiempo == datos.tiempo &&
                actual->datosVuelo.precio == datos.precio) {

                // Ya existe una conexión exacta
                printf("Ya existe una conexión de ");
                mostrarCiudad(origen);
                printf(" hacia ");
                mostrarCiudad(destino);
                printf(" con la compañía %s\n", datos.compania);
                return;
                }
            actual = actual->siguiente;
        }

        // Si no existe, insertamos al principio
        tNodoAdyacencias *nuevoNodo = (tNodoAdyacencias *) malloc(sizeof(tNodoAdyacencias));
        copiarCiudad(nuevoNodo->vertice, destino);
        nuevoNodo->datosVuelo = datos;
        nuevoNodo->siguiente = auxVerticeOrigen->adyacencias;
        auxVerticeOrigen->adyacencias = nuevoNodo;

    } else {
        printf("No se encontró el vértice de origen: ");
        mostrarCiudad(origen);
        printf("\n");
    }
}


void insertarArista(tGrafo *grafo, tCiudad origen, tCiudad destino, tDatosVuelo datos) {
    insertarConexion(grafo, origen, destino, datos);
    insertarConexion(grafo, destino, origen, datos);
}

void mostrarVerticesGrafo(tGrafo grafo) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL) {
        mostrarCiudad(aux->vertice);
        printf(" ");
        aux = aux->siguiente;
    }
    printf("\n");
}

void mostrarConexionesGrafo(tGrafo grafo) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL) {
        printf("Las conexiones de ");
        mostrarCiudad(aux->vertice);
        printf(" son:\n");
        tNodoAdyacencias *adyacencias = aux->adyacencias;
        while (adyacencias != NULL) {
            printf("   -> ");
            mostrarCiudad(adyacencias->vertice);
            printf(" ");
            mostrarDatosVuelo(adyacencias->datosVuelo);
            printf("\n");
            adyacencias = adyacencias->siguiente;
        }
        aux = aux->siguiente;
    }
}

tNodoGrafo* busquedaNodoGrafo(tGrafo grafo, tCiudad ciudad) {
    tNodoGrafo *aux = grafo;
    while (aux != NULL && !sonIguales(aux->vertice, ciudad)) {
        aux = aux->siguiente;
    }
    return aux;
}

tNodoAdyacencias* busquedaAdyacenciasNodoGrafo(tListaAdyacencias lista, tCiudad ciudad) {
    tNodoAdyacencias *aux = lista;
    while (aux != NULL && !sonIguales(aux->vertice, ciudad)) {
        aux = aux->siguiente;
    }
    return aux;
}

int tieneAristasSalientes(tGrafo grafo, tCiudad ciudad) {
    tNodoGrafo *aux = busquedaNodoGrafo(grafo, ciudad);
    if (aux == NULL) return 0;
    return aux->adyacencias != NULL;
}

int tieneAristasEntrantes(tGrafo grafo, tCiudad ciudad) {
    while (grafo != NULL) {
        if (busquedaAdyacenciasNodoGrafo(grafo->adyacencias, ciudad) != NULL) {
            return 1;
        }
        grafo = grafo->siguiente;
    }
    return 0;
}

int esFuente(tGrafo grafo, tCiudad ciudad) {
    return !tieneAristasEntrantes(grafo, ciudad) && tieneAristasSalientes(grafo, ciudad);
}

int esSumidero(tGrafo grafo, tCiudad ciudad) {
    return tieneAristasEntrantes(grafo, ciudad) && !tieneAristasSalientes(grafo, ciudad);
}

void mostrarConexionesDeUnVertice(tGrafo grafo, tCiudad ciudad) {
    tNodoGrafo *aux = busquedaNodoGrafo(grafo, ciudad);
    if (aux == NULL) {
        printf("No se encontró el vértice: ");
        mostrarCiudad(ciudad);
        printf("\n");
        return;
    }

    printf("Conexiones de ");
    mostrarCiudad(ciudad);
    printf(":\n");

    tNodoAdyacencias *ady = aux->adyacencias;
    while (ady != NULL) {
        printf("   -> ");
        mostrarCiudad(ady->vertice);
        printf(" ");
        mostrarDatosVuelo(ady->datosVuelo);
        printf("\n");
        ady = ady->siguiente;
    }
}

void mostrarCaminosLongitud2(tGrafo grafo, tCiudad ciudad) {
    tNodoGrafo *nodoOrigen = busquedaNodoGrafo(grafo, ciudad);
    if (nodoOrigen == NULL) {
        printf("No se encontró el vértice: ");
        mostrarCiudad(ciudad);
        printf("\n");
        return;
    }

    // Matriz para guardar las combinaciones ya mostradas
    tCiudad intermedio[100], destino[100];
    int contador = 0;

    tNodoAdyacencias *nivel1 = nodoOrigen->adyacencias;
    while (nivel1 != NULL) {
        tNodoGrafo *nodoIntermedio = busquedaNodoGrafo(grafo, nivel1->vertice);
        if (nodoIntermedio != NULL) {
            tNodoAdyacencias *nivel2 = nodoIntermedio->adyacencias;
            while (nivel2 != NULL) {
                if (!sonIguales(nivel2->vertice, ciudad)) {
                    int yaMostrado = 0;
                    for (int i = 0; i < contador; i++) {
                        if (sonIguales(intermedio[i], nivel1->vertice) &&
                            sonIguales(destino[i], nivel2->vertice)) {
                            yaMostrado = 1;
                            break;
                            }
                    }

                    if (!yaMostrado) {
                        copiarCiudad(intermedio[contador], nivel1->vertice);
                        copiarCiudad(destino[contador], nivel2->vertice);
                        contador++;

                        printf("Camino de longitud 2: ");
                        mostrarCiudad(ciudad);
                        printf(" -> ");
                        mostrarCiudad(nivel1->vertice);
                        printf(" -> ");
                        mostrarCiudad(nivel2->vertice);
                        printf("\n");
                    }
                }
                nivel2 = nivel2->siguiente;
            }
        }
        nivel1 = nivel1->siguiente;
    }
}


int estanConectadas(tGrafo grafo, tCiudad origen, tCiudad destino) {
    tNodoGrafo *nodoOrigen = busquedaNodoGrafo(grafo, origen);
    if (nodoOrigen == NULL) return 0;
    return busquedaAdyacenciasNodoGrafo(nodoOrigen->adyacencias, destino) != NULL;
}

int ciudadExiste(tGrafo grafo, tCiudad ciudad) {
    return busquedaNodoGrafo(grafo, ciudad) != NULL;
}

int esGrafoConexo(tGrafo grafo) {
    if (grafo == NULL) return 1;

    tPila pila;
    crearPilaVacia(&pila);

    tCiudad visitadas[100]; // maximo 100 ciudades si no tendria q
    int visitados = 0;

    apilar(&pila, grafo->vertice);  // empezamos desde el primer nodo

    while (!esPilaVacia(&pila)) {
        tCiudad actual;
        cima(&pila, &actual);
        desapilar(&pila);

        int yaEsta = 0;
        for (int i = 0; i < visitados; i++) {
            if (sonIguales(visitadas[i], actual)) {
                yaEsta = 1;
                break;
            }
        }

        if (!yaEsta) {
            copiarCiudad(visitadas[visitados], actual);
            visitados++;

            tNodoGrafo *nodoActual = busquedaNodoGrafo(grafo, actual);
            tNodoAdyacencias *ady = nodoActual->adyacencias;
            while (ady != NULL) {
                int yaVisitada = 0;
                for (int i = 0; i < visitados; i++) {
                    if (sonIguales(visitadas[i], ady->vertice)) {
                        yaVisitada = 1;
                        break;
                    }
                }
                if (!yaVisitada) {
                    apilar(&pila, ady->vertice);
                }
                ady = ady->siguiente;
            }
        }
    }

    int total = 0;
    tGrafo aux = grafo;
    while (aux != NULL) {
        total++;
        aux = aux->siguiente;
    }

    return visitados == total;
}

void mostrarFuentesYSumideros(tGrafo grafo) {
    printf("Ciudades fuente:\n");
    tGrafo aux = grafo;
    while (aux != NULL) {
        if (esFuente(grafo, aux->vertice)) {
            printf("  - ");
            mostrarCiudad(aux->vertice);
            printf("\n");
        }
        aux = aux->siguiente;
    }

    printf("\nCiudades sumidero:\n");
    aux = grafo;
    while (aux != NULL) {
        if (esSumidero(grafo, aux->vertice)) {
            printf("  - ");
            mostrarCiudad(aux->vertice);
            printf("\n");
        }
        aux = aux->siguiente;
    }
}
void trayectoConMasCompanias(tGrafo grafo) {
    tGrafo aux = grafo;
    tCiudad mejorOrigen, mejorDestino;
    int maxCompanias = 0;

    while (aux != NULL) {
        tNodoAdyacencias *ady1 = aux->adyacencias;
        while (ady1 != NULL) {
            int count = 0;
            tNodoAdyacencias *ady2 = aux->adyacencias;
            while (ady2 != NULL) {
                if (sonIguales(ady1->vertice, ady2->vertice)) {
                    count++;
                }
                ady2 = ady2->siguiente;
            }
            if (count > maxCompanias) {
                maxCompanias = count;
                copiarCiudad(mejorOrigen, aux->vertice);
                copiarCiudad(mejorDestino, ady1->vertice);
            }
            ady1 = ady1->siguiente;
        }
        aux = aux->siguiente;
    }

    if (maxCompanias > 0) {
        printf("\nEl trayecto con más compañías es de ");
        mostrarCiudad(mejorOrigen);
        printf(" a ");
        mostrarCiudad(mejorDestino);
        printf(" con %d compañías.\n", maxCompanias);
    } else {
        printf("\nNo se encontraron trayectos con múltiples compañías.\n");
    }
}

void mostrarTrayectoMasCaroYBarato(tGrafo grafo) {
    tGrafo aux = grafo;
    float maxPrecio = -1, minPrecio = 1e9;
    tCiudad oMax, dMax, oMin, dMin;

    while (aux != NULL) {
        tNodoAdyacencias *ady = aux->adyacencias;
        while (ady != NULL) {
            float precio = ady->datosVuelo.precio;
            if (precio > maxPrecio) {
                maxPrecio = precio;
                copiarCiudad(oMax, aux->vertice);
                copiarCiudad(dMax, ady->vertice);
            }
            if (precio < minPrecio) {
                minPrecio = precio;
                copiarCiudad(oMin, aux->vertice);
                copiarCiudad(dMin, ady->vertice);
            }
            ady = ady->siguiente;
        }
        aux = aux->siguiente;
    }

    printf("\nTrayecto más caro: ");
    mostrarCiudad(oMax);
    printf(" -> ");
    mostrarCiudad(dMax);
    printf(" (%.2f euros)\n", maxPrecio);

    printf("Trayecto más barato: ");
    mostrarCiudad(oMin);
    printf(" -> ");
    mostrarCiudad(dMin);
    printf(" (%.2f euros)\n", minPrecio);
}

void mostrarTrayectoMasLentoYMasRapido(tGrafo grafo) {
    tGrafo aux = grafo;
    int maxTiempo = -1, minTiempo = 1e9;
    tCiudad oMax, dMax, oMin, dMin;

    while (aux != NULL) {
        tNodoAdyacencias *ady = aux->adyacencias;
        while (ady != NULL) {
            int tiempo = ady->datosVuelo.tiempo;
            if (tiempo > maxTiempo) {
                maxTiempo = tiempo;
                copiarCiudad(oMax, aux->vertice);
                copiarCiudad(dMax, ady->vertice);
            }
            if (tiempo < minTiempo) {
                minTiempo = tiempo;
                copiarCiudad(oMin, aux->vertice);
                copiarCiudad(dMin, ady->vertice);
            }
            ady = ady->siguiente;
        }
        aux = aux->siguiente;
    }

    printf("\nTrayecto más lento: ");
    mostrarCiudad(oMax);
    printf(" -> ");
    mostrarCiudad(dMax);
    printf(" (%d min)\n", maxTiempo);

    printf("Trayecto más rápido: ");
    mostrarCiudad(oMin);
    printf(" -> ");
    mostrarCiudad(dMin);
    printf(" (%d min)\n", minTiempo);
}