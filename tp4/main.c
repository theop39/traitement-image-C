#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "image.h"
#include "traitement.h"
#include "entree_sortie.h"

int main(void) {
  t_image *image;

  image = LireImagePGM("voiron.pgm");
  Degrade(image);
  EcrireImagePGM("voiron_copie.pgm", *image);
  LibererImage(image);

  return EXIT_SUCCESS;
}
