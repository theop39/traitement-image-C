#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "image.h"
#include "traitement.h"
#include "entree_sortie.h"

int main(void) {
  t_image *image = NULL;
  t_image *rotation = NULL;

  image = LireImagePGM("voiron.pgm");
  rotation = Rotation(image);
  Miroir(image, MIROIR_HORIZONTAL);
  EcrireImagePGM("voiron_mirroir.pgm", *image);
  EcrireImagePGM("voiron_rotation.pgm", *rotation);

  LibererImage(image);
  LibererImage(rotation);


  return EXIT_SUCCESS;
}
