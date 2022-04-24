/*
 * Pasajeros.c
 *
 *  Created on: 23 abr. 2022
 *      Author: lcolisko
 */

#include "funciones.h"
#include "Pasajeros.h"

/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(ePassenger* list, int LEN){

	int i;
	for(i = 0; i < LEN; i++){
		list[i].isEmpty = 1;
	}
	return 0;
}


/**
* \brief add in a existing list of passengers the values received as parameters in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addPassenger(ePassenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]) {

	int i;
	for(i = 0; i < len; i++){

		if( list[i].isEmpty == 1) {

			list[i].id = i + 1;

			printf("Ingrese los datos del pasajero\nC%cdigo del pasajero registrado %d\n\n", 162, list[i].id);
			printf("a - Ingrese el nombre del pasajero:\n>>>\n");
			fflush(stdin);
			scanf("%[^\n]", list[i].name);

			printf("b - Ingrese el apellido del pasajero\n>>>\n");
			fflush(stdin);
			scanf("%[^\n]", list[i].lastName);

			printf("c - Ingrese el precio del vuelo\n");
			list[i].price = ingresoFlotantesPositivos();


			printf("d - Ingrese el tipo de pasajero\n");
			list[i].typePassenger= ingresoEnterosPositivos();

			printf("e - Ingrese el c%cdigo del vuelo:\n>>>\n", 162);
			fflush(stdin);
			scanf("%[^\n]", list[i].flycode);

			list[i].isEmpty = 0;
			return 0;
		}

	}
	return -1;
}


