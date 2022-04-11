/*
 * funciones.c
 *
 *  Created on: 3 abr. 2022
 *      Author: lcolisko
 */

#include "funciones.h"

/*
 * Funcion menuPrincipal: Imprime el menu principal y pide al usuario que ingrese una opción
 * Retorna un entero con la opcion que ingresó el usuario
 */
unsigned int menuPrincipal(float kilometros, float precioAR, float precioLATAM){
	unsigned int opcion;
	printf("\n\tMENU PRINCIPAL:\n");
	printf("1. Ingresar Kilómetros: (km = %.2f)\n", kilometros);
	printf("2. Ingresar Precio de Vuelos: (Aerolíneas = %.2f, Latam = %.2f)\n", precioAR, precioLATAM);
	printf("3. Calcular todos los costos:\n");
	printf("4. Informar Resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");
	printf(">>>>");
	scanf("%d", &opcion);
	while(opcion < 1 || opcion > 6){
		printf("Error. Ingrese un valor dentro de las opciones. Reigrese\n>>>>");
		scanf("%d", &opcion);
	}
	return opcion;
}

/*
 * Funcion ingresoValores: Permite ingresar valores mayores a 0, usada para ingresar kilometros y precios
 * Retorna el valor ingresado por el usuario.
 */
float ingresoValores(char mensaje[]){
	float valor;
	printf("%s\n>>>>", mensaje);
	scanf("%f", &valor);
	while(valor < 1){
		printf("Error. El ingreso no puede ser menor a 0. Reigrese\n>>>>");
		scanf("%f", &valor);
	}
	return valor;
}


/* Funcion calcularCostos: Mediante el ingreso de precio, kilometros, variacion pagando con debito,
* 						   variacion pagango con credito y el cambio de pesos a bitcoins
 * 						   calcula el costo para cada medio de pago.
 * Imprime el informe de cada opción de pago.
 *
 */
void calcularCostos(float precio, float kilometros, float variacionDebito, float variacionCredito, float pesosXBitcoin){

	float precioDebito, precioCredito, precioConBitcoin, precioUnitario;

	precioDebito = precio * (1 + variacionDebito);
	precioCredito = precio * (1 + variacionCredito);
	precioConBitcoin = precio / pesosXBitcoin;
	precioUnitario = precio / kilometros;

	printf("a) Precio con tarjeta de débito (descuento 10%c): $%.2f\n", 37, precioDebito) ;
	printf("b) Precio tarjeta de crédito (interés 25%c): $%.2f\n", 37, precioCredito);
	printf("c) Precio con Bitcoin (1BTC -> %.2f Pesos Argentinos): BTC %.2f\n", pesosXBitcoin, precioConBitcoin);
	printf("d) Precio por km (precio unitario): $%.2f\n", precioUnitario);
}

