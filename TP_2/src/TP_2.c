/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "UTN.h"
#include "ArrayPassenger.h"
#include "modificadores.h"

#define TAM 2000
#define TAM2 3



int main(void) {
	setbuf(stdout, NULL);

	int idAux = 1;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	char flycodeAux[10];
	int typePassengerAux;

	int opcionElegida;
	int opcionElegidaSubMenu;
	int opcionElegidaSubMenu2;


	int idModificador = 0;
	int idABorrar;

	float totalPrecio;
	float promedio;
	int cantidadQueSuperanElPromedio;

	int cargo;

	Passenger pasajeros[TAM];

	initPassengers(pasajeros, TAM);
	initIds(pasajeros, TAM);
	initStatusFly(pasajeros, TAM);



	do{
		printf("\n  ~~MENU PRINCIPAL~~\n 1. ALTAS \n 2. MODIFICAR \n 3. BAJA \n 4. INFORMAR \n 5. CARGA FORZADA \n 6. SALIR \n ");
		fflush(stdin);
		scanf("%d", &opcionElegida);
		while(opcionElegida > 6){
			llenarInt(&opcionElegida, "ERROR, OPCION NO VALIDA");
		}

		switch(opcionElegida){
			case 1: //ALTAS

				llenarArrayString(nameAux, "Ingrese el nombre: ");

				llenarArrayString(lastNameAux, "Ingrese el apellido: ");

				llenarFloat(&priceAux, "Ingrese el precio: ");

				llenarArrayString(flycodeAux, "Ingrese el codigo de vuelo: ");

				llenarInt(&typePassengerAux, "Ingrese el tipo de pasajero (2-Ejecutivo, 1-Turista): ");

				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux,priceAux,typePassengerAux, flycodeAux);

				cargo = 1;
				idAux++;
				break;

			case 2: //MODIFICAR
				if(cargo == 1){
					llenarInt(&idModificador, "Ingrese el id del pasajero: ");
					mostrarPasajero(pasajeros, TAM, idModificador);
					if(deseaContinuar() == 'n'){
						break;
					}
					idModificador = findPassengerById(pasajeros, TAM, idModificador);
					do{
						printf("\n  ~~MENU MODIFICADOR~~\n 1. MODIFICAR NOMBRE \n 2. MODIFICAR APELLIDO \n 3. MODIFICAR PRECIO \n 4. MODIFICAR TIPO DE PASAJERO \n 5. MODIFICAR CODIGO DE VUELO \n 6. SALIR");
						fflush(stdin);
						scanf("%d", &opcionElegidaSubMenu);
						while(opcionElegidaSubMenu > 6){
							llenarInt(&opcionElegidaSubMenu, "ERROR, OPCION NO VALIDA");
						}
						switch(opcionElegidaSubMenu){
							case 1:
								llenarArrayString(pasajeros[idModificador].name, "\n Ingrese el nuevo nombre: \n");
								break;
							case 2:
								llenarArrayString(pasajeros[idModificador].lastName, "\n Ingrese el nuevo apellido: \n");
								break;
							case 3:
								llenarFloat(&pasajeros[idModificador].price, "\n Ingrese el nuevo precio: \n");
								break;
							case 4:
								llenarInt(&pasajeros[idModificador].typePassenger, "\n Ingrese el tipo de pasajero (1- Turista 2- Ejecutivo 3- Primera Clase): \n");
								break;
							case 5:
								llenarArrayString(pasajeros[idModificador].flycode,"Ingrese el nuevo codigo de vuelo: ");
								break;
						}
					}while(opcionElegidaSubMenu != 6);
				} else {
					printf("\nANTES CARGUE UN PASAJERO");
				}
				break;

			case 3: //BAJA
				if(cargo == 1){
					llenarInt(&idABorrar, "Ingrese el ID del pasajero a bajar");
					mostrarPasajero(pasajeros, TAM, idABorrar);
					if(deseaContinuar() == 'n'){
						break;
					}
					removePassenger(pasajeros, TAM, idABorrar);
				} else {
					printf("\nANTES CARGUE UN PASAJERO");
				}
				break;

			case 4: //INFORMAR
				if(cargo == 1){
					printf("\n  ~~MENU INFORMADOR5~~\n 1. VER LISTADO DE LOS PASAJEROS ORDENADOS ALFABETICAMENTE POR APELLIDO Y TIPO DE PASAJERO \n 2. VER TOTAL Y PROMEDIO DE LOS PRECIOS DE LOS PASAJES Y CUANDOS PASAJEROS SUPERAN EL PREICO PROMEDIO \n 3. VER LISTADO DE LOS PASAJEROS POR CODIGO DE VUELO Y ESTADO DEL VUELO \n 4. SALIR");
					fflush(stdin);
					scanf("%d", &opcionElegidaSubMenu2);
					while(opcionElegidaSubMenu2 > 4){
						llenarInt(&opcionElegidaSubMenu2, "ERROR, OPCION NO VALIDA");
					}
					switch(opcionElegidaSubMenu2){
					case 1:
						sortPassengers(pasajeros, TAM, 1);
						printPassenger(pasajeros, TAM);
					case 2:
						totalPromedioPasajes(pasajeros, TAM, &promedio, &totalPrecio);
						superanElPromedio(pasajeros, TAM, promedio, &cantidadQueSuperanElPromedio);
						printf("\n El total de los precios de los pasajes es: %f ,El promedio es: %f y la cantidad que supera este es: %d \n", totalPrecio, promedio, cantidadQueSuperanElPromedio);
						break;
					case 3:
						sortPassengers2(pasajeros, TAM, 1);
						printPassenger(pasajeros, TAM);
						break;
					}

				} else {
					printf("\nANTES CARGUE UN PASAJERO");
				}
				break;

			case 5: //CARGA FORZADA
				strcpy(nameAux, "Matias");
				strcpy(lastNameAux, "Rivoira");
				priceAux = 10000;
				strcpy(flycodeAux, "AGS19");
				typePassengerAux = 3;

				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux,priceAux,typePassengerAux, flycodeAux);
				idAux++;

				strcpy(nameAux, "Amelia");
				strcpy(lastNameAux, "Valdez");
				priceAux = 5000;
				strcpy(flycodeAux, "ARS23");
				typePassengerAux = 3;

				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux,priceAux,typePassengerAux, flycodeAux);
				idAux++;

				strcpy(nameAux, "Paco");
				strcpy(lastNameAux, "Rivoira");
				priceAux = 3000;
				strcpy(flycodeAux, "ARS19");
				typePassengerAux = 2;

				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux,priceAux,typePassengerAux, flycodeAux);
				idAux++;

				strcpy(nameAux, "tintin");
				strcpy(lastNameAux, "Rivoira");
				priceAux = 30000;
				strcpy(flycodeAux, "ARS30");
				typePassengerAux = 1;

				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux,priceAux,typePassengerAux, flycodeAux);
				idAux++;

				strcpy(nameAux, "Nelson");
				strcpy(lastNameAux, "Acevedo");
				priceAux = 2000;
				strcpy(flycodeAux, "ARS23");
				typePassengerAux = 1;

				addPassenger(pasajeros, TAM, idAux, nameAux, lastNameAux,priceAux,typePassengerAux, flycodeAux);
				idAux++;

				cargo = 1;
				break;
		}
	}while(opcionElegida != 6);

	return EXIT_SUCCESS;
}
