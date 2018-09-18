# Makefile de redes2
CC = gcc
CFLAGS = -Wall -ansi -g -std=gnu99
COMPILE = -c
LIB = -Llib -lsource
HEADERS = -I includes

SRC = src/
SRCLIB = srclib/

EXE = ejercicio1 ejercicio2 ejercicio3 ejercicio4 ejercicio5

all: clean $(EXE)


clean:
		rm -f $(EXE) *.o *.h.gch lib/*

libsource.a: ordenacion.o tiempos.o permutaciones.o
	ar rcs lib/libsource.a $^
	rm -f *.o

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
