/**
 *
 * Descripcion: Implementacion funciones para busqueda 
 *
 * Fichero: busqueda.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 11-11-2016
 *
 */

#include "busqueda.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 *  Funciones de geracion de claves
 *
 *  Descripcion: Recibe el numero de claves que hay que generar
 *               en el parametro n_claves. Las claves generadas
 *               iran de 1 a max. Las claves se devuelven en 
 *               el parametro claves que se debe reservar externamente
 *               a la funcion.
 */

/**
 *  Funcion: generador_claves_uniforme
 *               Esta fucnion genera todas las claves de 1 a max de forma 
 *               secuencial. Si n_claves==max entonces se generan cada clave
 *               una unica vez.
 */
void generador_claves_uniforme(int *claves, int n_claves, int max)
{
	int i;

	for (i = 0; i < n_claves; i++)
	{
		claves[i] = 1 + (i % max);
	}

	return;
}

/**
 *  Funcion: generador_claves_potencial
 *               Esta funcion genera siguiendo una distribucion aproximadamente
 *               potencial. Siendo los valores mas pequenos mucho mas probables
 *               que los mas grandes. El valor 1 tiene una probabilidad del 50%,
 *               el dos del 17%, el tres el 9%, etc.
 */
void generador_claves_potencial(int *claves, int n_claves, int max)
{
	int i;

	for (i = 0; i < n_claves; i++)
	{
		claves[i] = (1 + max) / (1 + max * ((double)rand() / RAND_MAX));
	}

	return;
}

/***************************************************/
/* Funcion: ini_diccionario      Fecha: 12/12/16   */
/*                                                 */
/* Crea un diccionario                             */
/*                                                 */
/* Entrada:                                        */
/* tamaño:  tamaño de la tabla                     */
/* orden:   indica si la tabla esta ordenada o no  */
/*                                                 */
/***************************************************/
PDICC ini_diccionario(int tamanio, char orden)
{
	PDICC dic = NULL;
	int *tabla = NULL;

	if (tamanio < 1 || (orden != NO_ORDENADO && orden != ORDENADO))
	{
		return NULL;
	}

	dic = (PDICC)malloc(sizeof(DICC));
	if (!dic)
	{
		return NULL;
	}

	tabla = (int *)malloc(sizeof(int) * tamanio);
	if (!tabla)
	{
		return NULL;
	}

	dic->tamanio = tamanio;
	dic->orden = orden;
	dic->n_datos = 0;
	dic->tabla = tabla;

	return dic;
}

void libera_diccionario(PDICC pdicc)
{
	if (!pdicc)
	{
		return;
	}

	free(pdicc->tabla);
	free(pdicc);

	return;
}

int inserta_diccionario(PDICC pdicc, int clave)
{
	int j, A;
	int ip = 0;
	int ob = 0;
	int n_datos;
	if (!pdicc || clave < 0)
	{
		return ERR;
	}

	if (pdicc->n_datos >= pdicc->tamanio)
	{
		return ERR;
	}

	pdicc->tabla[pdicc->n_datos] = clave;
	n_datos = pdicc->n_datos;
	pdicc->n_datos++;

	if (pdicc->orden == ORDENADO)
	{
		A = pdicc->tabla[n_datos];
		j = n_datos - 1;

		while (j >= ip && pdicc->tabla[j] > A)
		{
			ob++;
			pdicc->tabla[j + 1] = pdicc->tabla[j];
			j--;
		}
		pdicc->tabla[j + 1] = A;
		if (j >= ip)
		{
			ob++;
		}
	}

	return ob;
}

int insercion_masiva_diccionario(PDICC pdicc, int *claves, int n_claves)
{
	int i;

	if (!pdicc || !claves)
	{
		return ERR;
	}

	for (i = 0; i < n_claves; i++)
	{
		if (inserta_diccionario(pdicc, claves[i]) == ERR)
		{
			return ERR;
		}
	}

	return OK;
}

int busca_diccionario(PDICC pdicc, int clave, int *ppos, pfunc_busqueda metodo)
{
	pfunc_busqueda metodo2 = bbin;
	int ob = 0;

	if (!pdicc || !ppos || !metodo || clave < 0)
	{
		return ERR;
	}

	if (metodo == metodo2 && pdicc->orden == NO_ORDENADO)
	{
		return ERR;
	}

	ob = metodo(pdicc->tabla, 0, pdicc->n_datos - 1, clave, ppos);

	if (*ppos < 0)
	{
		*ppos = NO_ENCONTRADO;
		return NO_ENCONTRADO;
	}
	return ob;
}

void imprime_diccionario(PDICC pdicc)
{
	int i;

	if (!pdicc)
	{
		printf("No hay nada que imprimir\n");
		return;
	}

	/*printf("Tamanio: %d\n",pdicc.tamano);
	printf("Num de Datos: %d\n", pdicc.n_datos);
	if(pdicc.orden == ORDENADO){
	    printf("Orden: Ordenado\n");
	}
	else{
	    printf("Orden: No Ordenado\n");
	}*/
	printf("Tabla: ");
	for (i = 0; i < pdicc->tamanio; i++)
	{
		printf("%d ", pdicc->tabla[i]);
	}
	printf("\n");

	return;
}

/* Funciones de busqueda del TAD Diccionario */
int bbin(int *tabla, int P, int U, int clave, int *ppos)
{
	int ob = 0;
	int medio;

	while (P <= U)
	{
		medio = ((U - P) / 2) + P;
		if (tabla[medio] == clave)
		{
			*ppos = medio + 1; /* Porque medio es el indice y ppos la posicion a mostrar*/
			return ob + 1;
		}
		else if (clave < tabla[medio])
		{
			U = medio - 1;
			ob++;
		}
		else if (clave > tabla[medio])
		{
			P = medio + 1;
			ob++;
		}
	}

	*ppos = NO_ENCONTRADO;
	return ERR;
}

int blin(int *tabla, int P, int U, int clave, int *ppos)
{
	int i;

	for (i = P; i <= U; i++)
	{
		if (tabla[i] == clave)
		{
			*ppos = ++i;
			return i;
		}
	}

	*ppos = NO_ENCONTRADO;
	return ERR;
}

int blin_auto(int *tabla, int P, int U, int clave, int *ppos)
{
	int i, aux;

	for (i = P; i <= U; i++)
	{
		if (tabla[i] == clave)
		{
			*ppos = i + 1;
			if (i != P)
			{ /*Si el elemento no es encontrado en la primera posicion, swapealo con el inmediatamente contrario*/
				aux = tabla[i];
				tabla[i] = tabla[i - 1];
				tabla[i - 1] = aux;
			}
			return i + 1;
		}
	}
	*ppos = NO_ENCONTRADO;
	return ERR;
}
