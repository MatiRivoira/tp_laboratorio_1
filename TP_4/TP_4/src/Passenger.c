/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Passenger.h"
#include "../inc/LinkedList.h"


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
Passenger* Passenger_new()
{
	Passenger* unPasajero;

	unPasajero = (Passenger*) malloc (sizeof(Passenger));

	return unPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr, char* precio, char* codigoVuelo, char* estadoVuelo)
{
	Passenger* unPasajero;
	unPasajero = Passenger_new();
	if(unPasajero != NULL){
		Passenger_setId(unPasajero, atoi(idStr));
		Passenger_setNombre(unPasajero, nombreStr);
		Passenger_setApellido(unPasajero, apellidoStr);
		Passenger_setPrecio(unPasajero, atof(precio));
		Passenger_setCodigoVuelo(unPasajero, codigoVuelo);
		Passenger_setTipoPasajero(unPasajero, tipoPasajeroStr);
		Passenger_setEstadoVuelo(unPasajero, estadoVuelo);
		return unPasajero;
	}
	return NULL;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getLastId(LinkedList* this, int* id){
	int retorno = -1;
	if(this != NULL && id != NULL){
		int tam = ll_len(this);
		int idMax = 0;
		int idAux;
		Passenger* aux;
		for(int i = 0; i < tam ; i++){
			aux = ll_get(this, i);
			Passenger_getId(aux, &idAux);
			if(idAux > idMax){
				idMax = idAux;
			}
		}
		*id = idMax + 1;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL){
		strcpy(this->apellido, apellido);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL){
		strcpy(apellido,this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL){
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL){
		strcpy(this->tipoPasajero,tipoPasajero);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL){
		strcpy(tipoPasajero,this->tipoPasajero);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio > 0){
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL){
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setEstadoVuelo (Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL){
		strcpy(this->estadoVuelo, estadoVuelo);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getEstadoVuelo (Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL){
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 0;
	}
	return retorno;
}

void Passenger_printOne(Passenger* this){
	if(this != NULL){
		int id;
		char nombre[50];
		char apellido[50];
		float precio;
		char tipoPasajero[20];
		char codigoVuelo[20];
		char estadoVuelo[20];

		Passenger_getId(this, &id);
		Passenger_getNombre(this, nombre);
		Passenger_getApellido(this, apellido);
		Passenger_getPrecio(this, &precio);
		Passenger_getTipoPasajero(this, tipoPasajero);
		Passenger_getCodigoVuelo(this, codigoVuelo);
		Passenger_getEstadoVuelo(this, estadoVuelo);


		printf("%-4d | %-20s | %-20s | %-20f | %s | %-20s | %-20s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
	}
}

void printPassenger(Passenger* pasajero){
	if(pasajero != NULL){
		printf("EL PASAJERO ES:\n%-4d | %-20s | %-20s | %-20f | %s | %-20s | %-20s\n", pasajero->id, pasajero->nombre, pasajero->apellido, pasajero->precio, pasajero->codigoVuelo, pasajero->tipoPasajero, pasajero->estadoVuelo);
	}
}

int saveAsText(FILE* pArchivo, LinkedList* pArrayListPassenger){
	int retorno = -1;
	Passenger* pasajero;

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoDePasajero[20];
	char codigoVuelo[10];
	char estadoVuelo[20];

	if(pArchivo != NULL && pArrayListPassenger != NULL){
		if(ll_len(pArrayListPassenger) > 0){
			fprintf(pArchivo,"Id,Nombre,Apellido,Precio,CodigoDelVuelo,TipoDePasajero,EstadoDelVuelo\n");
			for(int i = 0; i < ll_len(pArrayListPassenger); i++){
				pasajero = (Passenger*) ll_get(pArrayListPassenger, i);
				if(pasajero != NULL){
					Passenger_getId(pasajero, &id);
					Passenger_getNombre(pasajero, nombre);
					Passenger_getApellido(pasajero, apellido);
					Passenger_getPrecio(pasajero, &precio);
					Passenger_getTipoPasajero(pasajero, tipoDePasajero);
					Passenger_getCodigoVuelo(pasajero, codigoVuelo);
					Passenger_getEstadoVuelo(pasajero, estadoVuelo);

					fprintf(pArchivo, "%d, %s, %s, %f, %s, %s, %s \n", id, nombre, apellido, precio, codigoVuelo, tipoDePasajero, estadoVuelo);

					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

int saveAsBinary(FILE* pArchivo, LinkedList* pArrayListPassenger){
	int retorno = -1;
	Passenger* pasajero;

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoDePasajero[20];
	char codigoVuelo[10];
	char estadoVuelo[20];

	if(pArchivo != NULL && pArrayListPassenger != NULL){
		if(ll_len(pArrayListPassenger) > 0){
			fprintf(pArchivo,"Id,Nombre,Apellido,Precio,CodigoDelVuelo,TipoDePasajero,EstadoDelVuelo\n");
			for(int i = 0; i < ll_len(pArrayListPassenger); i++){
				pasajero = (Passenger*) ll_get(pArrayListPassenger, i);
				if(pasajero != NULL){
					Passenger_getId(pasajero, &id);
					Passenger_getNombre(pasajero, nombre);
					Passenger_getApellido(pasajero, apellido);
					Passenger_getPrecio(pasajero, &precio);
					Passenger_getTipoPasajero(pasajero, tipoDePasajero);
					Passenger_getCodigoVuelo(pasajero, codigoVuelo);
					Passenger_getEstadoVuelo(pasajero, estadoVuelo);

					fprintf(pArchivo, "%d, %s, %s, %f, %s, %s, %s \n", id, nombre, apellido, precio, codigoVuelo, tipoDePasajero, estadoVuelo);

					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

int sortById(void* pasajero, void* pasajero2){
	int retorno = -1;
	int id;
	int id2;
	if(pasajero != NULL && pasajero2 != NULL){
		if(Passenger_getId(pasajero, &id) == 0 && Passenger_getId(pasajero2, &id2) == 0){
			if(id > id2){
				retorno = 1;
			} else {
				retorno = -1;
			}

		}
	}
	return retorno;
}

int sortByName(void* pasajero, void* pasajero2){
	int retorno = -1;
	char name[50];
	char name2[50];
	if(pasajero != NULL && pasajero2 != NULL){
		if(Passenger_getNombre(pasajero, name) == 0 && Passenger_getNombre(pasajero2, name2) == 0){
			retorno = strcmp(name, name2);
			if(retorno == 0){
				retorno = sortById(pasajero, pasajero2);
			}
		}
	}
	return retorno;
}

int sortByLastName(void* pasajero, void* pasajero2){
	int retorno = -1;
	char LastName[50];
	char LastName2[50];
	if(pasajero != NULL && pasajero2 != NULL){
		if(Passenger_getApellido(pasajero, LastName) == 0 && Passenger_getApellido(pasajero2, LastName2) == 0){
			retorno = strcmp(LastName, LastName2);
		}
	}
	return retorno;
}

int sortByPrice(void* pasajero, void* pasajero2){
	int retorno;
	float precio;
	float precio2;
	if(pasajero != NULL && pasajero2 != NULL){
		if(Passenger_getPrecio(pasajero, &precio) == 0 && Passenger_getPrecio(pasajero2, &precio2) == 0){
			if(precio > precio2){
				retorno = 2;
			} else if(precio < precio2){
				retorno = -1;
			} else {
				retorno = 0;
			}
		}
	}
	return retorno;
}

int sortByflightstatus(void* pasajero, void* pasajero2){
	int retorno = -1;
	char estadoVuelo[20];
	char estadoVuelo2[20];
	if(pasajero != NULL && pasajero2 != NULL){
		if(Passenger_getEstadoVuelo(pasajero, estadoVuelo) == 0 && Passenger_getEstadoVuelo(pasajero2, estadoVuelo2) == 0){
			retorno = strcmp(estadoVuelo, estadoVuelo2);
		}
	}
	return retorno;
}
