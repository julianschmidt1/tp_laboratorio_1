/*
 * operaciones.c
 *
 *  Created on: 2 Apr 2022
 *      Author: Julian
 */

#include "MathOperations.h"

float Add(float firstNumber, float secondNumber) {
	float result;
	result = firstNumber + secondNumber;
	return result;
}

float Substract(float firstNumber, float secondNumber){
	float result;
	result = firstNumber - secondNumber;
	return result;
}

float Multiply(float firstNumber, float secondNumber){
	float result;
	result = firstNumber * secondNumber;
	return result;
}

float Divide(float firstNumber, float secondNumber) {
	float result;
	if(secondNumber != 0) {
		result = firstNumber / secondNumber;
		return result;
	} else {
		return 0;
	}
}

float CalculateValuePercentage(float value, float percentage) {
	float result;
	result = (value * percentage) / 100;
	return result;
}
