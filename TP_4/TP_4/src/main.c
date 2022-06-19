#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "UTN.h"
	/****************************************************
	  ATENCION:
	  SI APARECEN 3 WARNING ES BUG O REALEMENTE NO SE QUE ES PERO SE ARREGLA BORRANDO ALGUNA LETRA DE LA FUNCION controller_loadFromText Y VOLVIENDOLA A PONER
	*****************************************************/
int main(void)
{
	setbuf(stdout, NULL);

	int option = 0;
	int optionAux = 0;

	int guardo = 0;
	int pasajerosCargados = 0;
	int pasajerosActuales = 0;

	int pasajerosCargados2 = 0;
	int pasajerosActuales2 = 0;

	int borro1 = 0;
	int borro2 = 0;

	LinkedList* listaPasajeros = ll_newLinkedList();
	LinkedList* listaPasajeros2 = ll_newLinkedList();
	do{
		optionAux = 0;
		pasajerosActuales = ll_len(listaPasajeros);
		llenarInt(&option,"\n  ▂▂▂▃▃▅▅▆▆█ MENU PRINCIPAL █▆▆▅▅▃▃▂▂▂\n"
							"  1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
							"  2- Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
							"  3- Alta de pasajero.\n"
							"  4- Modificar datos de pasajero.\n"
							"  5- Baja de pasajero.\n"
							"  6- Listar pasajeros.\n"
							"  7- Ordenar pasajeros.\n"
							"  8- Opciones de desarrolador.\n"
							"  9- Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
							"  10- Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
							"  11- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 11, 1);
		switch(option){
			case 1:
				do{
					llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU CARGADOR █▆▆▅▅▃▃▂▂▂\n"
										"  1- Cargar en lista 1.\n"
										"  2- Cargar en lista 2.\n"
										"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
					switch(optionAux){
						case 1:
							if(controller_loadFromText("data.csv", listaPasajeros) == 0){
								pasajerosCargados = ll_len(listaPasajeros);
								pasajerosCargados = pasajerosCargados - pasajerosActuales;
								guardo = -1;
								printf("\n %d pasajeros cargados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados);
								system("pause");
							} else {
								printf("\n ERROR, no se pudo cargar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 2:
							if(controller_loadFromText("data2.csv", listaPasajeros2) == 0){
								pasajerosCargados2 = ll_len(listaPasajeros2);
								pasajerosCargados2 = pasajerosCargados2 - pasajerosActuales2;
								guardo = -1;
								printf("\n %d pasajeros cargados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados2);
								system("pause");
							} else {
								printf("\n ERROR, no se pudo cargar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
					}
				}while(optionAux != 3);
				break;
			case 2:
				do{
					llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU CARGADOR █▆▆▅▅▃▃▂▂▂\n"
										"  1- Cargar en lista 1.\n"
										"  2- Cargar en lista 2.\n"
										"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
					switch(optionAux){
						case 1:
							if(controller_loadFromBinary("data.csv", listaPasajeros) == 0){
								pasajerosCargados = ll_len(listaPasajeros);
								pasajerosCargados = pasajerosCargados - pasajerosActuales;
								guardo = -1;
								printf("\n %d pasajeros cargados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados);
								system("pause");
							} else {
								printf("\n ERROR, no se pudo cargar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 2:
							if(controller_loadFromBinary("data2.csv",listaPasajeros2) == 0){
									pasajerosCargados2 = ll_len(listaPasajeros2);
									pasajerosCargados2 = pasajerosCargados2 - pasajerosActuales2;
									guardo = -1;
									printf("\n %d pasajeros cargados exitosamente (ɔ◔‿◔)ɔ ♥ ", pasajerosCargados);
									system("pause");
								} else {
									printf("\n ERROR, no se pudo cargar el pasajero vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
							break;
					}
				}while(optionAux != 3);
				break;
			case 3:
				do{
					llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU ALTA █▆▆▅▅▃▃▂▂▂\n"
										"  1- Alta en lista 1.\n"
										"  2- Alta en lista 2.\n"
										"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
					switch(optionAux){
						case 1:
							if(controller_addPassenger(listaPasajeros) == 0){
								pasajerosCargados++;
								guardo = -1;
								printf("\n Pasajero cargado correctamente (ɔ◔‿◔)ɔ ♥, ");
								system("pause");
							} else {
								printf("\n ERROR, no se pudo cargar el pasajero vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 2:
							if(controller_addPassenger(listaPasajeros2) == 0){
								pasajerosCargados2++;
								guardo = -1;
								printf("\n Pasajero cargado correctamente (ɔ◔‿◔)ɔ ♥, ");
								system("pause");
							} else {
								printf("\n ERROR, no se pudo cargar el pasajero vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
					}
				}while(optionAux != 3);
				break;
			case 4:
				do{
					llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU MODIFICAR █▆▆▅▅▃▃▂▂▂\n"
										"  1- Modificar en lista 1.\n"
										"  2- Modificar en lista 2.\n"
										"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
					switch(optionAux){
						case 1:
							if(controller_editPassenger(listaPasajeros) == 0 && borro1 != 1){
								printf("\n Pasajero modificado correctamente (ɔ◔‿◔)ɔ ♥, ");
								system("pause");
							} else {
								printf("\n ERROR, no se pudo modificar el pasajero, vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 2:
							if(controller_editPassenger(listaPasajeros2) == 0 && borro2 != 1){
								printf("\n Pasajero modificado correctamente (ɔ◔‿◔)ɔ ♥, ");
								system("pause");
							} else {
								printf("\n ERROR, no se pudo modificar el pasajero, vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
					}
				}while(optionAux != 3);
				break;
			case 5:
				do{
					llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU BORRAR █▆▆▅▅▃▃▂▂▂\n"
										"  1- Borrar en lista 1.\n"
										"  2- Borrar en lista 2.\n"
										"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
					switch(optionAux){
						case 1:
							if(controller_removePassenger(listaPasajeros) == 0 && borro1 != 1){
								pasajerosCargados--;
								printf("\n Pasajero borrado correctamente (ɔ◔‿◔)ɔ ♥, ");
								system("pause");
							} else {
								printf("\n ERROR, no se pudo borrar el pasajero, vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 2:
							if(controller_removePassenger(listaPasajeros2) == 0 && borro2 != 1){
								pasajerosCargados2--;
								printf("\n Pasajero borrado correctamente (ɔ◔‿◔)ɔ ♥, ");
								system("pause");
							} else {
								printf("\n ERROR, no se pudo borrar el pasajero, vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
					}
				}while(optionAux != 3);
				break;
			case 6:
				do{
					llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU LISTAR █▆▆▅▅▃▃▂▂▂\n"
										"  1- Listar en lista 1.\n"
										"  2- Listar en lista 2.\n"
										"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
					switch(optionAux){
						case 1:
							if(pasajerosCargados > 0 && borro1 != 1){
								controller_ListPassenger(listaPasajeros);
							} else {
								printf("\nERROR, PRIMERO CARGUE UNA VIVIENDA ¯_(ツ)_/¯ ");
								system("pause");
							}
							break;
						case 2:
							if(pasajerosCargados2 > 0 && borro2 != 1){
								controller_ListPassenger(listaPasajeros2);
							} else {
								printf("\nERROR, PRIMERO CARGUE UNA VIVIENDA ¯_(ツ)_/¯ ");
								system("pause");
							}
							break;
					}
				}while(optionAux != 3);
				break;
			case 7:
				do{
					llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU ORDENAR █▆▆▅▅▃▃▂▂▂\n"
										"  1- Ordenar en lista 1.\n"
										"  2- Ordenar en lista 2.\n"
										"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
					switch(optionAux){
						case 1:
							if(controller_sortPassenger(listaPasajeros) == 0 && borro1 != 1){
								printf("\n Pasajeros ordenados correctamente (ɔ◔‿◔)ɔ ♥, ");
								system("pause");
							} else {
								printf("\n ERROR, no se pudo ordenar los pasajeros, vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 2:
							if(controller_sortPassenger(listaPasajeros2) == 0 && borro2 != 1){
								printf("\n Pasajeros ordenados correctamente (ɔ◔‿◔)ɔ ♥, ");
								system("pause");
							} else {
								printf("\n ERROR, no se pudo ordenar los pasajeros, vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
					}
				}while(optionAux != 3);
				break;
			case 8:
				if(controller_opcionesDesarrolador(listaPasajeros, listaPasajeros2, &borro1, &borro2) == 0){
					printf("\n Cambios efectuados exitosamente (ɔ◔‿◔)ɔ ♥, ");
					system("pause");
				} else {
					printf("\n ERROR, no se pudo efectuar los cambios vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
					system("pause");
				}
				break;
			case 9:
				do{
					llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU GUARDAR █▆▆▅▅▃▃▂▂▂\n"
										"  1- Guardar en lista 1.\n"
										"  2- Guardar en lista 2.\n"
										"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
					switch(optionAux){
						case 1:
							if(controller_saveAsText("data.csv",listaPasajeros) == 0 && borro1 != 1){
								guardo = 1;
								printf("\n %d pasajeros guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados);
								system("pause");
							} else {
								printf("\n ERROR, no se pudo guardar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 2:
							if(controller_saveAsText("data2.csv",listaPasajeros2) == 0 && borro2 != 1){
								guardo = 1;
								printf("\n %d pasajeros guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados2);
								system("pause");
							} else {
								printf("\n ERROR, no se pudo guardar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
					}
				}while(optionAux != 3);
				break;
			case 10:
				do{
					llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU GUARDAR █▆▆▅▅▃▃▂▂▂\n"
										"  1- Guardar en lista 1.\n"
										"  2- Guardar en lista 2.\n"
										"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
					switch(optionAux){
						case 1:
							if(controller_saveAsBinary("data.csv",listaPasajeros) == 0){
								guardo = 1;
								printf("\n %d pasajeros guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados);
								system("pause");
							} else {
								printf("\n ERROR, no se pudo guardar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
						case 2:
							if(controller_saveAsBinary("data2.csv",listaPasajeros2) == 0){
								guardo = 1;
								printf("\n %d pasajeros guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados2);
								system("pause");
							} else {
								printf("\n ERROR, no se pudo guardar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
								system("pause");
							}
							break;
					}
				}while(optionAux != 3);
				break;
			}
		if(guardo == -1 && option == 11){
			 llenarInt(&option,"\nEsta intentando salir sin guardar, ¿Desea guardar los cambios? | 1 = GUARDAR | 2= NO GUARDAR | 3= CANCELAR |\n", "ERROR, Opcion no valida, vuelva a intentarlo, ", 3, 1);
			 switch(option){
				 case 1:
					do{
						llenarInt(&optionAux,"\n  ▂▂▂▃▃▅▅▆▆█ MENU GUARDAR █▆▆▅▅▃▃▂▂▂\n"
											"  1- Guardar en lista 1.\n"
											"  2- Guardar en lista 2.\n"
											"  3- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 3, 1);
						switch(optionAux){
							case 1:
								if(controller_saveAsText("data.csv",listaPasajeros) == 0){
									guardo = 1;
									printf("\n %d pasajeros guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados);
									system("pause");
								} else {
									printf("\n ERROR, no se pudo guardar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
							case 2:
								if(controller_saveAsText("data.csv2",listaPasajeros2) == 0){
									guardo = 1;
									printf("\n %d pasajeros guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados);
									system("pause");
								} else {
									printf("\n ERROR, no se pudo guardar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
									system("pause");
								}
								break;
						}
					}while(optionAux != 3);
					break;
				 case 2:
					 guardo = 0;
					 option = 11;
					 break;
				 }
			}
	}while(option != 11 || guardo == -1);
	return 0;
}
