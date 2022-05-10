/*
 * vocales con acento
( acento agudo espa�ol )
� 160	� 181
� 130	� 144
� 161	� 214
� 162 	� 224
� 163	� 233

Funciones
Author: lcolisko
*/
#include "funciones.h"
#include "Pasajeros.h"

/*
/// \param *valor espacio para guardar un flotante
/// \param *mensaje
/// \param *mensaje de error
/// \param valor minimo posible
/// \param valor maximo posible
/// \param reintentos posible
/// \return 1 si todo est� bien
 */
int getFloatByConsola(float *valor, char *message, char *messageError, int min, int max, int reintentos){

	int retorno = -1; //Error de par�metros
    char datoIngresado[40];
	int flagEsValido;
	float auxValor;

	if(valor != NULL && message != NULL && messageError != NULL && min <= max && reintentos >= 0 ) {

		retorno = 0; //Error de valor

		do{
			printf("\n%s\n>>>>", message);

			myGets(datoIngresado, 40); // valor de 40 d�gitos

			flagEsValido = isFloat(datoIngresado);

			if (flagEsValido){
				auxValor = atof(datoIngresado);

				if(auxValor >= min && auxValor <= max) {

					*valor = auxValor;
					retorno = 1;
					break;
				}

			}
			printf("\n%s\n", messageError);
			reintentos--;

		} while(reintentos >= 0 );
	}

	return retorno;
}


/*
/// \param *valor espacio para guardar un entero
/// \param *mensaje
/// \param *mensaje de error
/// \param valor minimo posible
/// \param valor maximo posible
/// \param reintentos posible
/// \return 1 si todo est� bien
 */
int getIntByConsola(int *valor, char *message, char *messageError, int min, int max, int reintentos){

	int retorno = -1;
    char datoIngresado[100];
	int flagEsValido;
	int auxValor;

	if(valor != NULL && message != NULL && messageError != NULL && min <= max && reintentos >= 0 ) {

		retorno = 0; //Error de valor

		do{
			printf("\n%s\n>>>>", message);

			myGets(datoIngresado, 100);

			flagEsValido = isFloat(datoIngresado);

			if (flagEsValido){
				auxValor = atoi(datoIngresado);

				if(auxValor >= min && auxValor <= max) {

					*valor = auxValor;
					retorno = 1;
					break;
				}

			}
			printf("\n%s", messageError);
			reintentos--;

		} while(reintentos >= 0 );
	}

	return retorno;
}


/*
/// \param *valor espacio para guardar un string
/// \param *mensaje
/// \param *mensaje de error
/// \param valor minimo posible
/// \param valor maximo posible
/// \param reintentos posible
/// \return 1 si todo est� bien
 */
int getStringByConsola(char *valor, char *message, char *messageError, int limite, int reintentos){

	int retorno = -1;
    char datoIngresado[limite];
	int flagEsValido;

	if(valor != NULL && message != NULL && messageError != NULL && limite > 0 && reintentos >= 0 ) {

		retorno = 0; //Error de valor

		do{
			printf("\n%s\n>>>>", message);

			flagEsValido = myGets(datoIngresado, limite); // valor de 40 d�gitos


			if (flagEsValido == 1){
				strncpy(valor, datoIngresado, limite);
				retorno = 1;
				break;

			}
			printf("\n%s", messageError);
			reintentos--;

		} while(reintentos >= 0 );
	}

	return retorno;
}


/*
/// \param cadena
/// \return int 1 si es float
 */
int isFloat(char cadena[]) {

	int contadorPuntos = 0;
    int i, largoCadena;
    int retorno = -1;
	largoCadena = strlen(cadena);

	if(cadena != NULL && largoCadena > 0){

		retorno = 1; //VERDADERO: DATO VALIDO

		for(i = 0; i < largoCadena || cadena[i] != '\0'; i++) {

			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}

			if(cadena[i] == '.') {
				contadorPuntos++;
				continue;
			}

			if(cadena[i] > '9' || cadena[i] < '0' || contadorPuntos > 1){
				retorno = 0; // DATO NO V�LIDO
				break;
			}
		}
	}
	return retorno;
}

/*
 * Funcion isInt: Valida si un dato ingresado es un entero v�lido
 * Retorna: 0 en caso de que no sea v�lido -1 por error de par�metros y 1 si es un numero v�lido
 */
int isInt(char cadena[]) {

	int retorno = -1; //ERROR DE PARAMETROS
	int i, largoCadena;

	largoCadena = strlen(cadena);
	if(cadena != NULL && largoCadena > 0){

		retorno = 1; //VERDADERO

		for(i = 0; i < largoCadena || cadena[i] != '\0'; i++) {

			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}

			if(cadena[i] > '9' || cadena[i] < '0' ){
				retorno = 0; // DATO NO V�LIDO
				break;
			}
		}

	}
	return retorno;
}


/*
 * Funci�n myGets: Pide un dato por consola y lo guarda en una variable de forma segura
 *
 * Retorna: 0 en caso de que no sea v�lido -1 por error de par�metros y 1 si es un ingreso correcto
 */
int myGets(char *cadena, int limite) {

	int retorno = -1; // Error de par�metros
	char bufferString[4024];

	if( cadena != NULL && limite > 0){

		retorno = 0; // Error en ejecucion

		fflush(stdin);

		if( fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if( bufferString[ strlen(bufferString) -1] == '\n'){
				bufferString[ strlen(bufferString) -1] = '\0';
			}
			if(strlen(bufferString) <= limite)
			{
				strncpy(cadena, bufferString, limite);
				retorno = 1; // Fin correcto
			}
		}

	}


	return retorno;
}




