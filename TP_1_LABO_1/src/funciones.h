/*
 * funciones.h
 *
 *  Created on: 3 abr. 2022
 *      Author: lcolisko
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned int menuPrincipal(float kilometros, float precioAR, float precioLATAM);
float ingresoValores(char mensaje[]);
void calcularCostos(float precio, float kilometros, float variacionDebito, float variacionCredito, float pesosXBitcoin);

#endif /* FUNCIONES_H_ */
