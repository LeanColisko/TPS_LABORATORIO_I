/*
 * vocales con acento
( acento agudo español )
á 160	Á 181
é 130	É 144
í 161	Í 214
ó 162 	Ó 224
ú 163	Ú 233

Funciones
Author: lcolisko
*/
#include "funciones.h"
#include "Pasajeros.h"


char MenuPrincipal(){

	char opcion;

	printf("\nMen%c Principal:\n\n", 163);
	printf("1 - ALTA DE PASAJERO\n");
	printf("2 - MODIFICAR DATOS DE PASAJERO\n");
	printf("3 - BAJA DE PASAJERO\n");
	printf("4 - IMFORMACI%cN\n", 224);
	printf("5 - SALIR\n");
	printf(">>>>");

	fflush(stdin);
	scanf("%c", &opcion);

	while(opcion < '1' || opcion > '5'){
		printf("Por favor, ingrese un valor dentro de las opciones (1 a 5). Reigrese\n>>>>");
		fflush(stdin);
		scanf("%c", &opcion);
	}
	return opcion;

}


/*
 * Funcion ingresoValores: Permite ingresar valores mayores a 0, usada para ingresar kilometros y precios
 * Retorna el valor ingresado por el usuario.
 */
float ingresoFlotantesPositivos(){
	float valor = 0;
    char datoIngresado[20];
	int flagEsValido;

	do{
	    printf("\n>>>>\n");
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
 * Funcion ingresoValores: Permite ingresar valores mayores a 0, usada para ingresar kilometros y precios
 * Retorna el valor ingresado por el usuario.
 */
int ingresoEnterosPositivos(){
	int valor = 0;
    char datoIngresado[20];
	int flagEsValido;

	do{
	    printf("\n>>>>\n");
    	fflush(stdin);
    	scanf("%s", datoIngresado);

    	flagEsValido = esFlotanteValido(datoIngresado);
    	if (flagEsValido){
    	    valor = (int) strtol(datoIngresado, NULL, 20);
    	}
	} while(valor < 1 );

	return valor;
}

/*
 * Funcion esFlotanteValido: Valida si un numero es un flotante valido o no
 */
int esFlotanteValido(char cadena[]) {

	int contadorPuntos = 0;
    int i, largoCadena;
    int retorno = -1;

	largoCadena = strlen(cadena);
	if(cadena != NULL && largoCadena > 0){

		retorno = 1; //VERDADERO: DATO VALIDO

		for(i = 0; i <largoCadena; i++) {
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}

			if (cadena[i] == '.') {
				contadorPuntos++;
			}

			if(cadena[i] > '9' || cadena[i] < '0' || contadorPuntos > 1){
				retorno = 0; // DATO NO VÁLIDO
				break;
			}
		}

	}

	return retorno;
}

/*
 * Funcion esEnteroValido: Valida si un dato ingresado es un entero válido
 * Retorna: 0 en caso de que no sea válido -1 por error de parámetros y 1 si es un numero válido
 */
int esEnteroValido(char cadena[]) {

	int retorno = -1; //ERROR DE PARAMETROS
	int i, largoCadena;

	largoCadena = strlen(cadena);
	if(cadena != NULL && largoCadena > 0){

		retorno = 1; //VERDADERO

		for(i = 0; i <largoCadena; i++) {
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}

			if(cadena[i] > '9' || cadena[i] < '0' ){
				retorno = 0; // DATO NO VÁLIDO
				break;
			}
		}

	}
	return retorno;
}


