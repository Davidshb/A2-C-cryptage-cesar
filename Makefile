all: exec

exec: main.o cesar.o
	gcc *.o -o exec

main.o: main.c cesar.h gestion_fichier.o
	gcc -c main.c

cesar.o: cesar.c cesar.h
	gcc -c cesar.c

gestion_fichier.o: gestion_fichier.c gestion_fichier.h
	gcc -c gestion_fichier.c
