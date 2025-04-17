//
// Created by borja on 17/04/2025.
//

#include "Grafo.h"

#include <stdio.h>

void crearGrafoVacio(tGrafo *grafo, tElemento vertices[VERTICES]) {
     for (int i = 0; i < VERTICES; i++) {
          for (int j = 0; j < VERTICES; j++) {
               grafo -> matrizAdyacencias[i][j] = 0;
          }
     }

     grafo -> numeroVertices = VERTICES;
     for (int i = 0; i < VERTICES; i++) {
          asignarElemento(&grafo-> vertices[i], vertices[i]);
     }
}

void insertarArista(tGrafo *grafo, tElemento origen, tElemento destino) {
     int i = -1, j = -1;

     // Buscar índice del vértice origen
     for (int k = 0; k < grafo->numeroVertices; k++) {
          if (esIgual(grafo->vertices[k], origen)) {
               i = k;
          }
          if (esIgual(grafo->vertices[k], destino)) {
               j = k;
          }
     }

     if (i != -1 && j != -1) {

          grafo->matrizAdyacencias[i][j] = 1;
          //grafo->matrizAdyacencias[j][i] = 1; // si el grafo es dirigido habria q quitar esta linea
     } else {
          printf("Uno o ambos vértices no existen en el grafo.\n");
     }
}
void mostrarVertices(tGrafo grafo) {
     for (int i = 0; i < grafo.numeroVertices; i++) {
          mostrarElemento(grafo.vertices[i]);
     }
     printf("\n");
}

void mostrarConexionesGrafo(tGrafo grafo) {
     for (int i = 0; i < grafo.numeroVertices; i++) {
          for (int j = 0; j < grafo.numeroVertices; j++) {
               if (grafo.matrizAdyacencias[i][j] > 0) {
                    printf("El elemento ");
                    mostrarElemento(grafo.vertices[i]);
                    printf(" está conectado con ");
                    mostrarElemento(grafo.vertices[j]);
                    printf("\n");
               }
          }
     }
}


int esFuente(tGrafo grafo, tElemento vertice) {
     int indiceVertice = -1;


     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (esIgual(grafo.vertices[i], vertice)) {
               indiceVertice = i;
               break;
          }
     }

     if (indiceVertice == -1) {
          return -1;
     }


     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (grafo.matrizAdyacencias[i][indiceVertice] > 0) {
               return 0; // tiene al menos una entrada → no es fuente
          }
     }


     for (int j = 0; j < grafo.numeroVertices; j++) {
          if (grafo.matrizAdyacencias[indiceVertice][j] > 0) {
               return 1; // no tiene entradas y sí salidas → es fuente
          }
     }

     return 0; // no tiene entradas, pero tampoco salidas → no es fuente
}

int esSumidero(tGrafo grafo, tElemento vertice) {
     int indiceVertice = -1;

     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (esIgual(grafo.vertices[i], vertice)) {
               indiceVertice = i;
               break;
          }
     }

     if (indiceVertice == -1) {
          return -1;
     }


     for (int j = 0; j < grafo.numeroVertices; j++) {
          if (grafo.matrizAdyacencias[indiceVertice][j] > 0) {
               return 0; // tiene al menos una salida → no es sumidero
          }
     }


     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (grafo.matrizAdyacencias[i][indiceVertice] > 0) {
               return 1; // no tiene salidas y sí tiene entradas → es sumidero
          }
     }

     return 0; // no tiene entradas ni salidas → no es sumidero
}

void mostrarConexionesDeUnVertice(tGrafo grafo, tElemento vertice) {

     int indiceVertice = -1;
     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (esIgual(grafo.vertices[i], vertice)) {
               indiceVertice = i;
               break;
          }
     }
     if (indiceVertice == -1) {
          printf("No existe ese vertice en el grafo\n");
          return;
     }
     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (grafo.matrizAdyacencias[indiceVertice][i] > 0) {
               printf("El elemento ");
               mostrarElemento(grafo.vertices[indiceVertice]);
               printf(" está conectado con ");
               mostrarElemento(grafo.vertices[i]);
               printf("\n");
          }
     }
     printf("\n");
}
void mostrarCaminosLongitudDos(tGrafo grafo, tElemento vertice) {
     int indiceOrigen = -1;

     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (esIgual(grafo.vertices[i], vertice)) {
               indiceOrigen = i;
               break;
          }
     }

     if (indiceOrigen == -1) {
          printf("No existe ese vértice en el grafo\n");
          return;
     }

     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (grafo.matrizAdyacencias[indiceOrigen][i] > 0) {
               for (int j = 0; j < grafo.numeroVertices; j++) {
                    if (grafo.matrizAdyacencias[i][j] > 0 && j != indiceOrigen) {
                         printf("Camino de longitud 2: ");
                         mostrarElemento(grafo.vertices[indiceOrigen]);
                         printf(" → ");
                         mostrarElemento(grafo.vertices[i]);
                         printf(" → ");
                         mostrarElemento(grafo.vertices[j]);
                         printf("\n");
                    }
               }
          }
     }
}

int estanConectados(tGrafo grafo, tElemento origen, tElemento destino) {
     int indiceVerticeOrigen = -1;
     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (esIgual(grafo.vertices[i], origen)) {
               indiceVerticeOrigen = i;
               break;
          }
     }

     if (indiceVerticeOrigen == -1) {
          printf("No existe el siguiente vértice en el grafo: ");
          mostrarElemento(origen);
          return -1;
     }

     int indiceVerticeDestino = -1;
     for (int i = 0; i < grafo.numeroVertices; i++) {
          if (esIgual(grafo.vertices[i], destino)) {
               indiceVerticeDestino = i;
               break;
          }
     }

     if (indiceVerticeDestino == -1) {
          printf("No existe el siguiente vértice en el grafo: ");
          mostrarElemento(destino);
          return -1;
     }


     return grafo.matrizAdyacencias[indiceVerticeOrigen][indiceVerticeDestino] > 0 &&
            grafo.matrizAdyacencias[indiceVerticeDestino][indiceVerticeOrigen] > 0;
}

