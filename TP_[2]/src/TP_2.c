/*
 ============================================================================
 Name	: TP_2.c
 Author	: Leandro Colisko, Division F
 Date	: April 2022
 ============================================================================
 */

#include "funciones.h"
#include "Pasajeros.h"

#define LEN 2000

int main(void) {

	char opcion, banderaSalir;

	ePassenger Pasajeros[LEN];


	banderaSalir = 'N';

	setbuf(stdout, NULL);

	initPassengers(Pasajeros, LEN);

	do {
		opcion = MenuPrincipal();

		switch(opcion){
			case '1':
				printf("Opcion de alta");
				//r = addPassenger(Pasajeros, LEN, Pasajeros.id, Pasajeros.name[51], Pasajeros.lastName[51], Pasajeros.price, Pasajeros.typePassenger, Pasajeros.flycode[10]);

				break;
			case '2':
				printf("Opcion de Modificacion");
			break;
			case '3':
				printf("Opcion de baja");
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
