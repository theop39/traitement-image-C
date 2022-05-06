#include <stdio.h>
#include <stdlib.h>
#include "image.h"

t_image* CreerImage(int largeur, int hauteur) {
  t_image *image;

  image = (t_image*) malloc(sizeof(t_image));

  image->pixels = (unsigned char*) malloc(largeur * hauteur * sizeof(unsigned char) + 1);

  image->hauteur = hauteur;
  image->largeur = largeur;

  return image;
}

void LibererImage(t_image* image) {
  free(image->pixels);
  free(image);
}
