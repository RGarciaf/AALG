/**
 *
 * Descripcion: Implementacion de funciones de ordenacion
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include "ordenacion.h"

void swap ( int * A, int * B );

/***************************************************/
/* Funcion: InsertSort    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int SelectSort(int* tabla, int ip, int iu)
{
  int index = ip;
	int min = ip;
	int obs = 0;

	for (; ip < iu; ip++ ){

		for (min = ip, index = ip; index <= iu; index++ ){

			obs++;
			if ( tabla[index] < tabla[min] ){
				min = index;
			}
		}

		if ( min != ip ){
			swap ( &tabla[min], &tabla[ip] );
		}
	}

	return obs;
}

int SelectSortInv(int* tabla, int ip, int iu)
{
	int index = ip;
	int min = ip;
	int obs = 0;

	for (; ip < iu; ip++ ){

		for (min = ip, index = ip ; index <= iu; index++ ){

			obs++;
			if ( tabla[index] > tabla[min] ){
				min = index;
			}
		}

		if ( min != ip ){
			swap ( &tabla[min], &tabla[ip] );
		}

	}

	return obs;
}

void swap ( int * A, int * B ){
	int mem = *A;

	*A = *B;
	*B = mem;
}
