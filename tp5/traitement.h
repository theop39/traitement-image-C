#ifndef TRAITEMENT_H
#define TRAITEMENT_H

void Seuillage(t_image* image, unsigned char seuil);
void Negatif(t_image* image);
void ImageUnie(t_image *image, unsigned char couleur);
void Degrade(t_image* image);
void Miroir(t_image* image, int type);
t_image* Rotation(t_image* image);

#endif
