/*
 * modificadores.h
 *
 *  Created on: 12 may. 2022
 *      Author: Rivoira
 */

#ifndef MODIFICADORES_H_
#define MODIFICADORES_H_

#include "ArrayPassenger.h"




#endif /* MODIFICADORES_H_ */

int modificarNombre(Passenger* list,int tam,int id);

int modificarApellido(Passenger* list,int tam,int id);

int modificarPrecio(Passenger* list,int tam,int id);

int modificarTipoDePasajero(Passenger* list,int tam,int id);

int modificarCodigoDeVuelo(Passenger* list,int tam,int id);

void mostrarPasajero(Passenger* list,int tam, int id);

int initIds(Passenger* list, int len);

char deseaContinuar();

int totalPromedioPasajes(Passenger* list,int tam, float* promedio,float* totalPrecio);

int superanElPromedio(Passenger* list, int tam, float promedio, int* cantidadQueSuperanElPromedio);

int initStatusFly(Passenger* list, int tam);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers2(Passenger* list, int len, int order);
