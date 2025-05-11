//
// Created by borja on 17/04/2025.
//

#ifndef GRAFO_H
#define GRAFO_H
#include "tElemento.h"

typedef struct NodoAdyacencias {
    struct NodoAdyacencias *siguiente;
    tElemento vertice;
    int ponderacion; //puede ser cualquier tipo de datos
}tNodoAdyacencias;

typedef tNodoAdyacencias *tListaAdyacencias;

typedef struct NodoGrafo {
    struct NodoGrafo *siguiente;
    tListaAdyacencias adyacencias;
    tElemento vertice;

}tNodoGrafo;
typedef tNodoGrafo *tGrafo;

void crearGrafoVacio(tGrafo *grafo);
void insertarVertice(tGrafo *grafo, tElemento vertice);
void insertarConexion(tGrafo *grafo, tElemento origen, tElemento destino, int ponderacion); //dirigido
void insertarArista(tGrafo *grafo, tElemento origen, tElemento destino, int ponderacion);// no dirigido

void mostrarVerticesGrafo(tGrafo grafo);
void mostrarConexionesGrafo(tGrafo grafo);
tNodoGrafo* busquedaNodoGrafo(tGrafo grafo, tElemento vertice);
tNodoAdyacencias* busquedaAdyacenciasNodoGrafo(tNodoAdyacencias *nodo, tElemento vertice);
int tieneAristasSalientes(tGrafo grafo, tElemento vertice);
int tieneAristasEntrantes(tGrafo grafo, tElemento vertice);
int esFuente(tGrafo grafo, tElemento vertice);
int esSumidero(tGrafo grafo, tElemento vertice);
void mostrarConexionesDeUnVertice(tGrafo grafo, tElemento vertice);
void mostrarCamidosLongitud2(tGrafo grafo, tElemento vertice);
int estanConectadas(tGrafo grafo, tElemento origen, tElemento destino);

#endif //GRAFO_H
