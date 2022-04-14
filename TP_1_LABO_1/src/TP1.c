/*
 ============================================================================
 Name        : TP1.c
 Author      : Leandro Colisko Division F
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include "funciones.h"

int main(void) {

	char opcion;
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
	printf("\n\n");
	printf("--------------------------------------------------------------------\n");
	printf("%c%c%cBIENVENID%cS A LA CALCULADORA DE PRECIOS DE VIAJES MARAVILLOSOS%c%c%c\n", 173, 173, 173, 64, 33, 33, 33);
	printf("--------------------------------------------------------------------\n\n");
	do {
		opcion = menuPrincipal(kilometros, precioARG, precioLatam);

		switch(opcion){

			case '1':
				/*Opcion 1: Ingreso de kilometros del viaje*/
				kilometros = ingresoValores("1. Ingresar los Kilómetros del viaje: (km)");
			break;
			case '2':
				/*Opcion 2: Ingresar valores de precios*/
				if(kilometros > 0){
					printf("2. Ingresar Precios de Vuelo:\n");
					precioARG = ingresoValores("Ingrese el precio de vuelo para la empresa Aerolíneas Argentinas:");
					precioLatam = ingresoValores("Ingrese el precio de vuelo para la empresa Latam:");
				} else {
					printf("Es necesario previamente ingresar los kil%cmetros de vuelos.\n", 162);
				}
			break;
			case '3':
				/*Opcion 3: Calcular costos*/
				if(kilometros > 0 && precioARG > 0 && precioLatam > 0){
					printf("\n\n...CALCULANDO COSTOS...\n\n");
					realizoCalculos = 'S';
				} else{
					printf("\nFaltan datos para calcular los costos.\n");
				}
			break;
			case '4':
				/*Opcion 4: Informar costos*/
				if(realizoCalculos == 'S'){
					printf("\nLatam:\n");
					calcularCostos(precioLatam, kilometros, variacionDebito, variacionCredito, cambioBitcoin);
					printf("Aerol%cneas Argentias\n", 161);
					calcularCostos(precioARG, kilometros, variacionDebito, variacionCredito, cambioBitcoin);
					printf("e) Diferencia de precio: %.2f\n", precioARG - precioLatam);
				} else{
					printf("\nA%cn no se ha realizado el calculo de los costos. Por favor, ingrese la opci%cn 3.\n", 163, 162);
				}
			break;
			case '5':
				/*Opcion 5: Carga forzada*/
				kilometros = ingresoValores("1. Ingresar Kilómetros:");
				precioARG = ingresoValores("Ingrese el precio de vuelo para la empresa Aerolíneas Argentinas:");
				calcularCostos(precioARG, kilometros, variacionDebito, variacionCredito, cambioBitcoin);
				precioLatam = ingresoValores("Ingrese el precio de vuelo para la empresa Latam:");
				calcularCostos(precioLatam, kilometros, variacionDebito, variacionCredito, cambioBitcoin);
				printf("e) Diferencia de precio: %.2f\n", precioARG - precioLatam);
			break;

			case '6':

				do {
					printf("%cEst%c seguro/a que desar salir del programa%c (S/N)\n>>>>", 168, 160, 63);
					fflush(stdin);
					scanf("%c", &banderaSalir);
					banderaSalir = toupper(banderaSalir);
				} while(banderaSalir !='S' && banderaSalir !='N');

			break;
		}

	} while(banderaSalir != 'S');

	printf("GRACIAS POR UTILIZAR NUESTRO PROGRAMA\nCopyright: Leandro Colisko División F");
	return EXIT_SUCCESS;
}

