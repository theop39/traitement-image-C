#ifndef IMAGE_H
#define IMAGE_H

typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;

#define DEBUG 	0  // utilis� en interne dans le module entree_sortie.c
#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM
#define SEUIL1_PIXEL(valeur, seuil) (valeur < seuil) ? (0) : (255)
#define AFFICHER_FONCTION printf("%s\n",  __func__)
#define MIROIR_HORIZONTAL 0
#define MIROIR_VERTICAL 1

void LibererImage(t_image* image);
t_image* CreerImage(int largeur, int hauteur);

#endif
