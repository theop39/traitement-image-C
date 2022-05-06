traitement_image: image.o main.o traitement.o entree_sortie.o
    gcc image.o main.o traitement.o entree_sortie.o -o traitement_image

main.o: main.c
		    gcc -o main.o -c main.c -W -Wall -ansi -pedantic

traitement_image.o: traitement_image.c
    gcc -o traitement_image.o -c traitement_image.c-W -Wall -ansi -pedantic

entree_sortie.o: entree_sortie.c
	gcc -o entree_sortie.o -c entree_sortie.c -W -Wall -ansi -pedantic

image.o: image.o
	gcc -o image.o -c image.c -W -Wall -ansi -pedantic
