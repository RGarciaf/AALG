/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include "permutaciones.h"
#include <stdlib.h>

/***************************************************/
/* Funcion: aleat_num Fecha:                       */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{
  int num;

  if(inf>sup){
    return -1;
  }

  num = (rand()%(sup-inf+1)) + inf;

  return num;
}

/***************************************************/
/* Funcion: genera_perm Fecha:                     */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int* genera_perm(int n)
{
  int i;
  int* perm;
  int aux;
  int ale_num;

  if(n<1){
    return NULL;
  }

  perm = (int*) malloc (n*sizeof(int));

  if(!perm){
    return NULL;
  }

  for(i=0; i<n; i++){
    perm[i] = i+1; /*sumas 1 paras que la perm empiece en el 1*/
  }

  for(i=0; i<n; i++){

    ale_num = aleat_num(0, n-1); /*posicion donde voy a meter aux*/
    aux = perm[ale_num];   /*guardo el numero que esta en la posicion a al que lo voy a mover*/
    perm[ale_num] = perm[i];   /*permuto el numero*/
    perm[i] = aux;              /*meto el numero de antes en la posicion del que he querido mover*/
  }

  return perm;
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores:                                        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int N: Numero de elementos de cada              */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int tamanio)
{
  int i;
    int** array;


    array = (int**) malloc(n_perms*sizeof(int*));

    if(!array)
      return NULL;

    for(i=0; i<n_perms; i++){
      array[i] = genera_perm(tamanio);
      if(!array[i]){
        while(i != 0){
          free(array[i]);
          i--;
        }
        free (array);
        return NULL;
      }
    }

    return array;
}
