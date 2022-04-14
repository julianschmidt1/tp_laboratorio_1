/*
 * CalcPrices.h
 *
 *  Created on: 3 Apr 2022
 *      Author: Julian
 */

#ifndef CALCPRICES_H_
#define CALCPRICES_H_

#define DISCOUNT_PERCENTAGE 10
#define INCREMENT_PERCENTAGE 25
#define BITCOIN_ARS_VALUE 4606954.55

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn float GetDebitCardPrice(float, float)
 * @brief Esta función calcula el preciode la tarjeta de debito, en este caso reduciendo el valor original un 10%
 *
 * @param rawPrice
 * @param percentage
 * @return
 */
float GetDebitCardPrice(float rawPrice, float percentage);

/**
 * @fn float GetCreditCardPrice(float, float)
 * @brief Esta función calcula el precio con tarjeta de credito, en este caso agregando el 25% del valor original
 *
 * @param rawPrice
 * @param percentage
 * @return
 */
float GetCreditCardPrice(float rawPrice, float percentage);

/**
 * @fn float CalculateBitcoinToARS(float)
 * @brief Esta función calcula en bitcoin un monto en ARS
 *
 * @param valueARS
 * @return
 */
float CalculateBitcoinToARS(float valueARS);

/**
 * @fn void CalculateEveryPrice(float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*)
 * @brief Esta función hace todos los calculos de precio y los devuelve por puntero
 *
 * @param kilometers
 * @param latamPrice
 * @param aerolineasPrice
 * @param debitCardLatam
 * @param debitCardAerolineas
 * @param creditCardLatam
 * @param creditCardAerolineas
 * @param unitPriceLatam
 * @param unitPriceAerolineas
 * @param priceDiference
 * @param bitcoinLatam
 * @param bitcoinAerolineas
 */
void CalculateEveryPrice(float *kilometers, float *latamPrice,
		float *aerolineasPrice, float *debitCardLatam,
		float *debitCardAerolineas, float *creditCardLatam,
		float *creditCardAerolineas, float *unitPriceLatam,
		float *unitPriceAerolineas, float *priceDiference, float *bitcoinLatam,
		float *bitcoinAerolineas);

#endif /* CALCPRICES_H_ */
