#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "CalcPrices.h"
#include "ShowData.h"
#include "Menu.h"

void MainMenu();

int main(void) {
	setbuf(stdout, NULL);

	MainMenu();
}

void MainMenu() {
	float kilometers = 0;
	float aerolineasPrice = 0;
	float latamPrice = 0;
	float debitCardLatam;
	float creditCardLatam;
	float unitPriceLatam;
	float bitcoinLatam;

	float debitCardAerolineas;
	float creditCardAerolineas;
	float unitPriceAerolineas;
	float priceDiference;
	float bitcoinAerolineas;

	int selectedNumberOption;
	int hasCalculatedFlag = -1;

	do {
		MainMenuInterface(kilometers, aerolineasPrice, latamPrice);

		getInt("\n Ingresa la opción: ", "\n Opción ingresada no válida",
				&selectedNumberOption, 6, 1);

		switch (selectedNumberOption) {
		case 1:
			getFloat("\n Ingresar kilometraje: ", "\n Kilometraje inválido",
					&kilometers, 40000, 1);
			break;
		case 2:
			SubMenu(&aerolineasPrice, &latamPrice);
			break;
		case 3:
			if (kilometers > 1 && latamPrice > 1 && aerolineasPrice > 1) {
				CalculateEveryPrice(&kilometers, &latamPrice, &aerolineasPrice,
						&debitCardLatam, &debitCardAerolineas, &creditCardLatam,
						&creditCardAerolineas, &unitPriceLatam,
						&unitPriceAerolineas, &priceDiference, &bitcoinLatam,
						&bitcoinAerolineas);
				hasCalculatedFlag = 1;
			} else {
				printf(
						"\n *-*-*-* Es necesario ingresar valores antes de calcularlos *-*-*-* \n");
			}
			break;
		case 4:
			if (hasCalculatedFlag == 1) {
				ShowEveryCalculation(kilometers, latamPrice, aerolineasPrice,
						debitCardLatam, debitCardAerolineas, creditCardLatam,
						creditCardAerolineas, unitPriceLatam,
						unitPriceAerolineas, priceDiference, bitcoinLatam,
						bitcoinAerolineas);
			} else {
				printf(
						"\n *-*-*-* Es necesario calcular valores antes de mostrarlos *-*-*-*\n ");
			}
			break;
		case 5:
			kilometers = 7090;
			aerolineasPrice = 162965;
			latamPrice = 159339;
			CalculateEveryPrice(&kilometers, &latamPrice, &aerolineasPrice,
					&debitCardLatam, &debitCardAerolineas, &creditCardLatam,
					&creditCardAerolineas, &unitPriceLatam,
					&unitPriceAerolineas, &priceDiference, &bitcoinLatam,
					&bitcoinAerolineas);
			ShowEveryCalculation(kilometers, latamPrice, aerolineasPrice,
					debitCardLatam, debitCardAerolineas, creditCardLatam,
					creditCardAerolineas, unitPriceLatam, unitPriceAerolineas,
					priceDiference, bitcoinLatam, bitcoinAerolineas);
			break;
		case 6:
			printf("\n Cerrando sesión ...");
			break;
		}
		fflush(stdin); //Windows
	} while ((selectedNumberOption != 6));
}
