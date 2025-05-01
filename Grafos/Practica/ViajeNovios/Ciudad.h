#ifndef TCIUDAD_H
#define TCIUDAD_H

typedef char tCiudad[50];

void crearCiudad(tCiudad ciudad, const char *nombre);
int sonIguales(tCiudad c1, tCiudad c2);
void copiarCiudad(tCiudad destino, tCiudad origen);
void mostrarCiudad(tCiudad ciudad);

#endif // TCIUDAD_H

