/*
 * Menu.h
 *
 *  Created on: 9 Apr 2022
 *      Author: Julian
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "ShowData.h"
#include "Inputs.h"

/**
 * @fn void SubMenu(float*, float*)
 * @brief Funcion que muestra al usuario un submenu, recibe x params los punteros hacia los precios originales
 *
 * @pre
 * @post
 * @param aerolineasPrice
 * @param latanPrice
 */
void SubMenu(float *aerolineasPrice, float *latamPrice);

#endif /* MENU_H_ */
