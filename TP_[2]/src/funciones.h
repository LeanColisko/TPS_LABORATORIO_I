/*
 * funciones.h
 *
 *  Created on: 19 abr. 2022
 *      Author: lcolisko
 */

#ifndef FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pasajeros.h"

#define FUNCIONES_H_

/// \fn MenuPrincipal()
/// \param void solo imprime por pantalla cuando es invocada
/// \brief imprime por consola el menú principal de la aplicación
/// \return retorna un valor char con valores del '1' al '5'
char MenuPrincipal();


int esFlotanteValido(char cadena[]);
float ingresoFlotantesPositivos();

int esEnteroValido(char cadena[]);
int ingresoEnterosPositivos();

#endif /* FUNCIONES_H_ */
