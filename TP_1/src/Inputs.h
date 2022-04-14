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

/**
 * @fn char getChar(char*)
 * @brief Funcion que solicita a el usuario un char
 *
 * @pre
 * @post
 * @param message
 * @return retorna el char solicitado
 */
char getChar(char *message);

/**
 * @fn int getFloat(char[], char[], float*, float, float)
 * @brief Funcion que solicita un flotante, valida maximo, minimo, mensajes vacios
 * @param message
 * @param messageError
 * @param pValue
 * @param max
 * @param min
 * @return retorna -1 si todo mal o 0 todo bien
 */
int getFloat(char message[], char messageError[], float *pValue, float max, float min);

/**
 * @fn int getInt(char[], char[], int*, int, int)
 * @brief Funcion que solicita un entero, valida maximo, minimo, mensajes vacios
 * @param message
 * @param messageError
 * @param pValue
 * @param max
 * @param min
 * @return retorna -1 si todo mal o 0 todo bien
 */
int getInt(char message[], char messageError[], int *pValue, int max, int min);

#endif /* INPUTS_H_ */
