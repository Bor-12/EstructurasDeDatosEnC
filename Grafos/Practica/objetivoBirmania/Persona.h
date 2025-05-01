//
// Created by borja on 01/05/2025.
//
#ifndef TPERSONA_H
#define TPERSONA_H

typedef char tPersona[50];


void crearPersona(tPersona persona, const char *nombre);

int sonIguales(tPersona p1, tPersona p2);

void copiarPersona(tPersona destino, tPersona origen);

void mostrarPersona(tPersona persona);

#endif // TPERSONA_H

