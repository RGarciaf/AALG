CC = gcc
CFLAGS = -Wall -ansi -pedantic -g -std=gnu99
COMPILE = -c
LIB = -Llib -lsource
HEADERS = -I includes

SRC = src/
SRCLIB = srclib/

EXE = ejercicio1 ejercicio2 ejercicio3 ejercicio4 ejercicio5 ejercicio6 ejercicio7

all: clean $(EXE) clear


clean:
	rm -f $(EXE) *.o *.h.gch lib/*

clear:
	rm -f *.o *.h.gch

libsource.a: ordenacion.o tiempos.o permutaciones.o busqueda.o
	ar rcs lib/libsource.a $^

ejercicio1: $(SRC)ejercicio1.c libsource.a
	$(CC) $(CFLAGS) $< $(HEADERS) $(LIB) -o $@

ejercicio2: $(SRC)ejercicio2.c libsource.a
	$(CC) $(CFLAGS) $< $(HEADERS) $(LIB) -o $@

ejercicio3: $(SRC)ejercicio3.c libsource.a
	$(CC) $(CFLAGS) $< $(HEADERS) $(LIB) -o $@

ejercicio4: $(SRC)ejercicio4.c libsource.a
	$(CC) $(CFLAGS) $< $(HEADERS) $(LIB) -o $@

ejercicio5: $(SRC)ejercicio5.c libsource.a
	$(CC) $(CFLAGS) $< $(HEADERS) $(LIB) -o $@

ejercicio6: $(SRC)ejercicio6.c libsource.a
	$(CC) $(CFLAGS) $< $(HEADERS) $(LIB) -o $@

ejercicio7: $(SRC)ejercicio7.c libsource.a
	$(CC) $(CFLAGS) $< $(HEADERS) $(LIB) -o $@

permutaciones.o : $(SRCLIB)permutaciones.c
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) $(COMPILE) $^ $(HEADERS)

ordenacion.o : $(SRCLIB)ordenacion.c
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) $(COMPILE) $^ $(HEADERS)

tiempos.o : $(SRCLIB)tiempos.c
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) $(COMPILE) $^ $(HEADERS)

busqueda.o : $(SRCLIB)busqueda.c
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) $(COMPILE) $^ $(HEADERS)



execute: ejercicio1_execute ejercicio2_execute ejercicio3_execute ejercicio4_execute ejercicio5_execute

ejercicio1_execute:
		@echo Ejecutando $@
		@echo "./ejercicio1 -limInf 1 -limSup 100 -numN 10"
		@./ejercicio1 -limInf 1 -limSup 100 -numN 10
		@echo "\n"

ejercicio2_execute:
		@echo Ejecutando $@
		@echo "./ejercicio2 -tamanio 10 -numP 10"
		@./ejercicio2 -tamanio 10 -numP 10
		@echo "\n"

ejercicio3_execute:
		@echo Ejecutando $@
		@echo "./ejercicio3 -tamanio 10 -numP 10"
		@./ejercicio3 -tamanio 10 -numP 10
		@echo "\n"

ejercicio4_execute:
		@echo Ejecutando $@
		@echo "./ejercicio4 -tamanio 10"
		@./ejercicio4 -tamanio 10
		@echo "\n"

ejercicio5_execute:
		@echo Ejecutando $@
		@echo "./ejercicio5 -num_min 100 -num_max 300 -incr 10 -numP 1000 -fichSalida ejercicio5.dat"
		@./ejercicio5 -num_min 100 -num_max 300 -incr 10 -numP 1000 -fichSalida ejercicio5.dat
		# @head mergesort_ejercicio5.dat
		# @head quicksort_ejercicio5.dat
		# @./gnuplot.sh
		# @echo "\n"



test: ejercicio1_test ejercicio2_test ejercicio3_test ejercicio4_test ejercicio5_test

ejercicio1_test:
		@echo Ejecutando $@
		@./ejercicio1 -limInf 1 -limSup 5 -numN 10
		@echo "\n"

ejercicio2_test:
		@echo Ejecutando $@
		@./ejercicio2 -tamanio 1 -numP 5
		@echo "\n"

ejercicio3_test:
		@echo Ejecutando $@
		@./ejercicio3 -tamanio 1 -numP 5
		@echo "\n"

ejercicio4_test:
		@echo Ejecutando $@
		@./ejercicio4 -tamanio 1
		@echo "\n"

ejercicio5_test:
		@echo Ejecutando $@
		@./ejercicio5 -num_min 1 -num_max 5 -incr 1 -numP 5 -fichSalida ejercicio5.log
		@head SelectSort_ejercicio5.log
		@head SelectSortInv_ejercicio5.log
		@echo "\n"

ejercicio6_test:
	@echo Ejecutando ejercicio6
	@./ejercicio6 -tamanio 10 -clave 5

ejercicio7_test:
	@echo Ejecutando ejercicio7
	@./ejercicio7 -num_min 10 -num_max 100 -incr 10 -n_veces 1 -fichSalida busqueda.dat