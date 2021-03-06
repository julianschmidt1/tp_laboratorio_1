#include "ArrayPassenger.h"

/**
 * \brief Genera un id autoincremental
 * \return retorna el id
 *
 */
int Passenger_ObtenerID(void) {
	static int Passenger_idIncremental = 0;
	return Passenger_idIncremental++;
}

/**
 * \brief setea el campo isEmpty a LIBRE
 * \param Passenger list array de Passenger
 * \param len maximo tama?o de array se passengers
 * \return Retorna 0 si ok o -1 todo mal
 *
 */
int initPassengers(Passenger *list, int len) {
	int i;
	int rtn = -1;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && len > 0) {
		//RECORRO TODO EL ARRAY
		rtn = 0;
		for (i = 0; i < len; i++) {
			//SET ESTADO DE "LIBRE"
			list[i].isEmpty = LIBRE;
		}
	}

	return rtn;
}

/**
 * \brief Retorna pos del array con un isEmpty == LIBRE o -1 si no encuentra nada
 * \param Passenger array Array de Passenger
 * \param TAM len del array de passengers
 * \return pos del array si encuentra o -1 si no
 */
int Passenger_ObtenerIndexLibre(Passenger array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/**
 * \brief Devuelve pos del array del id q llega por parametros
 * \param Passenger list array de passenger
 * \param len tama?o de array
 * \return Retorna index de la posicion del id encontrado o -1 si nada
 */
int findPassengerById(Passenger *list, int len, int id) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == OCUPADO) {
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/**
 * \brief Recibe un passenger y lo printfea en pantalla
 * \param Passenger recibe un passenger
 */
void Passenger_MostrarUno(Passenger Passenger) {
	printf("\n\t> %d %s %s %f %d %s\n", Passenger.id, Passenger.name,
			Passenger.lastName, Passenger.price, Passenger.typePassenger,
			Passenger.flycode);
}

/**
 * \brief Funcion que itera el array que recibe y lo printfea en pantalla
 * \param Passenger list array de passenger
 * \param len tama?o de array
 * \return Retorna 1 si el array tiene datos cargados o 9 si nada
 */
int Passenger_MostrarTodos(Passenger array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (array != NULL && TAM > 0) {
		printf("\n\t> ID NOMBRE APELLIDO PRECIO TIPO CODIGO");
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				Passenger_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Permite al usuario la carga de datos inicialers
 * \param name puntero a la var name
 * \param lastName puntero a la var lastName
 * \param price puntero a la var price
 * \param typePassenger puntero a la var typePassenger
 * \param flycode puntero a la var flycode
 * \param userID puntero a la var userID
 * \param statusFlight puntero a la var statusFlight
 *  */
void cargarDatos(char *name, char *lastName, float *price, int *typePassenger,
		char *flycode, int *userID, int *statusFlight) {

	utn_getString("\nIngrese nombre de pasajero: ", "Nombre erroneo", 9999,
	MAX_CHARS_NAME, name);
	fflush(stdin);
	utn_getString("\nIngrese apellido de pasajero: ", "Apellido erroneo", 9999,
	MAX_CHARS_NAME, lastName);
	fflush(stdin);
	utn_getNumeroDecimal(&*price, "\nIngresa el precio del vuelo: ",
			"\nEl valor ingresado no es valido", 0, 10000000, 500);
	utn_getString("\nIngrese el codigo de vuelo: ", "Error en el codigo", 99999,
	MAX_CHARS_CODE, flycode);
	fflush(stdin);
	utn_getNumero(&*typePassenger,
			"\nIngrese el tipo de pasajero: (1. ECONOMICO / 2. MEDIO / 3. ALTA)",
			"Tipo ingresado invalido.", 1, 3, 5000);
	utn_getNumero(&*typePassenger,
			"\nIngrese el estado de vuelo (1. ACTIVO / 2. INACTIVO: ",
			"Estado ingresado invalido.", 1, 2, 5000);
}

/**
 * \brief Permite al usuario la carga de datos inicialers
 * \param Passenger array de passenger
 * \param name a la var name
 * \param lastName a la var lastName
 * \param price a la var price
 * \param typePassenger  a la var typePassenger
 * \param flycode a la var flycode
 * \param userID a la var userID
 * \param statusFlight a la var statusFlight
 * Return 1 si addeo bien el passenger y -1 si no
 *  */
int addPassengers(Passenger *list, int len, int id, char name[],
		char lastName[], float price, int typePassenger, char flycode[],
		int statusFlight) {
	int rtn = -1;

	Passenger auxPassenger;

	int index = Passenger_ObtenerIndexLibre(list, len);
	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1 && list != NULL) {

		strncpy(auxPassenger.name, name, MAX_CHARS_NAME);
		auxPassenger.id = id;
		strncpy(auxPassenger.lastName, lastName, MAX_CHARS_NAME);
		auxPassenger.price = price;
		auxPassenger.typePassenger = typePassenger;
		strncpy(auxPassenger.flycode, flycode, MAX_CHARS_CODE);
		auxPassenger.statusFlight = statusFlight;

		auxPassenger.isEmpty = OCUPADO;
		list[index] = auxPassenger;

		rtn = 1;
	}
	return rtn;
}

/**
 * \brief Menu que permite a el usuario seleccionar que campo de Passenger modificar
 * \param Passenger array de passenger
 * Return retorna el aux del passenger
 *  */
Passenger Passenger_ModificarUno(Passenger passenger) {
	int opc;
	Passenger auxiliar = passenger;

	do {
		printf("\n--- Modificaci?n de usuario ---\n");
		printf("\n1. Nombre"
				"\n2. Apellido"
				"\n3. Precio"
				"\n4. Tipo de pasajero"
				"\n5. Codigo de vuelo"
				"\n6. ESTADO DE VUELO"
				"\n7. Volver al men? principal");
		utn_getNumero(&opc, "\nIngrese la opcion: ", "\nOpcion erronea", 1, 6,
				99999);

		fflush(stdin);
		switch (opc) {
		case 1:
			utn_getString("\nIngrese nombre de pasajero: ", "Nombre erroneo",
					9999,
					MAX_CHARS_NAME, auxiliar.name);
			break;
		case 2:
			utn_getString("\nIngrese apellido de pasajero: ",
					"Apellido erroneo", 9999,
					MAX_CHARS_NAME, auxiliar.lastName);
			break;
		case 3:
			utn_getNumeroDecimal(&auxiliar.price,
					"\nIngresa el precio del vuelo: ",
					"\nEl valor ingresado no es valido", 0, 10000000, 500);
			break;
		case 4:
			utn_getNumero(&auxiliar.typePassenger,
					"\nIngrese el tipo de pasajero: ",
					"Tipo ingresado invalido.", 1, 3, 5000);
			break;
		case 5:
			utn_getString("\nIngrese el codigo de vuelo: ",
					"Error en el codigo", 99999,
					MAX_CHARS_CODE, auxiliar.flycode);
			break;
		case 6:
			utn_getNumero(&auxiliar.typePassenger,
					"\nIngrese el tipo de pasajero: (1. ACTIVO / 2. INACTIVO)",
					"Tipo ingresado invalido.", 1, 2, 5000);
			break;
		}

	} while (opc != 7);

	return auxiliar;
}

/**
 * \brief Permite al usuario la carga de datos inicialers
 * \param Passenger array de passenger
 * \param len tam del array
 * Return 1 si encontro el passenger y -1 si no
 *  */
int cargarBaja(Passenger list[], int len) {
	int rtn = -1;
	int idPassenger;
	int flag = 0;
	int confirm = -1;

	if (Passenger_MostrarTodos(list, len)) {
		//BANDERA EN 1 SI HAY Passenger DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idPassenger, "Ingrese ID a dar de baja",
				"Valor incorrecto", 0, len, 9999);

		while (findPassengerById(list, len, idPassenger) == -1) {
			puts("\n --- ID INEXISTENTE ---");

			utn_getNumero(&idPassenger, "Ingrese ID a dar de baja: ",
					"Valor incorrecto", 0, len, 99999);
		}

		utn_getNumero(&confirm,
				"\nEsta seguro que desea dar de baja? (1. SI - 2. NO)",
				"Opcion incorrecta", 1, 2, 9999);
		if (confirm == 1) {
			removePassenger(list, len, idPassenger);
		} else {
			rtn = -1;
		}
	}

	return rtn;
}

/**
 * \brief Cambia el isEmpty del pasajero encontrado por id
 * \param Passenger list array de passenger
 * \param len tama?o del array
 * \param id de usuario
 * Return retorna 0 si dio de baja el pasajero y -1 si no
 *  */
int removePassenger(Passenger *list, int len, int id) {
	int rtn = -1;
	int index;

	index = findPassengerById(list, len, id);
	if (index != -1) {
		list[index].isEmpty = BAJA;
		printf("\n ---- Usuario: %s %s dado de baja exitosamente ---- \n",
				list[index].name, list[index].lastName);
		rtn = 0;
	}

	return rtn;
}

/**
 * \brief Encuentra el id del usuario que sera modificado
 * \param Passenger list array de passenger
 * \param TAM tama?o del array
 * Return retorna 1 si modifico el pasajero y 0 si no
 *  */
int Passenger_Modificacion(Passenger array[], int TAM) {
	int rtn = 0;
	int idPassenger;
	int index;
	int flag = 0;
	Passenger auxiliar;

	if (Passenger_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Passenger DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Passenger PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		//printf("INGRESE ID A MODIFICAR: ");
		//scanf("%d", &idPassenger);
		utn_getNumero(&idPassenger, "Ingrese ID a modificar: ",
				"Valor incorrecto", 0, TAM, 99999);

		//BUSCO INDEX POR ID EN ARRAY
		while (findPassengerById(array, TAM, idPassenger) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			//printf("INGRESE ID A DAR DE BAJA: ");
			//scanf("%d", &idPassenger);
			utn_getNumero(&idPassenger, "Ingrese ID a modificar: ",
					"Valor incorrecto", 0, TAM, 99999);
		}

		//OBTENGO INDEX DEL ARRAY DE Passenger A MODIFICAR
		index = findPassengerById(array, TAM, idPassenger);

		//LLAMO A FUNCION QUE MODIFICA Passenger
		auxiliar = Passenger_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Funcion que calcula el precio total, promedio y contador de precios superiores al promedio
 * \param Passenger list array de passenger
 * \param len tama?o del array
 * \param average puntero a la var average
 * \param total puntero a la var total
 * \param avgCount puntero a la var avgCount
 *  */
void getAveragePrice(Passenger *list, int len, float *average, float *total,
		int *avgCount) {
	int i;

	// Obtenemos total
	for (i = 0; i < len; i++) {
		*total += list[i].price;
	}

	*average = (*total / i);
	for (i = 0; i < len; i++) {
		if (list[i].price > *average) {
			*avgCount = *avgCount + 1;
		}
	}
}

/**
 * \brief Ordena el array en el criterio definido
 * \param Passenger list array de passenger
 * \param len tama?o del array
 * Return retorna 1 si ordena correctamente y 0 si no
 *  */
int sortPassengersByCode(Passenger *list, int len, int order) {
	char flycodeAux[MAX_CHARS_NAME];
	int statusFlightAux;
	int indiceActual;

	switch (order) {
	case 1:
		for (indiceActual = 0; indiceActual < len - 1; indiceActual++) {
			int indiceSiguienteElemento = indiceActual + 1;
			// Si la cadena es mayor que la siguiente (alfabeticamente) entonces intercambiamos
			if (list[indiceActual].isEmpty == OCUPADO
					&& list[indiceSiguienteElemento].isEmpty == OCUPADO) {

				if (strcmp(list[indiceActual].flycode,
						list[indiceSiguienteElemento].flycode) > 0
						&& list[indiceActual].typePassenger
								> list[indiceSiguienteElemento].typePassenger) {
					// Movemos la cadena actual a la aux

					strncpy(flycodeAux, list[indiceActual].flycode,
					MAX_CHARS_NAME);
					statusFlightAux = list[indiceActual].statusFlight;
					// Movemos al actual el siguiente elemento
					strncpy(list[indiceActual].flycode,
							list[indiceSiguienteElemento].flycode,
							MAX_CHARS_NAME);
					list[indiceActual].statusFlight =
							list[indiceSiguienteElemento].statusFlight;
					list[indiceSiguienteElemento].statusFlight =
							statusFlightAux;
					// Y en el siguiente elemento, lo que hab?a antes en el actual pero ahora est? en aux
					strncpy(list[indiceSiguienteElemento].flycode, flycodeAux,
					MAX_CHARS_NAME);
				}
			}

		}
		break;
	case 0:
		for (indiceActual = 0; indiceActual < len - 1; indiceActual++) {
			int indiceSiguienteElemento = indiceActual + 1;
			// Si la cadena es mayor que la siguiente (alfabeticamente) entonces intercambiamos
			if (list[indiceActual].isEmpty == OCUPADO
					&& list[indiceSiguienteElemento].isEmpty == OCUPADO) {

				if (strcmp(list[indiceActual].flycode,
						list[indiceSiguienteElemento].flycode) < 0
						&& list[indiceActual].typePassenger
								< list[indiceSiguienteElemento].typePassenger) {
					// Movemos la cadena actual a la aux

					strncpy(flycodeAux, list[indiceActual].flycode,
					MAX_CHARS_NAME);
					statusFlightAux = list[indiceActual].statusFlight;
					// Movemos al actual el siguiente elemento
					strncpy(list[indiceActual].flycode,
							list[indiceSiguienteElemento].flycode,
							MAX_CHARS_NAME);
					list[indiceActual].statusFlight =
							list[indiceSiguienteElemento].statusFlight;
					list[indiceSiguienteElemento].statusFlight =
							statusFlightAux;
					// Y en el siguiente elemento, lo que hab?a antes en el actual pero ahora est? en aux
					strncpy(list[indiceSiguienteElemento].flycode, flycodeAux,
					MAX_CHARS_NAME);
				}
			}

		}
		break;
	}

	return 1;
}

/**
 * \brief Ordena el array en el criterio definido
 * \param Passenger list array de passenger
 * \param len tama?o del array
 * Return retorna 1 si ordena correctamente y 0 si no
 *  */
int sortPassengers(Passenger *list, int len, int order) {
	char auxApellido[MAX_CHARS_NAME];
	int auxTipoPasajero;
	int indiceActual;

	switch (order) {
	case 1:
		for (indiceActual = 0; indiceActual < len - 1; indiceActual++) {
			int indiceSiguienteElemento = indiceActual + 1;
			// Si la cadena es mayor que la siguiente (alfabeticamente) entonces intercambiamos
			if (list[indiceActual].isEmpty == OCUPADO
					&& list[indiceSiguienteElemento].isEmpty == OCUPADO) {

				if (strcmp(list[indiceActual].lastName,
						list[indiceSiguienteElemento].lastName) > 0
						&& list[indiceActual].typePassenger
								> list[indiceSiguienteElemento].typePassenger) {
					// Movemos la cadena actual a la aux

					strncpy(auxApellido, list[indiceActual].lastName,
					MAX_CHARS_NAME);
					auxTipoPasajero = list[indiceActual].typePassenger;
					// Movemos al actual el siguiente elemento
					strncpy(list[indiceActual].lastName,
							list[indiceSiguienteElemento].lastName,
							MAX_CHARS_NAME);
					list[indiceActual].typePassenger =
							list[indiceSiguienteElemento].typePassenger;
					list[indiceSiguienteElemento].typePassenger =
							auxTipoPasajero;
					// Y en el siguiente elemento, lo que hab?a antes en el actual pero ahora est? en aux
					strncpy(list[indiceSiguienteElemento].lastName, auxApellido,
					MAX_CHARS_NAME);
				}
			}
		}

		break;
	case 0:
		for (indiceActual = 0; indiceActual < len - 1; indiceActual++) {
			int indiceSiguienteElemento = indiceActual + 1;
			// Si la cadena es mayor que la siguiente (alfabeticamente) entonces intercambiamos
			if (list[indiceActual].isEmpty == OCUPADO
					&& list[indiceSiguienteElemento].isEmpty == OCUPADO) {

				if (strcmp(list[indiceActual].lastName,
						list[indiceSiguienteElemento].lastName) < 0
						&& list[indiceActual].typePassenger
								< list[indiceSiguienteElemento].typePassenger) {
					// Movemos la cadena actual a la aux

					strncpy(auxApellido, list[indiceActual].lastName,
					MAX_CHARS_NAME);
					auxTipoPasajero = list[indiceActual].typePassenger;
					// Movemos al actual el siguiente elemento
					strncpy(list[indiceActual].lastName,
							list[indiceSiguienteElemento].lastName,
							MAX_CHARS_NAME);
					list[indiceActual].typePassenger =
							list[indiceSiguienteElemento].typePassenger;
					list[indiceSiguienteElemento].typePassenger =
							auxTipoPasajero;
					// Y en el siguiente elemento, lo que hab?a antes en el actual pero ahora est? en aux
					strncpy(list[indiceSiguienteElemento].lastName, auxApellido,
					MAX_CHARS_NAME);

				}
			}
		}
		break;
	}

	return 1;
}

/**
 * \brief Muestra un menu y permite al usuario la seleccion de la opcion a mostrar
 * \param Passenger list array de passenger
 * \param len tama?o del array
 *  */
void ShowData(Passenger *list, int len) {
	int opc;
	float totalPasajes;
	float promedioPasajes;
	int avgCount = 0;

	if (list[0].isEmpty != LIBRE) {
		do {
			printf(
					"\n\n1. Listado de los pasajeros ordenados alfab?ticamente por Apellido y Tipo de pasajero."
							"\n2. Total y promedio de los precios de los pasajes, y cu?ntos pasajeros superan el precio promedio."
							"\n3. Listado de los pasajeros por C?digo de vuelo y estados de vuelos ?ACTIVO?"
							"\n0. Volver");
			utn_getNumero(&opc, "\nIngrese la opcion: ", "Opcion incorrecta", 0,
					3, 99999);

			switch (opc) {
			case 1:
				sortPassengers(list, len, 1);
				Passenger_MostrarTodos(list, len);
				break;
			case 2:
				getAveragePrice(list, len, &promedioPasajes, &totalPasajes,
						&avgCount);
				printf(
						"\n PROMEDIO: %2f \n TOTAL: %2f \n CANTIDAD PRECIOS MAYORES AL PROMEDIO: %d",
						promedioPasajes, totalPasajes, avgCount);
				break;
			case 3:
				sortPassengersByCode(list, len, 1);
				Passenger_MostrarTodos(list, len);
				break;
			}
		} while (opc != 0);
	} else {
		printf("\n NO ES POSIBLE INFORMAR, PRIMERO CARGUE DATOS \n");
	}
}
