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

void Miroir(t_image* image, int type) {

  if (type == MIROIR_HORIZONTAL) {

    unsigned char *temp = malloc(sizeof(unsigned char) * image->largeur);

    for (int y = 0; y < image->hauteur; y++) {
      for (int x = 0; x < image->largeur; x++) {
        temp[image->largeur - 1 - x] = image->pixels[y * image->largeur + x];
        image->pixels[y * image->largeur + x] = temp[x];
      }
    }

    free(temp);
  }
  else if (type == MIROIR_VERTICAL) {

    unsigned char *temp = malloc(sizeof(unsigned char) * image->hauteur);


    for (int x = 0; x < image->largeur; x++) {
      for (int y = 0; y < image->hauteur; y++) {
        temp[image->hauteur - 1 - y] = image->pixels[y * image->largeur + x];
        image->pixels[y * image->largeur + x] = temp[y];
      }
    }

    free(temp);
  }
  else {
    AFFICHER_FONCTION;
    fprintf(stderr, "type mirroir inconnu\n");
  }
}

t_image* Rotation(t_image* image) {
        t_image *newImage = CreerImage(image->hauteur, image->largeur);
        unsigned char *temp = (unsigned char*) malloc (sizeof(unsigned char) * image->hauteur);

        for (int x = 0; x < image->largeur; x++) {
          for (int y = 0; y < image->hauteur; y++) {
                  temp[image->hauteur - 1 - y] = image->pixels[y * image->largeur + x];

          }
            for (int i = 0; i < image->hauteur; i++)
              newImage->pixels[x * image->hauteur + i] = temp[i];
        }

        free(temp);

        return newImage;
}

int* Histogramme(t_image* image) {
  int *counteur =

  return counter;
}
