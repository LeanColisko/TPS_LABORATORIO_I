/*
 * appFunciones.c
 *
 *  Created on: 27 abr. 2022
 *      Author: lcolisko
 */

#include "funciones.h"
#include "appFunciones.h"

/*
 * imprime el men� principal de la aplicaci�n
 * retorna un valor char ingresado por el usuario, dentro de las opciones disponibles.
 */
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
/// \param void solo imprime por pantalla cuando es invocada
/// \brief imprime por consola el subMenu de modificacion de la aplicaci�n
/// \return retorna un valor char con valores del '1' al '6'
*/
char SubMenuModificar(){
	char opcion;

	printf("\nMen%c Modificaciones:\n\n", 163);
	printf("1 - MODIFICAR NOMBRE\n");
	printf("2 - MODIFICAR APEELIDO\n");
	printf("3 - MODIFICAR PRECIO\n");
	printf("4 - MODIFICAR TIPO DE PASAJERO\n");
	printf("5 - MODIFICAR C�DIGO DE VUELO\n");
	printf("6 - SALIR\n");
	printf(">>>>");

	fflush(stdin);
	scanf("%c", &opcion);

	while(opcion < '1' || opcion > '6'){
		printf("Por favor, ingrese un valor dentro de las opciones (1 a 6). Reigrese\n>>>>");
		fflush(stdin);
		scanf("%c", &opcion);
	}
	return opcion;
}


/*
/// \param void solo imprime por pantalla cuando es invocada
/// \brief imprime por consola el subMenu de informes de la aplicaci�n
/// \return retorna un valor char con valores del '1' al '4'
*/
char SubMenuInformar(){
	char opcion;

	printf("\nMen%c Informe:\n\n", 163);
	printf("1 - Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.\n");
	printf("2 - Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio promedio.\n");
	printf("3 - Listado de los pasajeros por C�digo de vuelo y estados de vuelos ACTIVO\n");
	printf("4 - SALIR\n");
	printf(">>>>");

	fflush(stdin);
	scanf("%c", &opcion);

	while(opcion < '1' || opcion > '4'){
		printf("Por favor, ingrese un valor dentro de las opciones (1 a 4). Reigrese\n>>>>");
		fflush(stdin);
		scanf("%c", &opcion);
	}
	return opcion;
}
