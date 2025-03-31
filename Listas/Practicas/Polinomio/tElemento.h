//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

typedef struct  {
    float coeficiente;
    int exponente;
} tElemento;

void asignarElemento(tElemento *e1, tElemento e2);
void leerElemento(tElemento *e);
int igualElemento(tElemento uno, tElemento dos);
int mayor(tElemento uno, tElemento dos);
void mostrarElemento(tElemento t);
int getExponente(tElemento e);
float getCoeficiente(tElemento e);
void derivada(tElemento *ed, tElemento e);
tElemento elementoVacio();

#endif // TELEMENTO_H

