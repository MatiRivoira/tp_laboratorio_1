#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "UTN.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main(){
	setbuf(stdout, NULL);

    int option = 0;
    int guardo = -1;
    int pasajerosCargados = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	llenarInt(&option,"\n  ▂▂▂▃▃▅▅▆▆█ MENU PRINCIPAL █▆▆▅▅▃▃▂▂▂\n"
							"  1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
							"  2- Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
							"  3- Alta de pasajero.\n"
							"  4- Modificar datos de pasajero.\n"
							"  5- Baja de pasajero.\n"
							"  6- Listar pasajeros.\n"
							"  7- Ordenar pasajeros.\n"
							"  8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
							"  9- Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
							"  10- Salir.", "\nERROR, Opcion no valida ¯_(ツ)_/¯, ", 10, 1);
        switch(option){
            case 1:
                if(controller_loadFromText("data.csv",listaPasajeros) == 0){
                	pasajerosCargados = ll_len(listaPasajeros);
                	printf("\n %d pasajeros cargados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados);
                	system("pause");
                } else {
                	printf("\n ERROR, no se pudo cargar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
                	system("pause");
                }
                break;
            case 2:
            	if(controller_loadFromBinary("data.csv",listaPasajeros) == 0){
                	pasajerosCargados = ll_len(listaPasajeros);
                	printf("\n %d pasajeros cargados exitosamente (ɔ◔‿◔)ɔ ♥ ", pasajerosCargados);
                	system("pause");
                } else {
                	printf("\n ERROR, no se pudo cargar el pasajero vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
                	system("pause");
                }
				break;
            case 3:
            	if(controller_addPassenger(listaPasajeros) == 0){
            		pasajerosCargados++;
            		printf("\n Pasajero cargado correctamente (ɔ◔‿◔)ɔ ♥, ");
            		system("pause");
            	} else {
            		printf("\n ERROR, no se pudo cargar el pasajero vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
            		system("pause");
            	}
				break;
            case 4:
            	if(controller_editPassenger(listaPasajeros) == 0){
            		printf("\n Pasajero modificado correctamente (ɔ◔‿◔)ɔ ♥, ");
            		system("pause");
            	} else {
            		printf("\n ERROR, no se pudo modificar el pasajero, vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
            		system("pause");
            	}
            	break;
            case 5:
            	if(controller_removePassenger(listaPasajeros) == 0){
            		pasajerosCargados--;
            		printf("\n Pasajero borrado correctamente (ɔ◔‿◔)ɔ ♥, ");
					system("pause");
				} else {
					printf("\n ERROR, no se pudo borrar el pasajero, vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
					system("pause");
				}
				break;
            case 6:
            	if(pasajerosCargados > 0){
            		controller_ListPassenger(listaPasajeros);
            	} else {
    				printf("\nERROR, PRIMERO CARGUE UNA VIVIENDA ¯_(ツ)_/¯ ");
    				system("pause");
            	}
            	break;
            case 7:
            	if(controller_sortPassenger(listaPasajeros) == 0){
            		printf("\n Pasajeros ordenados correctamente (ɔ◔‿◔)ɔ ♥, ");
					system("pause");
				} else {
					printf("\n ERROR, no se pudo ordenar los pasajeros, vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
					system("pause");
				}
				break;
            case 8:
            	if(controller_saveAsText("data.csv",listaPasajeros) == 0){
            		guardo = 1;
            		printf("\n %d pasajeros guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados);
					system("pause");
				} else {
					printf("\n ERROR, no se pudo guardar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
					system("pause");
				}
				break;
            case 9:
              	if(controller_saveAsBinary("data.bin",listaPasajeros) == 0){
              		guardo = 1;
					printf("\n %d pasajeros guardados exitosamente (ɔ◔‿◔)ɔ ♥, ", pasajerosCargados);
					system("pause");
				} else {
					printf("\n ERROR, no se pudo guardar los datos de los pasajeros vuelva a intentarlo ب(ﾉ◕╭╮◕), ");
					system("pause");
				}
				break;
        }
        if(guardo == -1 && option == 10){
             llenarInt(&option,"\nEsta intentando salir sin guardar, ¿Desea guardar los cambios? | 1 = GUARDAR | 2= NO GUARDAR | 3= CANCELAR |\n", "ERROR, Opcion no valida, vuelva a intentarlo, ", 3, 1);
             switch(option){
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
             		 guardo = 0;
             		 option = 10;
             		 break;
             }
        }
    }while(option != 10 && guardo == -1);
    return 0;
}

