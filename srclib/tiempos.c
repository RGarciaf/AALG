/**
 *
 * Descripcion: Implementacion de funciones de tiempo
 *
 * Fichero: tiempos.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */

#include "tiempos.h"
#include "ordenacion.h"

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo,
                              int n_perms,
                              int N,
                              PTIEMPO ptiempo)
{
	int i, ob, mob;
	  int** permutaciones;
	  clock_t t_ini, t_fin;
	  double secs;


	  if(n_perms<1 || N<1 || !ptiempo)
	    return -1;

	  permutaciones = genera_permutaciones(n_perms,N);

	  t_ini = clock();

	  for(i = 0, mob = 0 ; i < n_perms ; i++){

	    ob = metodo(permutaciones[i],0, N-1);
	    mob += ob;


	    if(i == 0){

	      ptiempo->min_ob = ob;
	      ptiempo->max_ob = ob;

	    }
	    else{

	      if(ob < ptiempo->min_ob){
	        ptiempo->min_ob = ob;
	      }

	      if(ob > ptiempo->max_ob){
	        ptiempo->max_ob = ob;
	      }
	    }

	  }

	  t_fin = clock();

	  if(libera_permutaciones(permutaciones, n_perms)==ERR){
	    return ERR;
	  }

	  secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;

	  /* ptiempo->tiempo  = secs*1000000000.0; */
		ptiempo->tiempo  = (secs*1000000000.0)/(double)n_perms;

	  ptiempo->medio_ob = (double)mob/(double)n_perms;
		/*printf("%d / %d = %lf\n",mob, n_perms, (double)mob/(double)n_perms ); */

		ptiempo->n_perms = n_perms;
		ptiempo->tamanio = N;

	  return OK;
}

/***************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha:       */
/*                                                 */
/* Vuestra documentacion                           */
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero,
                                int num_min, int num_max,
                                int incr, int n_perms)
{
	int i, p;
  PTIEMPO ptiempo;


  if(!fichero || incr < 1 || num_min < 1 || num_min > num_max || n_perms < 1){
    return ERR;
  }


  p = ((num_max-num_min)/incr) + 1;


  ptiempo = (PTIEMPO) malloc(p*sizeof(TIEMPO));

  if(!ptiempo)
    return ERR;


  for(i=num_min, p=0; i<=num_max; i= i+incr, p++){
    tiempo_medio_ordenacion(metodo, n_perms, i, &ptiempo[p]);

  }

  guarda_tabla_tiempos(fichero, ptiempo, (p-1));

  free(ptiempo);

  return OK;
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int n_tiempos)
{
	PTIEMPO taux;
  int i;
  FILE* pf;

  if(!fichero || !tiempo || n_tiempos < 0){
    return ERR;
  }

  pf = fopen(fichero, "w");

  fprintf(pf, "Tamano  Tiempo(ns)  media_OB  max_OB  min_OB\n");

  for(taux = tiempo, i=0 ; i<n_tiempos ; taux++, i++ ){
  fprintf(pf, "  %d   %.2f    %.2f       %d     %d\n",taux->tamanio, taux->tiempo, taux->medio_ob, taux->max_ob, taux->min_ob);
  }

  fclose(pf);
  return OK;
}

/***************************************************/
/* Funcion: tiempo_medio_busqueda Fecha: 12/12/16  */
/*                                                 */
/* Analiza el tiempo y numero de OBs que tarda     */
/* un algoritmo en ejecutarse y lo guarda en una   */
/* tabla                                           */
/*                                                 */
/* Entrada:                                        */
/* metodo:    el algortimo a analizar              */
/* generador: el generador de claves utilizado     */
/* orden:     indicador de si esta ordenada o no   */
/*            la tabla a analizar                  */
/* n_claves:  numero de claves a analizar          */
/* ptiempo:   array que guarda los dato            */
/* n_veces:   numero de veces que se analiza el    */
/*            algoritmo                            */
/*                                                 */
/* Salida:                                         */
/* OK/ERR                                          */
/***************************************************/
short tiempo_medio_busqueda(pfunc_busqueda metodo, pfunc_generador_claves generador, char orden, int n_claves, int n_veces, PTIEMPO ptiempo)
{

	int i, ob, mob;
	clock_t t_ini, t_fin;
	double secs;
	PDICC dic;
	int ppos;
	int *perm;
	int *claves;

	if (n_claves < 1 || !ptiempo)
		return -1;

	dic = ini_diccionario(n_claves, orden);
	if (!dic)
	{
		return ERR;
	}

	perm = genera_perm(n_claves);
	if (!perm)
	{
		libera_diccionario(dic);
		return ERR;
	}

	if (insercion_masiva_diccionario(dic, perm, n_claves) == ERR)
	{
		free(perm);
		libera_diccionario(dic);
		return ERR;
	}

	claves = ((int *)malloc(sizeof(int) * n_claves * n_veces)); /*tabla de claves a buscar*/
	if (!claves)
	{
		free(perm);
		libera_diccionario(dic);
		return ERR;
	}

	generador(claves, (n_claves * n_veces), n_claves);

	for (i = 0, ob = 0, mob = 0, secs = 0; i < n_veces * n_claves; i++)
	{

		t_ini = clock();
		ob = busca_diccionario(dic, claves[i], &ppos, metodo);
		t_fin = clock(); /*Solo queremos el tiempo de busqueda del metodo*/
		if (ob > ERR)
		{
			mob += ob;

			if (i == 0)
			{
				ptiempo->min_ob = ob;
				ptiempo->max_ob = ob;
			}
			else
			{
				if (ob < ptiempo->min_ob)
				{
					ptiempo->min_ob = ob;
				}

				if (ob > ptiempo->max_ob)
				{
					ptiempo->max_ob = ob;
				}
			}
			secs += (double)(t_fin - t_ini) / ((double)CLOCKS_PER_SEC / 1000000000);
		}
	}
	free(claves);
	free(perm);
	libera_diccionario(dic);

	ptiempo->tiempo = (secs / (n_veces * n_claves)); /*media de lo que tarda en buscar n_veces una clave*/

	ptiempo->medio_ob = mob / (n_veces * n_claves);
	ptiempo->n_veces = n_veces;
	ptiempo->tamanio = n_claves;

	return OK;
}

/****************************************************/
/* Funcion: genera_tiempo_busqueda Fecha: 12/11/16  */
/*                                                  */
/* Analiza el tiempo y numero de OBs que tarda      */
/* un algoritmo en ejecutarse varias veces          */
/*                                                  */
/* Entrada:                                         */
/* metodo:    el algortimo a analizar               */
/* generador: el generador de claves utilizado      */
/* orden:     indicador de si esta ordenada o no    */
/*            la tabla a analizar                   */
/* fichero:   fichero donde se guardara la info     */
/* num_min:   tamaño minimo desde el que se analiza */
/* num_max:   tamaño maximo a analizar              */
/* n_veces:   numero de veces que se analiza el     */
/*            algoritmo                             */
/*                                                  */
/* Salida:                                          */
/* OK/ERR                                           */
/****************************************************/
short genera_tiempos_busqueda(pfunc_busqueda metodo, pfunc_generador_claves generador, char orden, char *fichero, int num_min, int num_max, int incr, int n_veces)
{

	int n_claves, i;
	PTIEMPO ptiempo;

	if (!fichero || num_max < num_min || incr < 1 || n_veces < 1)
	{
		return ERR;
	}

	ptiempo = (PTIEMPO)malloc(sizeof(TIEMPO) * ((num_max - num_min) / incr + 1));
	if (!ptiempo)
	{
		return ERR;
	}

	for (i = 0, n_claves = num_min; n_claves <= num_max; n_claves += incr, i++)
	{

		tiempo_medio_busqueda(metodo, generador, orden, n_claves, n_veces, &ptiempo[i]);
	}

	ptiempo->n_perms = i;

	guarda_tabla_tiempos(fichero, ptiempo, i);

	free(ptiempo);

	return OK;
}
