/*
 * ArrayPassenger.c
 *
 *  Created on: 10 may. 2022
 *      Author: Rivoira
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayPassenger.h"


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len)
{

	for(int i = 0; i < len; i++){
		list[i].isEmpty = VACIO;
	}

	return 0;
}

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok */
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{

	for(int i = 0; i < len; i++){
		if(list[i].isEmpty == VACIO){

			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].flycode, flycode);
			list[i].isEmpty = 1;

			printf("\n el ID del pasajero es: %d", id);
			break;
		}
	}
	return -1;
}

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id){
	int retorno = -1;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id){
				retorno = i;
			}
		}
	}
	return retorno;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id){
	int indice;
	int retorno = -1;

	if(list != NULL && len > 0){
		indice = findPassengerById(list,len,id);
		if(indice != -1){
			list[indice].isEmpty = VACIO;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order){
	int value = 0;

	Passenger listAux;

	for(int i = 0; i < len; i++){
		for (int j = i+1; j < len; j++){
			if (list[j].isEmpty != -1){
				if (order == 1){
					if(list[i].typePassenger > list[j].typePassenger){
						value = 1;
					} else {
						if(list[i].typePassenger == list[j].typePassenger){
							value = strcmp(list[i].lastName, list[j].lastName);
						}
					}
				} else {
					if(list[i].typePassenger < list[j].typePassenger){
						value = 1;
					} else {
						if(list[i].typePassenger == list[j].typePassenger){
							value = strcmp(list[j].lastName, list[i].lastName);
						}
					}
				}
				if (value == 1){
					value = 0;

					listAux.id = list[i].id;
					strcpy(listAux.name, list[i].name);
					strcpy(listAux.lastName, list[i].lastName);
					listAux.price = list[i].price;
					strcpy(listAux.flycode, list[i].flycode);
					listAux.typePassenger = list[i].typePassenger;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;

					list[j].id = listAux.id;
					strcpy(list[j].name, listAux.name);
					strcpy(list[j].lastName, listAux.lastName);
					list[j].price = listAux.price;
					strcpy(list[j].flycode, listAux.flycode);
					list[j].typePassenger = listAux.typePassenger;

					j = i+1;
				}
			}
		}
	}
	return 0;
}

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length){
	char estadoVuelo[10];
	char typePassenger[0];
	for(int i = 0; i < length; i++){
		if(list[i].isEmpty != VACIO){
			if(list[i].statusFlight == 1){
				strcpy(estadoVuelo, "ACTIVO");
			} else {
				strcpy(estadoVuelo, "NO ACTIVO");
			}
			if(list[i].typePassenger == 1){
				strcpy(typePassenger, "TURISTA");
			} else if(list[i].typePassenger == 2){
				strcpy(typePassenger, "EJECUTIVO");
			} else {
				strcpy(typePassenger, "PRIMERA CLASE");
			}
			printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------- \n");
			printf("ID: %d | NAME: %s | LASTNAME %s | PRICE %f | FLYCODE: %s | TYPEPASSENGER: %s | STATUSFLIGHT %s",list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode,typePassenger, estadoVuelo);
			printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------");
		}
	}
	return 0;
}

