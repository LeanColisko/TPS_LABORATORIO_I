/*
 * Pasajeros.h
 *
 *  Created on: 23 abr. 2022
 *      Author: lcolisko
 */

#ifndef PASAJEROS_H_
#define PASAJEROS_H_

typedef struct{
	int typePassenger;
	char description[51];
} eTypePassenger;

typedef struct{
	int statusFlight;
	char statusDescription[51];
} eStatusFlight;


typedef struct
{	// Campos en la estructura de datos: ArrayPassanger
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} ePassenger;


/// \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
/// \param list Passenger* Pointer to array of passenger
/// \param len int Array length
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initPassengers(ePassenger* list, int LEN);


/// \brief add in a existing list of passengers the values received as parameters in the first empty position
/// \param list passenger*
/// \param len int
/// \param id int
/// \param name[] char
/// \param lastName[] char
/// \param price float
/// \param typePassenger int
/// \param flycode[] char
/// \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int addPassenger(ePassenger* list, int index, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);

/// \param id codigo de identificacion del usuario a modificar
/// \param eTypePassenger array del tipo de pasajero
/// \param lenTipoPasajero len del array tipo de pasajero
/// \brief pide al usuario los datos necesarios para cargar un pasajero
/// \return auxiliarPasenger
ePassenger askPassengerData(int id, eTypePassenger* TipoPasajero, int lenTipoPasajero);


/// \brief
/// \return index
int findPassengerIndex(ePassenger* list, int len);


/*
* \brief Remove a Passenger by Id (put isEmpty Flag in 1)
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
* Ejemplo uso:
* r = removePassenger(arrayPassengers, ELEMENTS, 20);
*/
int removePassenger(ePassenger* list, int len, int id);


/*
* \brief find a Passenger by Id en returns the index position in array.
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*/
int findPassengerById(ePassenger* list, int len,int id);


/// \param puntero de eTypePassenger
/// \param len largo del array de eTypePassenger
/// \brief imprime una tabla con los tipos de pasajeros disponibles
/// \return una entero con 1 si la función se ejecutó correctamente
int printTipoPasajero(eTypePassenger* list, int len);


/// \param puntero de ePassenger
/// \param len del array Passenger
/// \param index indice del album a modificar
/// \param puntero de eTipoPasajero
/// \param lenTipoAlbum del array de LenTipoPasajero
/// \brief modifica los datos de un PASAJERO cargado
/// \return un entero 1 en caso de que se ejecute correctamente
int changePassengerData(ePassenger* list, int len, int index, eTypePassenger* TipoPasajero, int lenTipoPasajero);


/// \param puntero de ePassenger
/// \param len: largo del array ePassenger
/// \param puntero de eTypePassenger
/// \param lenTipoPasajero del array de tipo de pasajero
/// \brief imprime por pantalla una tabla con todos los pasajeros cargados
/// \return un entero -1 para error  0 para OK
int printPassenger(ePassenger* list, int len, eTypePassenger* tipoPasajero, int lenTipoPasajero, eStatusFlight* status, int lenStatus);



int sortPassenger(ePassenger* list, int len);

/*
/// \param puntero de ePassenger
/// \param len del array Passenger
/// \param index indice del pasajero modificar
/// \param puntero de eTipoPasajero
/// \param lenTipoPasajero del array de LenTipoPasajero
/// \brief imprime los informes de acuerdo a la elección del usuario
/// \return un entero 1 en caso de que se ejecute correctamente
 */
int printsInformes(ePassenger* list, int len, eTypePassenger* TipoPasajero, int lenTipoPasajero, eStatusFlight* status, int lenStatus);

#endif /* PASAJEROS_H_ */
