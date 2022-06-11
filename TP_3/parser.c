#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){
	int retorno = -1;
		if(pFile != NULL && pArrayListPassenger != NULL){
			char id[10];
			char nombre[50];
			char apellido[50];
			char precio[30];
			char estado[20];
			char tipoDePasajero[20];
			char codigoVuelo[10];

			Passenger* newPasajero;

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoDePasajero, estado);

			while(1){
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoDePasajero, estado) == 7){
					newPasajero = Passenger_newParametros(id, nombre, tipoDePasajero, apellido, precio, codigoVuelo, estado);
					if(newPasajero != NULL){
						ll_add(pArrayListPassenger, newPasajero);
						retorno = 0;
					}
				}
				if(feof(pFile) != 0){
					break;
				}
			}
		}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pFile != NULL && pArrayListPassenger != NULL){
		char id[10];
		char nombre[50];
		char apellido[50];
		char precio[30];
		char estado[20];
		char tipoDePasajero[20];
		char codigoVuelo[10];

		Passenger* newPasajero;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoDePasajero, estado);

		while(1){
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoDePasajero, estado) == 7){
				newPasajero = Passenger_newParametros(id, nombre, tipoDePasajero, apellido, precio, codigoVuelo, estado);
				if(newPasajero != NULL){
					ll_add(pArrayListPassenger, newPasajero);
					retorno = 0;
				}
			}
			if(feof(pFile) != 0){
				break;
			}
		}
	}
	return retorno;
}
