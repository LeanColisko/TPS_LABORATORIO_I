/*
 ============================================================================
 Name	: TP_2.c
 Author	: Leandro Colisko, Division F
 Date	: April 2022
 ============================================================================
 */

#include "funciones.h"
#include "Pasajeros.h"
#include "appFunciones.h"

#define LEN 2000

int main(void) {

	char opcion, banderaSalir;
	int auxIndex = -1;
	int cantidadPasajeros = 0;
	int auxPaxToRemove;
	ePassenger Pasajeros[LEN], auxPasanger;

	banderaSalir = 'N';

	setbuf(stdout, NULL);

	initPassengers(Pasajeros, LEN);

	do {
		opcion = MenuPrincipal();

		switch(opcion){
			case '1':
				// Completar los datos del pasajero
				auxIndex = findPassengerIndex(Pasajeros, LEN);
				if( auxIndex != -1 ){
					auxPasanger = askPassengerData(auxIndex);
					addPassenger(Pasajeros, LEN, auxPasanger.id, auxPasanger.name, auxPasanger.lastName, auxPasanger.price, auxPasanger.typePassenger, auxPasanger.flycode);
					cantidadPasajeros++;
				} else {
					printf("La base de datos está completa.\n");
				}
				break;
			case '2':

				printf("Opcion de Modificacion\n");
				if(cantidadPasajeros>=1){
					for (int i = 0; i <LEN; i++){
						if( Pasajeros[i].isEmpty == 0 )
						{
							printf("%5d\t%s\t%s\t%10.5f\n", Pasajeros[i].id,	Pasajeros[i].name, Pasajeros[i].lastName, Pasajeros[i].price);
						}
					}
				} else{
					printf("Necesita ingresar un pasajero\n");
				}

			break;
			case '3':
				printf("Opcion de baja");
				if(cantidadPasajeros>=1) {
					getIntByConsola(&auxPaxToRemove, "Ingrese el id del pasajero a borrar:", "Error: debe ingresar un número entero mayor a 0", 0, 100000, 5);
					removePassenger(Pasajeros, LEN, auxPaxToRemove);
				} else {
					printf("Necesita ingresar un pasajero\n");
				}
			break;
			case '4':
				printf("Opcion de imprimir informe");
			break;
			case '5':
				do {
					printf("%cEst%c seguro/a que desar salir del programa%c (S/N)\n>>>>", 168, 160, 63);
					fflush(stdin);
					scanf("%c", &banderaSalir);
					banderaSalir = toupper(banderaSalir);
				} while(banderaSalir !='S' && banderaSalir !='N');

			break;
		}
	} while(banderaSalir != 'S');

}
