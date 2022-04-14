/*
 * ShowData.h
 *
 *  Created on: 6 Apr 2022
 *      Author: Julian
 */

#ifndef SHOWDATA_H_
#define SHOWDATA_H_

#include <stdio.h>
#include <stdlib.h>

void MainMenuInterface(float kilometers, float aerolineasPrice, float latamPrice);

void SubMenuInterface(float aerolineasPrice, float latamPrice);

void ShowEveryCalculation(float kilometers, float latamPrice,
		float aerolineasPrice, float debitCardLatam, float debitCardAerolineas,
		float creditCardLatam, float creditCardAerolineas,float unitPriceLatam,
		float unitPriceAerolineas, float priceDiference, float bitcoinLatam,
		float bitcoinAerolineas);

#endif /* SHOWDATA_H_ */
