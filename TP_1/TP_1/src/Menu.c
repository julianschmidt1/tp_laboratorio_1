/*
 * Menu.c
 *
 *  Created on: 9 Apr 2022
 *      Author: Julian
 */

#include "Menu.h"

void SubMenu(float *aerolineasPrice, float *latamPrice) {
	char selectedOption;

	do {

		SubMenuInterface(*aerolineasPrice, *latamPrice);
		selectedOption = getChar("\n Ingrese la opción: ");
		switch (selectedOption) {
		case 'a':
			getFloat("Ingrese el precio de aerolineas: ",
					"Precio ingresado invalido", &*aerolineasPrice, 1000000, 1);
			break;
		case 'b':
			getFloat("Ingrese el precio de LATAM: ",
					"Precio ingresado invalido", &*latamPrice, 1000000, 1);
			break;
		}
		//fflush(stdin); //Windows
	} while (selectedOption != 's');
}
