/*
 * ShowData.c
 *
 *  Created on: 6 Apr 2022
 *      Author: Julian
 */

#include "ShowData.h"

void MainMenuInterface(float kilometers, float aerolineasPrice, float latamPrice) {
	printf("\n ------------ Menú principal ------------ \n");
	printf("\n 1. Ingresar Kilómetros: ( km: %.2f )", kilometers);
	printf("\n 2. Ingresar precio de Vuelos");
	printf("\n - Precio vuelo Aerolíneas Argentinas: %f", aerolineasPrice);
	printf("\n - Precio vuelo latam: %f", latamPrice);
	printf("\n 3. Calcular todos los costos");
	printf("\n 4. Informar resultados");
	printf("\n 5. Carga forzada");
	printf("\n 6. Salir");
}

void SubMenuInterface(float aerolineasPrice, float latamPrice) {
	printf("\n a. Ingresar vuelo aerolineas: %f \n", aerolineasPrice);
	printf(" b. Ingresar vuelo latam: %f \n", latamPrice);
	printf(" s. Volver a menú principal: \n ");
}

void ShowEveryCalculation(float kilometers,float latamPrice,float aerolineasPrice,
		float debitCardLatam,float debitCardAerolineas,float creditCardLatam,
		float creditCardAerolineas,float unitPriceLatam,float unitPriceAerolineas,
		float priceDiference,float bitcoinLatam,float bitcoinAerolineas) {
	printf("\n Kilometros ingresados: %f", kilometers);
	printf("\n -------- LATAM -------- \n");
	printf("\n Precio LATAM: %f", latamPrice);
	printf("\n a) Precio con tarjeta de debito: %f", debitCardLatam);
	printf("\n b) P: %f", creditCardLatam);
	printf("\n c) Precio pagando con bitcoin: %f", bitcoinLatam);
	printf("\n d) Precio unitario: %f", unitPriceLatam);
	printf("\n \n -------- Aerolineas Argentinas -------- \n");
	printf("\n Precio Aerolineas: %f", aerolineasPrice);
	printf("\n a) Precio con tarjeta de debito: %f", debitCardAerolineas);
	printf("\n b) Precio con tarjeta de credito: %f", creditCardAerolineas);
	printf("\n c) Precio pagando con bitcoin: %f", bitcoinAerolineas);
	printf("\n d) Precio unitario: %f", unitPriceAerolineas);
	printf("\n \n La diferencia de precio es de: %f", priceDiference);
}
