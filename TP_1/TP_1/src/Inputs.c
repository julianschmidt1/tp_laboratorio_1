/*
 * Inputs.c
 *
 *  Created on: 2 Apr 2022
 *      Author: Julian
 */

#include "Inputs.h"

int getFloat(char message[], char messageError[], float *pValue, float max, float min) {
	int funcReturn = -1;
	int bufferFloat;
	int scanfReturn;
	if (message != NULL && min < max && messageError != NULL
			&& pValue != NULL) {
		printf("%s", message);
		scanfReturn = scanf("%d", &bufferFloat);
	}

	if(scanfReturn != 1 || bufferFloat > max || bufferFloat < min) {
		printf("%s", messageError);
	} else {
		*pValue = bufferFloat;
		funcReturn = 0;
	}

	return funcReturn;
}

char getChar(char *message) {
	char option;
	printf("%s", message);
	scanf("%c", &option);
	fflush(stdin); //Windows
	//__fpurge(stdin); //Linux
	return option;
}

int getIntGroso(char mensaje[], int reintentos, int minimo, int maximo,
		char mensajeError[], int *pNumeroIngresado) {
	int retorno = -1;
	int auxInt;
	int retornoScanf;
	if (mensaje != NULL && minimo < maximo && mensajeError != NULL
			&& pNumeroIngresado != NULL && reintentos > 0) {
		printf("%s", mensaje);
		retornoScanf = scanf("%d", &auxInt);

		do {
			if (retornoScanf != 1 || auxInt > maximo || auxInt < minimo) {
				printf("%s", mensajeError);
				retornoScanf = scanf("%d", &auxInt);
				reintentos--;
			} else {
				reintentos = 0;
				*pNumeroIngresado = auxInt;
				retorno = 0;
			}
		} while (reintentos > 0);
	}
	return retorno;
}

int getInt(char message[], char messageError[], int *pValue, int max, int min) {
	int funcReturn = -1;
	int bufferInt;
	int scanfReturn;
	if (message != NULL && min < max && messageError != NULL
			&& pValue != NULL) {
		printf("%s", message);
		scanfReturn = scanf("%d", &bufferInt);
	}

	if(scanfReturn != 1 || bufferInt > max || bufferInt < min) {
		printf("%s", messageError);
		//scanfReturn = scanf("%d", &bufferInt);
	} else {
		*pValue = bufferInt;
		funcReturn = 0;
	}


	return funcReturn;
}

