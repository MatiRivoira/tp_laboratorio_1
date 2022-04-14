/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "showResults.h"
#include "ingresoDeDatos.h"


int main(void) {
	setbuf(stdout, NULL);

	int km = 0;

	int precioAereolineas = 0;
	int precioLatam = 0;

	int opcionElegida;

	int calculado = 0;

	float pTarjetaCreditoLatam;
	float pTarjetaDebitoLatam;
	float pBitcoinLatam;
	float pPrecioUnitarioLatam;
	float pDiferenciaPrecioLatam;

	float pTarjetaCreditoAereolineas;
	float pTarjetaDebitoAereolineas;
	float pBitcoinAereolineas;
	float pPrecioUnitarioAereolineas;

	do {
		printf("    ~~MENU PRINCIPAL~~\n 1. Ingresar Kilómetros \n 2. Ingresar Precio de Vuelos \n 3. Calcular todos los costos \n 4. Informar Resultados \n 5. Carga forzada de datos \n 6. Salir \n ");
		scanf("%d", &opcionElegida);

		switch(opcionElegida){
			case 1: //INGRESO DE KILOMETROS
				printf("Ingrese los kilometros: ");
				scanf("%d", &km);
				while(km <= 0){
					printf("Error, Ingrese los Kilometros");
					scanf("%d", &km);
				}

			break;

			case 2: //INGRESO DE PRECIO DE LOS VUELOS
				printf("Ingrese el precio de vuelo Aerolineas: ");
				scanf("%d", &precioAereolineas);
				while(precioAereolineas <= 0) {
					printf("ERROR, Ingrese el precio de vuelo Aerolineas: ");
					scanf("%d", &precioAereolineas);
				}

				printf("Precio vuelo Latam: ");
				scanf("%d", &precioLatam);
				while(precioLatam <= 0) {
					printf("Error, Ingrese el precio de vuelo Latam: ");
					scanf("%d", &precioLatam);
				}
			break;

			case 3: //CALCULOS
				if(precioAereolineas != 0 && precioLatam != 0 && km != 0){

					calculosLatam(precioLatam, precioAereolineas, km, &pTarjetaCreditoLatam, &pTarjetaDebitoLatam, &pBitcoinLatam, &pPrecioUnitarioLatam, &pDiferenciaPrecioLatam);

					calculosAereolineas(precioLatam, precioAereolineas, km, &pTarjetaCreditoAereolineas, &pTarjetaDebitoAereolineas, &pBitcoinAereolineas, &pPrecioUnitarioAereolineas);

					calculado = 1;

				} else {
					printf("\n Falta ingresar algun vuelo o los kilometros, vuelva a intentarlo por favor \n");
				}
			break;

			case 4: //MOSTRAR RESULTADOS
				if(calculado == 1){
				showResultados(km, precioLatam, precioAereolineas, pTarjetaCreditoLatam, pTarjetaDebitoLatam, pBitcoinLatam, pPrecioUnitarioLatam, pDiferenciaPrecioLatam, pTarjetaCreditoAereolineas, pTarjetaDebitoAereolineas, pBitcoinAereolineas, pPrecioUnitarioAereolineas);
				} else {
					printf("\nNo se ha hecho ningun calculo \n \n");
				}
			break;

			case 5: //CARGA FORZADA
				km = 7090;
				precioLatam = 159339;
				precioAereolineas = 162965;

				calculosLatam(precioLatam, precioAereolineas, km, &pTarjetaCreditoLatam, &pTarjetaDebitoLatam, &pBitcoinLatam, &pPrecioUnitarioLatam, &pDiferenciaPrecioLatam);

				calculosAereolineas(precioLatam, precioAereolineas, km, &pTarjetaCreditoAereolineas, &pTarjetaDebitoAereolineas, &pBitcoinAereolineas, &pPrecioUnitarioAereolineas);

				showResultados(km, precioLatam, precioAereolineas, pTarjetaCreditoLatam, pTarjetaDebitoLatam, pBitcoinLatam, pPrecioUnitarioLatam, pDiferenciaPrecioLatam, pTarjetaCreditoAereolineas, pTarjetaDebitoAereolineas, pBitcoinAereolineas, pPrecioUnitarioAereolineas);

			break;
		}
	} while (opcionElegida != 6); //salir
	return EXIT_SUCCESS;
}







