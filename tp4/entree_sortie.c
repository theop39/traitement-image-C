#include <stdio.h>
#include <stdlib.h>
#include "image.h"


void AfficherImage(char* nomFichier) {
  char cmd[25];

  sprintf(cmd, "/snap/bin/xv %s &", nomFichier);

  system(cmd);
}

int EcrireImagePGM(const char* nomFichier, const t_image im){
  FILE *fichier;

  fichier = fopen(nomFichier, "w");

  if (fichier == NULL) {
    fprintf(stderr, "Erreur création image");
    exit(ERREUR);
  }

  fprintf(fichier, "P5\n") ;
	fprintf(fichier, "%d %d\n", im.largeur, im.hauteur) ;
	fprintf(fichier, "255\n") ;

  fwrite(im.pixels, im.largeur, im.hauteur, fichier) ;

  fclose(fichier);

  return OK;
}

t_image* LireImagePGM(const char* nomFichier)
//---------------------------------------------------------------------------
// crée dynamiquement une structure image
// retourne la structure image remplie à partir du fichier nomFichier
// si problème, retourne NULL
{
	FILE* f ;
	char s[256] ;
	char* c_res ;
	int i, largeur, hauteur ;
	t_image* im ; // la structure qui sera renvoyée

// ouverture de l'image en lecture
	f = fopen(nomFichier, "rb") ;	// b non necessaire sou Linux
	if (!f)
	{
		printf("Erreur ouverture de fichier\n") ;
		return(NULL) ;
	}

// lecture des 3 premières lignes et récupération dimensions de l'image
	for (i=1; i<4; i++)
	{
		if (i == 2)
		{
			fscanf(f, "%d %d\n", &largeur, &hauteur) ;
#if DEBUG
			printf("Largeur=%d ; hauteur=%d\n", largeur, hauteur) ;
#endif
		}
		else
		{
			c_res = fgets(s, 255, f) ;
			if (c_res == NULL)
			{
				printf("Erreur lecture ligne %d\n", i) ;
				fclose(f) ;
				return(NULL) ;
			}
#if DEBUG
			printf("ligne %d : %s", i, s) ;
#endif
		}
	}

// allocation mémoire pour les pixels de l'image
	im = CreerImage(largeur, hauteur) ;
	if (!im)
	{
		fclose(f) ;
		return(im) ;
	}

// lecture des pixels de l'image
	im->largeur = largeur ;
	im->hauteur = hauteur ;
	fread(im->pixels, im->largeur,im->hauteur, f) ;

// fermeture fichier
	fclose(f) ;
	return (im) ;
}
