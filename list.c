#include "liste.h"

//BUT Initialisé une liste à vide
//ENTREE la liste
//SORTIE la liste vide
    void initialisation (Liste * liste)
    {

      liste->debut = NULL;
      liste->fin = NULL;
      liste->taille = 0;

    }

//BUT Afficher une liste
//ENTREE la liste
//SORTIE affichage de la liste
    void affiche (Liste * liste){

      Maillon *courant;
      courant = liste->debut;

      while (courant != NULL){
          printf ("%p - %i - %i - %i\n", courant, courant->valeur.x,courant->valeur.y,courant->valeur.z);
          courant = courant->suivant;
      }
    }

//BUT Insérer un point dans une liste vide
//ENTREE la liste vide et le point
//SORTIE la liste avec le point
    int insListeVide (Liste * liste, Point *donnee){

      Maillon *nouveau_Maillon;

      if ((nouveau_Maillon = (Maillon *) malloc (sizeof (Maillon))) == NULL)
        return -1;

      nouveau_Maillon->valeur.x=donnee->x;
      nouveau_Maillon->valeur.y=donnee->y;
      nouveau_Maillon->valeur.z=donnee->z;

      nouveau_Maillon->suivant = NULL;
      liste->debut = nouveau_Maillon;
      liste->fin = nouveau_Maillon;
      liste->taille++;
      return 0;
    }

//BUT Insérer un point au début d'une liste
//ENTREE la liste et le point
//SORTIE la liste avec le nouveau point
    int insDebutListe (Liste * liste, Point *donnee){

     Maillon *nouveau_Maillon;

      if ((nouveau_Maillon = (Maillon *) malloc (sizeof (Maillon))) == NULL)
        return -1;


      nouveau_Maillon->valeur.x=donnee->x;
      nouveau_Maillon->valeur.y=donnee->y;
      nouveau_Maillon->valeur.z=donnee->z;

      nouveau_Maillon->suivant = liste->debut;
      liste->debut = nouveau_Maillon;
      liste->taille++;
      return 0;
    }

//BUT Insérer un point à la fin d'une liste
//ENTREE la liste et le point
//SORTIE la liste avec le nouveau point
    int insFinListe (Liste * liste, Maillon * courant, Point *donnee){

      Maillon *nouveau_Maillon;

      if ((nouveau_Maillon = (Maillon *) malloc (sizeof (Maillon))) == NULL)
        return -1;

      nouveau_Maillon->valeur.x=donnee->x;
      nouveau_Maillon->valeur.y=donnee->y;
      nouveau_Maillon->valeur.z=donnee->z;

      courant->suivant = nouveau_Maillon;
      nouveau_Maillon->suivant = NULL;

      liste->fin = nouveau_Maillon;

      liste->taille++;
      return 0;
    }

//BUT Insérer un point dans une liste
//ENTREE la liste et le point et la position
//SORTIE la liste avec le nouveau point
    int insListe (Liste * liste, Point *donnee, int pos){

      if (liste->taille < 2)
        return -1;
      if (pos < 1 || pos >= liste->taille)
        return -1;

      Maillon *courant;
      Maillon *nouveau_Maillon;

      int i;

      if ((nouveau_Maillon = (Maillon *) malloc (sizeof (Maillon))) == NULL)
        return -1;

      courant = liste->debut;
      for (i = 1; i < pos; ++i)
        courant = courant->suivant;

      if (courant->suivant == NULL)
        return -1;

      nouveau_Maillon->valeur.x=donnee->x;
      nouveau_Maillon->valeur.y=donnee->y;
      nouveau_Maillon->valeur.z=donnee->z;

      nouveau_Maillon->suivant = courant->suivant;
      courant->suivant = nouveau_Maillon;
      liste->taille++;
      return 0;
    }

//BUT Supprimer un point au début d'une liste
//ENTREE la liste
//SORTIE la liste avec le point en moins
    int suppDebut (Liste * liste){

      if (liste->taille == 0)
        return -1;

      Maillon *supp_Maillon;

      supp_Maillon = liste->debut;
      liste->debut = liste->debut->suivant;

      if (liste->taille == 1)
        liste->fin = NULL;

      free (supp_Maillon);
      liste->taille--;
      return 0;
    }

//BUT Supprimer un point à la fin d'une liste
//ENTREE la liste
//SORTIE la liste avec le point en moins
    int suppDansListe (Liste * liste, int pos){

      if (liste->taille <= 1 || pos < 1 || pos >= liste->taille)
        return -1;

      int i;

      Maillon *courant;
      Maillon *supp_Maillon;
      courant = liste->debut;

      for (i = 1; i < pos; ++i)
        courant = courant->suivant;

      supp_Maillon = courant->suivant;
      courant->suivant = courant->suivant->suivant;

      if(courant->suivant == NULL)
              liste->fin = courant;

      free (supp_Maillon);
      liste->taille--;

      return 0;
    }

//BUT Détruire une liste
//ENTREE la liste
//SORTIE la liste vide
    void detruire (Liste * liste){

      while (liste->taille > 0)
        suppDebut (liste);

    }

//BUT Permettre à l'utilisateur de choisir une option
//ENTREE la liste et k
//SORTIE le choix du joueur
    int menu (Liste *liste,int *k){

      int choix;
      printf("********** MENU **********\n");
      if (liste->taille == 0){
        printf ("1. Ajout du 1er element\n");
        printf ("2. Quitter\n");
      }else if(liste->taille == 1 || *k == 1){
        printf ("1. Ajout au debut de la liste\n");
        printf ("2. Ajout a la fin de la liste\n");
        printf ("4. Suppression au debut de la liste\n");
        printf ("6. Detruire la liste\n");
        printf ("7. Quitter\n");
      }else {
        printf ("1. Ajout au debut de la liste\n");
        printf ("2. Ajout a la fin de la liste\n");
        printf ("3. Ajout apres la position specifie\n");
        printf ("4. Suppression au debut de la liste\n");
        printf ("5. Suppression apres la position specifie\n");
        printf ("6. Detruire la liste\n");
        printf ("7. Quitter\n");
      }
      printf ("\n\nFaites votre choix : ");
      scanf ("%d", &choix);
      getchar();
      if(liste->taille == 0 && choix == 2)
        choix = 7;
      return choix;

    }
