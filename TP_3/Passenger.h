/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[10];
	char estadoVuelo[20];

} Passenger;

#define VACIO -1
#define NOMBRES 51

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr, char* precio, char* codigoVuelo, char* estadoVuelo);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);
int Passenger_getLastId(LinkedList* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);

void printPassenger(Passenger* pasajero);
int Passenger_printOne(Passenger* this);

int saveAsText(FILE* pArchivo, LinkedList* pArrayListPassenger);
int saveAsBinary(FILE* pArchivo, LinkedList* pArrayListPassenger);

int sortByName(Passenger* pasajero, Passenger* pasajero2);
int sortByLastName(Passenger* pasajero, Passenger* pasajero2);
int sortByPrice(Passenger* pasajero, Passenger* pasajero2);
int sortByflightstatus(Passenger* pasajero, Passenger* pasajero2);

#endif /* PASSENGER_H_ */
