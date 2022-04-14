main : nouveau_main.o dijkstra.o conducteur.o systemeRevenusEvenements.o import.o sauvegarde.o
	gcc -o main dijkstra.o conducteur.o nouveau_main.o systemeRevenusEvenements.o import.o sauvegarde.o

main.o : main.c dijkstra.h conducteur.h systemeRevenusEvenements.h import.h
	gcc -Wall nouveau_main.c -c

dijkstra.o : dijkstra.c dijkstra.h
	gcc -Wall dijkstra.c -c

conducteur.o : conducteur.c conducteur.h systemeRevenusEvenements.h 
	gcc -Wall conducteur.c -c

systemeRevenusEvenements.o : systemeRevenusEvenements.c systemeRevenusEvenements.h
	gcc -Wall systemeRevenusEvenements.c -c

import.o : import.c import.h
	gcc -Wall import.c -c

sauvegarde.o : sauvegarde.c sauvegarde.h
	gcc -Wall sauvegarde.c -c
