/*
 * Inputs.h
 *
 *  Created on: 2 Apr 2022
 *      Author: Julian
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>

int getIntGroso(char mensaje[], int reintentos, int minimo, int maximo,
		char mensajeError[], int *pNumeroIngresado);
char getChar(char *message);

int getFloat(char message[], char messageError[], float *pValue, float max, float min);
int getInt(char message[], char messageError[], int *pValue, int max, int min);

#endif /* INPUTS_H_ */
