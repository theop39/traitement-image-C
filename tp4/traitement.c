#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void Degrade(t_image* image) {
  float pas = 0;

#if (DEBUG)
  AFFICHER_FONCTION;
#else
for (int i = 0; i < image->largeur * image->hauteur; i++) {
  if (i % image->largeur == 0) {
    pas = 0.0;
  }
  image->pixels[i] = pas;

  pas += 255.0 / (image->largeur - 1.0);
}
#endif
}

void ImageUnie(t_image *image, unsigned char couleur) {
  #if DEBUG
    AFFICHER_FONCTION;
  #else
  for (int i = 0; i < image->largeur * image->hauteur; i++) {
    image->pixels[i] = couleur;
  }
  #endif
}

void Negatif(t_image* image) {
  #if DEBUG
    AFFICHER_FONCTION;
  #else
  for (int i = 0; i < image->largeur * image->hauteur; i++) {
    image->pixels[i] = 255 - image->pixels[i];
  }
  #endif
}

void Seuillage(t_image* image, unsigned char seuil) {

  #if DEBUG
    AFFICHER_FONCTION;
  #else
  for (int i = 0; i < image->largeur * image->hauteur; i++)
    image->pixels[i] = SEUIL1_PIXEL(image->pixels[i], seuil);
  #endif
}
