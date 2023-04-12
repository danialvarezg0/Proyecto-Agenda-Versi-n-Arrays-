# *****************************************************************
# Programación I. Curso 2022-2023
# Compilación del proyecto Agenda
# *****************************************************************

CC = gcc -Wall

all: agenda

display.o: display.c display.h
	$(CC) -c display.c

data.o: data.c data.h
	$(CC) -c data.c

agenda: agenda.c display.o data.o
	$(CC) display.o data.o agenda.c -o agenda

clean:
	rm -f agenda *.o *.bak *~

