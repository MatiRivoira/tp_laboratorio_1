/*
 * modificadores.c
 *
 *  Created on: 12 may. 2022
 *      Author: Rivoira
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include "UTN.h"
#include "ArrayPassenger.h"

int modificarNombre(Passenger* list,int tam,int id){
	int retorno = -1;
	char newName[51];
	char respuesta;

	int i = findPassengerById(list, tam, id);

	printf("El nombre es: ");
	printf(list[i].name);

	printf("¿desea continuar? s/n");
	fflush(stdin);
	scanf("%c", &respuesta);

	while(respuesta != 's' && respuesta != 'n'){
		printf("ERROR, ¿desea continuar? s/n");
		fflush(stdin);
		scanf("%c", &respuesta);
	}

	if(list != NULL && tam > 0 && id > -1 && respuesta == 's'){
		printf("Ingrese el nuevo nombre: ");
		fflush(stdin);
		gets(newName);

		strcpy(list[i].name, newName);
		retorno = 0;
	}
	return retorno;
}

int modificarApellido(Passenger* list,int tam,int id){
	int retorno = -1;
	char newLastName[51];
	char respuesta;

	int i = findPassengerById(list, tam, id);

	printf("El apellido es: ");
	printf(list[i].lastName);

	printf("¿desea continuar? s/n");
	fflush(stdin);
	scanf("%c", &respuesta);

	while(respuesta != 's' && respuesta != 'n'){
		printf("ERROR, ¿desea continuar? s/n");
		fflush(stdin);
		scanf("%c", &respuesta);
	}

	if(list != NULL && tam > 0 && id > -1 && respuesta == 's'){
		printf("Ingrese el nuevo nombre: ");
		fflush(stdin);
		gets(newLastName);

		strcpy(list[i].lastName, newLastName);
		retorno = 0;
	}
	return retorno;
}

int modificarPrecio(Passenger* list,int tam,int id){
	int retorno = -1;
	float newPrice;
	char respuesta;

	int i = findPassengerById(list, tam, id);

	printf("El precio es: ");
	printf("%f", list[i].price);

	printf("¿desea continuar? s/n");
	fflush(stdin);
	scanf("%c", &respuesta);

	while(respuesta != 's' && respuesta != 'n'){
		printf("ERROR, ¿desea continuar? s/n");
		fflush(stdin);
		scanf("%c", &respuesta);
	}

	if(list != NULL && tam > 0 && id > -1 && respuesta == 's'){
		printf("Ingrese el nuevo precio: ");
		fflush(stdin);
		scanf("%f", &newPrice);

		list[i].price = newPrice;
		retorno = 0;
	}
	return retorno;
}

int modificarTipoDePasajero(Passenger* list,int tam,int id){
	int retorno = -1;
	//int newTipoPasajero;
	char respuesta;

	int i = findPassengerById(list, tam, id);

	printf("El tipo de pasajero es: ");
	printf("%d",list[i].typePassenger);

	printf("¿desea continuar? s/n");
	fflush(stdin);
	scanf("%c", &respuesta);

	while(respuesta != 's' && respuesta != 'n'){
		printf("ERROR, ¿desea continuar? s/n");
		fflush(stdin);
		scanf("%c", &respuesta);
	}

	if(list != NULL && tam > 0 && id > -1 && respuesta == 's'){
		printf("Ingrese el nuevo tipo de pasajero: ");
		fflush(stdin);
		//scanf("%d", newTipoPasajero);

		//list[i].typePassenger = newTipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int modificarCodigoDeVuelo(Passenger* list,int tam,int id){
	int retorno = -1;
	char newFlyCode[10];
	char respuesta;

	int i = findPassengerById(list, tam, id);

	printf("El codigo de vuelo es: ");
	printf(list[i].flycode);

	printf("¿desea continuar? s/n");
	fflush(stdin);
	scanf("%c", &respuesta);

	while(respuesta != 's' && respuesta != 'n'){
		printf("ERROR, ¿desea continuar? s/n");
		fflush(stdin);
		scanf("%c", &respuesta);
	}

	if(list != NULL && tam > 0 && id > -1 && respuesta == 's'){
		printf("Ingrese el nuevo nombre: ");
		fflush(stdin);
		gets(newFlyCode);

		strcpy(list[i].flycode, newFlyCode);
		retorno = 0;
	}
	return retorno;
}

int initIds(Passenger* list, int len)
{
	for(int i = 0; i < len; i++){
		list[i].id = 0;
	}

	return 0;
}

void mostrarPasajero(Passenger* list,int tam, int id){
	int i = findPassengerById(list, tam, id);
	printf("El pasajero es: ");
	printf("\n Su id es: %d",list[i].id);
	printf("\n Su Nombre es: %s",list[i].name);
	printf("\n Su apellido es: %s",list[i].lastName);
	printf("\n El precio es:  %f",list[i].price);
	printf("\n El codigo de vuelo es:  %s",list[i].flycode);
	printf("\n El tipo de pasajero es:  %d",list[i].typePassenger);
}

char deseaContinuar(){
	char respuesta;
	printf("\n¿Desea continuar?, s/n");
	fflush(stdin);
	scanf("%c", &respuesta);
	while(respuesta != 's' && respuesta != 'n'){
		printf("\n ERROR, ¿Desea continuar?, s/n");
		fflush(stdin);
		scanf("%c", &respuesta);
	}
	return respuesta;
}

int totalPromedioPasajes(Passenger* list,int tam, float* promedio, float* totalPrecio){
	int contador = 0;
	float sumaPrice = 0;
	int retorno = -1;
	for(int i = 0; i < tam; i++){
		if(list[i].isEmpty != VACIO){
			contador++;
			sumaPrice = sumaPrice + list[i].price;
			retorno = 0;
		}
	}
	*totalPrecio = sumaPrice;
	*promedio = sumaPrice / contador;

	return retorno;
}

int superanElPromedio(Passenger* list,int tam, float promedio, int* cantidadQueSuperanElPromedio){
	int contador = 0;
	int retorno = -1;
	for(int i = 0; i < tam; i++){
		if(list[i].isEmpty != VACIO && list[i].price > promedio){
			contador++;
			retorno = 0;
		}
	}
	*cantidadQueSuperanElPromedio = contador;

	return retorno;
}


int initStatusFly(Passenger* list, int tam){
	int valor = 1;
	int contador = 0;
	for(int i = 0; i < tam; i++){
		if(contador == 1){
			valor = 2;
			contador--;
		} else{
			valor = 1;
			contador++;
		}
		list[i].statusFlight = valor;
}

	return 0;
}

int sortPassengers2(Passenger* list, int len, int order){
	int value = 0;

	Passenger listAux;

	for(int i = 0; i < len; i++){
		for (int j = i+1; j < len; j++){
			if (list[j].isEmpty != -1){
				if (order == 1){
					if(list[i].statusFlight > list[j].statusFlight){
						value = 1;
					} else {
						if(list[i].statusFlight == list[j].statusFlight){
							value = strcmp(list[i].flycode, list[j].flycode);
						}
					}
				} else {
					if(list[i].statusFlight < list[j].statusFlight){
						value = 1;
					} else {
						if(list[i].statusFlight == list[j].statusFlight){
							value = strcmp(list[j].flycode, list[i].flycode);
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
					listAux.statusFlight = list[i].statusFlight;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;
					list[i].statusFlight = list[j].statusFlight;

					list[j].id = listAux.id;
					strcpy(list[j].name, listAux.name);
					strcpy(list[j].lastName, listAux.lastName);
					list[j].price = listAux.price;
					strcpy(list[j].flycode, listAux.flycode);
					list[j].typePassenger = listAux.typePassenger;
					list[j].statusFlight = listAux.statusFlight;

					break;
				}
			}
		}
	}
	return 0;
}


