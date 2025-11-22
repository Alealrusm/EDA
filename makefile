TARGET = out
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -D_DEFAULT_SOURCE
SOURCES = main.c Funciones.c Estructuras.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

main.o: main.c Funciones.h Estructuras.h
	$(CC) $(CFLAGS) -c main.c

Funciones.o: Funciones.c Funciones.h Estructuras.h
	$(CC) $(CFLAGS) -c Funciones.c

Estructuras.o: Estructuras.c Estructuras.h
	$(CC) $(CFLAGS) -c Estructuras.c

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean