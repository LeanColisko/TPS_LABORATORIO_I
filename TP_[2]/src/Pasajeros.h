/*
 * Pasajeros.h
 *
 *  Created on: 23 abr. 2022
 *      Author: lcolisko
 */

#ifndef PASAJEROS_H_
#define PASAJEROS_H_

typedef struct
{	// Campos en la estructura de datos: ArrayPassanger
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
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
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[], float price, int typePassenger, char flycode[]);

/// \brief
/// \return auxiliarPasenger
ePassenger askPassengerData(int id);

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
* r = removePassenger(arrayPassengers, ELEMENTS,20);
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

#endif /* PASAJEROS_H_ */
