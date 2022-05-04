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



int isFloat(char cadena[]);
int getFloatByConsola(float *valor, char *message, char *messageError, int min, int max, int reintentos);

int isInt(char cadena[]);
int getIntByConsola(int *valor, char *message, char *messageError, int min, int max, int reintentos);

int getStringByConsola(char *valor, char *message, char *messageError, int limite, int reintentos);

int myGets(char *cadena, int limite);


#endif /* FUNCIONES_H_ */
