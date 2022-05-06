typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;

#define DEBUG 	0  // utilisé en interne dans le module entree_sortie.c
#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM

//----------------------------------------------------------------------
// LireImagePGM fait les allocations mémoires pour créer la structure
// et la zone pour stocker les pixels
// elle lit le fichier image et initialise la structure.
// ele renvoie un pointeur sur la structure créée
//----------------------------------------------------------------------
t_image* LireImagePGM(const char* nomFichier) ;

//----------------------------------------------------------------------
// EcrireImagePGM écrit l'image stockée dans la structure dans
// un fichier au format PGM dont le nom est passé en paramètre.
// elle renvoie OK si l'écriture s'est bien déroulée, ERREUR sinon
//----------------------------------------------------------------------
int EcrireImagePGM(const char* nomFichier, const t_image im) ;
