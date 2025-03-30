//
// Created by Javier Vergara Igual on 7/3/23.
//

#ifndef SECUAZ_H
#define SECUAZ_H

#define N 50

typedef struct {
    char nombre[N];
    int dineroCobrado;
} tSecuaz;

void crearSecuaz(tSecuaz* secuaz, char* nombre);
void asignar(tSecuaz* destino, tSecuaz origen); // copiarSecuaz
int iguales(tSecuaz s1, tSecuaz s2); // sonSecuacesIguales
char* dameNombre(tSecuaz secuaz);
int dameDineroCobrado(tSecuaz secuaz);
void cobrar(tSecuaz* secuaz, int cantidad);
void mostrarElemento(tSecuaz secuaz); // mostrarSecuaz
#endif
