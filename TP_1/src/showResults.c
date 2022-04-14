/*
 * showResults.c
 *
 *  Created on: 13 abr. 2022
 *      Author: Rivoira
 */
#include <stdio.h>
#include <stdlib.h>

int showResultados(int km, int precioLatam, int precioAereolineas, float pTarjetaCreditoLatam,float pTarjetaDebitoLatam,float pBitcoinLatam,float pPrecioUnitarioLatam,float pDiferenciaPrecioLatam,float pTarjetaCreditoAereolineas,float pTarjetaDebitoAereolineas,float pBitcoinAereolineas,float pPrecioUnitarioAereolineas){
	/***
	 * Muestra todos los resultados
	 */
	printf("KMs Ingresados: %d \n\nPrecio Aereolineas: $ %d \n a)Precio con tarjeta de debito: $ %f \n b)Precio con tarjeta de credito: $ %f \n c) Precio pegando con bitcoin: $ %f \n d) Mostrar precio unitario: $ %f \n\n",km, precioAereolineas, pTarjetaDebitoAereolineas, pTarjetaCreditoAereolineas, pBitcoinAereolineas, pPrecioUnitarioAereolineas);

	printf("Precio Aereolineas: $ %d \n a)Precio con tarjeta de debito: $ %f \n b)Precio con tarjeta de credito: $ %f \n c) Precio pegando con bitcoin: $ %f \n d) Mostrar precio unitario: $ %f \n La diferencia de precio es: $ %f \n\n", precioLatam, pTarjetaDebitoLatam, pTarjetaCreditoLatam, pBitcoinLatam, pPrecioUnitarioLatam, pDiferenciaPrecioLatam );

	system("PAUSE");

	return 0;
}

