/*
 ============================================================================
 Name        : TP_2.c
 Author      : Julián Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "ArrayPassenger.h"

#define MAX_PASSENGERS 2000

int main(void) {
	setbuf(stdout, NULL);
	int option;

	int userID;
	char name[MAX_CHARS_NAME];
	char lastName[MAX_CHARS_NAME];
	float price;
	char flycode[MAX_CHARS_CODE];
	int typePassenger;
	int statusFlight;


	Passenger passenger[MAX_PASSENGERS];

	int startUp = initPassengers(passenger, MAX_PASSENGERS);
	if (startUp == -1) {
		printf("Ocurrio un error al ejecutar el programa.");
		return 0;
	}

	fflush(stdin); //Windows
	do {
		printf("\n 1. ALTAS \n"
				"2. MODIFICAR \n"
				"3. BAJA \n"
				"4. INFORMAR \n"
				"5. CARGA FORZADA \n"
				"0. SALIR \n");

		utn_getNumero(&option, "Ingrese la opcion: ", "\n Opción no valida \n",
				0, 10, 90000);

		switch (option) {
		case 1:
			cargarDatos(name, lastName, &price, &typePassenger, flycode,
					&userID, &statusFlight);
			userID = Passenger_ObtenerID();
			addPassengers(passenger, MAX_PASSENGERS, userID, name, lastName,
					price, typePassenger, flycode, statusFlight);
			break;
		case 2:
			Passenger_Modificacion(passenger, MAX_PASSENGERS);
			break;
		case 3:
			cargarBaja(passenger, MAX_PASSENGERS);
			break;
		case 4:
			ShowData(passenger, MAX_PASSENGERS);
			break;
		case 5:
			for (int i = 0; i < 10; i++) {
				userID = Passenger_ObtenerID();
				addPassengers(passenger, MAX_PASSENGERS, userID, "TEST", "USER",
						69420, i, "ASDQWE", 1);
			}
			break;
		case 0:
			printf("\n -- Adios -- \n");
			break;
		}
	} while (option != 0);

	return 1;
}
