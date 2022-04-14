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

/**
 * @fn void MainMenuInterface(float, float, float)
 * @brief Muestra interfaz inicial del menu, recibe por params los valores a mostrar
 *
 * @pre
 * @post
 * @param kilometers
 * @param aerolineasPrice
 * @param latamPrice
 */
void MainMenuInterface(float kilometers, float aerolineasPrice, float latamPrice);

/**
 * @fn void SubMenuInterface(float, float)
 * @brief Muestra interfaz del submenu, recibe por params valores a mostrar
 *
 * @pre
 * @post
 * @param aerolineasPrice
 * @param latamPrice
 */
void SubMenuInterface(float aerolineasPrice, float latamPrice);

/**
 * @fn void ShowEveryCalculation(float, float, float, float, float, float, float, float, float, float, float, float)
 * @brief Muestra interfaz de resultados, recibe por params TODOS los resultados y los printea
 *
 * @pre
 * @post
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
void ShowEveryCalculation(float kilometers, float latamPrice,
		float aerolineasPrice, float debitCardLatam, float debitCardAerolineas,
		float creditCardLatam, float creditCardAerolineas,float unitPriceLatam,
		float unitPriceAerolineas, float priceDiference, float bitcoinLatam,
		float bitcoinAerolineas);

#endif /* SHOWDATA_H_ */
