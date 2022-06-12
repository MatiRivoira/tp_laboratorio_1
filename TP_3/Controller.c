#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "UTN.h"



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
		if(pArrayListPassenger != NULL && path != NULL){
			FILE* pArchivo;
			pArchivo = fopen (path, "r");
			if(pArchivo != NULL){
				if(parser_PassengerFromText(pArchivo, pArrayListPassenger) == 0){
					retorno = 0;
				}
			}
			fclose(pArchivo);
		}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
		if(pArrayListPassenger != NULL && path != NULL){
			FILE* pArchivo;
			pArchivo = fopen (path, "rb");
			if(pArchivo != NULL){
				if(parser_PassengerFromBinary(pArchivo, pArrayListPassenger) == 0){
					retorno = 0;
				}
			}
			fclose(pArchivo);
		}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
		if(pArrayListPassenger != NULL){
			Passenger* newPasajero;

			int id = 0;
			char idString[10];
			char nombreAux[20];
			char apellidoAux[20];
			float precioAux;
			char precioString[20];
			int tipoPasajeroAux;
			char tipoPasajeroAuxString[20];
			char codigoDeVueloAux[20];
			int estadoVueloAux;
			char estadoVueloAuxString[20];

			int tam = ll_len(pArrayListPassenger);

			if(tam > 0){
				id++;
				id = id + tam;
				itoa(id,idString, 10);
			} else {
				id++;
				itoa(id,idString, 10);
			}

			llenarString(nombreAux, "\nIngrese el nombre del pasajero: ");
			llenarString(apellidoAux, "\nIngrese el apellido del pasajero: ");
			llenarFloat(&precioAux, "\nIngrese el precio del vuelo: ", "Error. Ingrese un dato valido ¯_(ツ)_/¯, \n", 99999999, 1);
			itoa(precioAux, precioString, 20);
			llenarInt(&tipoPasajeroAux, "\nIngrese 1 para First Class, 2 para Executive Class, 3 para Economy Class: ", "Error. Ingrese una opcion valida ¯_(ツ)_/¯, \n", 3, 1);
			switch(tipoPasajeroAux){
				case 1:
					strcpy(tipoPasajeroAuxString,"First Class");
					break;
				case 2:
					strcpy(tipoPasajeroAuxString,"Executive Class");
					break;
				case 3:
					strcpy(tipoPasajeroAuxString,"Economy Class");
					break;
			}
			llenarString(codigoDeVueloAux, "\nIngrese el codigo de vuelo: ");
			llenarInt(&estadoVueloAux, "\nIngrese 1 si el vuelo esta Aterrizado, 2 si esta En horario, 3 si esta En vuelo, 4 si esta Demorado: ","Error. Ingrese una opcion valida ¯_(ツ)_/¯, \n",4,1);
			switch(estadoVueloAux){
				case 1:
					strcpy(estadoVueloAuxString,"Aterrizado");
					break;
				case 2:
					strcpy(estadoVueloAuxString,"En horario");
					break;
				case 3:
					strcpy(estadoVueloAuxString,"En vuelo");
					break;
				case 4:
					strcpy(estadoVueloAuxString,"Demorado");
					break;
			}
			newPasajero = Passenger_newParametros(idString, nombreAux, tipoPasajeroAuxString, apellidoAux, precioString, codigoDeVueloAux, estadoVueloAuxString);
			if(newPasajero != NULL){
				ll_add(pArrayListPassenger, newPasajero);
				retorno = 0;
			}
		}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int id;
	int respuesta;
	int opcion;

	Passenger* pasajeroAux;
	char nameAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char tipoPasajeroStrAux[20];
	char codigoVueloAux[10];
	int estadoDeVueloAux;
	char estadoDeVueloStrAux[20];

	if(pArrayListPassenger != NULL){
		llenarInt(&id, "Ingrese el id del pasajero a modificar: ", "ERROR, ese id no esta cargado, vuelva a intentarlo ب(ﾉ◕╭╮◕), ", ll_len(pArrayListPassenger), 1);
		pasajeroAux = ll_get(pArrayListPassenger, id - 1);
		printPassenger(pasajeroAux);
		respuesta = deseaContinuar();
		if(respuesta == 's'){
			do{
				llenarInt(&opcion, "\n▂▃▅▆█ MENU MODIFICADOR █▆▅▃▂"
								   "\n 1. MODIFICAR NOMBRE"
								   "\n 2. MODIFICAR APELLIDO"
								   "\n 3. MODIFICAR PRECIO"
								   "\n 4. MODIFICAR TIPO DE PASAJERO"
								   "\n 5. MODIFICAR CODIGO DE VUELO"
								   "\n 6. MODIFICAR ESTADO DE VUELO"
								   "\n 7. SALIR", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 7, 1);
				switch(opcion){
					case 1:
						llenarString(nameAux, "\nIngrese el nuevo nombre: ");
						Passenger_setNombre(pasajeroAux, nameAux);
						break;
					case 2:
						llenarString(apellidoAux, "\nIngrese el nuevo apellido: ");
						Passenger_setApellido(pasajeroAux, apellidoAux);
						break;
					case 3:
						llenarFloat(&precioAux, "\nIngrese el precio del vuelo: ", "Error. Ingrese un dato valido ¯_(ツ)_/¯, \n", 99999999, 1);
						Passenger_setPrecio(pasajeroAux, precioAux);
						break;
					case 4:
						llenarInt(&tipoPasajeroAux, "\nIngrese 1 para First Class, 2 para Executive Class, 3 para Economy Class: ", "Error. Ingrese una opcion valida ¯_(ツ)_/¯, \n", 3, 1);
						switch(tipoPasajeroAux){
							case 1:
								strcpy(tipoPasajeroStrAux,"First Class");
								break;
							case 2:
								strcpy(tipoPasajeroStrAux,"Executive Class");
								break;
							case 3:
								strcpy(tipoPasajeroStrAux,"Economy Class");
								break;
						}
						Passenger_setTipoPasajero(pasajeroAux, tipoPasajeroStrAux);
						break;
					case 5:
						llenarString(codigoVueloAux, "\nIngrese el nuevo codigo de vuelo: ");
						Passenger_setCodigoVuelo(pasajeroAux, codigoVueloAux);
						break;
					case 6:
						llenarInt(&estadoDeVueloAux, "\nIngrese 1 si el vuelo esta Aterrizado, 2 si esta En horario, 3 si esta En vuelo, 4 si esta Demorado: ","Error. Ingrese una opcion valida ¯_(ツ)_/¯, \n",4,1);
						switch(estadoDeVueloAux){
							case 1:
								strcpy(estadoDeVueloStrAux,"Aterrizado");
								break;
							case 2:
								strcpy(estadoDeVueloStrAux,"En horario");
								break;
							case 3:
								strcpy(estadoDeVueloStrAux,"En vuelo");
								break;
							case 4:
								strcpy(estadoDeVueloStrAux,"Demorado");
								break;
						}
						break;
						Passenger_setEstadoVuelo(pasajeroAux, estadoDeVueloStrAux);
				}
			}while(opcion != 7);
		}
		retorno = 0;
	}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
		int id;
		int respuesta;
		Passenger* pasajeroAux;

		if(pArrayListPassenger != NULL){
			llenarInt(&id, "Ingrese el id del pasajero a modificar: ", "ERROR, ese id no esta cargado, vuelva a intentarlo ب(ﾉ◕╭╮◕), ", ll_len(pArrayListPassenger), 1);
			pasajeroAux = (Passenger*) ll_get(pArrayListPassenger, id - 1);
			printPassenger(pasajeroAux);
			respuesta = deseaContinuar();
			if(respuesta =='s'){
				ll_remove(pArrayListPassenger, id - 1);
			}
			retorno = 0;
		}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger){
	int retorno = -1;
	if(pArrayListPassenger != NULL){
		Passenger* unPasajero;
		for(int i = 0; i < ll_len(pArrayListPassenger); i++){
			unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			retorno = Passenger_printOne(unPasajero);
		}
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int opcion;
	int sentido;
	int valor = 0;

	Passenger* unPasajero;
	Passenger* unPasajero2;

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[20];

	int id2;
	char nombre2[50];
	char apellido2[50];
	float precio2;
	char tipoPasajero2[20];
	char codigoVuelo2[20];
	char estadoVuelo2[20];

	llenarInt(&opcion, "Ingrese como quiere ordenar los pasajeros, 1- POR NOMBRE, 2- POR APELLIDO, 3- POR PRECIO DE VUELO. 4- POR ESTADO DE VUELO, 5- CANCELAR", "ERROR, opcion no valida, vuelva a intentarlo ب(ﾉ◕╭╮◕),)", 5, 1);
	llenarInt(&sentido, "Ingrese 1- PARA CRECIENTE, 2- DECRECIENTE", "ERROR, opcion no valida, vuelva a intentarlo ب(ﾉ◕╭╮◕),)", 2, 1);

	for(int i = 0 ; i < ll_len(pArrayListPassenger); i++){
		unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
		for(int j = i+1; j < ll_len(pArrayListPassenger) ;j++){
			unPasajero2 = (Passenger*) ll_get(pArrayListPassenger, j);
			switch(opcion){
				case 1:
					valor = sortByName(unPasajero,unPasajero2);
					break;
				case 2:
					valor = sortByLastName(unPasajero,unPasajero2);
					break;
				case 3:
					valor = sortByPrice(unPasajero,unPasajero2);
					break;
				case 4:
					valor = sortByflightstatus(unPasajero,unPasajero2);
					break;
				case 6:
					return 0;
					break;
			}

			if(valor < 0 && sentido == 2){
				Passenger_getId(unPasajero, &id);
				Passenger_getNombre(unPasajero, nombre);
				Passenger_getApellido(unPasajero, apellido);
				Passenger_getPrecio(unPasajero, &precio);
				Passenger_getTipoPasajero(unPasajero, tipoPasajero);
				Passenger_getCodigoVuelo(unPasajero, codigoVuelo);
				Passenger_getEstadoVuelo(unPasajero, estadoVuelo);

				Passenger_getId(unPasajero2, &id2);
				Passenger_getNombre(unPasajero2, nombre2);
				Passenger_getApellido(unPasajero2, apellido2);
				Passenger_getPrecio(unPasajero2, &precio2);
				Passenger_getTipoPasajero(unPasajero2, tipoPasajero2);
				Passenger_getCodigoVuelo(unPasajero2, codigoVuelo2);
				Passenger_getEstadoVuelo(unPasajero2, estadoVuelo2);

				Passenger_setId(unPasajero2, id);
				Passenger_setNombre(unPasajero2, nombre);
				Passenger_setApellido(unPasajero2, apellido);
				Passenger_setPrecio(unPasajero2, precio);
				Passenger_setTipoPasajero(unPasajero2, tipoPasajero);
				Passenger_setCodigoVuelo(unPasajero2, codigoVuelo);
				Passenger_setEstadoVuelo(unPasajero2, estadoVuelo);

				Passenger_setId(unPasajero, id2);
				Passenger_setNombre(unPasajero, nombre2);
				Passenger_setApellido(unPasajero, apellido2);
				Passenger_setPrecio(unPasajero, precio2);
				Passenger_setTipoPasajero(unPasajero, tipoPasajero2);
				Passenger_setCodigoVuelo(unPasajero, codigoVuelo2);
				Passenger_setEstadoVuelo(unPasajero, estadoVuelo2);
			} else if(valor > 0 && sentido == 1){
				Passenger_getId(unPasajero, &id);
				Passenger_getNombre(unPasajero, nombre);
				Passenger_getApellido(unPasajero, apellido);
				Passenger_getPrecio(unPasajero, &precio);
				Passenger_getTipoPasajero(unPasajero, tipoPasajero);
				Passenger_getCodigoVuelo(unPasajero, codigoVuelo);
				Passenger_getEstadoVuelo(unPasajero, estadoVuelo);

				Passenger_getId(unPasajero2, &id2);
				Passenger_getNombre(unPasajero2, nombre2);
				Passenger_getApellido(unPasajero2, apellido2);
				Passenger_getPrecio(unPasajero2, &precio2);
				Passenger_getTipoPasajero(unPasajero2, tipoPasajero2);
				Passenger_getCodigoVuelo(unPasajero2, codigoVuelo2);
				Passenger_getEstadoVuelo(unPasajero2, estadoVuelo2);

				Passenger_setId(unPasajero2, id);
				Passenger_setNombre(unPasajero2, nombre);
				Passenger_setApellido(unPasajero2, apellido);
				Passenger_setPrecio(unPasajero2, precio);
				Passenger_setTipoPasajero(unPasajero2, tipoPasajero);
				Passenger_setCodigoVuelo(unPasajero2, codigoVuelo);
				Passenger_setEstadoVuelo(unPasajero2, estadoVuelo);

				Passenger_setId(unPasajero, id2);
				Passenger_setNombre(unPasajero, nombre2);
				Passenger_setApellido(unPasajero, apellido2);
				Passenger_setPrecio(unPasajero, precio2);
				Passenger_setTipoPasajero(unPasajero, tipoPasajero2);
				Passenger_setCodigoVuelo(unPasajero, codigoVuelo2);
				Passenger_setEstadoVuelo(unPasajero, estadoVuelo2);
			}
			retorno = 0;
		}
	}
	controller_ListPassenger(pArrayListPassenger);
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL && path != NULL){
		FILE* pArchivo;
		pArchivo = fopen (path, "w");
		if(pArchivo != NULL){
			retorno = saveAsText(pArchivo, pArrayListPassenger);
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL && path != NULL){
		FILE* pArchivo;
		pArchivo = fopen (path, "wb");
		if(pArchivo != NULL){
			retorno = saveAsBinary(pArchivo, pArrayListPassenger);
		}
		fclose(pArchivo);
	}
	return retorno;
}

