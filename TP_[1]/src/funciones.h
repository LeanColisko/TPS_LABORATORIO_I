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

/// \fn menuPrincipal(float kilometros, float precioAR, float precioLATAM)
/// \param kilometros Numero de kilometro ingresados por el usuario, si no lo hubiera es 0.
/// \param precioAR Precio del viaje para Aerolíneas Argentinas ingresados por el usuario, si no lo hubiera es 0.
/// \param precioLATAM Precio del viaje para LATAM ingresados por el usuario, si no lo hubiera es 0.
/// \brief Esta funcion imprime el menu principal de nuestro programa y devuelve un entero con la opcion seleccionada.
/// \return Devuelve un entero con la opción seleccionada por el usuario.
char menuPrincipal(float kilometros, float precioAR, float precioLATAM);

/// \fn ingresoValores(char mensaje[]);
/// \param mensaje[] Cadena de texo que servirá para pedir un valor al usuario.
/// \brief Permite el ingreso de nuemeros flotantes positivos.
/// \return Devuelve el valor ingresado por el usuario.
float ingresoValores(char mensaje[]);


/// \fn esFlotanteValido(char cadena[]);
/// \param cadena[] Cadena de texto a validar si es o no flotante valido.
/// \brief Valida si una cadena ingresada por un usuario es un numero flotante valido o no.
/// \return Devuelve 1 en caso de que la cadena sea valida y 0 en caso contrario.
int esFlotanteValido(char cadena[]);


/// \fn calcularCostos(float precio, float kilometros, float variacionDebito, float variacionCredito, float pesosXBitcoin);
/// \param precio Precio Bruto del viaje.
/// \param kilometros Kilometros totales del viaje.
/// \param variacionDebito El valor del descuento o aumento del precio por elegir el medio de pago TARJETA DE DÉBITO. Para ingresar descuentos el valor debe ser negativo
/// 						  para ingresar aumentos el numero debe ser positvio. Ejemplo si por pagar con débito se tiene un descuento del diez por ciento
///						  la función esperará -0.1
/// \param variacionCredito El valor del descuento o aumento del precio por elegir el medio de pago TARJETA DE CRÉDITO. Para ingresar descuentos el valor debe ser negativo
/// 						  para ingresar aumentos el numero debe ser positvio. Ejemplo si por pagar con CRÉDOTP se tiene un recargo del 25 por ciento
///						  la función esperará el valor 0.25
/// \brief Calcula el costo de viaje en diferentes medios de pago (debito, credito, Bitcoin y el precio por kilometro).
/// \return Imprime por consola el informe.
void calcularCostos(float precio, float kilometros, float variacionDebito, float variacionCredito, float pesosXBitcoin);

#endif /* FUNCIONES_H_ */
