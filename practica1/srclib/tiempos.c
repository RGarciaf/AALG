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

	  ptiempo->n_elems = n_perms;
	  ptiempo->N = N;

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

  for(taux = tiempo, i=0 ; i<=n_tiempos ; taux++, i++ ){
  fprintf(pf, "  %d   %.2f    %.2f       %d     %d\n",taux->N, taux->tiempo, taux->medio_ob, taux->max_ob, taux->min_ob);
  }

  fclose(pf);
  return OK;
}
