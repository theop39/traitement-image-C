#include <stdio.h>
#include <stdlib.h>
#include "entree_sortie.h"

void AfficherImage(char* nomFichier) {
  char cmd[25];

  sprintf(cmd, "/snap/bin/xv %s &", nomFichier);

  system(cmd);
}

unsigned char* CreerImage(int largeur, int hauteur) {
  unsigned char *pixels;


  pixels = (unsigned char*) malloc(largeur * hauteur * sizeof(unsigned char) + 1);

    return pixels;
}

void ImageUnie(unsigned char* image, int largeur, int hauteur, unsigned char couleur) {
  for (int i = 0; i < largeur * hauteur; i++) {
    image[i] = couleur;
  }
}

void Negatif(unsigned char* image, int largeur, int hauteur) {
  for (int i = 0; i < largeur * hauteur; i++) {
    image[i] = 255 - image[i];
  }
}

void Seuillage(unsigned char* image, int largeur, int hauteur, unsigned char seuil) {
  for (int i = 0; i < largeur * hauteur; i++) {
    if (image[i] < seuil) {
      image[i] = 0;
    }
    else {
      image [i] = 255;
    }
  }
}

void Degrade(unsigned char* image, int largeur, int hauteur) {
  float pas = 0;

  for (int i = 0; i < largeur * hauteur; i++) {
    if (i % largeur == 0) {
      pas = 0.0;
    }

    image[i] = pas;

    pas += 255.0 / (largeur - 1.0);

  }
}

int main(void) {
  unsigned char *image;
  int hauteur = 600, largeur = 300;

  image = CreerImage(largeur, hauteur);


  Degrade(image, largeur, hauteur);

  EcrireImagePGM("degrade.pgm", image, largeur, hauteur);
  AfficherImage("degrade.pgm");

  free(image);

  return EXIT_SUCCESS;
}
