/**************************************************/
/* Programa: ejercicio4       Fecha:              */
/* Autores:                                       */
/*                                                */
/* Programa que Comprueba SelectSort              */
/*                                                */
/* Entrada: Linea de comandos                     */
/* -tamanio: numero elementos permutacion         */
/* Salida: 0: OK, -1: ERR                         */
/**************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "permutaciones.h"
#include "ordenacion.h"

typedef int (* pfunc_busqueda)(int* tabla, int ip, int iu);

void copiarM(int* tabAux, int* tabla, int ip, int iu)
{

  int i=0;

  while(ip < iu){
    tabla[ip++] = tabAux[i++];
  }
}

void bucle(int tamano, int * perm, pfunc_busqueda sorter){
  int j, ret;

  for(j = 0; j < tamano; j++) {
    printf("%d \t", perm[j]);
  }
	printf("\n" );

  ret = sorter(perm, 0, tamano-1);

  if (ret == ERR) {
    printf("Error: Error en BubbleSort\n");
    free(perm);
    exit(-1);
  }

  for(j = 0; j < tamano; j++) {
    printf("%d \t", perm[j]);
  }
  printf("\nObs: %d\n", ret);
}

int main(int argc, char** argv)
{
  int tamano, i, j;
  // int j, ret;
  int* perm = NULL, * perm2 = NULL;

  srand(time(NULL));

  if (argc != 3) {
    fprintf(stderr, "Error en los parametros de entrada:\n\n");
    fprintf(stderr, "%s -tamanio <int>\n", argv[0]);
    fprintf(stderr, "Donde:\n");
    fprintf(stderr, " -tamanio : numero elementos permutacion.\n");
    return 0;
  }
  printf("Practica numero 1, apartado 4\n");
  printf("Realizada por: Roman Garcia\n");
  printf("Grupo: 1271\n");
printf("Pareja: 9\n");

  /* comprueba la linea de comandos */
  for(i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-tamanio") == 0) {
      tamano = atoi(argv[++i]);
    } else {
      fprintf(stderr, "Parametro %s es incorrecto\n", argv[i]);
    }
  }

  perm2 = (int*) malloc (tamano*sizeof(int));

  if(!perm2){
    return -1;
  }

  perm = genera_perm(tamano);
  copiarM(perm, perm2, 0,tamano );

  if (perm == NULL) { /* error */
    printf("Error: No hay memoria\n");
    exit(-1);
  }

  for(j = 0; j < tamano; j++) {
    perm[j] =  j;
    perm2[j] = j;
    printf("%d \t", perm[j]);
  }

	bucle(tamano, perm, (pfunc_busqueda) quicksort);
  bucle(tamano, perm2, (pfunc_busqueda) quicksort_src);

  free(perm);
  free(perm2);

  return 0;
}
