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


/// \param cadena
/// \return int 1 si es float
int isFloat(char cadena[]);

/// \param *valor espacio para guardar un flotante
/// \param *mensaje
/// \param *mensaje de error
/// \param valor minimo posible
/// \param valor maximo posible
/// \param reintentos posible
/// \return 1 si todo está bien
int getFloatByConsola(float *valor, char *message, char *messageError, int min, int max, int reintentos);

/// \param cadena
/// \return int 1 si es int
int isInt(char cadena[]);

/// \param *valor espacio para guardar un entero
/// \param *mensaje
/// \param *mensaje de error
/// \param valor minimo posible
/// \param valor maximo posible
/// \param reintentos posible
/// \return 1 si todo está bien
int getIntByConsola(int *valor, char *message, char *messageError, int min, int max, int reintentos);

/// \param *valor espacio para guardar un string
/// \param *mensaje
/// \param *mensaje de error
/// \param valor minimo posible
/// \param valor maximo posible
/// \param reintentos posible
/// \return 1 si todo está bien
int getStringByConsola(char *valor, char *message, char *messageError, int limite, int reintentos);

/// \param *cedena espacio para guardar un de forma segura un ingreso de usuario
/// \param limite maximos de caracters permitidos
/// \return 1 si todo está bien
int myGets(char *cadena, int limite);


#endif /* FUNCIONES_H_ */
