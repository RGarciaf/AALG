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
int merge(int* tabla, int ip, int iu, int medio);
int rec_mergesort(int* tabla, int ip, int iu);
void copiar(int* tabAux, int* tabla, int ip, int iu);

int quicksort_stat(int* tabla, int ip, int iu);
int quicksort_avg(int* tabla, int ip, int iu);
int partir(int* tabla, int ip, int iu, int* pos);
int partir_avg(int* tabla, int ip, int iu, int* pos);
int partir_stat(int* tabla, int ip, int iu, int* pos);

int medio(int *tabla, int ip, int iu, int *pos);
int medio_avg(int *tabla, int ip, int iu, int *pos);
int medio_stat(int* tabla, int ip, int iu, int *pos);

/***************************************************/
/* Funcion: SelectSort    Fecha:                   */
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

/***************************************************/
/* Funcion: SelectSortInv    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
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

/***************************************************/
/* Funcion: swap    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
void swap ( int * A, int * B ){
	int mem = *A;

	*A = *B;
	*B = mem;
}

/***************************************************/
/* Funcion: merge                                  */
/*                                                 */
/* Algortimo de ordenacion de tablas               */
/*                                                 */
/* Entrada:                                        */
/* tabla: tabla a ordenar                          */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/* medio: posicion de division de la tabla         */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int merge(int* tabla, int ip, int iu, int medio)
{
  int* tabAux;
  int i, j, k, ob = 0;

  tabAux = (int*) malloc(sizeof(int) * (iu-ip+1));

  if(!tabAux)
    return ERR;

  i = ip;
  j = medio +1;
  k = 0;

  while( i <= medio && j <= iu ){


    if(tabla[i] < tabla[j]){

      tabAux[k] = tabla[i];
      i++;

    } else {
      tabAux[k] = tabla[j];
      j++;

    }


    k++;
  }

  ob=k;

  if( i > medio){

    if(j > iu){

    }

    while(j <= iu){

      tabAux[k] = tabla[j];
      j++;
      k++;
    }

  } else if(j > iu){


    if(i > medio){

    }

    while(i <= medio){
      tabAux[k] = tabla[i];
      i++;
      k++;
    }

  }


  copiar(tabAux, tabla, ip, iu);
  free(tabAux);

  return ob;

}

/***************************************************/
/* Funcion: mergesort    Fecha:                    */
/*                                                 */
/* Algortimo de ordenacion de tablas               */
/*                                                 */
/* Entrada:                                        */
/* tabla: tabla a ordenar                          */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int mergesort(int* tabla, int ip, int iu)
{
  int M = (ip + iu)/2;
  int ob = 0;

  if(ip > iu || !tabla)
    return ERR;

  if(ip == iu)
    return 0;

  ob += rec_mergesort(tabla, ip, M);
  ob += rec_mergesort(tabla, M+1, iu);

  return ob + merge(tabla, ip, iu, M);

}

/***************************************************/
/* Funcion: rec_mergesort    Fecha:                */
/*                                                 */
/* Algortimo de ordenacion de tablas recursivo     */
/*                                                 */
/* Entrada:                                        */
/* tabla: tabla a ordenar                          */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int rec_mergesort(int* tabla, int ip, int iu)
{
  int M = (ip + iu)/2;
  int ob = 0;

  if(ip == iu)
    return 0;

  ob += rec_mergesort(tabla, ip, M);
  ob += rec_mergesort(tabla, M+1, iu);

  return ob + merge(tabla, ip, iu, M);

}

/***************************************************/
/* Funcion: copiar           Fecha:                */
/*                                                 */
/* Copia una tabla                                 */
/*                                                 */
/* Entrada:                                        */
/* tabla: tabla a copiar                           */
/* tabAux: tabla donde se va a copiar              */
/* ip: posicion desde la que se quiere copiar      */
/* iu: posicion hasta la que se quiere copair      */
/*                                                 */
/***************************************************/
void copiar(int* tabAux, int* tabla, int ip, int iu)
{

  int i=0;

  while(ip <= iu){
    tabla[ip++] = tabAux[i++];
  }
}

/***************************************************/
/* Funcion: QuickSort    Fecha:                    */
/*                                                 */
/* Algortimo de ordenacion de tablas               */
/*                                                 */
/* Entrada:                                        */
/* tabla:  tabla a ordenar                         */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int quicksort(int* tabla, int ip, int iu){
  int m;
  int ob = 0;

  if (ip>iu || !tabla){
    return ERR;
  }

  else if (ip==iu){
    return OK;
  }

  else{

    ob+= partir(tabla, ip, iu, &m);

    if(ip<m-1){
      ob+= quicksort(tabla, ip, m-1);
    }

    if (m+1 < iu){
      ob+= quicksort(tabla, m+1, iu);
    }

    return ob;
  }
}

/***************************************************/
/* Funcion: InsertSort_stat    Fecha:              */
/*                                                 */
/* Algortimo de ordenacion de tablas               */
/*                                                 */
/* Entrada:                                        */
/* tabla:  tabla a ordenar                         */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int quicksort_stat(int* tabla, int ip, int iu){
  int m;
  int ob = 0;

  if (ip>iu || !tabla){
    return ERR;
  }

  else if (ip==iu){
    return OK;
  }

  else{

    ob+= partir_stat(tabla, ip, iu, &m);

    if(ip<m-1){
      ob+= quicksort_stat(tabla, ip, m-1);
    }

    if (m+1 < iu){
      ob+= quicksort_stat(tabla, m+1, iu);
    }

    return ob;
  }
}

/***************************************************/
/* Funcion: InsertSort_avg    Fecha:               */
/*                                                 */
/* Algortimo de ordenacion de tablas               */
/*                                                 */
/* Entrada:                                        */
/* tabla:  tabla a ordenar                         */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int quicksort_avg(int* tabla, int ip, int iu)
{
  int m;
  int ob = 0;

  if (ip>iu || !tabla){
    return ERR;
  }

  else if (ip==iu){
    return OK;
  }

  else{

    ob+= partir_avg(tabla, ip, iu, &m);

    if(ip<m-1){
      ob+= quicksort_avg(tabla, ip, m-1);
    }

    if (m+1 < iu){
      ob+= quicksort_avg(tabla, m+1, iu);
    }

    return ob;
  }
}

/***************************************************/
/* Funcion: Partir    Fecha:                       */
/*                                                 */
/* Parte la tabla que le pasan en 2 subtablas      */
/*                                                 */
/* Entrada:                                        */
/* tabla:  tabla a ordenar                         */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/* pos: posicion de pivote donde partir la tabla   */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int partir(int* tabla, int ip, int iu, int* pos){
  int k, i;
  int ob = 0;

  if(!tabla || !pos){
    return ERR;
  }

  medio(tabla, ip, iu, pos);

  k=tabla[*pos];

  swap( &tabla[ip], &tabla[*pos]);
  *pos=ip;

  for(i=ip+1; i<=iu; i++){
    ob++;
    if(tabla[i]<k){
      (*pos)++;
      swap( &tabla[i], &tabla[*pos]);
    }
  }
  swap( &tabla[ip], &tabla[*pos]);
  return ob;
}

/***************************************************/
/* Funcion: Partir_avg    Fecha:                   */
/*                                                 */
/* Parte la tabla que le pasan en 2 subtablas      */
/*                                                 */
/* Entrada:                                        */
/* tabla:  tabla a ordenar                         */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/* pos: posicion de pivote donde partir la tabla   */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int partir_avg(int* tabla, int ip, int iu, int* pos){
  int k, i;
  int ob = 0;

  if(!tabla || !pos){
    return ERR;
  }

  medio_avg(tabla, ip, iu, pos);

  k=tabla[*pos];

  swap( &tabla[ip], &tabla[*pos]);
  *pos=ip;

  for(i=ip+1; i<=iu; i++){
    ob++;
    if(tabla[i]<k){
      (*pos)++;
      swap( &tabla[i], &tabla[*pos]);
    }
  }
  swap( &tabla[ip], &tabla[*pos]);
  return ob;
}

/***************************************************/
/* Funcion: Partir_stat    Fecha:                  */
/*                                                 */
/* Parte la tabla que le pasan en 2 subtablas      */
/*                                                 */
/* Entrada:                                        */
/* tabla:  tabla a ordenar                         */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/* pos: posicion de pivote donde partir la tabla   */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int partir_stat(int* tabla, int ip, int iu, int* pos){
  int k, i;
  int ob = 0;

  if(!tabla || !pos){
    return ERR;
  }
  medio_avg(tabla, ip, iu, pos);
  medio_stat(tabla, ip, iu, pos);

  k=tabla[*pos];

  swap( &tabla[ip], &tabla[*pos]);
  *pos=ip;

  for(i=ip+1; i<=iu; i++){
    ob++;
    if(tabla[i]<k){
      (*pos)++;
      swap( &tabla[i], &tabla[*pos]);
    }
  }
  swap( &tabla[ip], &tabla[*pos]);
  return ob;
}

/***************************************************/
/* Funcion: medio    Fecha:                        */
/*                                                 */
/* Selecciona el primer elemento de la tabla como  */
/* pivote                                          */
/*                                                 */
/* Entrada:                                        */
/* tabla:  tabla a ordenar                         */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/* pos: posicion de pivote donde partir la tabla   */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int medio(int *tabla, int ip, int iu, int *pos)
{
  if(!tabla){
    return ERR;
  }

  *pos = ip;
  return 0;
}

/***************************************************/
/* Funcion: medio_avg    Fecha:                    */
/*                                                 */
/* Selecciona el elemento de en medio de la tabla  */
/* como pivote                                     */
/*                                                 */
/* Entrada:                                        */
/* tabla:  tabla a ordenar                         */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/* pos: posicion de pivote donde partir la tabla   */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int medio_avg(int *tabla, int ip, int iu, int *pos)
{

  if(!tabla || !pos){
    return ERR;
  }

  *pos = (ip+iu)/2;

  return 0;
}

/***************************************************/
/* Funcion: medio_stat    Fecha:                   */
/*                                                 */
/* Selecciona el elemento con valor intermedio de  */
/* la tabla entre el priemro, el de en medio       */
/* y el ultimo                                     */
/*                                                 */
/* Entrada:                                        */
/* tabla:  tabla a ordenar                         */
/* ip: posicion desde la que se quiere ordenar     */
/* iu: posicion hasta la que se quiere ordenar     */
/* pos: posicion de pivote donde partir la tabla   */
/*                                                 */
/* Salida:                                         */
/* ob: numero de operaciones basicas realizadas    */
/***************************************************/
int medio_stat(int* tabla, int ip, int iu, int *pos)
{
  int ob=0;

  if(!tabla || !pos){
    return ERR;
  }

  if (tabla[ip] > tabla[*pos]) {
    ob++;
    if (tabla[*pos] > tabla[iu]) {
      ob++;
      return ob;
    }
    else if (tabla[ip] > tabla[iu]) {
      ob++;
      *pos=iu;
      return ob;
    }
    else{
      ob++;
      *pos=ip;
      return ob;
    }
  }
  else{
    ob++;
    if (tabla[ip] > tabla[iu]){
      ob++;
      *pos=ip;
      return ob;
    }
    else if (tabla[*pos] > tabla[iu]){
      ob++;
      *pos=iu;
      return ob;
    }
    else{
      ob++;
      return ob;
    }
  }
  return ob;
}
