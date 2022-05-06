#define DEBUG 	0  // utilisé en interne dans le module entree_sortie.c 
#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM

// on passe un nom de fichier et l'adresse de 2 entiers
// la fonction alloue de la mémoire pour stocker les pixels lus
// elle retourne l'adresse où sont rangés les pixels
// et renseigne la largeur et la hauteur de l'image
// c'est à l'appelant de libérer (free) la mémoire allouée 
unsigned char* LireImagePGM(const char* nomFichier, int* largeur, int* hauteur) ;

// On passe un nom de fichier, l'adresse des pixels de l'image et ses dimensions
// La fonction retourne OK si l'écriture réussit et ERREUR en cas d'échec
int EcrireImagePGM(const char* nomFichier, const unsigned char* buffer, const int largeur, const int hauteur) ;
