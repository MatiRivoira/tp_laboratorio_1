/*
 * calculos.c
 *
 *  Created on: 12 abr. 2022
 *      Author: Rivoira
 */

#include <stdio.h>
#include <stdlib.h>

int calculosLatam(int precioLatam, int precioAereolineas, int kilometros, float* pTarjetaCredito, float* pTarjetaDebito, float* pBitcoin, float* pPrecioUnitario, float* pDiferenciaPrecio){
	/***
	 * calcula todos los costos de latam
	 */
	int retorno;

	if(pTarjetaCredito != NULL && pTarjetaDebito != NULL && pBitcoin != NULL && pPrecioUnitario != NULL && pDiferenciaPrecio != NULL){
		*pTarjetaDebito = (float) precioLatam - precioLatam * 10 / 100;

		*pTarjetaCredito = (float) precioLatam + precioLatam * 25 / 100;

		*pBitcoin = (float) precioLatam / 4606954.55;

		*pPrecioUnitario = (float) precioLatam / kilometros;

		if(precioLatam > precioAereolineas){
			*pDiferenciaPrecio = precioLatam - precioAereolineas;
		} else {
			*pDiferenciaPrecio = precioAereolineas - precioLatam;
		}


		retorno = 0;
	} else {
		retorno = -1;
	}
	return retorno;
}

int calculosAereolineas(int precioLatam, int precioAereolineas, int kilometros, float* pTarjetaCredito, float* pTarjetaDebito, float* pBitcoin, float* pPrecioUnitario, float* pDiferenciaPrecio){
	/***
	 * calcula todos los costos de aereolineas
	 */
	int retorno;

	if(pTarjetaCredito != NULL && pTarjetaDebito != NULL && pBitcoin != NULL && pPrecioUnitario != NULL && pDiferenciaPrecio != NULL){
		*pTarjetaDebito = (float) precioAereolineas - precioAereolineas * 10 / 100;

		*pTarjetaCredito = (float) precioAereolineas + precioAereolineas * 25 / 100;

		*pBitcoin = (float) precioAereolineas / 4606954.55;

		*pPrecioUnitario = (float) precioAereolineas / kilometros;

		retorno = 0;
	} else {
		retorno = -1;
	}
	return retorno;
}
