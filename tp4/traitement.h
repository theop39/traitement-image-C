#ifndef TRAITEMENT_H
#define TRAITEMENT_H

void Seuillage(t_image* image, unsigned char seuil);
void Negatif(t_image* image);
void ImageUnie(t_image *image, unsigned char couleur);
void Degrade(t_image* image);

#endif
