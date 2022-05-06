#include <stdio.h>
#include <stdlib.h>

typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;

#define DEBUG 	0  // utilis� en interne dans le module entree_sortie.c
#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM

t_image* CreerImage(int largeur, int hauteur) {
  t_image *image;

  image = (t_image*) malloc(sizeof(t_image));

  image->pixels = (unsigned char*) malloc(largeur * hauteur * sizeof(unsigned char) + 1);

  image->hauteur = hauteur;
  image->largeur = largeur;

  return image;
}

void ImageUnie(t_image *image, unsigned char couleur) {
  for (int i = 0; i < image->largeur * image->hauteur; i++) {
    image->pixels[i] = couleur;
  }
}

void Negatif(t_image* image) {
  for (int i = 0; i < image->largeur * image->hauteur; i++) {
    image->pixels[i] = 255 - image->pixels[i];
  }
}

void Seuillage(t_image* image, unsigned char seuil) {
  for (int i = 0; i < image->largeur * image->hauteur; i++) {
    if (image->pixels[i] < seuil) {
      image->pixels[i] = 0;
    }
    else {
      image->pixels [i] = 255;
    }
  }
}

void Degrade(t_image* image) {
  float pas = 0;

  for (int i = 0; i < image->largeur * image->hauteur; i++) {
    if (i % image->largeur == 0) {
      pas = 0.0;
    }

    image->pixels[i] = pas;

    pas += 255.0 / (image->largeur - 1.0);
  }
}

void LibererImage(t_image* image) {
  free(image->pixels);
  free(image);
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
	im = CreerImageBis(largeur, hauteur) ;
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

int main(void) {
  t_image *image;

  image = LireImagePGM("voiron.pgm");
  EcrireImagePGM("voiron_copie.pgm", *image);
  LibererImage(image);
  
  return EXIT_SUCCESS;
}
