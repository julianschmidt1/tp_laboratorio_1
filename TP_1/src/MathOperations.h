/*
 * operaciones.h
 *
 *  Created on: 2 Apr 2022
 *      Author: Julian
 */

#ifndef MATHOPERATIONS_H_
#define MATHOPERATIONS_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn float Add(float, float)
 * @brief Suma dos valores
 *
 * @pre
 * @post
 * @param firstNumber
 * @param secondNumber
 * @return retorna suma
 */
float Add(float firstNumber, float secondNumber);

/**
 * @fn float Substract(float, float)
 * @brief Resta dos valores
 *
 * @pre
 * @post
 * @param firstNumber
 * @param secondNumber
 * @return retorna diferencia
 */
float Substract(float firstNumber, float secondNumber);

/**
 * @fn float Multiply(float, float)
 * @brief Multiplica dos valores
 *
 * @pre
 * @post
 * @param firstNumber
 * @param secondNumber
 * @return retorna producto
 */
float Multiply(float firstNumber, float secondNumber);

/**
 * @fn float Divide(float, float)
 * @brief Divide dis valores
 *
 * @pre
 * @post
 * @param firstNumber
 * @param secondNumber
 * @return retorna division
 */
float Divide(float firstNumber, float secondNumber);

/**
 * @fn float CalculateValuePercentage(float, float)
 * @brief Calcula el porcentaje de un valor
 *
 * @pre
 * @post
 * @param value
 * @param percentage
 * @return retorna valor
 */
float CalculateValuePercentage(float value, float percentage);

#endif /* MATHOPERATIONS_H_ */
