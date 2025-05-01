#ifndef GRAFO_H
#define GRAFO_H

#include "InfoVuelos.h"
#include "Ciudad.h"

typedef struct NodoAdyacencias {
    struct NodoAdyacencias *siguiente;
    tCiudad vertice;                 // ciudad de destino
    tDatosVuelo datosVuelo;          // compañía, tiempo, precio
} tNodoAdyacencias;

typedef tNodoAdyacencias *tListaAdyacencias;

typedef struct NodoGrafo {
    struct NodoGrafo *siguiente;
    tListaAdyacencias adyacencias;  // lista de vuelos salientes
    tCiudad vertice;                // ciudad de origen
} tNodoGrafo;

typedef tNodoGrafo *tGrafo;

// Funciones del grafo
void crearGrafoVacio(tGrafo *grafo);
void insertarVertice(tGrafo *grafo, tCiudad ciudad);
void insertarConexion(tGrafo *grafo, tCiudad origen, tCiudad destino, tDatosVuelo datos); // dirigido
void insertarArista(tGrafo *grafo, tCiudad origen, tCiudad destino, tDatosVuelo datos);    // no dirigido

void mostrarVerticesGrafo(tGrafo grafo);
void mostrarConexionesGrafo(tGrafo grafo);
tNodoGrafo* busquedaNodoGrafo(tGrafo grafo, tCiudad ciudad);
tNodoAdyacencias* busquedaAdyacenciasNodoGrafo(tListaAdyacencias lista, tCiudad ciudad);
int tieneAristasSalientes(tGrafo grafo, tCiudad ciudad);
int tieneAristasEntrantes(tGrafo grafo, tCiudad ciudad);
int esFuente(tGrafo grafo, tCiudad ciudad);
int esSumidero(tGrafo grafo, tCiudad ciudad);
void mostrarConexionesDeUnVertice(tGrafo grafo, tCiudad ciudad);
void mostrarCaminosLongitud2(tGrafo grafo, tCiudad ciudad);
int estanConectadas(tGrafo grafo, tCiudad origen, tCiudad destino);

int ciudadExiste(tGrafo grafo, tCiudad ciudad);

int esGrafoConexo(tGrafo grafo);
void mostrarCiudadesConUnaEscala(tGrafo grafo, tCiudad ciudad);
int esConexionDirecta(tGrafo grafo, tCiudad origen, tCiudad destino);
void mostrarFuentesYSumideros(tGrafo grafo);
void trayectoConMasCompanias(tGrafo grafo);
void mostrarTrayectoMasCaroYBarato(tGrafo grafo);
void mostrarTrayectoMasLentoYMasRapido(tGrafo grafo);

#endif // GRAFO_H
