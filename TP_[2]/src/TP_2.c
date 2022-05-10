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
#define LEN_TIPO_P 3
#define LEN_STATUS 3


int main(void) {

	char opcion, banderaSalir;
	int auxIndex, idAux;
	int cantidadPasajeros = 0;
	int auxPaxToRemove;
	int resultadoAux, respuestaAdd;
	int idAutoincremental = 1;
	ePassenger Pasajeros[LEN], auxPasanger;
	eTypePassenger TipoPasajeros[LEN_TIPO_P] = {{1, "Turista"}, { 2, "Business"}, {3, "First class"}};
	eStatusFlight StatusReserva[LEN_STATUS] = {{1, "ACTIVO"}, { 2, "CHECK-IN"}, {3, "CANCELLED"}};

	auxIndex = -1;
	respuestaAdd = -1;

	banderaSalir = 'N';

	setbuf(stdout, NULL);

	initPassengers(Pasajeros, LEN);

	do {
		opcion = MenuPrincipal();

		switch(opcion){
			case '1':

				auxIndex = findPassengerIndex(Pasajeros, LEN);

				if( auxIndex > -1 ){
					auxPasanger = askPassengerData(idAutoincremental, TipoPasajeros, LEN_TIPO_P);
					respuestaAdd = addPassenger(Pasajeros, auxIndex, auxPasanger.id, auxPasanger.name, auxPasanger.lastName, auxPasanger.price, auxPasanger.typePassenger, auxPasanger.flycode);

					if(respuestaAdd == 0){
						cantidadPasajeros++;
						idAutoincremental++;
						printf("Pasajero agregado correctamente.\n");
						respuestaAdd = -1;
					}
					auxIndex = -1;
				} else {
					printf("La base de datos está completa.\n");
				}
				break;
			case '2':
				printf("Opcion de Modificación\n");
				if(cantidadPasajeros > 0){

					getIntByConsola(&idAux, "Ingrese el id del pasajero que desea modificar", "Error: dato no válido, reintente", 1, 1000000, 5);
					auxIndex = findPassengerById(Pasajeros, LEN, idAux);
					if(auxIndex > -1){
						changePassengerData(Pasajeros, LEN, auxIndex, TipoPasajeros, LEN_TIPO_P);
					} else {
						printf("No hemos encontrado el código ingresado\n");
					}
					auxIndex = -1;


				} else{
					printf("Necesita ingresar un pasajero\n");
				}

			break;
			case '3':
				printf("Opcion de baja");
				if(cantidadPasajeros > 0){

					getIntByConsola(&auxPaxToRemove, "Ingrese el id del pasajero a borrar:", "Error: debe ingresar un número entero mayor a 0", 0, 100000, 5);
					resultadoAux = removePassenger(Pasajeros, LEN, auxPaxToRemove);
					if(resultadoAux == 0 ){
						printf("El pasajero fue borrado correctamente\n");
					} else{
						printf("Error no pudimos borrar el pasajero, revise el id.\n");
					}

				} else {
					printf("Necesita ingresar un pasajero\n");
				}

			break;
			case '4':
				printf("Opcion de imprimir informe");
				if(cantidadPasajeros > 0){

					printsInformes(Pasajeros, LEN, TipoPasajeros, LEN_TIPO_P, StatusReserva, LEN_STATUS);

				} else {
					printf("Necesita ingresar un pasajero\n");
				}
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
