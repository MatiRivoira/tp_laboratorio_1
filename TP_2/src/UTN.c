/*
 * UTN.C
 *
 *  Created on: 21 abr. 2022
 *      Author: Rivoira
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

int inicializarArray(int array[], int tam, int inicializador){
    int i;
    int retorno = -1;
    if(array != NULL && tam > 0){
		for(i=0;i<tam;i++)
		{
			array[i] = inicializador;
		}
		retorno = 0;
    }
    return retorno;
}

int mostrarArray(int array[], int tam){
	int retorno = -1;
	int i;
	if(array != NULL && tam > 0){
		for(i=0;i<tam;i++){
			printf("El numero %d es: %d \n", i + 1, array[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int mostrarParesArray(int array[], int tam){
	int retorno = -1;
	int i;
	printf("Los numeros pares son: ");
	if(array != NULL && tam > 0){
		for(i=0;i<tam;i++){
			if(array[i]%2 == 0){
				printf("%d, ", array[i]);
			}
		}
	}
	return retorno;
}

int numeroDeLasPosicionesImpares(int array[], int tam){
	int retorno = -1;
	int i;
	printf("\nLos números de las posiciones impares son: ");
	if(array != NULL && tam > 0){
		for(i=0;i<tam;i++){
			if(array[i]%2 != 0){
				printf("%d, ", i);
			}
		}
	}
	return retorno;
}

int llenarArrayString(char array[], char texto[]){
	printf(texto);
	fflush(stdin);
	gets(array);

	return 0;
}


int llenarInt(int* variable, char texto[]){
	printf(texto);
	fflush(stdin);
	scanf("%d", variable);

	return 0;

}

float llenarFloat(float* variable, char texto[]){
	printf(texto);
	fflush(stdin);
	scanf("%f", variable);

	return 0;
}
