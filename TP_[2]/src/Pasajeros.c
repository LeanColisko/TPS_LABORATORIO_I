/*
 * Pasajeros.c
 *
 *  Created on: 23 abr. 2022
 *      Author: lcolisko
 */

#include "funciones.h"
#include "appFunciones.h"
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


/*
* \brief busca un espacio libre en el array de pasajeros
* \param list passenger*
* \param len int
* \return int Return (-1) if Error [Retur index if Ok]
*/
int findPassengerIndex(ePassenger* list, int len)
{
	int index = -1;
	int i;
	if(list != NULL && len > 0) {

		for(i = 0; i < len; i++){
			if( list[i].isEmpty == 1) {
				index = i;
				break;
			}
		}

	}
	return index;
}


/*
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
int addPassenger(ePassenger* list, int index, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
	int retorno = -1;

	if( list != NULL && id > -1) {

		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price = price;
		list[index].typePassenger = typePassenger;
		strcpy(list[index].flycode, flycode);
		list[index].isEmpty = 0;
		list[index].statusFlight = 1;
		retorno = 0;
	}
	return retorno;
}

/*
/// \param id codigo de identificacion del usuario a modificar
/// \param eTypePassenger array del tipo de pasajero
/// \param lenTipoPasajero len del array tipo de pasajero
/// \brief pide al usuario los datos necesarios para cargar un pasajero
/// \return auxiliarPasenger
*/
ePassenger askPassengerData(int id, eTypePassenger* TipoPasajero, int lenTipoPasajero)
{
	ePassenger list;

	printf("Ingrese los datos del pasajero\nC%cdigo del pasajero registrado:%d\n\n", 162, id);

	list.id = id;

	getStringByConsola(list.name, "a - Ingrese el nombre del pasajero:", "Error: dato no válido, reintente", 51, 5);

	getStringByConsola(list.lastName, "b - Ingrese el apellido del pasajero:", "Error: dato no válido, reintente", 51, 5);

	getFloatByConsola(&list.price, "c - Ingrese el precio del vuelo:", "Error: dato no válido, reintente", 0, 1000000, 5);


	printf("d - Ingrese el tipo de pasajero: en base a la siguiente lista:\n");
	printTipoPasajero(TipoPasajero, lenTipoPasajero);
	getIntByConsola(&list.typePassenger, "", "Error: dato no válido, reintente", 1, 100, 5);

	getStringByConsola(list.flycode, "e - Ingrese el código del vuelo:", "Error: dato no válido, reintente", 11, 5);

	return list;
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

	if(index > -1 && list != NULL && id > -1){
		list[index].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}



/*
/// \param puntero de eTypePassenger
/// \param len largo del array de eTypePassenger
/// \brief imprime una tabla con los tipos de pasajeros disponibles
/// \return una entero con 1 si la función se ejecutó correctamente
 */
int printTipoPasajero(eTypePassenger* list, int len)
{
	int i, retorno;
	retorno = -1;

	if(list != NULL && len > 0){

		printf("Listado tipos de pasajeros:\n");
		printf("+---------------------------+\n");
		printf("| Código | Descripción      |\n");
		printf("+--------+------------------+\n");
		for(i = 0; i < len; i++) {
			printf("| %-6d | %-17s|\n", list[i].typePassenger, list[i].description);
		}
		retorno = 0;
	}
	return retorno;
}



/*
/// \param puntero de ePassenger
/// \param len del array Passenger
/// \param index indice del pasajero modificar
/// \param puntero de eTipoPasajero
/// \param lenTipoPasajero del array de LenTipoPasajero
/// \brief modifica los datos de un PASAJERO cargado
/// \return un entero 1 en caso de que se ejecute correctamente
 */
int changePassengerData(ePassenger* list, int len, int index, eTypePassenger* TipoPasajero, int lenTipoPasajero){

	int retorno;
	char opcion;
	char banderaSalir;
	banderaSalir = 'N';
	retorno = -1;

	if(list != NULL && len > 0 && index > -1){

		retorno = 0;
		do{

				opcion = SubMenuModificar();

				switch(opcion){
					case '1':
						printf("Nombre registrado: %s", list[index].name);
						getStringByConsola(list[index].name, "Ingrese el nuevo NOMBRE:", "Error: dato no válido, reintente", 51, 5);
					break;
					case '2':
						printf("Apellido registrado: %s", list[index].lastName);
						getStringByConsola(list[index].lastName, "Ingrese el nuevo APELLIDO:", "Error: dato no válido, reintente", 51, 5);
					break;
					case '3':
						printf("Precio actualmente registrado: %.2f", list[index].price);
						getFloatByConsola(&list[index].price, "Ingrese el nuevo precio del pasaje:", "Error: dato no válido, reintente", 0, 1000000, 5);
					break;
					case '4':
						printf("Código del tipo de pasajero registrado: %d\n", list[index].typePassenger);
						printf("Ingrese el nuevo código del tipo de pasajero basandose en la siguiente lista:\n");
						printTipoPasajero(TipoPasajero, lenTipoPasajero);
						getIntByConsola(&list[index].typePassenger, "", "Error: dato no válido, reintente", 1, 100, 5);
					break;
					case '5':
						printf("Código de vuelo registrado: %s", list[index].flycode);
						getStringByConsola(list[index].flycode, "Ingrese el nuevo código de vuelo:", "Error: dato no válido, reintente", 11, 5);
					break;
					case '6':
						do {
							printf("%cEst%c seguro/a que desar finalizar con las modificaciones%c (S/N)\n>>>>", 168, 160, 63);
							fflush(stdin);
							scanf("%c", &banderaSalir);
							banderaSalir = toupper(banderaSalir);
						} while(banderaSalir !='S' && banderaSalir !='N');

					break;
				}
			} while(banderaSalir != 'S');

	}
	return retorno;
}


/**
/// \param puntero de ePassenger
/// \param len: largo del array ePassenger
/// \param puntero de eTypePassenger
/// \param lenTipoPasajero del array de tipo de pasajero
/// \param puntero de eStatusFlight
/// \param lenStatus del array de tipo de pasajero
/// \brief imprime por pantalla una tabla con todos los pasajeros cargados
/// \return un entero -1 para error  0 para OK
 */
int printPassenger(ePassenger* list, int len, eTypePassenger* tipoPasajero, int lenTipoPasajero, eStatusFlight* status, int lenStatus)
{
	int i, j, k, retorno;
	retorno = -1;

	if(list != NULL && len > 0 && tipoPasajero != NULL && lenTipoPasajero > 0){
		retorno = 0;

		printf("+-----+--------------------+--------------------+------------+------------+--------------------+--------------------+\n");
		printf("| Id  |      Apellido      |       Nombre       |   Precio   |  Cod.Vuelo |  Tipo de Pasajero  |  Estado de Reserva |\n");
		printf("+-----+--------------------+--------------------+------------+------------+--------------------+--------------------+\n");
		for(i = 0; i < len; i++) {

			for(j = 0 ; j < lenTipoPasajero; j++){

				for(k = 0; k < lenStatus; k++){

					if(		list[i].isEmpty == 0 &&
							list[i].typePassenger == tipoPasajero[j].typePassenger
							&& list[i].statusFlight == status[k].statusFlight){

						printf("| %-3d | %-18s | %-18s | %10.2f | %-10s | %-18s | %-18s |\n", list[i].id,
								list[i].lastName, list[i].name, list[i].price, list[i].flycode,
								tipoPasajero[j].description, status[k].statusDescription);
						break;
					}
				}
			}
		}
		printf("+-----+--------------------+--------------------+------------+------------+--------------------+--------------------+\n");

	}
	return retorno;
}


/**
/// \param puntero de ePassenger
/// \param len: largo del array ePassenger
/// \brief ordena el Array de pasajero por apellido y código de pasajero ambos de forma ascendente.
/// \return un entero -1 para error  0 para OK
 */

int sortPassenger(ePassenger* list, int len){

	int i, j, retorno;
	ePassenger pasajerosOrdenado;
	retorno = -1;

	if(list != NULL && len > 0 ){
		retorno = 0;
		for(i = 0; i < len-1; i++) {

			for(j = 1; j < len; j++)

				if( list[i].isEmpty == 0 &&
						(strcmp(list[i].lastName, list[j].lastName) < 1 ||
						(strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].typePassenger > list[j].typePassenger)
						)) {
					pasajerosOrdenado = list[i];
					list[i] = list[j];
					list[j] = pasajerosOrdenado;
				}


		}
	}
	return retorno;
}





/*
/// \param puntero de ePassenger
/// \param len del array Passenger
/// \param index indice del pasajero modificar
/// \param puntero de eTipoPasajero
/// \param lenTipoPasajero del array de LenTipoPasajero
/// \param puntero de eStatusFlight
/// \param lenStatus del array de tipo de pasajero
/// \brief imprime los informes de acuerdo a la elección del usuario
/// \return un entero 1 en caso de que se ejecute correctamente
 */
int printsInformes(ePassenger* list, int len, eTypePassenger* TipoPasajero, int lenTipoPasajero, eStatusFlight* status, int lenStatus)
{

	int retorno;
	char opcion;
	char banderaSalir;
	banderaSalir = 'N';
	retorno = -1;



	if(list != NULL && len > 0){

		retorno = 0;
		do{

				opcion = SubMenuInformar();

				switch(opcion){
					case '1':
						sortPassenger(list, len);
						printPassenger(list, len, TipoPasajero, lenTipoPasajero, status, lenStatus);
					break;
					case '2':

					break;
					case '3':

					break;
					case '4':
						do {
							printf("%cEst%c seguro/a que desar salir del men%c de informes%c (S/N)\n>>>>", 168, 160, 163, 63);
							fflush(stdin);
							scanf("%c", &banderaSalir);
							banderaSalir = toupper(banderaSalir);
						} while(banderaSalir !='S' && banderaSalir !='N');

					break;
				}
			} while(banderaSalir != 'S');

	}
	return retorno;
}












