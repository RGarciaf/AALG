Practica 1 Analisis de Algoritmos

Roman Garcia Fernandez
Pareja 9
Grupo 1271

Para la correcta compilacion ES NECESARIO QUE EXISTA LA CARPETA ./LIB en la misma localizacion del makefile

He creado un makefile con el que compilar dada la organizacion que he seguido. 
Existe el makefile facilitado pero para usarlo hará falta poner todos los archivos en la misma ruta que el makefile

El makefile que he creado puede realizar las mismas funciones que el facilitado:
	Con "make test" ejecutará todos los test con los parametros dados en el anterior makefile
	Con "make execute" se ejecutaran todos los ejercicios con los valores usados para la documentacion

Una de las modificaciones es la creacion de una libreria con los modulos esenciales: "libsourse.a"
Se puede compilar con "make libsource.a"

Por defecto, "make all", elimina los archivos objeto. 
Para mantenerlos se puede compilar cada uno de los ejercicios por separado: "make ejercicioX" (donde X es el numero de ejercicio a compilar)

La organizacion del codigo es la siguiente:
	En la carpeta src se encuentra el codigo facilitado de los ejercicios
	En la carpeta srclib se encuentra el codigo con los modulos tiempo, permutaciones y ordenacion
	En la carpeta includes se encuentran los archivos de cabecera de todos los archivos .c

