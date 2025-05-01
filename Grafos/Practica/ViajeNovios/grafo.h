//
// Created by borja on 01/05/2025.
//

#ifndef GRAFO_H
#define GRAFO_H
#include "Ciudad.h"
typedef struct NodoAdyacencias {
    struct NodoAdyacencias *siguiente;
    tCiudad ciudad;
} tNodoAdyacencias;

typedef tNodoAdyacencias *tListaAdyacencias;

typedef struct NodoGrafo {
    struct NodoGrafo *siguiente;
    tCiudad ciudad;
    tListaAdyacencias listaAdyacencias;
}tNodoGrafo;
typedef tNodoGrafo *tGrafo;
void crearGrafoVacio(tGrafo *grafo);
void insertarVertice(tGrafo *grafo, tCiudad ciudad);
void insertarConexion(tGrafo *grafo, tCiudad origen, tCiudad destino);
void insertarArista(tGrafo *grafo, tCiudad origen, tCiudad destino);
void mostrarGrafo(tGrafo grafo);
int numeroConexionesVertice(tGrafo grafo, tCiudad ciudad);
void ciudadEnPosicion(tGrafo grafo,char *nombreCiudad, int posicion, tCiudad resultado);

#endif //GRAFO_H
