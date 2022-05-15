/*
 * Passenger.h
 *
 *  Created on: 8 May 2022
 *      Author: Julian
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

#define MAX_CHARS_NAME 51
#define MAX_CHARS_CODE 10
#define LIBRE 0
#define BAJA 1
#define OCUPADO -1

#define ACTIVO 1
#define INACTIVO 2

#define ECONOMICO 1
#define MEDIO 2
#define ALTA 3

typedef struct {
	char name[MAX_CHARS_NAME];
	char lastName[MAX_CHARS_NAME];
	float price;
	char flycode[MAX_CHARS_CODE];
	int typePassenger;
	int statusFlight;

	int id;
	int isEmpty;
} Passenger;

/** INICIO CABECERAS DE FUNCION*/
int Passenger_ObtenerID(void);
int initPassengers(Passenger* list, int len);
int Passenger_ObtenerIndexLibre(Passenger array[], int TAM);
int findPassengerById(Passenger* list, int len, int id);
void Passenger_MostrarUno(Passenger Passenger);
int Passenger_MostrarTodos(Passenger array[], int TAM);

int cargarBaja(Passenger list[], int len);
int removePassenger(Passenger* list, int len, int id);

void ShowData(Passenger* list, int len);
void getAveragePrice(Passenger* list, int len, float *average, float *total, int *avgCount);

int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);

void cargarDatos(char* name, char* lastName, float *price, int *typePassenger, char* flycode, int *userID, int *statusFlight);
int addPassengers(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight);
Passenger Passenger_ModificarUno(Passenger Passenger);
int Passenger_Modificacion(Passenger array[], int TAM);


#endif /* ARRAYPASSENGER_H_ */
