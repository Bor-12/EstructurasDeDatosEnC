//
// Created by borja on 27/02/2025.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#define MAX_PAIS 50
#define MAX_ACCION 200

typedef struct {
    char pais[MAX_PAIS];
    char descripcion[MAX_ACCION];
    int nivelAlerta; // 5 = alerta máxima, 1 = mínima
} tElemento;

void asignarElemento(tElemento *PunteroElemento, tElemento valor);
tElemento crearElemento(const char* pais, const char* descripcion, int nivelAlerta);
int esMenor(tElemento e1, tElemento e2);
int esIgual(tElemento e1, tElemento e2);
void mostrarElemento(tElemento e);
tElemento elementoVacio();

#endif // TELEMENTO_H

