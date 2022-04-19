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
char menuPrincipal(float kilometros, float precioAR, float precioLATAM) {

	char opcion;

	printf("\n\tMENU PRINCIPAL:\n");
	printf("1. Ingresar Kil%cmetros: (km = %.2f)\n", 162, kilometros);
	printf("2. Ingresar Precio de Vuelos: (Aerol%cneas = %.2f, Latam = %.2f)\n", 161, precioAR, precioLATAM);
	printf("3. Calcular todos los costos\n");
	printf("4. Informar Resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");
	printf(">>>>");

	fflush(stdin);
	scanf("%c", &opcion);
	while(opcion < '1' || opcion > '6'){
		printf("Error. Ingrese un valor del 1 al 6. Reigrese\n>>>>");
		fflush(stdin);
		scanf("%c", &opcion);
	}
	return opcion;
}

/*
 * Funcion ingresoValores: Permite ingresar valores mayores a 0, usada para ingresar kilometros y precios
 * Retorna el valor ingresado por el usuario.
 */
float ingresoValores(char mensaje[]){
	float valor = 0;
    char datoIngresado[20];
	int flagEsValido;

	do{
	    printf("%s\n>>>>", mensaje);
    	fflush(stdin);
    	scanf("%s", datoIngresado);

    	flagEsValido = esFlotanteValido(datoIngresado);
    	if (flagEsValido){
    	    valor = strtof(datoIngresado, NULL);
    	}
	} while(valor < 1 );

	return valor;
}

/*
 * Funcion esFlotanteValido: Valida si un numero es un flotante valido o no
 */
int esFlotanteValido(char cadena[]) {
    int longitud = strlen(cadena);
    int contadorPuntos = 0;

    if (longitud <= 0) {
        return 0;
    }
    for (int i = 0; i < longitud; i++) {

        if (cadena[i] == '.') {

            contadorPuntos++;
            if(contadorPuntos > 1){
                return 0;
            }
        }

        if (!isdigit(cadena[i]) && cadena[i] != '.') {
            return 0;
        }
    }
    return 1;
}

/* Funcion calcularCostos: Mediante el ingreso de precio, kilometros, variacion pagando con debito,
* 						   variacion pagango con credito y el cambio de pesos a bitcoins
 * 						   calcula el costo para cada medio de pago.
 * Imprime el informe de cada opción de pago.
 *
 */
void calcularCostos(float precio, float kilometros, float variacionDebito, float variacionCredito, float pesosXBitcoin) {

	float precioDebito, precioCredito, precioConBitcoin, precioUnitario;

	precioDebito = precio * (1 + variacionDebito);
	precioCredito = precio * (1 + variacionCredito);
	precioConBitcoin = precio / pesosXBitcoin;
	precioUnitario = precio / kilometros;

	printf("a) Precio con tarjeta de d%cbito (descuento 10%c): $%.2f\n", 130, 37, precioDebito) ;
	printf("b) Precio tarjeta de cr%cdito (inter%cs 25%c): $%.2f\n", 130, 130, 37, precioCredito);
	printf("c) Precio con Bitcoin (1BTC -> %.2f Pesos Argentinos): BTC %.5f\n", pesosXBitcoin, precioConBitcoin);
	printf("d) Precio por km (precio unitario): $%.2f\n\n", precioUnitario);
}

