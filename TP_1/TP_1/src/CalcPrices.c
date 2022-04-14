/*
 * CalcPrices.c
 *
 *  Created on: 3 Apr 2022
 *      Author: Julian
 */

#include "CalcPrices.h"
#include "MathOperations.h"

float GetDebitCardPrice(float rawPrice, float percentage) {
	float finalPrice;
	float valueToDiscount = CalculateValuePercentage(rawPrice, percentage);
	finalPrice = Substract(rawPrice, valueToDiscount);

	return finalPrice;
}

float GetCreditCardPrice(float rawPrice, float percentage) {
	float finalPrice;
	float valueToIncrement = CalculateValuePercentage(rawPrice, percentage);
	finalPrice = Add(rawPrice, valueToIncrement);

	return finalPrice;
}

float CalculateBitcoinToARS(float valueARS) {
	float finalPrice;
	finalPrice = Divide(valueARS, BITCOIN_ARS_VALUE);
	return finalPrice;
}

void CalculateEveryPrice(float *kilometers, float *latamPrice,
		float *aerolineasPrice, float *debitCardLatam,
		float *debitCardAerolineas, float *creditCardLatam,
		float *creditCardAerolineas, float *unitPriceLatam,
		float *unitPriceAerolineas, float *priceDiference, float *bitcoinLatam,
		float *bitcoinAerolineas) {

	*debitCardLatam = GetDebitCardPrice(*latamPrice, DISCOUNT_PERCENTAGE);
	*debitCardAerolineas = GetDebitCardPrice(*aerolineasPrice,
	DISCOUNT_PERCENTAGE);
	*creditCardLatam = GetCreditCardPrice(*latamPrice, INCREMENT_PERCENTAGE);
	*creditCardAerolineas = GetCreditCardPrice(*aerolineasPrice,
	INCREMENT_PERCENTAGE);

	*unitPriceLatam = Divide(*latamPrice, *kilometers);
	*unitPriceAerolineas = Divide(*aerolineasPrice, *kilometers);
	*priceDiference = Substract(*latamPrice, *aerolineasPrice);

	*bitcoinLatam = CalculateBitcoinToARS(*latamPrice);
	*bitcoinAerolineas = CalculateBitcoinToARS(*aerolineasPrice);

}
