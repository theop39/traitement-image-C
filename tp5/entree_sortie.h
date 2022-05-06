#ifndef ENTREE_SORTIE_H
#define ENTREE_SORTIE_H

int EcrireImagePGM(const char* nomFichier, const t_image im);
void AfficherImage(char* nomFichier);
t_image* LireImagePGM(const char* nomFichier);

#endif
