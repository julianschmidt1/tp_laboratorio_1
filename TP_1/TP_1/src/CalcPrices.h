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

float GetDebitCardPrice(float rawPrice, float percentage);
float GetCreditCardPrice(float rawPrice, float percentage);
float CalculateBitcoinToARS(float valueARS);
void CalculateEveryPrice(float *kilometers, float *latamPrice,
		float *aerolineasPrice, float *debitCardLatam,
		float *debitCardAerolineas, float *creditCardLatam,
		float *creditCardAerolineas, float *unitPriceLatam,
		float *unitPriceAerolineas, float *priceDiference, float *bitcoinLatam,
		float *bitcoinAerolineas);

#endif /* CALCPRICES_H_ */
