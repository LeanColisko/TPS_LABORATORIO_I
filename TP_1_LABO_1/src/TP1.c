/*
 ============================================================================
 Name        : TP1.c
 Author      : Leandro Colisko Division F
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {

	unsigned int opcion;
	float kilometros, precioARG, precioLatam;
	float cambioBitcoin, variacionDebito, variacionCredito;
	char realizoCalculos, banderaSalir;

	realizoCalculos = 'N';
	banderaSalir = 'N';
	kilometros = 0;
	precioARG = 0;
	precioLatam = 0;
	cambioBitcoin = 4606954.55;
	variacionDebito = -0.1;
	variacionCredito = 0.25;

	setbuf(stdout, NULL);
	printf("¡¡¡BIENVENID@S A LA CALCULADORA DE PRECIOS DE VIAJES MARAVILLOSOS!!!\n\n");

	do {
		opcion = menuPrincipal(kilometros, precioARG, precioLatam);

		switch(opcion){

			case 1:
				/*Opcion 1: Ingreso de kilometros del viaje*/
				kilometros = ingresoValores("1. Ingresar los Kilómetros del viaje: (km)");
			break;
			case 2:
				/*Opcion 2: Ingresar valores de precios*/
				if(kilometros > 0){
					printf("2. Ingresar Precios de Vuelo:\n");
					precioARG = ingresoValores("Ingrese el precio de vuelo para la empresa Aerolíneas Argentinas:");
					precioLatam = ingresoValores("Ingrese el precio de vuelo para la empresa Latam:");
				} else {
					printf("Es necesario previamente ingresar los kilómetros de vuelos.\n");
				}
			break;
			case 3:
				/*Opcion 3: Calcular costos*/
				if(kilometros > 0 && precioARG > 0 && precioLatam > 0){
					printf("\n\n...CALCULANDO COSTOS...\n\n");
					realizoCalculos = 'S';
				} else{
					printf("\nFaltan datos para calcular los costos.\n");
				}
			break;
			case 4:
				/*Opcion 4: Informar costos*/
				if(realizoCalculos == 'S'){
					printf("Imprimiendo Informes\nLatam:\n");
					calcularCostos(precioLatam, kilometros, variacionDebito, variacionCredito, cambioBitcoin);
					printf("Aerolíneas Argentias\n");
					calcularCostos(precioARG, kilometros, variacionDebito, variacionCredito, cambioBitcoin);
					printf("e) Diferencia de precio: %.2f\n", precioARG - precioLatam);
				} else{
					printf("\nAún no se ha realizado el calculo de los costos.\n");
				}
			break;
			case 5:
				/*Opcion 5: Carga forzada*/
				kilometros = ingresoValores("1. Ingresar Kilómetros:");
				precioARG = ingresoValores("Ingrese el precio de vuelo para la empresa Aerolíneas Argentinas:");
				calcularCostos(precioARG, kilometros, variacionDebito, variacionCredito, cambioBitcoin);
				precioLatam = ingresoValores("Ingrese el precio de vuelo para la empresa Latam:");
				calcularCostos(precioLatam, kilometros, variacionDebito, variacionCredito, cambioBitcoin);
				printf("e) Diferencia de precio: %.2f\n", precioARG - precioLatam);
			break;
			case 6:
				printf("¿Está seguro/a que desar salir del programa? (S/N)\n>>>>");
				fflush(stdin);
				scanf("%c", &banderaSalir);
				while(banderaSalir !='S' && banderaSalir !='N'){
					printf("¿Está seguro/a que desar salir del programa? (S/N)\n>>>>");
					fflush(stdin);
					scanf("%c", &banderaSalir);
				}
			break;
		}

	} while(banderaSalir != 'S');

	printf("El programa finalizó con éxito.");

	return EXIT_SUCCESS;
}

