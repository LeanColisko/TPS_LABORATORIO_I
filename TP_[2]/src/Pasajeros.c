/*
 * Pasajeros.c
 *
 *  Created on: 23 abr. 2022
 *      Author: lcolisko
 */

#include "funciones.h"
#include "Pasajeros.h"

/**
* \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(ePassenger* list, int LEN)
{
	int i;
	int retorno = -1;
	if(list != NULL && LEN > 0)
	{
		for(i = 0; i < LEN; i++){
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
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
int addPassenger(ePassenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
	int index;
	int retorno = -1;

	if(&id > 0) {
		index = id - 1;
		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price = price;
		list[index].typePassenger = typePassenger;
		strcpy(list[index].flycode, flycode);
		list[index].isEmpty = 0;

		retorno = 0;
	}
	return retorno;
}


/**
* \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(ePassenger* list, int len,int id) {

	int index = -1;
	int i;
	if(list != NULL && len > 0 && id > 0)
	{
		for(i = 0; i < len; i++){
			if(list[i].id == id){
				index = i; // Devuelve el index del id buscado
				break;
			}
		}
	}
	return index;
}



/*
* \brief Remove a Passenger by Id (put isEmpty Flag in 1)
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
* Ejemplo uso:
* r = removePassenger(arrayPassengers, ELEMENTS,20);
*/
int removePassenger(ePassenger* list, int len, int id)
{
	int index;
	int retorno = -1;
	index = findPassengerById(list, len, id);

	if(index != 1){
		list[index].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}



int findPassengerIndex(ePassenger* list, int len)
{
	int index = -1;
	int i;
	for(i = 0; i < len; i++){
		if( list[i].isEmpty == 1) {
			index = i + 1;
			break;
		}
	}
	return index;
}

ePassenger askPassengerData(int id)
{
	ePassenger list;

	printf("Ingrese los datos del pasajero\nC%cdigo del pasajero registrado:%d\n\n", 162, id);

	list.id = id;

	getStringByConsola(list.name, "a - Ingrese el nombre del pasajero:", "Error: dato no válido, reintente", 51, 5);

	getStringByConsola(list.lastName, "b - Ingrese el apellido del pasajero:", "Error: dato no válido, reintente", 51, 5);

	getFloatByConsola(&list.price, "c - Ingrese el precio del vuelo:", "Error: dato no válido, reintente", 0, 1000000, 5);

	getIntByConsola(&list.typePassenger, "d - Ingrese el tipo de pasajero:", "Error: dato no válido, reintente", 0, 5, 5);

	getStringByConsola(list.flycode, "e - Ingrese el código del vuelo:", "Error: dato no válido, reintente", 10, 5);

	return list;
}


