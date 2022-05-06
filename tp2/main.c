#include <stdio.h>
#include <stdlib.h>
#include "entree_sortie.h"

void AfficherImage(char* nomFichier) {
  char cmd[25];

  sprintf(cmd, "/snap/bin/xv %s &", nomFichier);

  system(cmd);
}

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

int main(void) {
  t_image *image, *image2, *image3, *image4;

  image = CreerImage(300, 600);
  image2 = LireImagePGM("guadalest.pgm");
  image3 = CreerImage(300, 600);
  image4 = CreerImage(300, 600);

  ImageUnie(image, 0);
  ImageUnie(image3, 127);
  Negatif(image2);
  Seuillage(image3, 114);
  Degrade(image4);

  EcrireImagePGM("couleur_unie.pgm", *image);
  EcrireImagePGM("negatif.pgm", *image2);
  EcrireImagePGM("Seuillage.pgm", *image3);
  EcrireImagePGM("degrade.pgm", *image4);


  /*
  AfficherImage("couleur_unie.pgm");

  Degrade(image, largeur, hauteur);
  EcrireImagePGM("degrade.pgm", image, largeur, hauteur);
  AfficherImage("degrade.pgm");
  */

  LibererImage(image);
  LibererImage(image2);
  LibererImage(image3);
  LibererImage(image4);
/*
  image = CreerImage(largeur, hauteur);
  image = LireImagePGM("guadalest.pgm", &largeur, &hauteur);
  Negatif(image, largeur, hauteur);

  image = CreerImage(largeur, hauteur);

  ImageUnie(image, largeur, hauteur, 50);
  EcrireImagePGM("imageTest.pgm", image, largeur, hauteur);
  AfficherImage("imageTest.pgm");

  pixels = LireImagePGM("guadalest.pgm", &largeur, &hauteur);

  EcrireImagePGM("guadalest_copie.pgm", pixels, largeur, hauteur);

  free(pixels);

  AfficherImage("guadalest_copie.pgm");
  */

  //Seuillage(image, largeur, hauteur, 167);
  //EcrireImagePGM("guadalest_copie2.pgm", image, largeur, hauteur);
  return EXIT_SUCCESS;
}
